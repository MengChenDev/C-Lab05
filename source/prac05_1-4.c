// main.c

#include <stdio.h>
#include <stdlib.h>
#include "triangle.c"
#include "add-4.c"

void display_menu()
{
  printf("请选择一个选项执行:\n");
  printf("1. 判断三角形\n");
  printf("2. 给小学生出加法题\n");
  printf("3. 掷骰子游戏\n");
  printf("0. 退出程序\n");
  printf("请输入您的选择（0-3）：");
}

int main()
{
  int choice;

  do
  {
    display_menu();
    scanf(" %d", &choice);
    switch (choice)
    {
    case 1:
      // 判断三角形
      JudgeTriangle();
      break;
    case 2:
      // 出加法题
      Add();
      break;
    case 3:
      // 掷骰子游戏
      // ...（调用相关函数）
      break;
    case 0:
      printf("感谢使用，再见！\n");
      break;
    default:
      system("cls");
      printf("无效的选项，请重新选择。\n");
      getchar();
    }
  } while (choice != 0);

  return 0;
}
