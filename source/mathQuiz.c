#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../header/add-5.h"

// 生成随机数和运算类型
void generateMathQuestion(int *num1, int *num2, OperationType *opType)
{
  *num1 = rand() % 10 + 1;               // 生成1到10之间的随机数
  *num2 = rand() % 10 + 1;               // 生成1到10之间的随机数
  *opType = (OperationType)(rand() % 4); // 随机选择运算类型
}

// 根据运算类型计算结果
double calculateResult(int num1, int num2, OperationType opType)
{
  switch (opType)
  {
  case ADD:
    return num1 + num2;
  case SUBTRACT:
    return num1 - num2;
  case MULTIPLY:
    return num1 * num2;
  case DIVIDE:
    // 进行浮点数除法并返回结果
    return (double)num1 / num2;
  }
  return 0; // 默认返回0
}

void MathQuiz()
{
  int num1, num2, studentAnswer;
  double correctAnswer;
  int score = 0;
  int wrongAnswers = 0;
  const int totalQuestions = 10;
  const int pointsPerQuestion = 10;
  OperationType opType;

  system("cls");

  srand((unsigned)time(NULL)); // 初始化随机数生成器

  for (int i = 0; i < totalQuestions; ++i)
  {
    // 生成一道数学运算题
    generateMathQuestion(&num1, &num2, &opType);
    correctAnswer = calculateResult(num1, num2, opType);

    // 根据运算类型显示题目
    char opChar;
    switch (opType)
    {
    case ADD:
      opChar = '+';
      break;
    case SUBTRACT:
      opChar = '-';
      break;
    case MULTIPLY:
      opChar = '*';
      break;
    case DIVIDE:
      opChar = '/';
      break;
    }
    printf("请计算第 %d 题: %d %c %d 的结果：", i + 1, num1, opChar, num2);

    // 获取学生的答案并进行判断
    scanf("%d", &studentAnswer);
    if (opType == DIVIDE)
    {
      // 如果是除法，需要将学生答案转换为浮点数比较
      if (abs(studentAnswer - correctAnswer) < 0.01)
      {
        printf("Right!\n");
        score += pointsPerQuestion; // 每题正确加10分
      }
      else
      {
        printf("Not correct! The correct answer was %.2f\n", correctAnswer);
        wrongAnswers++; // 记录错误题数
      }
    }
    else
    {
      if (studentAnswer == correctAnswer)
      {
        printf("Right!\n");
        score += pointsPerQuestion; // 每题正确加10分
      }
      else
      {
        printf("Not correct! The correct answer was %.2f\n", correctAnswer);
        wrongAnswers++; // 记录错误题数
      }
    }
  }

  // 输出总分和做错的题数
  printf("总分为：%d\n", score);
  printf("做错的题数：%d\n", wrongAnswers);

  printf("按下回车返回主菜单...");
  getchar(); // 清除缓冲区中的换行符
  getchar(); // 等待用户输入
  system("cls");
}
