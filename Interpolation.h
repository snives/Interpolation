#include "Arduino.h"

#ifndef Interpolation_h
#define Interpolation_h

//TODO: Use generics so mapping can be from type T to type U

class Interpolation
{
  public:
    Interpolation(int rangex[], int rangey[], size_t size);
    int Transform(int x);
    //float Transform(float x);
	int Test(int i);
	size_t GetSize();
  private:
	//pointers to arrays
    int* _spaceX;
    int* _spaceY;
    size_t _size;
};

#endif
