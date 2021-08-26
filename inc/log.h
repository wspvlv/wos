#ifndef LOG_H
#define LOG_H

#include <vga.h>

#define log(X,Y)	vp(ve(X,VCLW,VCLK), 78, 24); vp(ve(Y,VCLW,VCLK), 79, 24)

#endif