#include <stddef.h>
#include <stdint.h>

// Multiboot info structure
typedef struct {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    uint32_t syms[4];
    uint32_t mmap_length;
    uint32_t mmap_addr;
} multiboot_info_t;

void kernel_main(multiboot_info_t* mb_info) {
    const char *str = "Hello from TenOS Kernel!";
    char *vidptr = (char*)0xb8000; // Video memory begins here.
    unsigned int i = 0;
    unsigned int j = 0;

    // Clear the screen
    while (j < 80 * 25 * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = 0x07; // Light grey on black background.
        j += 2;
    }

    // Write the string to video memory
    j = 0;
    while (str[j] != '\0') {
        vidptr[i] = str[j];
        vidptr[i+1] = 0x07;
        ++j;
        i += 2;
    }

    return;
}
