// dice.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../header/dice.h"

static int rollDice()
{
  return rand() % 6 + 1;
}

static bool checkWinningCondition(int sum, int myPoint)
{
  if ((sum == 7 || sum == 11) && myPoint == 0)
    return true;
  if ((sum == 2 || sum == 3 || sum == 12) && myPoint == 0)
    return false;
  if (myPoint != 0 && sum == myPoint)
    return true;
  return false;
}

void Dice()
{
  system("cls");
  srand((unsigned)time(NULL));

  int firstRoll = rollDice();
  int secondRoll = rollDice();
  int sum = firstRoll + secondRoll;
  int myPoint = 0;
  GameStatus gameStatus = CONTINUE;
  int rollsCount = 1;

  printf("First roll: %d\n", firstRoll);
  printf("Second roll: %d\n", secondRoll);

  if (!checkWinningCondition(sum, myPoint))
  {
    myPoint = sum;
    printf("Your point is set to: %d\n", myPoint);
  }
  else
  {
    gameStatus = checkWinningCondition(sum, myPoint) ? WON : LOST;
  }

  while (gameStatus == CONTINUE)
  {
    firstRoll = rollDice();
    secondRoll = rollDice();
    sum = firstRoll + secondRoll;
    rollsCount++;

    printf("Roll #%d: %d\n", rollsCount, sum);

    if (rollsCount > 7)
    {
      gameStatus = LOST;
      break;
    }

    if (checkWinningCondition(sum, myPoint))
    {
      gameStatus = WON;
    }
  }

  switch (gameStatus)
  {
  case WON:
    printf("Congratulations! You won the game!\n");
    break;
  case LOST:
    printf("Sorry, you lost the game.\n");
    break;
  default:
    printf("The game ended unexpectedly.\n");
    break;
  }

  printf("按下回车返回主菜单...");
  getchar(); // 清除缓冲区中的换行符
  getchar(); // 等待用户输入
  system("cls");
}