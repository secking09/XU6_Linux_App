#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdlib.h>
#include "string.h"
#include <termios.h>

#define DMA_BASE_ADDRESS   0x80020000
#define SG_BASE_ADDRESS    0x30000000
#define MEM_BUFFER_ADDRESS 0x31000000
#define PACKAGER_BASE      0x80060000
   

#define PAGE_SIZE1        65535
#define PAGE_SIZE2        4095

#define DESC1            0x30000000
#define MM2S_DMACR       0x00
#define MM2S_DMASR       0x04
#define MM2S_CURDESC     0x08
#define MM2S_CURDESC_MSB 0x0C
#define MM2S_TAILDESC    0x10
#define MM2S_SA          0x18
#define MM2S_SA_MSB      0x1C
#define MM2S_LENGTH      0x28
#define S2MM_DMACR       0x30
#define S2MM_DMASR       0x34
#define S2MM_CURDESC     0x38
#define S2MM_TAILDESC    0x40
#define S2MM_DA          0x48
#define S2MM_DA_MSB      0x4C
#define S2MM_LENGTH      0x58

#define NXTDESC				0x00
#define NXTDESC_MSB			0x04
#define BUFFER_ADDRESS	    0x08
#define BUFFER_ADDRESS_MSB  0x0C
#define CONTROL				0x18
#define STATUS				0x1C
#define APP0				0x20
#define APP1				0x24
#define APP2				0x28
#define APP3				0x2C
#define APP4				0x30




void mmio_write(unsigned int *base, unsigned int offset, unsigned int value);
unsigned int mmio_read(unsigned int *base, unsigned int offset);

unsigned int dma_set(unsigned int* dma_virtual_address, int offset, unsigned int value) {
    dma_virtual_address[offset>>2] = value;
}
void dma_s2mm_status(unsigned int* dma_virtual_address) {
    unsigned int status = mmio_read(dma_virtual_address, S2MM_DMASR);
    printf("Stream to memory-mapped status (0x%08x@0x%02x):", status, S2MM_DMASR);
    if (status & 0x00000001) printf(" halted"); else printf(" running");
    if (status & 0x00000002) printf(" idle");
    if (status & 0x00000008) printf(" SGIncld");
    if (status & 0x00000010) printf(" DMAIntErr");
    if (status & 0x00000020) printf(" DMASlvErr");
    if (status & 0x00000040) printf(" DMADecErr");
    if (status & 0x00000100) printf(" SGIntErr");
    if (status & 0x00000200) printf(" SGSlvErr");
    if (status & 0x00000400) printf(" SGDecErr");
    if (status & 0x00001000) printf(" IOC_Irq");
    if (status & 0x00002000) printf(" Dly_Irq");
    if (status & 0x00004000) printf(" Err_Irq");
    printf("\n");
}
void memdump(void* virtual_address, int byte_count) {
    uint32_t *p = virtual_address; // Interpret as 32-bit values
    int offset;

    for (offset = 0; offset < byte_count / 4; offset++) { // Divide by 4 to process 32-bit words
        printf("%08x / \n", p[offset]); // Print each 32-bit word
    }
    printf("\n");
}



int recv_status;
int main()
{

    int reg_value_2;
    unsigned int read_val;
    int fd;
    int status;
    unsigned int *sg_base, *axi_base, *packager_base; 

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0) {
    perror("open /dev/mem failed");
    exit(EXIT_FAILURE);
    }

    sg_base = mmap(NULL, PAGE_SIZE2, PROT_READ | PROT_WRITE, MAP_SHARED, fd, SG_BASE_ADDRESS & ~(PAGE_SIZE2 - 1));
    if (sg_base == MAP_FAILED) {
        perror("sg_base failed");
        exit(EXIT_FAILURE);
    }
        else {
            printf("oldu bu \n\r");
        }

    axi_base = mmap(NULL, PAGE_SIZE2, PROT_READ | PROT_WRITE, MAP_SHARED, fd, DMA_BASE_ADDRESS & ~(PAGE_SIZE2 - 1));
    if (axi_base == MAP_FAILED) {
        perror("dma_base failed");
        exit(EXIT_FAILURE);
    }
    packager_base = mmap(NULL, PAGE_SIZE2, PROT_READ | PROT_WRITE, MAP_SHARED, fd, PACKAGER_BASE & ~(PAGE_SIZE2 - 1));
    if (packager_base == MAP_FAILED) {
        perror("packager_base failed");
        exit(EXIT_FAILURE);
    }


    for (int i=0; i<40; i++)
    {
        mmio_write(sg_base,i*0x4,0x0); 
    }

   
    //memdump(axi_base,64);



    mmio_write(sg_base,NXTDESC,0x00000000); 
    mmio_write(sg_base,NXTDESC_MSB,0x00000000); 
    mmio_write(sg_base,BUFFER_ADDRESS,0x30010000); 
    mmio_write(sg_base,BUFFER_ADDRESS_MSB,0x00000000);
    mmio_write(sg_base,0x10,0x00000000);
    mmio_write(sg_base,0x14,0x00000000);
    mmio_write(sg_base,CONTROL,0x0C0BBC60); 
    mmio_write(sg_base,STATUS,0x00000000);  
    mmio_write(sg_base,APP0,0x00000000); 
    mmio_write(sg_base,APP1,0x00000000); 
    mmio_write(sg_base,APP2,0x00000000); 
    mmio_write(sg_base,APP3,0x00000000); 
    mmio_write(sg_base,APP4,0x00000000); 

    //mmio_write(sg_base,NXTDESC+0x40,SG_BASE_ADDRESS); 
    //mmio_write(sg_base,NXTDESC_MSB+0x40,0x00000000); 
    //mmio_write(sg_base,BUFFER_ADDRESS+0x40,MEM_BUFFER_ADDRESS); 
    //mmio_write(sg_base,BUFFER_ADDRESS_MSB+0x40,0x00000000);
    //mmio_write(sg_base,0x10+0x40,0x00000000);
    //mmio_write(sg_base,0x14+0x40,0x00000000);
    //mmio_write(sg_base,CONTROL+0x40,0x0C001000); 
    //mmio_write(sg_base,STATUS+0x40,0x00000000);  
    //mmio_write(sg_base,APP0+0x40,0x00000000); 
    //mmio_write(sg_base,APP1+0x40,0x00000000); 
    //mmio_write(sg_base,APP2+0x40,0x00000000); 
    //mmio_write(sg_base,APP3+0x40,0x00000000); 
    //mmio_write(sg_base,APP4+0x40,0x00000000); 
    //mmio_write(axi_base, S2MM_CURDESC, w_base_addr);
    //mmio_write(axi_base, S2MM_DMACR, 0x1);
    //mmio_write(axi_base, S2MM_TAILDESC, w_base_addr);
    //memdump(sg_base,0x80);
    
    mmio_write(axi_base,S2MM_DMACR,0x4);
    mmio_write(axi_base,MM2S_DMACR,0x4);
    mmio_write(packager_base,0x0,0x2);
    while(1){
        printf("DMA Reset is in progress... \n\r");
        read_val = mmio_read(axi_base, S2MM_DMACR);
        printf("%x '\n\r", read_val);
        if(read_val != 0x4){
            break;
        }
    }
    
    dma_s2mm_status(axi_base);
    
    mmio_write(axi_base,S2MM_CURDESC,SG_BASE_ADDRESS);
    mmio_write(axi_base,S2MM_DMACR,0x00407011);
    mmio_write(axi_base,S2MM_TAILDESC,SG_BASE_ADDRESS);
    printf("memory dump; \n");
   // memdump(axi_base,0x100); 
    mmio_write(packager_base,0x4,0x2F8);
    
    dma_s2mm_status(axi_base);
    return 0;
}


void mmio_write(unsigned int *base, unsigned int offset, unsigned int value) {
    *(volatile unsigned int  *)(base + (offset / sizeof(unsigned int))) = value;
}
unsigned int mmio_read(unsigned int *base, unsigned int offset) {
    return *(volatile unsigned int *)(base + (offset / sizeof(unsigned int)));
}



