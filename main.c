#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#define H 5
#define L 8
struct admin
{
 char name[10]; //姓名
 char password[10]; // 密码
 char ID[10] ; //工号
};
typedef struct admin adm;
struct student
{
 char name[10]; //姓名
 char password[10]; // 密码
 char ID[10] ; //学号
int time;
int a[8][8];
int h;
int judge;
};typedef struct student stu;
void menu(stu*st,adm*ad);
void fx1(stu*st,adm*ad);//进入菜单系统
void fx2(stu*st,adm*ad);//学生注册账号操作
void fx3(stu*st,adm*ad);//进入学生操作的登录系统
void fx4(stu*st,adm*ad);//管理员注册账号操作
void fx5(stu*st,adm*ad);//进入管理员操作的登录系统
void fx6(stu*st,adm*ad);//查询实验室预约情况
void fx7(stu*st,adm*ad);//学生操作中的预约时间
void fx8(stu*st,adm*ad);//学生操作中的取消预约
void fx9(stu*st,adm*ad);//学生操作中的报告电脑故障
void fx10(stu*st,adm*ad);//管理员操作中的维护电脑状态
void fx11(stu*st,adm*ad);//管理员操作中的查询实验室使用情况
void fx12(stu*st,adm*ad);//管理员操作中的查询学生信息
void fx13(stu*st,adm*ad);//管理员操作中的统计一天使用情况
void Sleep(int millisecond)
{
	clock_t begin = clock();//获取当前的CPU时钟的时间
	while(clock() - begin < millisecond);//如果时间差没达到休息时间要求就一直循环
}

void fx6(stu*st,adm*ad)//查询实验室预约情况
{
		system("cls");
printf("实验室可以预约的时间为8：00-17:00\n");
  printf("\n\t\t* ------ 可以预约的时间段为 --------*");
	printf("\n\t\t* ------ 1.8:00-9:00  2.9:00-10:00  3.10:00-11:00--------*");
	printf("\n\t\t* ------ 4.11:00-12:00  5.12:00-13:00  6.13:00-14:00--------*");
	printf("\n\t\t* ------ 7.14:00-15:00  8.15:00-16:00  9.16:00-17:00--------*");
	printf("\n\n");
 int c[H][L]={0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,};//实验室座位表（设刚开始全空）
//自定义一个休眠函数

	int i=0,j,count=0;
	int x,y;
	int choie;
		srand((unsigned)time(0));
	printf("\t\t实验室可以使用的座位情况表：\n");
	for(i=0;i<H;i++)
    for(j=0;j<L;j++)
	{
		if(c[i][j])
			printf(" # ");//有人就显示#
		else 
			printf(" * ");//无人就显示*
		count++;
		if(count%8==0)
		printf("\n");
	}
	count=0;
	printf("返回上级菜单请输入1，退出系统请输入0\n");
	printf("请进行您的选择：");
		int a;
	scanf("%d",&a);
	switch(a)
	{
	case 1:system("cls");
		fx3(st,ad);
		break;
	case 2:exit(0);
	default:
		do{printf("请输入正确的指令！");
			printf("返回上级菜单请输入1，退出系统请输入0\n");
	        printf("请进行您的选择：");
			scanf("%d",&a);
		}while(!((a==1)||(a==0)));
		switch(a)
	{
	case 1:system("cls");
		fx3(st,ad);
		break;
	case 2:exit(0);}
	}
}
void fx7(stu*st,adm*ad)
{
	system("cls");
	FILE *fp;
	fp=fopen("book.txt","w");
	int a;
    printf("\n\n");
    printf("\n\t\t\t\t 实验室预约系统\n");
    printf("\n\t\t*****************************************************");
    printf("\n\t\t* ------ 可以预约的时间段为 --------*");
	printf("\n\t\t* ------ 1.8:00-9:00  2.9:00-10:00  3.10:00-11:00--------*");
	printf("\n\t\t* ------ 4.11:00-12:00  5.12:00-13:00  6.13:00-14:00--------*");
	printf("\n\t\t* ------ 7.14:00-15:00  8.15:00-16:00  9.16:00-17:00--------*");
    printf("\n\t\t*****************************************************");
    printf("\n\n");
	printf("请选择您想要预约的时间段：");
	scanf("%d",&a);
	if((a<1)||(a>9))
	{
		
		do
		{   printf("您预约的时间有误！请重新预约!\n");
		    Sleep(3000);
			system("cls");
			printf("\n\n");
    printf("\n\t\t\t\t 实验室预约系统\n");




    printf("\n\t\t*****************************************************");
    printf("\n\t\t* ------ 可以预约的时间段为 --------*");
	printf("\n\t\t* ------ 1.8:00-9:00  2.9:00-10:00  3.10:00-11:00--------*");
	printf("\n\t\t* ------ 4.11:00-12:00  5.12:00-13:00  6.13:00-14:00--------*");
	printf("\n\t\t* ------ 7.14:00-15:00  8.15:00-16:00  9.16:00-17:00--------*");
    printf("\n\t\t*****************************************************");
    printf("\n\n");
	printf("请选择您想要预约的时间段：");
	scanf("%d",&a);
		}while(!((a>=1)&&(a<=9)));
	}
	int c[H][L]={0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,};//实验室座位表（设刚开始全空）
//自定义一个休眠函数

	int i=0,j,count=0;
	int x,y;
	int choie;
		srand((unsigned)time(0));
	printf("\t\t实验室实时座位使用情况表：\n");
	for(i=0;i<H;i++)
    for(j=0;j<L;j++)
	{
		if(c[i][j])
			printf(" # ");//有人就显示#
		else 
			printf(" * ");//无人就显示*
		count++;
		if(count%8==0)
		printf("\n");
	}
	count=0;
	
printf("\n请选择你要的位置（x，y）：");//选择要预定的座位
scanf("%d,%d",&x,&y);
	
printf("///执行中");
for(i = 0; i < 6; ++i)
		{
			Sleep(500);
			printf(".");
		}
 
system("cls");
c[x-1][y-1]=1;
	printf("\t\t实验室实时座位使用情况表：\n");
for(i=0;i<H;i++)
for(j=0;j<L;j++)
{
		if(c[i][j])
			printf(" # ");
 
else
	printf(" * ");
		count++;
		if(count%8==0)
		printf("\n");
}	
printf("预约成功！\n你的位置坐标为（%d，%d）\n",x,y);
switch(a)
{
case 1:printf("您预约的时间段为8:00-9:00 ");
	break;
case 2:printf("您预约的时间段为9:00-10:00 ");
	break;
case 3:printf("您预约的时间段为10:00-11:00 ");
	break;
case 4:printf("您预约的时间段为11:00-12:00 ");
	break;
case 5:printf("您预约的时间段为12:00-13:00 ");
	break;
case 6:printf("您预约的时间段为13:00-14:00 ");
	break;
case 7:printf("您预约的时间段为14:00-15:00 ");
	break;
case 8:printf("您预约的时间段为15:00-16:00 ");
	break;
case 9:printf("您预约的时间段为16:00-17:00 ");
}
st[0].h=a;
st[0].a[0][0]=x;
st[0].a[0][1]=y;
st[0].judge=0;
fprintf(fp,"%d (%d,%d)",a,x,y);
printf("\n\n");
printf("返回上级菜单请输入1，退出系统请输入0\n");
	printf("请进行您的选择：");
		int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:system("cls");
		fx3(st,ad);
		break;
	case 2:exit(0);
	default:
		do{printf("请输入正确的指令！");
			printf("返回上级菜单请输入1，退出系统请输入0\n");
	        printf("请进行您的选择：");
			scanf("%d",&z);
		}while(!((z==1)||(z==0)));
		switch(z)
	{
	case 1:system("cls");
		fx3(st,ad);
		break;
	case 2:exit(0);}
	}


}
void fx8(stu*st,adm*ad)//学生操作中的取消预约
{
	system("cls");
	int a,x,y;
	a=st[0].h;
	x=st[0].a[0][0];
    y=st[0].a[0][1];
   switch(a)
{
case 1:printf("您预约的时间段为8:00-9:00 ");
	break;
case 2:printf("您预约的时间段为9:00-10:00 ");
	break;
case 3:printf("您预约的时间段为10:00-11:00 ");
	break;
case 4:printf("您预约的时间段为11:00-12:00 ");
	break;
case 5:printf("您预约的时间段为12:00-13:00 ");
	break;
case 6:printf("您预约的时间段为13:00-14:00 ");
	break;
case 7:printf("您预约的时间段为14:00-15:00 ");
	break;
case 8:printf("您预约的时间段为15:00-16:00 ");
	break;
case 9:printf("您预约的时间段为16:00-17:00 ");
}
   printf("您预约的座位为%d行%d列的位置：",x,y);
   printf("\n");
   printf("您确定要取消预约吗？\n");
   printf("输入1确定 输入2返回上一级菜单\n");
   printf("请进行您的选择：");
   int b;
   scanf("%d",&b);
switch(b)
{
case 1:
 printf("///执行中");
 int i;
for(i = 0; i < 6; ++i)
		{
			Sleep(500);
			printf(".");
		}
printf("\n\n");
  printf("取消预约成功！");
  printf("\n\n");
printf("返回上级菜单请输入1，退出系统请输入0\n");
	printf("请进行您的选择：");
		int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:system("cls");
		fx3(st,ad);
		break;
	case 2:exit(0);
	default:
		do{printf("请输入正确的指令！");
			printf("返回上级菜单请输入1，退出系统请输入0\n");
	        printf("请进行您的选择：");
			scanf("%d",&z);
		}while(!((z==1)||(z==0)));
		switch(z)
	{
	case 1:system("cls");
		fx3(st,ad);
		break;
	case 2:exit(0);}
	}
  break;
case 2:system("cls");
	fx3(st,ad);
}


}
void fx9(stu*st,adm*ad)//学生操作中的报告电脑故障
{
	system("cls");
	int a,x,y;
	a=st[0].h;
	x=st[0].a[0][0];
    y=st[0].a[0][1];
	int c[H][L]={0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,};//实验室座位表（设刚开始全空）
//自定义一个休眠函数

	int i=0,j,count=0;
	int choie;
		srand((unsigned)time(0));
	printf("\t\t实验室实时座位使用情况表：\n");
	for(i=0;i<H;i++)
    for(j=0;j<L;j++)
	{
		if(c[i][j])
			printf(" # ");//有人就显示#
		else 
			printf(" * ");//无人就显示*
		count++;
		if(count%8==0)
		printf("\n");
	}
	count=0;
	printf("\n\n");
    printf("您预约的座位为%d行%d列的位置：",x,y);
    printf("\n");
	printf("您确定要上报机器发生故障吗?");
	printf("\n\n");
	printf("输入1确定 输入2返回上一级菜单\n");
   printf("请进行您的选择：");
   int b;
   scanf("%d",&b);
switch(b)
{
case 1:
 printf("///执行中");
 int i;
for(i = 0; i < 6; ++i)
		{
			Sleep(500);
			printf(".");
		}
printf("\n\n");
  printf("上报机器故障成功！");
  printf("\n\n");
printf("返回上级菜单请输入1，退出系统请输入0\n");
	printf("请进行您的选择：");
		int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:system("cls");
		fx3(st,ad);
		break;
	case 2:exit(0);
	default:
		do{printf("请输入正确的指令！");
			printf("返回上级菜单请输入1，退出系统请输入0\n");
	        printf("请进行您的选择：");
			scanf("%d",&z);
		}while(!((z==1)||(z==0)));
		switch(z)
	{
	case 1:system("cls");
		fx3(st,ad);
		break;
	case 2:exit(0);}
	}
  break;
case 2:system("cls");
	fx3(st,ad);
}
	
st[0].judge=1;
}
void fx10(stu*st,adm*ad)//管理员操作中的维护电脑状态
{
	system("cls");
	int a,x,y,b;
	a=st[0].h;
	x=st[0].a[0][0];
    y=st[0].a[0][1];
	b=st[0].judge;
	if(b==1)
	{
 int c[H][L]={0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,
             0,0,0,0,0,0,0,0,};//实验室座位表（设刚开始全空）
//自定义一个休眠函数

	int i=0,j,count=0;
	int choie;
		srand((unsigned)time(0));
	printf("\t\t实验室实时座位使用情况表：\n");
	for(i=0;i<H;i++)
    for(j=0;j<L;j++)
	{
		if(c[i][j])
			printf(" # ");//有人就显示#
		else 
			printf(" * ");//无人就显示*
		count++;
		if(count%8==0)
		printf("\n");
	}
	count=0;
	
printf("您要上报故障的位置为（%d，%d）：",x,y);//选择要预定的座位
	
printf("///执行中");
for(i = 0; i < 6; ++i)
		{
			Sleep(500);
			printf(".");
		}
 
system("cls");
c[x-1][y-1]=1;
	printf("\t\t实验室实时座位使用情况表：\n");
for(i=0;i<H;i++)
for(j=0;j<L;j++)
{
		if(c[i][j])
			printf(" ! ");
 
else
	printf(" * ");
		count++;
		if(count%8==0)
		printf("\n");
}	
printf("\n");
printf("上报故障成功！");
 printf("\n\n");
printf("返回上级菜单请输入1，退出系统请输入0\n");
	printf("请进行您的选择：");
		int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);
	default:
		do{printf("请输入正确的指令！");
			printf("返回上级菜单请输入1，退出系统请输入0\n");
	        printf("请进行您的选择：");
			scanf("%d",&z);
		}while(!((z==1)||(z==0)));
		switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);}
	}
  
}

	else
	{
		printf("目前没有学生上报机器问题！");
		printf("\n\n");
	
printf("返回上级菜单请输入1，退出系统请输入0\n");
	printf("请进行您的选择：");
		int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);
	default:
		do{printf("请输入正确的指令！");
			printf("返回上级菜单请输入1，退出系统请输入0\n");
	        printf("请进行您的选择：");
			scanf("%d",&z);
		}while(!((z==1)||(z==0)));
		switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);}
	}
  
}

}
void fx11(stu*st,adm*ad)//管理员操作中的查询实验室使用情况
{
	int a,b,x,y;
	a=st[0].h;
	x=st[0].a[0][0];
    y=st[0].a[0][1];
	b=st[0].judge;
switch(b)
{
case 0:
	{
	  char s[100];
		switch(a)
{
case 1:strcpy(s,"预约的时间段为8:00-9:00 ");
	break;
case 2:strcpy(s,"预约的时间段为9:00-10:00 ");
	break;
case 3:strcpy(s,"预约的时间段为10:00-11:00 ");
	break;
case 4:strcpy(s,"预约的时间段为11:00-12:00 ");
	break;
case 5:strcpy(s,"预约的时间段为12:00-13:00 ");
	break;
case 6:strcpy(s,"预约的时间段为13:00-14:00 ");
	break;
case 7:strcpy(s,"预约的时间段为14:00-15:00 ");
	break;
case 8:strcpy(s,"预约的时间段为15:00-16:00 ");
	break;
case 9:strcpy(s,"预约的时间段为16:00-17:00 ");
}
		printf("学号为：%s\n",st[0].ID);
		printf("姓名为：%s的同学\n",st[0].name);
		printf("%s\n",s);
	    printf("预约的座位为%d行%d列的位置：",x,y);
		printf("\n\n");
	
printf("返回上级菜单请输入1，退出系统请输入0\n");
	printf("请进行您的选择：");
		int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);
	default:
		do{printf("请输入正确的指令！");
			printf("返回上级菜单请输入1，退出系统请输入0\n");
	        printf("请进行您的选择：");
			scanf("%d",&z);
		}while(!((z==1)||(z==0)));
		switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);}
	}break;
}
case 1:
	{char s[100];
		switch(a)
{
case 1:strcpy(s,"预约的时间段为8:00-9:00 ");
	break;
case 2:strcpy(s,"预约的时间段为9:00-10:00 ");
	break;
case 3:strcpy(s,"预约的时间段为10:00-11:00 ");
	break;
case 4:strcpy(s,"预约的时间段为11:00-12:00 ");
	break;
case 5:strcpy(s,"预约的时间段为12:00-13:00 ");
	break;
case 6:strcpy(s,"预约的时间段为13:00-14:00 ");
	break;
case 7:strcpy(s,"预约的时间段为14:00-15:00 ");
	break;
case 8:strcpy(s,"预约的时间段为15:00-16:00 ");
	break;
case 9:strcpy(s,"预约的时间段为16:00-17:00 ");
}
		printf("学号为：%s\n",st[0].ID);
		printf("姓名为：%s的同学\n",st[0].name);
		printf("%s\n",s);
	    printf("上报%d行%d列的位置机器出现故障：",x,y);
		printf("\n\n");
	
printf("返回上级菜单请输入1，退出系统请输入0\n");
	printf("请进行您的选择：");
		int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);
	default:
		do{printf("请输入正确的指令！");
			printf("返回上级菜单请输入1，退出系统请输入0\n");
	        printf("请进行您的选择：");
			scanf("%d",&z);
		}while(!((z==1)||(z==0)));
		switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);}
		
  }
	}break;
default:
	{
		printf("目前没有查询到学生的相关预约信息！\n\n");
		printf("返回上级菜单请输入1，退出系统请输入0\n");
	printf("请进行您的选择：");
		int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);
	default:
		do{printf("请输入正确的指令！");
			printf("返回上级菜单请输入1，退出系统请输入0\n");
	        printf("请进行您的选择：");
			scanf("%d",&z);
		}while(!((z==1)||(z==0)));
		switch(z)
	{
	case 1:system("cls");
		fx5(st,ad);
		break;
	case 2:exit(0);}
		
  }break;
	}
	}
}
void fx12(stu*st,adm*ad)//管理员操作中的查询学生信息
{
	 FILE *fp;
   int c;

   fp = fopen("student.txt","r");
   while(1)
   {
      c = fgetc(fp);
      if( feof(fp) )
      {
          break ;
      }
      printf("%c", c);
   }
   fclose(fp);
}
void fx13(stu*st,adm*ad)
{printf("10");}


void fx2(stu*st,adm*ad)//学生注册账号
{
	FILE *fp;
	char s[10]="hi";
	char m[10]="hi";
	char n[10]="hi";
	fp=fopen("student.txt","w");
	//打开"student"文件，并且在文件末尾写入数据 
	printf("请输入你的学号：");
	getchar();
	gets(s);
	printf("\n");
	strcpy(st[0].ID,s);
	printf("请输入你的姓名：");
	gets(m);
	printf("\n");
	strcpy(st[0].name,m);
    printf("请输入你的密码：");
	gets(n);
	printf("\n");
	strcpy(st[0].password,n);
	printf("\n");
	fprintf(fp,"%s %s %s",s,m,n);
	fclose(fp);
	printf("注册成功！");
	printf("\n\n");
	printf("如果选择登录账号请输入1，如果想要退出系统请输入0\n");
	printf("请进行你的选择：");
	int a=0;
	scanf("%d",&a);
	switch(a)
	{
	case 1:system("cls");
		printf("欢迎来到登录系统！\n");
		printf("请输入你的学号：");
	getchar();
	gets(s);
	printf("\n");
	
	printf("请输入你的姓名：");
	gets(m);
	printf("\n");

    printf("请输入你的密码：");
	gets(n);
	printf("\n");
		if((strcmp(st[0].ID,s)==0)&&(strcmp(st[0].name,m)==0)&&(strcmp(st[0].password,n)==0))
		{
			printf("登录成功！");
			system("cls");
			fx3(st,ad);
		}
		else
		{ 
			
			do{system("cls");
			printf("您输入的有误！请重新输入或者退出！\n");
			printf("输入1再次输入，输入0退出系统\n");
			printf("请进行你的选择：");
			int b;
			scanf("%d",&b);
			if(b==0)
			{
				exit(0);
			}
			if(b==1)
			{
				printf("欢迎来到登录系统！\n");
		printf("请输入你的学号：");
	getchar();
	gets(s);
	printf("\n");
	
	printf("请输入你的姓名：");
	gets(m);
	printf("\n");

    printf("请输入你的密码：");
	gets(n);
	printf("\n");
			}
			}while(!((strcmp(st[0].ID,s)==0)&&(strcmp(st[0].name,m)==0)&&(strcmp(st[0].password,n)==0)));

			printf("登录成功！");
			system("cls");
			fx3(st,ad);
		}
	case 0:
		exit(0);
	}
}

	
void fx4(stu*st,adm*ad)//管理员注册账号操作
{

    char s[10]="hi";
	char m[10]="hi";
	char n[10]="hi";
	printf("请输入你的工号：");
	getchar();
	gets(s);
	printf("\n");
	strcpy(ad[0].ID,s);
	printf("请输入你的姓名：");
	gets(m);
	printf("\n");
	strcpy(ad[0].name,m);
    printf("请输入你的密码：");
	gets(n);
	printf("\n");
	strcpy(ad[0].password,n);
	printf("\n");
	printf("注册成功！");
	printf("\n\n");
	printf("如果选择登录账号请输入1，如果想要退出系统请输入0\n");
	printf("请进行你的选择：");
	int a=0;
	scanf("%d",&a);
	switch(a)
	{
	case 1:system("cls");
		printf("欢迎来到登录系统！\n");
		printf("请输入你的学号：");
	getchar();
	gets(s);
	printf("\n");
	
	printf("请输入你的姓名：");
	gets(m);
	printf("\n");

    printf("请输入你的密码：");
	gets(n);
	printf("\n");
		if((strcmp(ad[0].ID,s)==0)&&(strcmp(ad[0].name,m)==0)&&(strcmp(ad[0].password,n)==0))
		{
			printf("登录成功！");
			system("cls");
			fx5(st,ad);
		}
		else
		{ 
			
			do{system("cls");
			printf("您输入的有误！请重新输入或者退出！\n");
			printf("输入1再次输入，输入0退出系统\n");
			printf("请进行你的选择：");
			int b;
			scanf("%d",&b);
			if(b==0)
			{
				exit(0);
			}
			if(b==1)
			{
				printf("欢迎来到登录系统！\n");
		printf("请输入你的工号：");
	getchar();
	gets(s);
	printf("\n");
	
	printf("请输入你的姓名：");
	gets(m);
	printf("\n");

    printf("请输入你的密码：");
	gets(n);
	printf("\n");
			}
			}while(!((strcmp(ad[0].ID,s)==0)&&(strcmp(ad[0].name,m)==0)&&(strcmp(ad[0].password,n)==0)));

			printf("登录成功！");
			system("cls");
			fx5(st,ad);
		}
	case 0:
		exit(0);
	};
}
void fx3(stu*st,adm*ad)
{
	printf("您好！\n请选择您的功能\n1.查询实验室预约情况\n2.预约时间\n3.取消预约\n4.报告电脑故障\n5.返回\n\n");
	int a=0;
	printf("您的选择是(请输入对应功能前的数字编号）：");
	scanf("%d",&a);
	if(a==1)
	{
	  fx6(st,ad);
	}
	if(a==2)
	{
		fx7(st,ad);
	}
	if(a==3)
	{
		fx8(st,ad);
	}
	if(a==4)
	{
		fx9(st,ad);
	}
	if(a==5)
	{
         system("cls");
         menu(st,ad);
	}

}
void fx5(stu*st,adm*ad)
{  
	printf("您好！\n请选择您的功能\n1.维护电脑状态\n2.查询实验室使用情况\n3.查询学生信息\n4.统计一天实验室使用情况\n5.返回\n\n");
	int a=0;
	printf("您的选择是(请输入对应功能前的数字编号）：");
	scanf("%d",&a);
	if(a==1)
	{
		fx10(st,ad);
	}
	if(a==2)
	{
		fx11(st,ad);
	}
	if(a==3)
	{
		fx12(st,ad);
	}
	if(a==4)
	{
		fx13(st,ad);
	}
	if(a==5){

         system("cls");
        menu(st,ad);
	}
}

void fx1(stu*st,adm*ad)
{
	int a=0;
	int b=0;
	printf("请进入角色选择\n");
	printf("1.学生   2.管理员\n");
	printf("请选择您要进行的操作(输入1进入学生操作 输入2进入管理员操作）:");
	getchar();
	scanf("%d",&a);
	if(a==1)
	{   
		printf("1.注册账号\n2.退出系统\n");
		printf("输入1注册账号  输入2退出系统\n请选择您要进行的操作:");
		scanf("%d",&b);
		if(b==1)
		{
			fx2(st,ad);
		}
	
	
		if(b==2)
		{
			exit(0);
		}
	}
	if(a==2)
	{
		printf("1.注册账号\n2.退出系统\n");
		printf("输入1注册账号  输入2退出系统\n请选择您要进行的操作:");
		scanf("%d",&b);

		if(b==1)
		{
			fx4(st,ad);
		}
		if(b==2)
		{
			exit(0);
		}
	}

}
void menu(stu*st,adm*ad)
{
char ch[10];
	int a=0;
	printf("                                  欢迎来到智能实验室预约系统        ");
	printf("\n");
	printf(" 输入1查看菜单                          输入0退出系统");
	printf("\n");
	printf("进行你的选择：");
	scanf("%d",&a);
	if((a!=0)&&(a!=1))
	{
		do
			{
				printf("输入错误 请输入正确的指示!\n");
				printf("进行你的选择：");
				scanf("%d",&a);
			}while(!((a==1)||(a==0)));
	}
	if(a==1)
	{ 
	fx1(st,ad);
	}
	if(a==0)
	{
		printf("输入任意键退出");
		getchar();
		exit(0);
	}
	
	exit(0);
}


int main()
{
	stu st[40];
	adm ad[10];
    menu(st,ad);
}
