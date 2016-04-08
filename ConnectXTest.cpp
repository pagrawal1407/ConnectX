/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
 
class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(ConnectXTest, toggleTurnCheck)
{
  ConnectX C;
  int turn;

  if (C.whoseTurn() == 1)
    turn = 2;
  else
    turn = 1;
  
  C.placePiece(0);  
  ASSERT_EQ(turn, C.whoseTurn());
  
  turn = 2;
  C.placePiece(0);  
  ASSERT_EQ(turn, C.whoseTurn());
}

TEST(ConnectXTest, showBoardCheck)
{
  ConnectX C;
  int turn;

  if (C.whoseTurn() == 1)
    turn = 1;
  else
    turn = 2;
  
  C.placePiece(0);
  C.showBoard();
  ASSERT_EQ(turn, C.at(0,5));
  
  turn = 1;
  C.placePiece(0);
  C.showBoard();
  ASSERT_EQ(turn, C.at(0,4));
}

TEST(ConnectXTest, outOfBoundLeftCheck)
{
  ConnectX C;
  ASSERT_EQ(-1, C.at(-1,-2));
}


TEST(ConnectXTest, outOfBoundRightCheck)
{
  ConnectX C(5,4,3);
  
  ASSERT_EQ(-1, C.at(7,8));
}

TEST(ConnectXTest, inBoundCheck)
{
  ConnectX C(5,4,3);
  
  ASSERT_EQ(0, C.at(2,2));
}

TEST(ConnectXTest, invalidWidth)
{
  ConnectX C (0,0,0);
  int turn = 2;

  ASSERT_EQ (turn, C.whoseTurn());
}

TEST(ConnectXTest, invalidHeight)
{
  ConnectX C (1,0,0);
  int turn = 2;

  ASSERT_EQ (turn, C.whoseTurn());
}

TEST(ConnectXTest, invalidToWin)
{
  ConnectX C (1,1,0);
  int turn = 2;

  ASSERT_EQ (turn, C.whoseTurn());
}

TEST(ConnectXTest, outOfBoundFail)
{
  ConnectX C;
  
  ASSERT_EQ(-1, C.at(-1,2));
}
