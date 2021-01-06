/*


黑白子交换。有三个白子和三个黑子如下图布置：(-表示一个空格)
○	○	○	-	●	●	●
游戏的目的是用多少的步数将上图中白子和黑子的位置进行交换：
●	●	●	-	○	○	○
游戏的规则是：一次只能移动一个棋子；棋子可以向空格中移动，
也可以跳过一个对方的格子进入空格，但不能向后跳，也不能跳过两个子。
请用计算机实现上述游戏。


*/
#include <stdio.h>
int count = 0;
void print(int *a);                                 //输出黑白子的函数/
void change(int *m, int *n);               //交换黑白子的函数/
int main()
{
    int i, flag;
    int a[7] = {1, 1, 1, 0, 2, 2, 2};
    print(a);


    while(a[0] + a[1] + a[2] != 6 || a[4] +a[5] + a[6] != 3)
    {
        flag = 1;
        for(i = 0; i < 5 && flag; i++)                                                       //将白子向右跳过一个黑子进入空格中/
        {
            if(a[i] == 1 && a[i + 1] == 2 && a[i + 2] == 0)
            {
                change(&a[i], &a[i + 2]);
                print(a);
                flag = 0;
            }
        }
		
        for(i = 0; i < 5 && flag; i++)                                                  //将黑子向左跳过一个白子进入空格中/
        {
            if(a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 2)
            {
                change(&a[i], &a[i + 2]);
                print(a);
                flag = 0;
            }
        }
        for(i = 0; i < 6 && flag; i++)                                                                   //将白子向右移入空格并不产生阻塞现象/
         {
            if(a[i] == 1 && a[i + 1] == 0 && (i == 0 || a[i - 1] != a[i + 2]))
            {
                change(&a[i], &a[i + 1]);
                print(a);
                flag = 0;
            }
        }
        for(i = 0; i < 6 && flag; i++)                                                            //将黑子向左移入空格中并不产生阻塞现象/
        {
            if(a[i] == 0 && a[i + 1] == 2 && (i == 5 || a[i - 1] != a[i + 2]))
            {
                change(&a[i], &a[i + 1]);
                print(a);
                flag = 0;
            }
        }
    }
}
void print(int *a)
{
    int i;
    printf("No.  %2d: ---------------------------\n", count++);
    printf("       ");
    for(i = 0; i <= 6; i++)
    {
        printf("| %c", a[i] == 1?'*':(a[i] == 2?'@':' '));
    }
    printf("        |\n---------------------------\n");
}
void change(int *m, int *n)
{
    int temp;
    temp = *m;
    *m = *n;
    *n = temp;
}
