#include "wasmOs.h"

// Simple VGA text mode print function
void print(const char* str) {
    static unsigned short* video_memory = (unsigned short*)0xB8000;
    static int position = 0;

    while (*str) {
        // Write character with white text on black background
        video_memory[position] = (*str) | (0x0F << 8);
        position++;
        str++;
    }
}

int main(int argc, char ** argv) {
    print("Hello from platformOS!");
    print(" C kernel starting...");
    init();
    print(" WebAssembly kernel running...");
    Z_kernelmainZ_iv();
    print(" Kernel execution complete!");
    return 0;
}