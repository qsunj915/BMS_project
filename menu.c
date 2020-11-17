#include <stdio.h>
#include "library.h"

void sign(char c)
{
	int index=0;
	while(index++ < 24)
		 printf("%c", c);
	 printf("\n");
}

void menu_main(void)
{
 sign('S');
 printf("\n");
 printf("图书管理系统\n");
 printf("1.图书基本信息管理\n");
 printf("2.购书结算处理\n");
 printf("3.销售历史记录\n");
 printf("0.退出系统\n\n");
 sign('E');
}

void message_manage_menu(void)
{
	int sel;

	printf("图书基本信息管理\n");
	printf("1.增加图书\n");//2020/10/21初步完成
	printf("2.删除图书\n");//2020/10/21初步完成
	printf("3.修改图书\n");
	printf("4.查找图书\n");
	printf("5.书库总表\n");//2020/10/21初步完成
	printf("6.返回首页\n");//2020/10/21初步完成
	printf("\n");
	printf("请输入您要进行的操作： ");

	scanf("%d", &sel);
	switch(sel)
	{
		case 1: ;Morebook();//调试记录2020/10/11
			break;
		case 2: ;Deletebook();
			break;
		case 3: ;Changebook();
			break;
		case 4: ;Booklook();
			break;
		case 5: ;Booklist();
			break;
		default:
			break;
	}
}

void sum_menu(void)
{
	int sel;

	printf("购书结算处理\n\n");
	printf("1.会员登陆\n");//初步完成2020/10/22
	printf("2.非会员进入\n");//初步完成2020/10/22
	printf("0.返回\n\n");
	printf("请输入您要进行的操作： ");

	scanf("%d", &sel);
	switch(sel)
	{
	case 1: vip_sign_in();
		break;
	case 2: nvip_sum_menu();
		break;
	default:
		;
	}
}


void eatline(void)
{
	while(getchar() != '\n')
		continue;
}


void Sale_History(int mode, int sq)//被调用一次而不做事，记录卖书+1，显示记录，不增加卖书数  参数：mode模式，sq书籍数组位置
{
	static int n_saled=0;
	static int mem_gp[100];

	if(mode == SHOW)
	{
		int index, te;

		if(n_saled != 0)
		{
			printf("售书历史记录\n\n");

			//测试printf("%d", n_saled);  测试通过，但是无法打印历史记录
			//循环系统显示卖书记录
			for(index = 0; index<n_saled; index++)
			{
				//printf("进入循环体\n");		测试通过，已进入循环体但只进入一次
				te = mem_gp[index];
				//printf("%d", te);				测试通过，te值正确
				sale_history(te);//1.以后再添加显示时间，2.缺失买书数量2020/10/22
			}
		}
		else
			printf("\n暂无购书记录");
		printf("感谢您使用本软件，再见！\n\n");
	}
	else
	{
		mem_gp[n_saled] = sq;
		n_saled++;
	}
}

