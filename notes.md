sudo apt-get install libc6-dev-i386
npm install
npm run asbuild

might be better to copy the files in to that dir, because it generates the path based on your dir when you run it

./lib/wabt/build/wasm2c ./build/optimized.wasm -o optimized.c
nasm -f elf32 kernel.asm -o kasm.o


gcc -m32 -c ./build/optimized.c -o kc.o
<!-- 
or maybe

gcc -m32 -c kernel.c -o kc.o

or  -->

<!-- cc -o kernel kernel.c ./build/optimized.c ./build/wasm-rt-impl.c -->


ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o