//============================================================================
// Name        : ScratchPad.cpp
// Author      : Sandeep Bhat
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


bool allocate2Dint(int rows, int cols, int ***ptr);
void init2D(int rows, int cols, int ***ptr);
bool deallocate2Dint(int rows, int cols, int ***ptr);
void print2D(int rows, int cols, int **ptr);

int main()
{
  int rows = 4;
  int cols = 3;
  int **ptr;

  cout << "Allocating 2D array" << endl;
  if(allocate2Dint(rows, cols, &ptr))
  {
    cout << "Allocated 2D array" << endl;
    init2D(rows, cols, &ptr);
    cout << "Initialized 2D array" << endl;
    print2D(rows, cols, ptr);
    deallocate2Dint(rows, cols, &ptr);
    cout << "Deallocated 2D array" << endl;
  }
	return 0;
}

void init2D(int rows, int cols, int ***ptr)
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      (*ptr)[r][c] = r * cols + c;
    }
  }
}

void print2D(int rows, int cols, int **ptr)
{
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      printf("%3d",ptr[r][c]);
    }
    printf("\n");
  }
}

bool allocate2Dint(int rows, int cols, int ***ptr)
{
  *ptr = (int **)malloc(rows * sizeof(int *));
	if(ptr == NULL)
	{
	  return false;
	}
	for(int r = 0; r < rows; r++)
	{
		(*ptr)[r] = (int *)malloc(cols * sizeof(int));
		if((*ptr)[r] == NULL)
    {
		  return false;
    }
	}
	return true;
}

bool deallocate2Dint(int rows, int cols, int ***ptr)
{
  for(int r = 0; r < rows; r++)
  {
    free((*ptr)[r]);
  }
  free(*ptr);
  return true;
}
