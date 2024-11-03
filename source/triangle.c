// triangle.c

#include "../header/triangle.h"
#include <stdio.h>
#include <stdlib.h>

void judgeTriangleType(int a, int b, int c)
{
  if (a + b > c && a + c > b && b + c > a)
  { // 判断是否能构成三角形
    if (a == b && b == c)
    { // 等边三角形
      printf("等边三角形\n");
    }
    else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
    { // 直角三角形
      if (a == b || b == c || a == c)
      { // 等腰直角三角形
        printf("等腰直角三角形\n");
      }
      else
      {
        printf("直角三角形\n");
      }
    }
    else if (a == b || b == c || a == c)
    { // 等腰三角形
      printf("等腰三角形\n");
    }
    else
    {
      printf("一般三角形\n"); // 一般三角形
    }
  }
  else
  {
    printf("不能构成三角形\n");
  }
}

int JudgeTriangle()
{
  int a, b, c;
  system("cls");
  printf("请输入三条边的长度（a b c）：");
  scanf(" %d %d %d", &a, &b, &c); // 输入三条边的长度
  judgeTriangleType(a, b, c);     // 调用函数判断三角形类型
  printf("按下回车返回主菜单\n");
  getchar();
  getchar();
  system("cls");
  return 0;
}
