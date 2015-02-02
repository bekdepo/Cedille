#include <logging.h>
#include <cedille/pmm.h>
#include <cedille/heap.h>
extern uint32_t _kernel_start,_kernel_end;
void init_vmm();
int kmain() {
	printk("debug","Control transfered to kmain()\n");
	init_early_malloc(&_kernel_end);
	init_pmm();
	init_vmm();
	while(1) {
		
	}
	return 0;
}
