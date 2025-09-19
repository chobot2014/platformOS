/// <reference path="../node_modules/assemblyscript/assembly.d.ts" />

export function kernelmain(): i32 {
  // Simple computation to show the kernel is working
  let result = 0;
  for (let i = 0; i < 5; i++) {
    result += i * 2;
  }

  // Return a value to indicate success
  return result;
}
