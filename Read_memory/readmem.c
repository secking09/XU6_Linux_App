#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE - 1))

void read_memory_to_file(off_t physical_address, size_t length, const char *output_file);
int main(int argc, char *argv[])
 {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <physical_address> <length> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    off_t physical_address = strtoul(argv[1], NULL, 0);
    size_t length = strtoul(argv[2], NULL, 0);
    const char *output_file = argv[3];

    read_memory_to_file(physical_address, length, output_file);

    printf("Memory dump written to %s\n", output_file);

    return EXIT_SUCCESS;
}


void read_memory_to_file(off_t physical_address, size_t length, const char *output_file) {
    int mem_fd;
    void *mapped_base, *mapped_dev_base;
    off_t page_offset;

    // Open /dev/mem
    mem_fd = open("/dev/mem", O_RDONLY | O_SYNC);
    if (mem_fd == -1) {
        perror("Error opening /dev/mem");
        exit(EXIT_FAILURE);
    }

    // Calculate the page-aligned base address and offset
    off_t page_base = physical_address & PAGE_MASK;
    page_offset = physical_address - page_base;

    // Map the physical memory into the virtual address space
    mapped_base = mmap(NULL, length + page_offset, PROT_READ, MAP_SHARED, mem_fd, page_base);
    if (mapped_base == MAP_FAILED) {
        perror("Error mapping memory");
        close(mem_fd);
        exit(EXIT_FAILURE);
    }

    // Access the memory
    mapped_dev_base = mapped_base + page_offset;

    // Open the output file
    FILE *file = fopen(output_file, "w");
    if (!file) {
        perror("Error opening output file");
        munmap(mapped_base, length + page_offset);
        close(mem_fd);
        exit(EXIT_FAILURE);
    }

    // Write to the output file
    fprintf(file, "#include <stdint.h>\n\n");
    fprintf(file, "const uint8_t memory_dump[] = {\n");
    for (size_t i = 0; i < length; i++) {
        fprintf(file, "    0x%02x%s", *((unsigned char *)mapped_dev_base + i), (i < length - 1) ? "," : "");
        if ((i + 1) % 16 == 0) {
            fprintf(file, "\n");
        }
    }
    fprintf(file, "\n};\n");
    fprintf(file, "const size_t memory_dump_size = %zu;\n", length);

    // Clean up
    fclose(file);
    if (munmap(mapped_base, length + page_offset) == -1) {
        perror("Error unmapping memory");
    }
    close(mem_fd);
}

