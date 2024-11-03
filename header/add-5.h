// add.h
#ifndef ADD_H
#define ADD_H

// 声明运算类型枚举
typedef enum
{
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE
} OperationType;

// 函数声明
void generateMathQuestion(int *num1, int *num2, OperationType *opType);
int calculateAnswer(int num1, int num2, OperationType opType);
void checkAnswer(int userAnswer, int correctAnswer, int *score, int *wrongAnswers);

#endif // ADD_H
