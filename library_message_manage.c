#include <stdio.h>
#include <string.h>
#include "library.h"

extern struct Book books[];
extern int tot_books;														//2020/10/21使用外部引用时总报错==用内部变量定义暂时解决 == 2020/10/22找到原因：在头文件中定义导致多重声明
//tot_books  记录书的总数
void Morebook(void)
{	
	char sel='Y';

	while(sel == 'Y')
	{
																							//缺一个读取books数量的函数== 2020/10/21用tot_books解决
		printf("增加图书\n\n");

		printf("请输入编号：\n");
		scanf("%s", books[tot_books].ISBN);

		printf("请输入书名：\n");
		scanf("%s", books[tot_books].Name);

		printf("请输入价格：\n");
		scanf("%lf", &books[tot_books].Price);

		printf("请输入作者：\n");
		scanf("%s", books[tot_books].Author);

		printf("请输入出版时间：\n");
		scanf("%s", books[tot_books].Publish);

		tot_books++;

		printf("是否继续增加？Y/N\n");
		//出现问题：scanf好像没执行==实质：scanf吃掉了回车  == 解决方案：清空缓冲区
		while(getchar() != '\n')
			continue;
		scanf("%c", &sel);
		//scanf("%c");
	}																					//出现新问题：输入N时报错！===目前不清楚原因  2020/10/11 === 2020/10/21问题消失（改进删除回车方式后）
}

void Deletebook(void)
{
	printf("增加图书\n\n");
	printf("1.按编号删除\n");
	printf("2.按书名删除\n");
	printf("0.取消操作\n\n");
	printf("请输入你要进行的操作：");
}

void Changebook(void)
{
	int sel;

	printf("修改图书\n\n");
	printf("1.编号修改\n");
	printf("2.书名修改\n");
	printf("0.取消操作\n\n");
	printf("请输入你要进行的操作：");
	scanf("%d", &sel);
	Bookgrasp_change(sel);
}

void Booklook(void)
{
	printf("查询图书\n\n");
	printf("1.编号查询\n");
	printf("2.书名查询\n");
	printf("0.取消操作\n\n");
	printf("请输入你要进行的操作：");

}


void Booklist(void)
{
	int index;

	if(tot_books != 0)
		for(index=0; index<tot_books; index++)
		{
			printf("编号：%s\n", books[index].ISBN);
			printf("书名：%s\n", books[index].Name);
			printf("价格：%lf\n", books[index].Price);
			printf("作者：%s\n", books[index].Author);
			printf("出版时间：%s\n", books[index].Publish);
			printf("%s\n", line);
		}
	else
		printf("系统还没有书！");
}

void Bookgrasp_change(int sel)
{
	int gp, index;
	char ISBN[14], NAME[20];
	char ys = 'y';
	//读取书籍位置
	if(sel == 1)
		{
			printf("输入图书编号： ");
			scanf("%s", &ISBN);
			for(index=0; index<tot_books; index++)
			{
				if(strcmp(books[index].ISBN, ISBN) == 0);
				gp = index;
				break;
			}
		}
	else if(sel == 2)
		{
			printf("输入图书书名： ");
			scanf("%s", &NAME);
			for(index=0; index<tot_books; index++)
			{
				if(strcmp(books[index].Name, NAME) == 0);
				gp = index;
				break;
			}
		}
	else if(sel == 0)
		;
	else
		printf("错误");


		printf("图书信息：\n");
		printf("编号：%s\n", books[gp].ISBN);
		printf("书名：%s\n", books[gp].Name);
		printf("价格：%lf\n", books[gp].Price);
		printf("作者：%s\n", books[gp].Author);
		printf("出版时间：%s\n", books[gp].Publish);
		
	while(ys = 'y')
		{
			sel = 0;
			printf("请输入你要修改的信息：\n");
			printf("1.编号\n");
			printf("2.书名\n");
			printf("3.价格\n");
			printf("4.作者\n");
			printf("5.出版时间\n");
			printf("0.退出\n");

			scanf("%d", sel);
			while(getchar() != '\n')
				continue;

			switch(sel)
			{
			case 1:
				printf("请输入修改后的编号：\n");
				scanf("%s", books[gp].ISBN);
				break;
			case 2:
				printf("请输入修改后的书名：\n");
				scanf("%s", books[gp].Name);
				break;
			case 3:
				printf("请输入修改后的价格：\n");
				scanf("%lf", &books[gp].Price);
				break;
			case 4:
				printf("请输入修改后的作者：\n");
				scanf("%s", books[gp].Author);
				break;
			case 5:
				printf("请输入修改后的出版时间：\n");
				scanf("%s", books[gp].Publish);
				break;
			default:
				break;//可有可无
			}
			printf("是否继续修改？\n");
			ys = getchar();
			while(getchar() != '\n')
				continue;
		}

}


int Grasp_book(int sel)
{
	int gp=101, index;
	char ISBN[14], NAME[20];
	//读取书籍位置
	if(sel == SEL_IBSN)
		{
			printf("输入图书编号： ");
			scanf("%s", &ISBN);

			for(index=0; index<tot_books; index++)
			{
				if(strcmp(books[index].ISBN, ISBN) == 0)
				{
					gp = index;
					break;
				}
			}

			//测试语句printf("%d\n", gp);			2020/10/22通过测试===函数完成
		}
	else if(sel == SEL_NAME)
		{
			printf("输入图书书名： ");
			scanf("%s", &NAME);
			for(index=0; index<tot_books; index++)
			{
				if(strcmp(books[index].Name, NAME) == 0)
				{
					gp = index;
					break;
				}
			}
		}
	else if(sel == 0)
		;
	else
		printf("错误");


	if(gp > tot_books)
		{
			printf("没有对应的书！\n");
			gp=100;
		}

	//printf("%d", gp);  测试完成，结果正确
	eatline();
	return(gp);//返回图书位置编号
}