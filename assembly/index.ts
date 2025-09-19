/// <reference path="../node_modules/assemblyscript/assembly.d.ts" />

// TypeScript OS Kernel - Core functionality implemented in TypeScript
// This will be compiled to WebAssembly, then to C, then linked into the kernel

// VGA text mode memory access
const VGA_MEMORY: u32 = 0xB8000;
const VGA_WIDTH: i32 = 80;

// Color constants
const COLOR_WHITE: u8 = 0x0F;
const COLOR_GREEN: u8 = 0x0A;
const COLOR_RED: u8 = 0x0C;

// Write a character to VGA memory
function writeChar(x: i32, y: i32, char: u8, color: u8): void {
  const offset: u32 = ((y * VGA_WIDTH + x) * 2);
  const value: u16 = ((color << 8) | char);
  store<u16>(VGA_MEMORY + offset, value);
}

// Write a string to VGA memory
function writeString(x: i32, y: i32, str: string, color: u8): void {
  let pos = x;
  for (let i = 0; i < str.length; i++) {
    const charCode = str.charCodeAt(i);
    writeChar(pos, y, <u8>charCode, color);
    pos++;
  }
}

// Clear the screen
function clearScreen(): void {
  for (let y = 0; y < 25; y++) {
    for (let x = 0; x < VGA_WIDTH; x++) {
      writeChar(x, y, 32, COLOR_WHITE); // Space character
    }
  }
}

// Simple delay function
function delay(count: i32): void {
  for (let i = 0; i < count; i++) {
    // Busy wait
  }
}

// Convert number to string
function numberToString(num: i32): string {
  if (num == 0) return "0";
  let result = "";
  let n = num;
  while (n > 0) {
    result = String.fromCharCode(48 + (n % 10)) + result;
    n = n / 10;
  }
  return result;
}

// Main kernel function - ALL OS functionality implemented in TypeScript!
export function kernelmain(): i32 {
  // Clear screen - TypeScript function call
  clearScreen();

  // Welcome messages - TypeScript string operations
  writeString(0, 0, "=== platformOS v1.0 ===", COLOR_GREEN);
  writeString(0, 1, "TypeScript Kernel Active!", COLOR_WHITE);
  writeString(0, 2, "WebAssembly Runtime: Running", COLOR_WHITE);

  // System status - TypeScript variables and logic
  writeString(0, 4, "System Status: INITIALIZED", COLOR_GREEN);
  writeString(0, 5, "Kernel Language: TypeScript", COLOR_WHITE);
  writeString(0, 6, "Execution Mode: WebAssembly", COLOR_WHITE);

  // Counter demonstration - TypeScript loops and string conversion
  writeString(0, 8, "TypeScript Counter:", COLOR_WHITE);
  for (let i: i32 = 1; i <= 5; i++) {
    const numStr = numberToString(i);
    writeString((i - 1) * 4, 9, numStr, COLOR_RED);
    delay(1000000); // TypeScript delay function
  }

  // System information - TypeScript string concatenation
  writeString(0, 11, "Hardware Information:", COLOR_WHITE);
  writeString(2, 12, "- CPU: 32-bit x86", COLOR_WHITE);
  writeString(2, 13, "- Memory: 4MB available", COLOR_WHITE);
  writeString(2, 14, "- Display: VGA Text Mode", COLOR_WHITE);

  // Final status - TypeScript success indication
  writeString(0, 16, "platformOS Status: OPERATIONAL", COLOR_GREEN);
  writeString(0, 17, "All core functionality in TypeScript!", COLOR_WHITE);
  writeString(0, 18, "WebAssembly execution successful", COLOR_GREEN);

  // Return success code - TypeScript return value
  return 42;
}
