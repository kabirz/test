#include "common.h"
#include "wdt.h"

void wdt_init(int ms)
{
	//0.032ms
	WTCON = (65 << 8) | (1 << 3) | (1 << 2);
	WTCNT = 32 * ms;
	WTDAT = WTCNT;
}

void wdt_enable(void)
{
	WTCON |= 1 << 5;
}

void wdt_disable(void)
{
	WTCON &= ~(1 << 5);
}

void wdt_clr_int(void)
{
	WTCLRINT = 1;
}
