/* Minimal WebAssembly runtime stubs for kernel environment */

#include <stdint.h>

typedef uint32_t wasm_rt_type_t;
typedef uint32_t wasm_rt_trap_t;

#define WASM_RT_TRAP_NONE 0

extern uint32_t wasm_rt_call_stack_depth;

/* Stub implementations - minimal for kernel */
void wasm_rt_trap(wasm_rt_trap_t code) {
    /* Kernel trap - could halt or handle error */
    __asm__ volatile("hlt");
}

void wasm_rt_register_func_type(uint32_t param_count, uint32_t result_count,
                               const wasm_rt_type_t* params, const wasm_rt_type_t* results) {
    /* Stub - do nothing in minimal kernel */
}

void* wasm_rt_allocate_memory(uint32_t initial_pages, uint32_t max_pages) {
    /* Stub - return NULL for now */
    return (void*)0;
}

void* wasm_rt_allocate_table(uint32_t elements, uint32_t max_elements, uint32_t element_size) {
    /* Stub - return NULL for now */
    return (void*)0;
}

/* Missing functions that wasm2c generated code expects */
void Z_envZ_abortZ_viiii(int a, int b, int c, int d) {
    /* Environment abort - halt the kernel */
    __asm__ volatile("hlt");
}

uint32_t wasm_rt_grow_memory(uint32_t pages) {
    /* Stub - can't grow memory in kernel, return failure */
    return (uint32_t)-1;
}

/* Global variables */
uint32_t wasm_rt_call_stack_depth = 0;