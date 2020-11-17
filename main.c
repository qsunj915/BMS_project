#include <stdio.h>
#include "library.h"

struct Book books[100]={
	"111", "111" ,11.0, "111","111",
	"222", "222" ,11.0, "222","222",
	"333", "333" ,11.0, "333","333",
	"444", "444" ,11.0, "444","444"
};

int tot_books = 4;

int main(void)
{
	int sel;

	menu_main();
	printf("请输入您要进行的操作： ");
	scanf("%d", &sel);
	eatline();				//解决输入无效问题

	while(sel != 0)
	{
		switch(sel)
		{
			case 1: message_manage_menu();//调试记录2020/10/11
				break;
			case 2: sum_menu();//调试记录2020/10/22
				break;
			case 3: Sale_History(SHOW, 0);
				break;
			default:
				printf("错误！");
		}
		menu_main();
		printf("请输入您要进行的操作： ");
		scanf("%d", &sel);//2020/10/21改进==可回到首页
		//出现BUG：错误输入字母会触发死循环==用清除输入函数解决2020/10/22
		eatline();
	}//关于0的输入问题待解决2020/10/21
	return 0;
}