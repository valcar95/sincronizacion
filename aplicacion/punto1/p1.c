#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


void main(int argc, char *argv[])
{
   struct timeval ti, tf;
   gettimeofday(&ti, NULL);   // Instante inicial
   gettimeofday(&tf, NULL);   // Instante final
   double tiempo= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
   printf("Total tiempo: %g milisegundos\n", tiempo);
   
}

