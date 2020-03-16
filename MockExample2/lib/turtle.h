/*
 * turtle.h
 *
 *  Created on: Mar 9, 2020
 *      Author: echnhog
 */

#ifndef MOCKEXAMPLE2_LIB_TURTLE_H_
#define MOCKEXAMPLE2_LIB_TURTLE_H_


class Turtle {
public:
  // ...
  virtual ~Turtle() {};
  virtual void PenUp() = 0;
  virtual void PenDown() = 0;
  virtual void Forward(int distance) = 0;
  virtual void Turn(int degrees) = 0;
  virtual void GoTo(int x, int y) = 0;
  virtual int GetX() const = 0;
  virtual int GetY() const = 0;
};


#endif /* MOCKEXAMPLE2_LIB_TURTLE_H_ */
