#include <stdio.h>
#include "library.h"

extern struct Book books[100];

void vip_verity(void)
{
	char sel;

	printf("请问你是会员吗？(Y/N)");
	scanf("%c", &sel);
	if(sel == 'Y')
		printf("欢迎会员回来！");
	else
		printf("欢迎顾客光临！");
}


void vip_message(void)
{
 int id, age;
 char sex;
 char name[20];
 scanf("%s", name);
 printf("请输入会员%s的基本信息:\n", name);
 printf("输入会员编号： ");
 scanf("%d", &id);
 printf("输入会员性别（F：女   M：男）： "); 
 scanf("%c", &sex);
 printf("输入会员年龄： ");
 scanf("%d", &age);
 printf("\n会员%s的基本信息如下：\n");
 printf("ID      Sex     Age");
 printf("%-8d%c       %d\n", id, sex, age);
}

void vip_rand_check(void)
{
	int scores;

	printf("请输入该会员的积分： ");
	scanf("%d", &scores);

	if(scores<1000)
		printf("普通会员！");
	else if(scores<5000)
		printf("银卡会员！");
	else if(scores<10000)
		printf("金卡会员！");
	else
		printf("贵宾会员！");
}


void vip_sign_in(void)
{
	long num;

	printf("会员登陆\n\n");
	printf("请输入您的会员号： ");

	scanf("%d", &num);

	vip_sum_menu();
}

char vip_sum_menu(void)//2020/10/21 会员结账系统，初步编码未完成
{
	int n, gp;
	const double cut=0.5;
	char sel='Y';

	while(sel == 'Y')
	{
		printf("会员结账\n\n");

		gp = Grasp_book(SEL_IBSN);//抓取图书的函数，暂时没码 === 2020/10/22初步完成
		
		if(gp == 100)//如果gp非法，则跳过下一步
			goto miss;

		printf("请输入购买数量： ");
		scanf("%d", &n);
		eatline();

		printf("编号    书名    价格    作者");
		printf("    出版社    数量\n");
		printf("%-8s%-8s%-8.2lf%-8s%-8s%d\n",
			books[gp].ISBN, books[gp].Name, books[gp].Price, books[gp].Author, books[gp].Publish, n);//未完成
	
		printf("%s\n", line);
		printf("结账信息   总价格：%6.2lf会员价：%6.1lf\n", n*books[gp].Price, n*books[gp].Price*cut);
		
		Sale_History(UNSHOW, gp);//记录销售历史记录的大函数（与sale_history不同），暂时未码2020/10/21 == 初步完成，读入书籍的数组位置
		
		miss://goto终点


		printf("是否继续选择图书？Y/N\n");
		scanf("%c", &sel);
		eatline();
	}

	return(sel);
}

char nvip_sum_menu(void)
{
	int n, gp;
	char sel='Y';
	while(sel == 'Y')
	{
		printf("非会员结账\n\n");
		gp = Grasp_book(SEL_IBSN);

		if(gp == 100)//如果gp非法，则跳过下一步
			goto miss;

		printf("请输入购买数量： ");
		scanf("%d", &n);
		eatline();

		printf("编号    书名    价格    作者");
		printf("    出版社    数量\n");
		printf("%-8s%-8s%-8.2lf%-8s%-8s%d\n",
			books[gp].ISBN, books[gp].Name, books[gp].Price, books[gp].Author, books[gp].Publish, n);//未完成
	
		printf("%s\n", line);
		printf("结账信息   总价格：%6.2lf\n", n*books[gp].Price);

		Sale_History(UNSHOW, gp);

		miss:

		printf("是否继续选择图书？Y/N\n");
		scanf("%c", &sel);
		eatline();
	}

	return(sel);
}