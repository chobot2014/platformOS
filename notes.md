sudo apt-get install libc6-dev-i386
npm install
npm run asbuild

might be better to copy the files in to that dir, because it generates the path based on your dir when you run it


cd ./lib
rm -d wabt
git clone https://github.com/WebAssembly/wabt.git
cd wabt
mkdir build
cd build
git submodule update --init
cmake ..
cmake --build .
cp wasm2c ../../../build

cd ../../../build



gcc -o linkedKernel osInjector.c wasmOs.c wasm-rt-impl.c

./lib/wabt/build/wasm2c ./build/optimized.wasm -o optimized.c
nasm -f elf32 kernel.asm -o kasm.o


gcc -m32 -c ./build/optimized.c -o kc.o
<!-- 
or maybe

gcc -m32 -c kernel.c -o kc.o

or  -->

<!-- cc -o kernel kernel.c ./build/optimized.c ./build/wasm-rt-impl.c -->


ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o
ld -m amd64 -T link.ld -o kernel kasm.o kc.o

well, here's the thing, I need to be able to call a function written in c
that allows me to get access to the physical memory map.

I need to do this to interact properly with something like a display



