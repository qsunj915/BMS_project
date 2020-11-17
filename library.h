#ifndef __LIBRARY_H
#define __LIBRARY_H

#include "stdio.h"
#define line "-----------------------------------------"

#define SEL_IBSN 1
#define SEL_NAME 2

#define SHOW 3
#define UNSHOW 2

struct Book
{
	char ISBN[14];
	char Name[20];
	double Price;
	char Author[20];
	char Publish[30];
};							//天坑：直接在头文件声明books会出现多重定义--不能在头文件中进行变量或函数的定义


void sign(char);
void menu_main(void);
void message_manage_menu(void);
void sum_check(void);
void vip_message(void);
void vip_verity(void);
void vip_rand_check(void);
void sum_menu(void);
void vip_sign_in(void);
char vip_sum_menu(void);
char nvip_sum_menu(void);

void Morebook(void);
void Deletebook(void);
void Changebook(void);
void Booklist(void);
void Booklook(void);
void Bookgrasp_change(int);

void sale_history(int );
void Sale_History(int, int);



//功能型函数
int Grasp_book(int sel);
void eatline(void);

#endif