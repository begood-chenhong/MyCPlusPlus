/*
 * painter.h
 *
 *  Created on: Mar 9, 2020
 *      Author: echnhog
 */

#ifndef MOCKEXAMPLE2_LIB_PAINTER_H_
#define MOCKEXAMPLE2_LIB_PAINTER_H_

#include "turtle.h"

class Painter
{
public:
    Painter()
    {
      this->x = 0;
      this->y = 0;
    }

    bool draw(Turtle& turtle)
    {
      turtle.PenDown();
      turtle.PenUp();
      turtle.GoTo(0, 0);

      turtle.PenUp();
      turtle.PenDown();
      turtle.GoTo(0, 0);

      turtle.GoTo(1, 1);

      return true;
    }

private:
  int x;
  int y;
};


#endif /* MOCKEXAMPLE2_LIB_PAINTER_H_ */
