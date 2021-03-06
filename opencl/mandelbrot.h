/* Simple library meant to be called from occam that serves as proof 
 * of concept for occam -> C/opencl interopability
 *
 * Copyright 2011 - Brendan Le Foll - brendan@fridu.net
 * Copyright 2011 - University of Kent
 */

#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "initial.h"
#include "mandelbrot_cl.h"

#define MAX_SOURCE_SIZE (0x100000)
#define CLKERNELDEFS "mandelbrot.cl"
#define CLVISKERNELDEFS "mandelbrot_vis.cl"
#define MULTI_GPUS 1
#define JOBS_PER_FRAME 3
#define CAN_USE_DOUBLE 1
// after 1200 we loose too much precision and our target is wrong
#define MAX_NUM_ITERATIONS 1200

#define DEBUG 0
#define CLMANDEL 1
#define C_PRINT 0
#define DOUBLE 1

#if DOUBLE
typedef double cl_fract;
#else
typedef cl_float cl_fract;
#endif

#if C_PRINT
  #include "colour.h"
#endif

void _mandelbrot (int *w);
void _mandelbrotvis (int *w);
void _initmandelbrot (int *w);
void _initmandelbrotvis (int *w);
int mandelbrot (cl_char (*data)[IMAGEWIDTH*2], cl_fract *job);
void mandelbrot_c (cl_char (*data)[IMAGEWIDTH*2], cl_fract *job);
int mandelbrotvis (cl_int *data, cl_fract *job);
int init_mandelbrot ();
int init_mandelbrotvis ();

#endif
