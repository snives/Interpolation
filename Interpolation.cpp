#include "Interpolation.h"


Interpolation::Interpolation(int rangex[], int rangey[], size_t size) {
  _spaceX = rangex;
  _spaceY = rangey;
  _size = size;
}


int Interpolation::Transform(int x) {
  
  //Bound the output by the range of the input.
  if (x <= _spaceX[0])
    return _spaceY[0];
  else if (x >= _spaceX[_size - 1])
    return _spaceY[_size - 1];

  //First find which section the value is bounded by.
  int i=0;
  while(x > _spaceX[i+1])
    i++;

  //simple linear interpolation between spacea[i]-spacea[i+1]
  int y2 = _spaceX[i+1];
  int y1 = _spaceX[i];
  int x2 = _spaceY[i+1];
  int x1 = _spaceY[i];
  
  int half = (y2 - y1) >> 1;    //faciliate proper rounding without floats
  int y = ((x - y1) * (x2 - x1) + half) / (y2 - y1) + x1;
  return y;
}

//Make a function for floats now, using a template method






//float Interpolation::Transform(float x);
    
