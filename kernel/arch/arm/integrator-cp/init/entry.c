#include <state.h>
#include <logging.h>
#include <cedille/pmm.h>
#include <cedille/heap.h>
#include <arch/arm/arm4/interrupts.h>
#ifdef GRAPHICS_DEVICE_PL110
#include <arch/arm/arm4/integrator-cp/pl110.h>
#endif

extern uintptr_t _kernel_start,_kernel_end;

int kernel_entry (void) {
	
#ifdef GRAPHICS_DEVICE_PL110
	arm4_integrator_cp_pl110_start();
	log_low("kernel[pre]-> Started graphics device \"PL110\"\n");
#endif
	
	for(int i = 0; i!=80; i++) {
		log_low("-");
	}
	log_low("\n");
	text_console_init();
	low_printname();
	log_low("Using advanced logging...\n\n");
	printk("debug","Kernel Resides @ 0x%X => 0x%X\n",&_kernel_start,&_kernel_end);
	printk("status","Logging on UART0!\n");
    printk("status","Entering boot phase\n");
    printk("cpu","Initialising hardware\n");
	printk("arm4","Initialising Interrupts...\n");
	arm4_init_interrupts();
	asm("swi 0");
	printk("info","Initialising physical memory manager.\n");
	init_early_malloc(&_kernel_end);
	pmm_set_maxmem(0x4000000);
	init_pmm();
	printk("status","Ending Boot Phase...\n");
	
	idle();
    return 0;
}