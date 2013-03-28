#include <stdio.h>
#include <stdlib.h>

int main()
{
  long  mat[5][5], **ptr;

  mat[0][0] = 3;
  ptr = (long **)mat;

  printf("  mat          %p \n",   mat);
  printf("  mat[0]       %p \n",   mat[0]);
  printf(" *mat          %p \n",  *mat);
  printf(" &mat          %p \n",  &mat);
  printf("  ptr          %p \n",   ptr);
  printf("  mat[0][0]    %d \n",   mat[0][0]);
  printf(" &mat[0][0]    %p \n",  &mat[0][0]);
  printf(" &ptr[0][0]    %p \n",  &ptr[0][0]);
  printf("  ptr[0]       %p \n",   ptr[0]);
  printf(" *ptr          %p \n",  *ptr);
  printf(" &ptr          %p \n",  &ptr);

  return 0;
}


//Output in Eclipse IDE on Mac OS X
/*
  mat          0x7fff530c3ac0
  mat[0]       0x7fff530c3ac0
 *mat          0x7fff530c3ac0
 &mat          0x7fff530c3ac0
  ptr          0x7fff530c3ac0
  mat[0][0]    3
 &mat[0][0]    0x7fff530c3ac0
 &ptr[0][0]    0x3
  ptr[0]       0x3
 *ptr          0x3
 &ptr          0x7fff530c3ab8

 Note: A ~~ B,  implies A is equivalent to B
       A !~~ B, implies A is not equivalent to B

 // For 2D array long mat[][];
 mat ~~ mat[0] ~~ *mat ~~ &mat ~~ &mat[0][0]  
 // The above is true for 1D array also
 // Pointers are variables, Array names are not,
 // in the sense that mat++ is illegal.

 // For double pointer long **ptr;
 ptr !~~ &ptr
 ptr !~~ ptr[0]
 ptr[0] ~~ *ptr // (by definition  A[i] = *(A # i), 
                //  # indicating pointer addition) 

 */
