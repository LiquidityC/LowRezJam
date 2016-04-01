# LowRezJam (2016)

My submission to [#LowRezJam2016](https://itch.io/jam/lowrezjam2016)

The game is not close to completion. Hopefully I will remember to change this README when it is.
Either way the latest commits will probably confirm just about how far I've come.

If you want to compile the code and check it out then please follow these unstructions:

### Compile
- git clone https://github.com/LiquidityC/LowRezJam --recursive
- cd LowRezJam
- mkdir build
- cd build
- cmake ..
- make
- cd ..
- ./build/lowrezjam

You'll need to install sdl2. sdl2_image, sdl2_mixer and sdl2_ttf in order to get it to compile
on archlinux this is done with 'pacman -S sdl2 sdl2_mixer sdl2_ttf sdl2_image' on debian based distros it's something
like this: 'apt-get install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-mixer-dev'

Good Luck!
