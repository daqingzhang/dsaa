#ifndef __DEBUG_H__
#define __DEBUG_H__
#include <stdio.h>

#define ioprintf printf

#ifdef CONFIG_DEBUG
#define DEBUG ioprintf
#else
#define DEBUG(...) do{}while(0)
#endif

#endif
