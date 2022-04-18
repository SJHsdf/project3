#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<graphics.h>
#include<conio.h>
#include<iostream>
using namespace std;
int js=0;

struct me
{
	me *lch;
	me *rch;
	me *lpar;
	me *rpar;
	char chhu[30];
};
struct dl
{
	int front;
	int rare;
    me *xxx[100];
};




void creatdl(dl &x)
{
	
	x.front=x.rare=0;
}



void rdl(dl &x,me *xx)
{
	x.xxx[x.rare]=xx;
	x.rare++;
}


me* pop(dl &x)
{
	return x.xxx[x.front];
	x.front++;
}



void sx1(me *T)//字辈信息输出函数
{
	dl x;
	creatdl(x);//初始化队列
	printf("输出子辈信息：\n");
	if(T!=NULL)
	{
		rdl(x,T);//入队操作函数
		while(x.front!=x.rare)
		{
			me *xx;
			xx=pop(x);//出队操作函数
			printf("%s，",xx->chhu);
			js++;x.front++;
			if(js==1||js==3||js==7||js==15)
				printf("\n");
			
			if(xx->lch)
				rdl(x,xx->lch);
			if(xx->rch)
				rdl(x,xx->rch);
		}
	}
	js=0;

}


void sx2(me *T)//父辈信息输出函数
{
	dl x;
	creatdl(x);//初始化队列
	printf("\n");
	printf("输出父辈信息：\n");
	if(T!=NULL)
	{
		rdl(x,T);//入队操作函数
		while(x.front!=x.rare)
		{
			me *xx;
			xx=pop(x);//出队操作函数
			printf("%s，",xx->chhu);
			x.front++;
			js++;
			if(js==1||js==3||js==7||js==15)
				printf("\n");
			if(xx->lpar)
				rdl(x,xx->lpar);
			if(xx->rpar)
				rdl(x,xx->rpar);
		}
	}
	js=0;

}


void creat(me* &x)
{
	me *p[20];int i=0;
	while(i<18)
	{
		p[i]=new me;
		i++;
	}
	strcpy(p[0]->chhu,"儿子");
	strcpy(p[1]->chhu,"女儿");
	strcpy(p[2]->chhu,"孙子");
	strcpy(p[3]->chhu,"孙女");
	strcpy(p[4]->chhu,"外孙");
	strcpy(p[5]->chhu,"外孙女");
	strcpy(p[6]->chhu,"曾孙");
	strcpy(p[7]->chhu,"曾孙女");
	strcpy(p[8]->chhu,"外曾孙");
	strcpy(p[9]->chhu,"外曾孙女");
	strcpy(p[10]->chhu,"外曾孙");
	strcpy(p[11]->chhu,"外曾孙女");
	strcpy(p[12]->chhu,"外曾孙");
	strcpy(p[13]->chhu,"外曾孙女");
	strcpy(p[14]->chhu,"玄孙");
	strcpy(p[15]->chhu,"玄孙女");
	strcpy(p[16]->chhu,"外玄孙");
	strcpy(p[17]->chhu,"外玄孙女");
	x->lch=p[0];
	x->rch=p[1];i=0;
	while(i<8)
	{
		p[i]->lch=p[(i+1)*2];
		p[i]->rch=p[(i+1)*2+1];
		i++;
	}
	while(i<18)
	{
		p[i]->lch=NULL;
		p[i]->rch=NULL;
		i++;
	}
	p[0]->lpar=p[0]->rpar=x;
	p[1]->lpar=p[1]->rpar=x;
	p[16]->rpar=p[17]->rpar=p[7];p[16]->lpar=p[17]->lpar=NULL;
	p[14]->lpar=p[15]->lpar=p[6];p[14]->rpar=p[15]->rpar=NULL;
	p[12]->rpar=p[13]->rpar=p[5];p[12]->lpar=p[13]->lpar=NULL;
	p[10]->lpar=p[11]->lpar=p[4];p[10]->rpar=p[11]->rpar=NULL;
	p[8]->rpar=p[9]->rpar=p[3];p[8]->lpar=p[9]->lpar=NULL;
	p[6]->lpar=p[7]->lpar=p[2];p[6]->rpar=p[7]->rpar=NULL;
	p[4]->rpar=p[5]->rpar=p[1];p[4]->lpar=p[5]->lpar=NULL;
	p[2]->lpar=p[3]->lpar=p[0];p[2]->rpar=p[3]->rpar=NULL;
	i=0;
	while(i<18)
	{
		p[i]=new me;
		i++;
	}
	strcpy(p[0]->chhu,"父亲");
	strcpy(p[1]->chhu,"母亲");
	strcpy(p[2]->chhu,"爷爷");
	strcpy(p[3]->chhu,"奶奶");
	strcpy(p[4]->chhu,"外公");
	strcpy(p[5]->chhu,"外婆");
	strcpy(p[6]->chhu,"太公");
	strcpy(p[7]->chhu,"太婆");
	strcpy(p[8]->chhu,"太外公");
	strcpy(p[9]->chhu,"太外婆");
	strcpy(p[10]->chhu,"外太公");
	strcpy(p[11]->chhu,"外太婆");
	strcpy(p[12]->chhu,"外太外公");
	strcpy(p[13]->chhu,"外太外婆");
	strcpy(p[14]->chhu,"高祖父");
	strcpy(p[15]->chhu,"高祖母");
	strcpy(p[16]->chhu,"外高祖父");
	strcpy(p[17]->chhu,"外高祖母");
	x->lpar=p[0];x->rpar=p[1];i=0;
	strcpy(x->chhu,"我");
	while(i<8)
	{
		p[i]->lpar=p[(i+1)*2];
		p[i]->rpar=p[(i+1)*2+1];
		i++;
	}
	while(i<18)
	{
		p[i]->lpar=NULL;
		p[i]->rpar=NULL;
		i++;
	}
	p[0]->lch=p[0]->rch=x;
	p[1]->lch=p[1]->rch=x;
	p[2]->lch=p[3]->lch=p[0];p[2]->rch=p[3]->rch=NULL;
	p[4]->rch=p[5]->rch=p[1];p[4]->lch=p[5]->lch=NULL;
	p[6]->lch=p[7]->lch=p[2];p[6]->rch=p[7]->rch=NULL;
	p[8]->rch=p[9]->rch=p[3];p[8]->lch=p[9]->lch=NULL;
	p[10]->lch=p[11]->lch=p[4];p[10]->rch=p[11]->rch=NULL;
	p[12]->rch=p[13]->rch=p[5];p[12]->lch=p[13]->lch=NULL;
	p[14]->lch=p[15]->lch=p[6];p[14]->rch=p[15]->rch=NULL;
	p[7]->lpar=p[7]->rpar=NULL;free(p[16]);free(p[17]);
}

void fwcz(me *x)//关系计算函数
{
	printf("请选择对应关系：1.父  2.母  3.子  4.女  0.退出\n");
	me *yd1,*yd2;
	yd1=x;
	char pdf;
	while(1)
	{
		scanf("%c",&pdf);
		if(pdf=='1')//男性长辈的输入情况
		{
			yd2=yd1->lpar;
			if(yd2!=NULL)
			{
				yd1=yd2;
				printf("此人与你的对应关系是：%s\n继续进行输入或按0退出\n",yd1->chhu);
			}
			else//超出范围
			{
				printf("此程序只提供九代之内直系亲属的计算，您的查询超出范围，请重新输入或按0退出\n");
			}
		}



		if(pdf=='2')//女性长辈的输出
		{
			yd2=yd1->rpar;
			if(yd2!=NULL)
			{
				yd1=yd2;
				printf("此人与你的对应关系是：%s\n继续进行输入或按0退出\n",yd1->chhu);
			}
			else
			{
				printf("此程序只提供九代之内直系亲属的计算，您的查询超出范围，请重新输入或按0退出\n");
			}
		}



		if(pdf=='3')//男性字辈的输入
		{
			yd2=yd1->lch;
			if(yd2!=NULL)
			{
				yd1=yd2;
				printf("此人与你的对应关系是：%s\n继续进行输入或按0退出\n",yd1->chhu);
			}
			else
			{
				printf("此程序只提供九代之内直系亲属的计算，您的查询超出范围，请重新输入或按0退出\n");
			}
		}


		if(pdf=='4')//女性字辈的输入
		{
			yd2=yd1->rch;
			if(yd2!=NULL)
			{
				yd1=yd2;
				printf("此人与你的对应关系是：%s\n继续进行输入或按0退出\n",yd1->chhu);
			}
			else
			{
				printf("此程序只提供九代之内直系亲属的计算，您的查询超出范围，请重新输入或按0退出\n");
			}
		}
		if(pdf=='0')//计算模块运算结束，输出最终计算结果。
		{
			printf("最终计算结果，此人为你的：%s\n",yd1->chhu);
			break;
		}
	}
	
}

int main()
{
	

	me *p;
	p=new me;
	creat(p);
	char select;
	printf("1.计算关系  2.输出整体关系图   3.退出程序\n");printf("请选择执行功能：");
	while(1)
	{
		
		scanf("%c",&select);
		if(select=='1')
		{
			fwcz(p);
			system("pause");
			system("cls");
			printf("请选择执行功能：1.计算关系  2.输出整体关系图   3.退出程序\n");
		}

		else if(select=='2')
		{
			IMAGE img;
			initgraph(1200,1000);
			loadimage(&img,L"C:\\Users\\admin\\Documents\\Visual Studio 2010\\Projects\\2020数据结构课设\\xx.jpg",0,0,true);//此图片为关系树图。
			putimage(0,0,&img);
			_getch();
			closegraph();
			system("cls");
			sx1(p);sx2(p);
			printf("\n");
			system("pause");
			system("cls");
			printf("请选择执行功能：1.计算关系  2.输出整体关系图   3.退出程序\n");
		}
		else if(select=='3')
		{
			printf("系统退出\n");
			break;
		}
	}
	system("pause");
}