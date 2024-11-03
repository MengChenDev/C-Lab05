#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../header/add_1-4.h"

void generateAdditionQuestion(int *num1, int *num2)
{
  srand((unsigned)time(NULL));
  *num1 = rand() % 100;
  *num2 = rand() % 100;
}

int checkAnswer(int answer, int num1, int num2)
{
  return answer == num1 + num2;
}

void Add()
{
  int num1, num2, studentAnswer;
  int correct = 0;

  system("cls");
  // 生成一道加法运算题
  generateAdditionQuestion(&num1, &num2);

  while (!correct)
  {
    printf("请计算 %d + %d 的结果：", num1, num2);
    // 获取学生的答案并进行判断
    scanf("%d", &studentAnswer);
    if (checkAnswer(studentAnswer, num1, num2))
    {
      printf("Right!\n");
      correct = 1;
    }
    else
    {
      printf("Not correct, try again.\n");
    }
  }

  printf("按下回车返回主菜单...");
  getchar();
  getchar();
  system("cls");
}