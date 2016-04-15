#!/bin/sh

echo "Building"
mkdir -p build/release
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain-archlinux-x86_64-mingw32.cmake ..
make
cp lowrezjam.exe release/.
cd ..

echo "Copying files"
cp /usr/x86_64-w64-mingw32/bin/SDL2.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/SDL2_image.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/SDL2_mixer.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/SDL2_ttf.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/libbz2-1.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/libfreetype-6.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/libgcc_s_seh-1.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/libpng16-16.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/libstdc++-6.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/libwinpthread-1.dll build/release/.
cp /usr/x86_64-w64-mingw32/bin/zlib1.dll build/release/.

cp -r sounds build/release/.
cp -r textures build/release/.

mv build/release build/LowRezJam

echo "Compressing"
cd build
zip -r LowRezJam.zip LowRezJam/
cd ..
