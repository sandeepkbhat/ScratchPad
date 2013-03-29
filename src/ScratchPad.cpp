#include <stdio.h>
#include <stdlib.h>

#define PRINT(x,y,z) printf("x = %d,\ty=%d,\tz=%d\n",x,y,z);

int main()
{

  int x,y,z;

  // The following is evaluated as ((++x) || (++y && ++z))
  x = y = z = 1;
  ++x || ++y && ++z; PRINT(x,y,z);

  // The following is evaluated as (++x | (++y & ++z))
  x = y = z = 1;
  ++x | ++y & ++z; PRINT(x,y,z);

  return 0;
}
