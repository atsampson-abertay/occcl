/* Simple library meant to be called from occam that serves as proof 
 * of concept for occam -> C/opencl interopability
 *
 * Copyright 2011 - Brendan Le Foll - brendan@fridu.net
 * Copyright 2011 - University of Kent
 */

#ifdef __OPENCL_VERSION__
    #ifdef USE_DOUBLE
        #pragma OPENCL EXTENSION cl_khr_fp64 : enable
        typedef double floatcl;
    #elif USE_FLOAT
        typedef float floatcl;
    #else
        #error "use -D USE_DOUBLE or -D USE_FLOAT."
    #endif
#endif