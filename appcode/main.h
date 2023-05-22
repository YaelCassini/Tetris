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



#define HEIGHT 26 //游戏区域高度 
#define WIDTH 12 //游戏区域宽度 
#define BOX 0.25 //方块大小 





typedef struct rank{//排行榜用户信息结构体 
    int number;
	char name[40];
	int grade;
	struct rank *next;	
} RANK; 
struct blocks{//随机方块生成 
 int Block[4][4];
 string Color;
 int nNext;
}; 



//函数声明 
void	StartGame();//开始游戏 
void 	InitGameboard();// 绘制游戏界面 
int		RandomBlock();//生成新的随机形状 
int		isClean();//判断是否需要消除 
void	CleanLine(int n);//消除一行 
void	DrawBlock(double x, double y, int n); //画出俄罗斯方块形状 
void	DrawBox(double x, double y); //画单个方块 
void	DrawTheScreen();//刷新游戏界面 
int		IfRotateCW();//判断是否可旋转 
void	RotateCW(); //旋转 
int		find_center();//找到旋转中心 
void	TimerEventProcess(int timerID);//计时器调用函数 
void	KeyboardEventProcess(int key, int event);//键盘调用函数
void	CharEventProcess(char ch); // 字符调用函数
void	KeyboardGameProcess(int key, int event);//游戏中的键盘调用 
void	MouseEventProcess(int x, int y, int button, int event); // 鼠标调用函数 
int		Fall();//下落一格 
int		IfFall();//判断是否能够下落 
int		IfMoveLeft();//判断是否能左移 
int		IfMoveRight();//判断是否能够右移 
void	MoveTetris(int m);//左右移动 
int     isGameOver();//判断 
void	DrawSquare(double m,double n,double x,double y);//画方格
int  	rotate_block_number(int n);//旋转编号控制 
void 	NextRan();//生成随机形状 
void	SillyFace();//表情 
void inputranking();//从文件输入已有排行榜 
void printrank(RANK *head1);//显示排行榜 
RANK *insert(RANK* head1,RANK* ptr0);//插入新节点 
void outputranking(RANK *head1);//把现排行榜输出到文件 
void DisplayClear(void);// 清屏函数，provided in libgraphics
void startTimer(int id, int timeinterval);// 计时器启动函数，provided in libgraphics
void drawRank(double x, double y, double w, double h, int fillflag, char *label1,char *label2,char *label3); //画排行榜 



// 全局变量
 double winwidth, winheight;   // 窗口尺寸
 float  rot_angle = 0;         // 三角形旋转角度
 int    enable_rotation = 1;   // 允许旋转
 int    show_more_buttons = 0; // 显示更多按钮
 int    show_menu = 0;           //显示菜单 
 int    show_help=0,show_author=0;
 int    show_button = 1;         //显示按钮 
 int    show_textbook = 1;       //显示文本框 
 int    show_secondmenu[10] = {0};     //显示二级菜单 
 int    background[HEIGHT][WIDTH];		//游戏区域数组 
 int	  in_menu=1,in_Game=0;				//游戏是否处于菜单界面 
 int    number;                       //方块代号 
 int    level=0;                   //关卡数 
 int TimerCounter,TimerCounter1;
 int bx=4,by=0;
 int nSpeed=800,nScore;
 int OnSpeed=800;
 int Next_num;
 int Next_cl=0;
 int Now_cl=0;
 int SillyNum;
 int times = 0;      //选择颜色次数 

static char * selectedLabel = NULL;//最后选中的按钮 

RANK *head=NULL;//排行榜链表头指针 
RANK *ptr;//排行榜遍历指针 
RANK *ptrnew=NULL;//排行榜新加入的结点 
RANK *ptr0;//排行榜遍历指针 

FILE *fp;//文件指针 
int size=sizeof(RANK);//结构体大小 

 char TheNumber[4];//排行的字符串储存 
 char TheGrade[8];//成绩的字符串储存 

 int inputrank=0;//是否已读入排行榜 
 
char firstName[40] = "YourFirstName";
char lastName[40] = "YourLastName";//用户名 

char historyname[5][40]={{"NEW GAME"},{"NEW GAME"},{"NEW GAME"},{"NEW GAME"},{"NEW GAME"}};



// 用户的显示函数
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
