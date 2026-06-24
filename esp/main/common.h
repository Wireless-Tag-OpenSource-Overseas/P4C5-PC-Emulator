#ifndef COMMON_H
#define COMMON_H

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

struct Globals {
	void *pc;
	void *kbd;
	void *mouse;
	void *panel;
	void *panel_fb;   /* DMA frame buffer 0 for double-buffering */
	void *panel_fb1;  /* DMA frame buffer 1 for double-buffering */
};

extern EventGroupHandle_t global_event_group;
extern struct Globals globals;

#endif /* COMMON_H */
