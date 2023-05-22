#ifndef A_H
#define A_H 1 


#include "graphics.h"
#include "imgui.h" 
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <string.h>
#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include "imgui.h"
#include<string.h>



#define HEIGHT 26 //��Ϸ����߶� 
#define WIDTH 12 //��Ϸ������ 
#define BOX 0.25 //�����С 





typedef struct rank{//���а��û���Ϣ�ṹ�� 
    int number;
	char name[40];
	int grade;
	struct rank *next;	
} RANK; 
struct blocks{//����������� 
 int Block[4][4];
 string Color;
 int nNext;
}; 



//�������� 
void	StartGame();//��ʼ��Ϸ 
void 	InitGameboard();// ������Ϸ���� 
int		RandomBlock();//�����µ������״ 
int		isClean();//�ж��Ƿ���Ҫ���� 
void	CleanLine(int n);//����һ�� 
void	DrawBlock(double x, double y, int n); //��������˹������״ 
void	DrawBox(double x, double y); //���������� 
void	DrawTheScreen();//ˢ����Ϸ���� 
int		IfRotateCW();//�ж��Ƿ����ת 
void	RotateCW(); //��ת 
int		find_center();//�ҵ���ת���� 
void	TimerEventProcess(int timerID);//��ʱ�����ú��� 
void	KeyboardEventProcess(int key, int event);//���̵��ú���
void	CharEventProcess(char ch); // �ַ����ú���
void	KeyboardGameProcess(int key, int event);//��Ϸ�еļ��̵��� 
void	MouseEventProcess(int x, int y, int button, int event); // �����ú��� 
int		Fall();//����һ�� 
int		IfFall();//�ж��Ƿ��ܹ����� 
int		IfMoveLeft();//�ж��Ƿ������� 
int		IfMoveRight();//�ж��Ƿ��ܹ����� 
void	MoveTetris(int m);//�����ƶ� 
int     isGameOver();//�ж� 
void	DrawSquare(double m,double n,double x,double y);//������
int  	rotate_block_number(int n);//��ת��ſ��� 
void 	NextRan();//���������״ 
void	SillyFace();//���� 
void inputranking();//���ļ������������а� 
void printrank(RANK *head1);//��ʾ���а� 
RANK *insert(RANK* head1,RANK* ptr0);//�����½ڵ� 
void outputranking(RANK *head1);//�������а�������ļ� 
void DisplayClear(void);// ����������provided in libgraphics
void startTimer(int id, int timeinterval);// ��ʱ������������provided in libgraphics
void drawRank(double x, double y, double w, double h, int fillflag, char *label1,char *label2,char *label3); //�����а� 



// ȫ�ֱ���
 double winwidth, winheight;   // ���ڳߴ�
 float  rot_angle = 0;         // ��������ת�Ƕ�
 int    enable_rotation = 1;   // ������ת
 int    show_more_buttons = 0; // ��ʾ���ఴť
 int    show_menu = 0;           //��ʾ�˵� 
 int    show_help=0,show_author=0;
 int    show_button = 1;         //��ʾ��ť 
 int    show_textbook = 1;       //��ʾ�ı��� 
 int    show_secondmenu[10] = {0};     //��ʾ�����˵� 
 int    background[HEIGHT][WIDTH];		//��Ϸ�������� 
 int	  in_menu=1,in_Game=0;				//��Ϸ�Ƿ��ڲ˵����� 
 int    number;                       //������� 
 int    level=0;                   //�ؿ��� 
 int TimerCounter,TimerCounter1;
 int bx=4,by=0;
 int nSpeed=800,nScore;
 int OnSpeed=800;
 int Next_num;
 int Next_cl=0;
 int Now_cl=0;
 int SillyNum;
 int times = 0;      //ѡ����ɫ���� 

static char * selectedLabel = NULL;//���ѡ�еİ�ť 

RANK *head=NULL;//���а�����ͷָ�� 
RANK *ptr;//���а����ָ�� 
RANK *ptrnew=NULL;//���а��¼���Ľ�� 
RANK *ptr0;//���а����ָ�� 

FILE *fp;//�ļ�ָ�� 
int size=sizeof(RANK);//�ṹ���С 

 char TheNumber[4];//���е��ַ������� 
 char TheGrade[8];//�ɼ����ַ������� 

 int inputrank=0;//�Ƿ��Ѷ������а� 
 
char firstName[40] = "YourFirstName";
char lastName[40] = "YourLastName";//�û��� 

char historyname[5][40]={{"NEW GAME"},{"NEW GAME"},{"NEW GAME"},{"NEW GAME"},{"NEW GAME"}};



// �û�����ʾ����
void display(void);
void printhistory();
void inputhistoryname();
void ouputhistoryname();
void inputhistory(char *address); 
void outputhistory(char *address);


#include "tetris-menu.c"
#include "tetris-game.c"
#include "tetris-rank.c"
#include "tetris-gameui.c"
#include "tetris-history.c"


#endif
