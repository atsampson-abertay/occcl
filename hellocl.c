/* Simple library meant to be called from occam that serves as proof 
 * of concept for occam -> C/opencl interopability
 *
 * Copyright 2011 - Brendan Le Foll - bl73@kent.ac.uk
 */

#include "sin.h"
#include "rot13.h"
#include <stdlib.h>
#include <stdio.h>

#define SIN 1
#define PRINT_SIN 0

int main() {
  char plaintext[]="Hello, World!";
  char ciphertext[sizeof plaintext];
  
  cl_int error;
#if SIN
  int i;
#endif

  // CL initialisation
  error = initialisecl();

#if SIN
  // SIN wave
  fprintf (stdout, "========= SIN =========\n");
  // Create and initialize the input data
  cl_float *data;
  data = (cl_float*)malloc(sizeof(cl_float)*10240);
  for (i=0; i<10240; i++) {
    data[i] = i;
  }
  // init sin
  error = init_sin();
  fprintf (stdout, "init errors = %s\n", errorMessageCL(error));
  // run sin kernel
  error += clsin(data);
  fprintf (stdout, "clsin errors = %s\n", errorMessageCL(error));
#if PRINT_SIN
  for (i=0; i<10240; i++) {
    printf("sin(%d) = %f\n", i, data[i]);
    i = i + 100;
  }
#endif
  // free data
  free (data);
#endif

  // reinit cl_error
  error = 0;
  fprintf (stdout, "========= ROT13 =========\n");
  // rot13 initialisation
  error += init_rot13();
  fprintf (stdout, "init errors = %s\n", errorMessageCL(error));

  // run rot13 CL kernel
  error += rot13(plaintext, ciphertext);

  // Finally, output out happy message.
  fprintf (stdout, "rot13 errors = %d, ciphertext = %s\n", error, ciphertext);

  return error;
}
