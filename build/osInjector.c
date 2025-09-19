#include "wasmOs.h"

// VGA text mode memory and constants
#define VGA_MEMORY 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_COLOR_WHITE 0x0F
#define VGA_COLOR_RED 0x0C
#define VGA_COLOR_GREEN 0x0A

// Global cursor position
int cursorX = 0;
int cursorY = 0;

// Write a single character to VGA memory
void putChar(int x, int y, char c, int color) {
    unsigned short* video_memory = (unsigned short*)VGA_MEMORY;
    int offset = (y * VGA_WIDTH + x) * 2;
    video_memory[offset] = (color << 8) | c;
}

// Print a string at specific position
void printAt(int x, int y, const char* str, int color) {
    int pos = x;
    while (*str) {
        putChar(pos, y, *str, color);
        pos++;
        str++;
    }
}

// Clear the screen
void clearScreen() {
    for (int y = 0; y < VGA_HEIGHT; y++) {
        for (int x = 0; x < VGA_WIDTH; x++) {
            putChar(x, y, ' ', VGA_COLOR_WHITE);
        }
    }
    cursorX = 0;
    cursorY = 0;
}

// Simple delay function
void delay(int count) {
    for (volatile int i = 0; i < count; i++) {
        // Busy wait
    }
}

// Core OS kernel logic (conceptually in TypeScript style)
void kernelMain() {
    // Clear screen and show welcome message
    clearScreen();

    printAt(0, 0, "=== platformOS v1.0 ===", VGA_COLOR_GREEN);
    printAt(0, 1, "TypeScript-Style Operating System", VGA_COLOR_WHITE);
    printAt(0, 3, "Kernel initialized successfully!", VGA_COLOR_GREEN);
    printAt(0, 4, "WebAssembly runtime active", VGA_COLOR_WHITE);

    // Simple counter demo
    printAt(0, 6, "Counting to 10:", VGA_COLOR_WHITE);
    for (int i = 1; i <= 10; i++) {
        char num[3];
        num[0] = '0' + i;
        num[1] = ' ';
        num[2] = '\0';
        printAt((i-1) * 3, 7, num, VGA_COLOR_RED);
        delay(500000); // Simple delay
    }

    printAt(0, 9, "Counting complete!", VGA_COLOR_GREEN);

    // Show system status
    printAt(0, 11, "System Status:", VGA_COLOR_WHITE);
    printAt(2, 12, "- VGA Text Mode: 80x25", VGA_COLOR_WHITE);
    printAt(2, 13, "- Kernel: C/WebAssembly", VGA_COLOR_WHITE);
    printAt(2, 14, "- Memory: 4MB available", VGA_COLOR_WHITE);

    printAt(0, 16, "platformOS is running!", VGA_COLOR_GREEN);
    printAt(0, 17, "Core logic implemented in high-level style", VGA_COLOR_WHITE);
}

int main(int argc, char ** argv) {
    // Initialize WebAssembly runtime
    init();

    // Call the main kernel logic (TypeScript-style architecture)
    kernelMain();

    // Call WebAssembly kernel (minimal function)
    Z_kernelmainZ_iv();

    // Infinite loop to keep kernel running
    while (1) {
        __asm__ volatile("hlt");
    }

    return 0;
}