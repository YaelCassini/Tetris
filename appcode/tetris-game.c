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


//������ɫѡ��Χ
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
	} ,//L��
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
	} ,//J��

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
	} ,//����

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
	},//T��
 };


/*
����ԭ�ͣ�void NextRan()
��������������һ���������״���� 
���������� �� 
����ֵ��������
��Ҫ�ֲ��������壺int random 
��Ҫ�ֲ�������;������random�����ɵ�һ������� 
�����㷨����������һ��С��28���������Ϊ�������״���� 
*/ 
void NextRan(){
	int random=rand(); 
	Next_num = random % 28;
} 
/*
����ԭ�ͣ�int RandomBlock()
���������������µķ��� 
���������� �� 
����ֵ�������������ɷ���Ĵ��� 
��Ҫ�ֲ��������壺int Now_num 
��Ҫ�ֲ�������;������Now_num����ŵ�ǰ�ķ������ 
�����㷨��������Ƕ��ѭ���������ɵ���״���ݷ��뱳��������
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
			background[i][j] = Block[Next_num][i][j-(WIDTH/2-2)];//���뱳������ 
		}
	bx=4;
	by=0;
	}
	Now_num=Next_num;
	NextRan();
	
	return Now_num;

}

/*
����ԭ�ͣ�int isClean(int n)
�����������ж�ĳһ���Ƿ���Ҫ���� 
���������� n:���������е����� 
����ֵ����������1����Ҫ����������0���������� 
��Ҫ�ֲ��������壺�� 
��Ҫ�ֲ�������;�������� 
�����㷨��������Ƕ��ѭ���ķ�ʽͳ�Ʊ���������ĳһ�еķ���������������==����������Ҫ���� 
*/
int isClean(int n)
{
	int i, count = 0;
	for (i = 0; i < WIDTH; i++)
	    {
		    if (background[n][i] == 2)
			    count++;//����һ�����ж��ٸ����� 
	    	if (count == WIDTH) return 1;//��Ҫ���� 
	}
	return 0;
}
/*
����ԭ�ͣ�void CleanLine(int n)
������������������
���������� n:���������е����� 
����ֵ�������� 
��Ҫ�ֲ��������壺�� 
��Ҫ�ֲ�������;������
�����㷨��������Ƕ��ѭ������Ҫ������������������һ�У��������һ������ 
*/
void CleanLine(int n)
{
	int i, j;
	for (i = n; i > 0; i--) {
		for(j=0;j<WIDTH;j++)//�����沿������һ�� 
		{
			background[i][j]=background[i-1][j];
		}
	}
	for (i = 0; i < WIDTH; i++)
		background[0][i] = 0;//��һ�й��� 
	
}
/*
����ԭ�ͣ�void DrawBox(double x, double y)
���������������������� 
���������� double x��x���ꣻ double y��y���� 
����ֵ�������� 
��Ҫ�ֲ��������壺�� 
��Ҫ�ֲ�������;�������� 
�����㷨�������� 
*/
void DrawBox(double x, double y)
{
	SetPenSize(1);
	drawRectangle(x, y, BOX-0.03, BOX-0.03, 1);
}
/*
����ԭ�ͣ�void DrawBlock(double x, double y, int n)
������������������״
���������� x:x����; y:y����; n:����Ĵ��� 
����ֵ�������� 
��Ҫ�ֲ��������壺�� 
��Ҫ�ֲ�������;�������� 
�����㷨��������Ƕ��ѭ���ķ�ʽ�������飬��������״���Ƴ��� 
*/
void DrawBlock(double x, double y, int n)//��������״ 
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
����ԭ�ͣ�void DrawTheScreen()
����������ˢ����Ϸ���� 
���������� �� 
����ֵ�������� 
��Ҫ�ֲ��������壺�� 
��Ҫ�ֲ�������;�������� 
�����㷨������ʹ��Ƕ��ѭ�������������飬���»���������Ϸ���� 
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
����ԭ�ͣ�void TimerEventProcess(int timerID)
������������ʱ���ص����� 
���������� int timerID����ʱ������ 
����ֵ��������
��Ҫ�ֲ��������壺�� 
��Ҫ�ֲ�������;�������� 
�����㷨��������ʱ��1���ڿ�����Ϸ���̣���ʱ��0����ʵʱˢ�½��� 
*/
void TimerEventProcess(int timerID)
{
	int tmp;
	
		if(in_Game){
			switch (timerID) {
			case 1://�������Ѷȼ��� 
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
		if(isGameOver()){//�ж���Ϸ�Ƿ���� 
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
����ԭ�ͣ�void KeyboardGameProcess(int key, int event)
�������������̻ص����� 
����������int key�����̴��ţ�int event������״̬ 
����ֵ��������
��Ҫ�ֲ��������壺�� 
��Ҫ�ֲ�������;�������� 
�����㷨������ ������Ϸ�п��Ʒ�����ƶ� ����esc��ͣ��Ϸ 
*/
void KeyboardGameProcess(int key, int event)/*ÿ������������Ϣ����Ҫִ��*/
{
	double oldradius;
	int tmp;
	uiGetKeyboard(key, event); // GUI��ȡ����

	if (in_Game) {

		switch (event) {
		case KEY_DOWN:
			switch (key) {
			case VK_LEFT:
				key_flag=1;
				strcpy(KeyStatus,"��");
				if (IfMoveLeft() == 1)//�ж��Ƿ������� 
				{
					bx--;
					MoveTetris(-1);
					DrawTheScreen();
				}
				key_flag=0;

				break;

			case VK_RIGHT:
				key_flag=1;
				strcpy(KeyStatus,"��");
				if (IfMoveRight() == 1)//�ж��Ƿ������� 
				{
					bx++;
					MoveTetris(1);
					DrawTheScreen();
				}
				key_flag=0;
				break;
			case VK_UP:
				key_flag=1;
				strcpy(KeyStatus,"��rotate");
				if (IfRotateCW() == 1)// �ж��Ƿ���˳ʱ����ת
				{
					RotateCW();
					DrawTheScreen();
				}
				key_flag=0;
				break;
			case VK_DOWN:
				key_flag=1;
				strcpy(KeyStatus,"��speed up");
				tmp=Fall();
				DrawTheScreen();
				break;
			case VK_SPACE:
				key_flag=1;
				strcpy(KeyStatus,"space speed up");
				tmp=Fall();
				DrawTheScreen();
				break;
			case VK_ESCAPE://��ͣ��Ϸ 	
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

int Fall()//����һ�� ��ʱ�亯����ʱ���� 
{
	int r=1;
	int i = 0, j = 0;
	if (IfFall() == 0) {  //�����½� 
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
//-----------�ж����--------------// 
int IfRotateCW(){//�ж��Ƿ������ת 
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

int IfFall()//�ж��Ƿ��ܹ����� 
{
	int i = 0, j = 0;
	for (i = HEIGHT - 1; i > 0; i--) {
		for (j = 0; j < WIDTH; j++) {
			if (background[i][j] == 2 && background[i - 1][j] == 1) //�Ƿ������²����� 
				return 0;
			if (i == HEIGHT - 1 && background[i][j] == 1)//�Ƿ������ײ� 
				return 0;
		}

	}
	return 1;


}
int IfMoveLeft() {
	int i = 0, j = 0;
	for (i = 0; i <HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (background[i][j] == 1 && j == 0) return 0;//�ж��Ƿ����߽� 
			if (background[i][j] == 1 && background[i][j - 1] == 2) return 0;//�ж��Ƿ��������䷽�� 
		}
	}

	return 1;
}

int IfMoveRight() {
	int i = 0, j = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (background[i][j] == 1 && j == WIDTH - 1) return 0;//�ж��Ƿ����߽� 
			if (background[i][j] == 1 && background[i][j + 1] == 2) return 0;//�ж��Ƿ��������䷽�� 
		}
	}
	return 1;
}

//----------------------------------//
//---------�ƶ�����˹���� ----------// 
void MoveTetris(int m) {
	int i = 0, j = 0;
	if (m == -1)//����
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
	if (m == 1)//����
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


void RotateCW(){//��ת 
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
����ԭ�ͣ�int isGameOver()
�����������ж���Ϸ�Ƿ���� 
������������
����ֵ����������1����Ϸ����������0����Ϸδ���� 
��Ҫ�ֲ��������壺�� 
��Ҫ�ֲ�������;�������� 
�����㷨������ ѭ��������Ϸ�����һ�У����й̶���������Ϸ���� 
*/
int isGameOver(){
	int i;
	for(i=0;i<WIDTH;i++)
	{
		if(background[4][i]==2) return 1;

	}

	return 0;
} 
