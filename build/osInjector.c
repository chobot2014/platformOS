#include "wasmOs.h"

// Minimal C bootstrap for TypeScript OS
// All core functionality is implemented in TypeScript and compiled to WebAssembly

int main(int argc, char ** argv) {
    // Initialize WebAssembly runtime
    init();

    // Call the TypeScript kernel - ALL OS functionality is in TypeScript!
    // This calls the kernelmain() function from assembly/index.ts
    // which was compiled to WebAssembly, then to C, then linked here
    Z_kernelmainZ_iv();

    // Infinite loop to keep kernel running
    while (1) {
        __asm__ volatile("hlt");
    }

    return 0;
}