

Name :- Parag Agrawal

Bug 1: In the inBounds() Funtion.
  The function fails when we pass an invalid width with a valid height in the inBounds() function. 
  First condition checks for the width. Since it is invalid, it makes the value of inside variable as false.
  Then, second condition checks for the height. Since it is valid, it changes the value of inside variable from false to true and returns it.
  So, the result of inBounds() function is true in this case, which is not correct as we passed an invalid width. Ideally, it should return false.
  This case is demonstrated in the very last test case in ConnectXTest.cpp file, which fails due to the bug.

Bug 2: In the constructor
  Constructor checks for the validity of wide, high, and x variables and if they are less than or equal to zero, it assigns the default values.
  But it does not check the case when wide, high, and x all three are valid, i.e. greater than zero, but the value of x is greater than wide and high variables.
  We need to check this case because, x is assigned to the toWin variable and lets consider for example, width = 4, height = 4, and toWin = 5.
  This will create a board of size 4 x 4, i.e. having 4 rows and 4 columns. But to win the game, the player will need to make a combination of 5 which is not possible on a 4 x 4 board. So, technically this is not a valid game as no player can ever win the game. But the provided code does not check for this condition.
  
