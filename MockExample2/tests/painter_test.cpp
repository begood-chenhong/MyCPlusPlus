/*
 * draw_test.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: echnhog
 */

#include "gmock/gmock.h"  // Brings in gMock.
#include "gtest/gtest.h"

#include "lib/turtle.h"
#include "lib/painter.h"

using ::testing::AtLeast;
using ::testing::AnyNumber;
using ::testing::_;

class MockTurtle : public Turtle {
 public:
  // ...
  MOCK_METHOD(void, PenUp, (), (override));
  MOCK_METHOD(void, PenDown, (), (override));
  MOCK_METHOD(void, Forward, (int distance), (override));
  MOCK_METHOD(void, Turn, (int degrees), (override));
  MOCK_METHOD(void, GoTo, (int x, int y), (override));
  MOCK_METHOD(int, GetX, (), (const, override));
  MOCK_METHOD(int, GetY, (), (const, override));
};


TEST(TurtleTest, draw)
{
  MockTurtle turtle;
  Painter painter;

  EXPECT_CALL(turtle, PenDown())
      .Times(AtLeast(1));

  EXPECT_CALL(turtle, PenUp())
      .Times(AtLeast(1));

  EXPECT_CALL(turtle, GoTo(_, _))
       .Times(AnyNumber());
  EXPECT_CALL(turtle, GoTo(0, 0))  // sticky
      .Times(2);

  ASSERT_TRUE(painter.draw(turtle));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
