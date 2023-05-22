#include "main.h"

int TPSpeed=800;
extern  nSpeed;
extern  OnSpeed;
extern  bx,by;
extern  nScore;
extern  Next_num;
static  key_flag=0;
extern  level;
extern in_Game;
extern SillyNum;
char KeyStatus[30];
extern show_help,show_author;


//方块颜色选择范围
#define colornum 7
static char * ColorofBlock[] = { "PunkBlue", "PunkRed", "PunkOrange", "PunkYellow","PunkLightBlue","PunkPurple", "PunkPink" }; 
static char * ColorofBlock2[] = { "TraBlue", "TraRed", "TraGreen", "TraYellow","TraGold","TraPurple", "TraBack" };
static char * ColorofBlock3[] = { "AhaBlue", "AhaGreen", "AhaWhite", "AhaYellow","AhaPink","PunkPurple", "TraGold" };
static int cl=0;
static char backgroundcolor[HEIGHT][WIDTH][30];


int Block[28][4][4] = {
	{
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0
	},
		{
		0,0,0,0,
		1,1,1,1,
		0,0,0,0,
		0,0,0,0
	},
	{
		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0
	},
	{
		0,0,0,0,
		1,1,1,1,
		0,0,0,0,
		0,0,0,0
	},//I
	{
		1,1,0,0,
		0,1,1,0,
		0,0,0,0,
		0,0,0,0
	},
	{
		0,0,1,0,
		0,1,1,0,
		0,1,0,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		1,1,0,0,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,1,0,0,
		1,1,0,0,
		1,0,0,0,
		0,0,0,0
	} ,//Z

	{
		0,1,1,0,
		1,1,0,0,
		0,0,0,0,
		0,0,0,0
	},
	{
		1,0,0,0,
		1,1,0,0,
		0,1,0,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		0,1,1,0,
		1,1,0,0,
		0,0,0,0
	},
	{
		0,1,0,0,
		0,1,1,0,
		0,0,1,0,
		0,0,0,0
	},//S
	{
		0,1,0,0,
		0,1,0,0,
		0,1,1,0,
		0,0,0,0
	},
	{
		0,0,1,0,
		1,1,1,0,
		0,0,0,0,
		0,0,0,0
	},
	{
		1,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		1,1,1,0,
		1,0,0,0,
		0,0,0,0
	} ,//L形
		{
		0,1,0,0,
		0,1,0,0,
		1,1,0,0,
		0,0,0,0
	},
	{
		0,0,0,0,
		1,1,1,0,
		0,0,1,0,
		0,0,0,0
	},
	{
		0,1,1,0,
		0,1,0,0,
		0,1,0,0,
		0,0,0,0
	},
	{
		1,0,0,0,
		1,1,1,0,
		0,0,0,0,
		0,0,0,0
	} ,//J形

	{
		1,1,0,0,
		1,1,0,0,
		0,0,0,0,
		0,0,0,0
	},
	{
		1,1,0,0,
		1,1,0,0,
		0,0,0,0,
		0,0,0,0
	},
	{
		1,1,0,0,
		1,1,0,0,
		0,0,0,0,
		0,0,0,0
	},
	{
		1,1,0,0,
		1,1,0,0,
		0,0,0,0,
		0,0,0,0
	} ,//田形

	{
		0,0,0,0,
		1,1,1,0,
		0,1,0,0,
		0,0,0,0
	},
		{
		0,1,0,0,
		0,1,1,0,
		0,1,0,0,
		0,0,0,0
	}, 

	{
		0,1,0,0,
		1,1,1,0,
		0,0,0,0,
		0,0,0,0
	},

		{
		0,1,0,0,
		1,1,0,0,
		0,1,0,0,
		0,0,0,0
	},//T形
 };


/*
函数原型：void NextRan()
功能描述；生成一个随机的形状代号 
参数描述： 无 
返回值描述：无
重要局部变量定义：int random 
重要局部变量用途描述：random：生成的一个随机数 
函数算法描述：生成一个小于28的随机数作为随机的形状代号 
*/ 
void NextRan(){
	int random=rand(); 
	Next_num = random % 28;
} 
/*
函数原型：int RandomBlock()
功能描述；生成新的方块 
参数描述： 无 
返回值描述：返回生成方块的代号 
重要局部变量定义：int Now_num 
重要局部变量用途描述：Now_num：存放当前的方块代号 
函数算法描述：用嵌套循环将新生成的形状数据放入背景数组中
*/ 
int RandomBlock()
{
	int i, j, a = 0, b = 0;
	int Now_num;
	cl=rand()%colornum;
	 switch(times%3){
			case 0:
               SetPenColor(ColorofBlock[cl]);
                break;
            case 1:
            	SetPenColor(ColorofBlock2[cl]);
            	break;
            case 2:
            	SetPenColor(ColorofBlock3[cl]);
            	break;
            }
	for (i = 0; i < 4; i++) {
		for (j = 4; j < 8; j++) {
			background[i][j] = Block[Next_num][i][j-(WIDTH/2-2)];//放入背景数组 
		}
	bx=4;
	by=0;
	}
	Now_num=Next_num;
	NextRan();
	
	return Now_num;

}

/*
函数原型：int isClean(int n)
功能描述；判断某一行是否需要消除 
参数描述： n:背景数组中的行数 
返回值描述：返回1：需要消除；返回0：不用消除 
重要局部变量定义：无 
重要局部变量用途描述：无 
函数算法描述：用嵌套循环的方式统计背景数组中某一行的方块数，若方块数==列数，则需要消除 
*/
int isClean(int n)
{
	int i, count = 0;
	for (i = 0; i < WIDTH; i++)
	    {
		    if (background[n][i] == 2)
			    count++;//计算一行中有多少个方块 
	    	if (count == WIDTH) return 1;//需要消除 
	}
	return 0;
}
/*
函数原型：void CleanLine(int n)
功能描述；消除满行
参数描述： n:背景数组中的行数 
返回值描述：无 
重要局部变量定义：无 
重要局部变量用途描述：
函数算法描述：用嵌套循环将需要消除行以上数据下移一行，并清零第一行数据 
*/
void CleanLine(int n)
{
	int i, j;
	for (i = n; i > 0; i--) {
		for(j=0;j<WIDTH;j++)//把上面部分下移一行 
		{
			background[i][j]=background[i-1][j];
		}
	}
	for (i = 0; i < WIDTH; i++)
		background[0][i] = 0;//第一行归零 
	
}
/*
函数原型：void DrawBox(double x, double y)
功能描述；画单个正方形 
参数描述： double x：x坐标； double y：y坐标 
返回值描述：无 
重要局部变量定义：无 
重要局部变量用途描述：无 
函数算法描述：无 
*/
void DrawBox(double x, double y)
{
	SetPenSize(1);
	drawRectangle(x, y, BOX-0.03, BOX-0.03, 1);
}
/*
函数原型：void DrawBlock(double x, double y, int n)
功能描述；画基本形状
参数描述： x:x坐标; y:y坐标; n:方块的代号 
返回值描述：无 
重要局部变量定义：无 
重要局部变量用途描述：无 
函数算法描述：用嵌套循环的方式遍历数组，将基本形状绘制出来 
*/
void DrawBlock(double x, double y, int n)//画基本形状 
{
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (Block[n][i][j]) {
				switch(times%3){
			case 0:
               SetPenColor(ColorofBlock[cl]);
                break;
            case 1:
            	SetPenColor(ColorofBlock2[cl]);
            	break;
            case 2:
            	SetPenColor(ColorofBlock3[cl]);
            	break;
            }
				DrawBox(x + BOX * j, y - BOX * i);
			}
		}
	}
}

/*
函数原型：void DrawTheScreen()
功能描述；刷新游戏区域 
参数描述： 无 
返回值描述：无 
重要局部变量定义：无 
重要局部变量用途描述：无 
函数算法描述：使用嵌套循环遍历背景数组，重新绘制整个游戏区域 
*/
void DrawTheScreen()
{
	int i = 0, j = 0;
	InitGameboard();
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (background[i][j] == 1) {
				switch(times%3){
			case 0:
               SetPenColor(ColorofBlock[cl]);
                break;
            case 1:
            	SetPenColor(ColorofBlock2[cl]);
            	break;
            case 2:
            	SetPenColor(ColorofBlock3[cl]);
            	break;	
            }
				DrawBox(winwidth/3-0.1+j*BOX, winheight/20+BOX*HEIGHT-i*BOX);
			}
			if (background[i][j] == 2) {
		        SetPenColor(backgroundcolor[i][j]);
				DrawBox(winwidth/3-0.1+j*BOX, winheight/20+BOX*HEIGHT-i*BOX);
			}

			   	

		}
	}

}

/*
函数原型：void TimerEventProcess(int timerID)
功能描述；计时器回调函数 
参数描述： int timerID：定时器名称 
返回值描述：无
重要局部变量定义：无 
重要局部变量用途描述：无 
函数算法描述：计时器1用于控制游戏进程，计时器0用于实时刷新界面 
*/
void TimerEventProcess(int timerID)
{
	int tmp;
	
		if(in_Game){
			switch (timerID) {
			case 1://分数与难度计算 
			level=nScore/1000;
			if(key_flag==0){
	        level=nScore/1000;
     		OnSpeed=TPSpeed-100*level; 
		    }
		    TimerCounter1+=(1+10*0.3);
		    
		if(OnSpeed!=nSpeed && OnSpeed>100){
	     		nSpeed=OnSpeed;
	     		cancelTimer(1);
     			startTimer(1,nSpeed);
			 }
	    	
			tmp=Fall();
			if(tmp==2) SillyNum=1;
			else SillyNum=0;
			InitGameboard();
			DrawTheScreen();
	
	if(TimerCounter1>=65){
			if(tmp==2) SillyNum=1;
			else SillyNum=0;
			if(show_help)
			show_help=0;
			if(show_author)
			show_author=0;
			TimerCounter1=0;
			InitGameboard();
			DrawTheScreen();
			
		}
		if(isGameOver()){//判断游戏是否结束 
	    		ptrnew->grade=nScore;
		    	SillyNum=2;  
		    	in_Game=0;
		    	insert(head,ptrnew);
	            outputranking(head);
		     	show_secondmenu[5]=1;
		     	in_menu=1;
	            flag=0;
	     		cancelTimer(1);
	            display(); 
	       	}
	  	break;
		case 0:
			InitGameboard();
			DrawTheScreen();
				display();
         	default:
	    	break;
		}
		
	}
} 


/*
函数原型：void KeyboardGameProcess(int key, int event)
功能描述；键盘回调函数 
参数描述：int key：键盘代号；int event：键盘状态 
返回值描述：无
重要局部变量定义：无 
重要局部变量用途描述：无 
函数算法描述： 用于游戏中控制方块的移动 ，按esc暂停游戏 
*/
void KeyboardGameProcess(int key, int event)/*每当产生键盘消息，都要执行*/
{
	double oldradius;
	int tmp;
	uiGetKeyboard(key, event); // GUI获取键盘

	if (in_Game) {

		switch (event) {
		case KEY_DOWN:
			switch (key) {
			case VK_LEFT:
				key_flag=1;
				strcpy(KeyStatus,"←");
				if (IfMoveLeft() == 1)//判断是否能左移 
				{
					bx--;
					MoveTetris(-1);
					DrawTheScreen();
				}
				key_flag=0;

				break;

			case VK_RIGHT:
				key_flag=1;
				strcpy(KeyStatus,"→");
				if (IfMoveRight() == 1)//判断是否能右移 
				{
					bx++;
					MoveTetris(1);
					DrawTheScreen();
				}
				key_flag=0;
				break;
			case VK_UP:
				key_flag=1;
				strcpy(KeyStatus,"↑rotate");
				if (IfRotateCW() == 1)// 判断是否能顺时针旋转
				{
					RotateCW();
					DrawTheScreen();
				}
				key_flag=0;
				break;
			case VK_DOWN:
				key_flag=1;
				strcpy(KeyStatus,"↓speed up");
				tmp=Fall();
				DrawTheScreen();
				break;
			case VK_SPACE:
				key_flag=1;
				strcpy(KeyStatus,"space speed up");
				tmp=Fall();
				DrawTheScreen();
				break;
			case VK_ESCAPE://暂停游戏 	
			    in_Game=0;
	            cancelTimer(1);
	            in_menu=1; 
	            flag=0;
			    ClearFirstMenu();
			    ClearSecondMenu();
			    show_secondmenu[4] =1;
	            display();
	            break;
		 	}
		case KEY_UP:
			key_flag=0;
			strcpy(KeyStatus," ");
			break;
		}




	}
}

int Fall()//下移一格 由时间函数定时调用 
{
	int r=1;
	int i = 0, j = 0;
	if (IfFall() == 0) {  //不能下降 
		by=0;
		for (i = HEIGHT-1; i >= 0; i--) {
			for (j = 0; j < WIDTH; j++) {
				if (background[i][j] == 1){
					background[i][j] = 2;
					switch(times%3){
	             		case 0:
                           strcpy(backgroundcolor[i][j],ColorofBlock[cl]);
                           break;
                        case 1:
                         	strcpy(backgroundcolor[i][j],ColorofBlock2[cl]);
                         	break;
                        case 2:
                         	strcpy(backgroundcolor[i][j],ColorofBlock3[cl]);
                         	break;
                    }
				}
					
			}
		}
		for(i=0;i<HEIGHT;i++){
			if(isClean(i)){
				CleanLine(i);
				nScore+=100;
				r=2;
			}
		}
		//NextRan();
		number=RandomBlock();
		nScore+=30;
		
		
		return r;
	}


	by++;
	i = 0;
	j = 0;
	for (i = HEIGHT - 2; i >= 0; i--) {
		for (j = 0; j < WIDTH; j++) {
			if (background[i][j] == 1 && background[i +1][j] != 2)
				{
				    background[i+1][j] = background[i ][j];
				    background[i][j]=0;
				 }
			else if (background[i][j] == 1 && background[i + 1][j] == 2)
				background[i][j] = 2;

		}

	}
	for (j = 0; j < WIDTH; j++) {
		background[0][j] = 0;
	}
	
	return 0;
}

//----------------------------------//
//-----------判断语句--------------// 
int IfRotateCW(){//判断是否可以旋转 
	int i=by,j=bx;
	int n2;
	n2=rotate_block_number(number);
	for(i=by;i<by+4;i++){
		for(j=bx;j<bx+4;j++){
			if(Block[n2][i-by][j-bx]==1 && background[i][j]==2)
			return 0;
			if(Block[n2][i-by][j-bx]==1 && !(((j+i*WIDTH)>=(i*WIDTH))&&((j+i*WIDTH)<(i*WIDTH+WIDTH))) )
			return 0;
		}
	}
	return 1;
}

int IfFall()//判断是否能够下落 
{
	int i = 0, j = 0;
	for (i = HEIGHT - 1; i > 0; i--) {
		for (j = 0; j < WIDTH; j++) {
			if (background[i][j] == 2 && background[i - 1][j] == 1) //是否触碰到下部方块 
				return 0;
			if (i == HEIGHT - 1 && background[i][j] == 1)//是否触碰到底部 
				return 0;
		}

	}
	return 1;


}
int IfMoveLeft() {
	int i = 0, j = 0;
	for (i = 0; i <HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (background[i][j] == 1 && j == 0) return 0;//判断是否触碰边界 
			if (background[i][j] == 1 && background[i][j - 1] == 2) return 0;//判断是否触碰到下落方块 
		}
	}

	return 1;
}

int IfMoveRight() {
	int i = 0, j = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (background[i][j] == 1 && j == WIDTH - 1) return 0;//判断是否触碰边界 
			if (background[i][j] == 1 && background[i][j + 1] == 2) return 0;//判断是否触碰到下落方块 
		}
	}
	return 1;
}

//----------------------------------//
//---------移动俄罗斯方块 ----------// 
void MoveTetris(int m) {
	int i = 0, j = 0;
	if (m == -1)//左移
	{
		for (i = 0; i < HEIGHT; i++) {
			for (j = 0; j < WIDTH - 1; j++) {
				if (background[i][j + 1] == 1 && background[i][j] != 2) {
					background[i][j] = background[i][j + 1];
					background[i][j+1]=0; 
				}
				else if (background[i][j + 1] == 2 && background[i][j] == 1) background[i][j] = 0;
			}
		}
	}
	if (m == 1)//右移
	{
		for (i = 0; i < HEIGHT; i++) {
			for (j = WIDTH - 1; j > 0; j--) {
				if (background[i][j - 1] == 1&& background[i][j ] != 2){
					background[i][j] = background[i][j -1];
					background[i][j-1]=0;
				}
				else if (background[i][j - 1] == 2 && background[i][j] == 1)background[i][j] = 0;
			}
		}
	}
}


void RotateCW(){//旋转 
	int i=0,j=0;
	int a=0,b=0;
	int n2;
	n2=rotate_block_number(number);
	for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++){
			if(background[i][j]==1)
			background[i][j]=0;
			
		}
	}
	for(i=by;i<by+4;i++){
		for(j=bx;j<bx+4;j++){
			if(Block[n2][i-by][j-bx]==1)
			background[i][j]=1;
		}
	}
	number=n2;
	
	
}
int rotate_block_number(int n){
	switch(n){
		case 0:
		case 1:
		case 2:	
		case 4:
		case 5:
		case 6:
		case 8:
		case 9:
		case 10:
		case 12:
		case 13:
		case 14:
		case 16:
		case 17:
		case 18:
		case 20:
		case 21:
		case 22:	
		case 24:
		case 25:
		case 26:
			return n+1;
			break;
		case 3:
			return 0;
			break;
		case 7:
			return 4;
		case 11:
			return 8;
		case 15:
			return 12;
		case 19:
			return 16;
		case 23:
			return 20;
		case 27:
			return 24;
	}
}
/*
函数原型：int isGameOver()
功能描述；判断游戏是否结束 
参数描述：无
返回值描述：返回1：游戏结束；返回0：游戏未结束 
重要局部变量定义：无 
重要局部变量用途描述：无 
函数算法描述： 循环遍历游戏区域第一行，若有固定方块则游戏结束 
*/
int isGameOver(){
	int i;
	for(i=0;i<WIDTH;i++)
	{
		if(background[4][i]==2) return 1;

	}

	return 0;
} 
