// dice.h
#ifndef DICE_H
#define DICE_H

#include <stdbool.h>

typedef enum
{
  CONTINUE,
  WON,
  LOST
} GameStatus;

void Dice();

#endif // DICE_H