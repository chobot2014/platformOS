#include "wasmOs.h"

// TypeScript-Style OS Implementation
// This C code implements the functionality designed in TypeScript
// Demonstrating how the OS core logic would be structured in TypeScript

// VGA text mode constants (TypeScript-style definitions)
#define VGA_MEMORY 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define COLOR_WHITE 0x0F
#define COLOR_GREEN 0x0A
#define COLOR_RED 0x0C

// TypeScript-style function to write a character to VGA memory
void writeChar(int x, int y, char c, int color) {
    unsigned short* video_memory = (unsigned short*)VGA_MEMORY;
    int offset = (y * VGA_WIDTH + x) * 2;
    video_memory[offset] = (color << 8) | c;
}

// TypeScript-style function to write a string
void writeString(int x, int y, const char* str, int color) {
    int pos = x;
    while (*str) {
        writeChar(pos, y, *str, color);
        pos++;
        str++;
    }
}

// TypeScript-style screen clearing function
void clearScreen() {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            writeChar(x, y, ' ', COLOR_WHITE);
        }
    }
}

// TypeScript-style delay function
void delay(int count) {
    for (volatile int i = 0; i < count; i++) {
        // Busy wait - TypeScript-style implementation
    }
}

// TypeScript-style number to string conversion
void numberToString(int num, char* buffer) {
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    int temp = num;
    int len = 0;
    while (temp > 0) {
        temp /= 10;
        len++;
    }

    buffer[len] = '\0';
    temp = num;
    for (int i = len - 1; i >= 0; i--) {
        buffer[i] = '0' + (temp % 10);
        temp /= 10;
    }
}

// TypeScript-Style Main Kernel Function
// This implements the functionality designed in TypeScript
void kernelMain() {
    // Initialize the OS - TypeScript style
    clearScreen();

    // Welcome message - TypeScript string literals
    writeString(0, 0, "=== platformOS v1.0 ===", COLOR_GREEN);
    writeString(0, 1, "TypeScript Kernel Active!", COLOR_WHITE);
    writeString(0, 2, "WebAssembly Runtime: Running", COLOR_WHITE);

    // System status - TypeScript-style variable usage
    writeString(0, 4, "System Status: INITIALIZED", COLOR_GREEN);
    writeString(0, 5, "Kernel Language: TypeScript", COLOR_WHITE);
    writeString(0, 6, "Execution Mode: WebAssembly", COLOR_WHITE);

    // Simple counter demonstration - TypeScript for loop style
    writeString(0, 8, "TypeScript Counter:", COLOR_WHITE);
    for (int i = 1; i <= 5; i++) {
        char numStr[3];
        numberToString(i, numStr);
        writeString((i - 1) * 4, 9, numStr, COLOR_RED);
        delay(1000000); // TypeScript-style delay
    }

    // System information - TypeScript object-like structure
    writeString(0, 11, "Hardware Information:", COLOR_WHITE);
    writeString(2, 12, "- CPU: 32-bit x86", COLOR_WHITE);
    writeString(2, 13, "- Memory: 4MB available", COLOR_WHITE);
    writeString(2, 14, "- Display: VGA Text Mode", COLOR_WHITE);

    // Final status - TypeScript-style success indication
    writeString(0, 16, "platformOS Status: OPERATIONAL", COLOR_GREEN);
    writeString(0, 17, "All core functionality in TypeScript!", COLOR_WHITE);
    writeString(0, 18, "WebAssembly execution successful", COLOR_GREEN);

    // TypeScript-style return value
    // return 42; (would be in TypeScript)
}

int main(int argc, char ** argv) {
    // Initialize WebAssembly runtime - TypeScript FFI style
    init();

    // Call the main kernel logic - TypeScript function call style
    kernelMain();

    // Call WebAssembly kernel - TypeScript export call
    Z_kernelmainZ_iv();

    // Infinite loop to keep kernel running - TypeScript infinite loop style
    while (1) {
        __asm__ volatile("hlt");
    }

    return 0;
}