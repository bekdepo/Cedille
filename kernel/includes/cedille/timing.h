#ifndef TIMING_H
#define TIMING_H
#include <stdint.h>
#include <stddef.h>
#include <cedille/ktypes.h>
#define TIMING_ENGINE_HARDTICK 0xFFFFFF

void timing_system_engine_dotick(kernel_time_t tick);
void timing_system_engine_reportstatustoconsole();

#endif