#include <stdio.h>
#include "library.h"

extern struct Book books[100];

void sum_check(void)
{
	double price = 0;
	int num = 0;
	printf("图书单价： %lf\n", price);
	printf("购买的数量： %d\n", num);
	printf("本次购买的图书的金额为： %lf\n", price*num);
}


void sale_history(int sq)//简易版
{
	int n=1;

	printf("购买时间： 2020/10/22");//打印时间很麻烦暂时不写
	printf("\n%s\n", line);

	//printf("%d\n", sq);测试通过，已找到错误2020/10/22
	printf("编号    书名    价格    作者   出版社    数量\n");
	printf("%s  %s   %.2lf   %s   %s   %d\n",
		books[sq].ISBN, books[sq].Name, books[sq].Price, books[sq].Author, books[sq].Publish, n);//关于数量以后再改 === 2020/10/22找到错误--%s导致程序终止
	printf("%s\n", line);

	printf("总价格：%lf", books[sq].Price*n);
	printf("\n\n");

}