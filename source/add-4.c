#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../header/add_1-4.h"

void generateAdditionQuestion(int *num1, int *num2)
{
  *num1 = rand() % 10 + 1; // 生成1到10之间的随机数
  *num2 = rand() % 10 + 1; // 生成1到10之间的随机数
}

int checkAnswer(int answer, int num1, int num2)
{
  return answer == num1 + num2;
}

void Add()
{
  int num1, num2, studentAnswer;
  int score = 0;
  int wrongAnswers = 0;
  const int totalQuestions = 10;
  const int pointsPerQuestion = 10;

  system("cls");

  srand((unsigned)time(NULL)); // 初始化随机数生成器

  for (int i = 0; i < totalQuestions; ++i)
  {
    // 生成一道加法运算题
    generateAdditionQuestion(&num1, &num2);
    printf("请计算第 %d 题: %d + %d 的结果：", i + 1, num1, num2);

    // 获取学生的答案并进行判断
    scanf("%d", &studentAnswer);
    if (checkAnswer(studentAnswer, num1, num2))
    {
      printf("Right!\n");
      score += pointsPerQuestion; // 每题正确加10分
    }
    else
    {
      printf("Not correct!\n");
      wrongAnswers++; // 记录错误题数
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