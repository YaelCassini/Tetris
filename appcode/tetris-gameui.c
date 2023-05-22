#include "main.h"

extern  number;
extern  nScore;
extern  Next_cl;
double width,height;
extern  Next_num;
extern  level;
extern  levelflag;
extern SillyNum;
extern char KeyStatus[];
extern show_menu;
extern show_help,show_author;


void DrawSquare(double m,double n,double x,double y)
{
	//SetPenSize(0.01);
	MovePen(m-x/2,n-y/2);
	DrawLine(x,0);
	DrawLine(0,y);
	DrawLine(-x,0);
	DrawLine(0,-y);
}
//绘制游戏初始界面 
void StartGame()

{
	int i,j;
	in_Game=1;
	show_menu=1;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < 12; j++) {
			background[i][j] = 0;
		}
}
	InitGameboard();
	
	number=RandomBlock();
	startTimer(1,OnSpeed);
	startTimer(0,20);
}

void InitGameOverboard(){
		
	
	
}

void InitGameboard(){
	

	
	char TheScore[100]={"0"};
	char LEVEL[10]={"0"};
	width=GetWindowWidth();
    height=GetWindowHeight();
    
    //绘制游戏区域
    SetPenSize(5);
    MovePen(0,0);
	StartFilledRegion(1);
	switch(times%3){
			case 0:
                SetPenColor("PunkDarkPurple");
                break;
            case 1:
            	SetPenColor("Black");
            	break;
            case 2:
            	SetPenColor("AhaDGreen");
            	break;
            }//背景颜色 
    DrawSquare(width/2,height/2,width,height);
    EndFilledRegion();
    switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaWhite");
            	break;
            }

    drawRectangle(width/3-0.18,height/20+BOX-0.06,BOX*(WIDTH)+0.13,BOX*(HEIGHT-4)+0.1,0);
    //SetPenColor("Red");
    //drawRectangle(width/3-0.105,height/20+0.01+BOX,BOX*(WIDTH),BOX*(HEIGHT-4),0);
    
    //绘制形状提示框 
        switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraYellow");
            	break;
            case 2:
            	SetPenColor("AhaWhite");
            	break;
            }

    MovePen(width*2/3,(height+BOX*HEIGHT)/2-0.5);
    SetPointSize(40);
	DrawTextString("NEXT");
        switch(times%3){
			case 0:
                SetPenColor("PunkPink");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaBlue");
            	break;
            }
    MovePen(width*2/3-0.03,(height+BOX*HEIGHT)/2-0.5); 
	DrawTextString("NEXT");
    DrawBlock(width*2/3+0.5,(height+BOX*HEIGHT)/2-1.3,Next_num);
	 switch(times%3){
			case 0:
                SetPenColor("PunkPink");
                break;
            case 1:
            	SetPenColor("TraYellow");
            case 2:
            	SetPenColor("AhaWhite");
            	break;
            }
	SetPenSize(5);
	DrawSquare(width*2/3+0.8,(height+BOX*HEIGHT)/2-1.5,6*BOX+0.02,6*BOX+0.02);
	
	//绘制速度框
	 switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraYellow");
            	break;
            case 2:
            	SetPenColor("AhaWhite");
            	break;
            }
	MovePen(width/8-2*BOX,(height)/2+2*BOX+BOX);
	SetPointSize(40);
	DrawTextString("Level");
	MovePen(width/8-2*BOX-0.03,(height)/2+2*BOX+BOX); 
	 switch(times%3){
			case 0:
                SetPenColor("PunkPink");
                break;
            case 1:
            	SetPenColor("TraGold");
                break;
            case 2:
            	SetPenColor("AhaBlue");
            	break;
            }
	DrawTextString("Level");
	 switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaWhite");
            	break;
            }
	MovePen(width/8-2*BOX+1.2,(height)/2+2*BOX+BOX);
	DrawTextString(itoa(level,LEVEL, 10));
	
	//绘制计分框
	 switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraYellow");
            	break;
            case 2:
            	SetPenColor("AhaWhite");
            	break;
            }
	MovePen(width/8-2*BOX,(height-BOX*HEIGHT)/2+2*BOX+2*BOX+BOX); 
	SetPointSize(40);
	DrawTextString("Score");
	MovePen(width/8-2*BOX-0.03,(height-BOX*HEIGHT)/2+2*BOX+2*BOX+BOX); 
	 switch(times%3){
			case 0:
                SetPenColor("PunkPink");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaBlue");
            	break;
            };
	DrawTextString("Score");
	 switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaWhite");
            	break;
            }
	MovePen(width/8-2*BOX+1.3,(height-BOX*HEIGHT)/2+2*BOX+2*BOX+BOX); 
	DrawTextString(itoa(nScore, TheScore, 10));
	
	//绘制表情
	 switch(times%3){
			case 0:
                SetPenColor("PunkPink");
                break;
            case 1:
            	SetPenColor("TraYellow");
            	break;
            case 2:
            	SetPenColor("AhaWhite");
            	break;
            }
    SetPointSize(40);
    MovePen(width*2/3,(height+BOX*HEIGHT)/2-4.5);
	SillyFace(); 
	SetPenSize(5);
	
	//绘制键盘状况 
	SetPenColor("White");
	SetPointSize(20);
	MovePen(width*2/3,0.6); 
	DrawTextString("KeyStatus");
	//MovePen(width*2/3-0.03,1); 
	//SetPenColor("PunkPink");
	//DrawTextString("KeyStatus");
	SetPenColor("White");
	SetPointSize(20);
	MovePen(width*2/3+1.2,0.6); 
	DrawTextString(KeyStatus);
	
	//绘制暂停按钮
/*	if (button(GenUIID(0), width*2/3+1,(height+BOX*HEIGHT)/4,8*BOX,4*BOX,"PAUSE")){
		    in_menu=1;
		    show_button=1;
	        show_secondmenu[4] =1;
			 in_Game=0;
     	    // selectedLabel = "PAUSE";
	         cancelTimer(1);
	         in_menu=1;
	         flag=0;
     	    // DisplayClear();
     	     //showpausemenu();
     	     //InitGameboard();
	         display();

   
	}*/
	drawMenu(); 
	if(show_help){
		show_author=0;
			SetPenSize(5);
			switch(times%3){
			case 0:
                SetPenColor("PunkDarkPurple");
                break;
            case 1:
            	SetPenColor("Black");
            	break;
            case 2:
            	SetPenColor("AhaDGreen");
            	break;	
            }

	    	MovePen(0.5,winheight/4*3+0.2);
			switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaBlue");
            	break;
            }
			DrawTextString("Use \" up key \" to rotate") ;
			MovePen(0.5,winheight/4*3);
			switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaBlue");
            	break;
            }
			DrawTextString("Use \" right key & left key \" to move") ;
			MovePen(0.5,winheight/4*3-0.2);
			switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaBlue");
            	break;
            }
			DrawTextString("Use \" down key \" to speed up") ;}

	if(show_author){
		show_help=0;
			SetPenSize(2);
			switch(times%3){
			case 0:
                SetPenColor("PunkDarkPurple");
                break;
            case 1:
            	SetPenColor("Black");
            	break;
            case 2:
            	SetPenColor("AhaDGreen");
            	break;	
            }

	    	MovePen(0.5,winheight/4*3+0.1);
			switch(times%3){
			case 0:
                SetPenColor("PunkBlue");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaBlue");
            	break;
            }
            SetPointSize(5); 
			DrawTextString("It\'s a game by ") ;
			MovePen(0.5,winheight/4*3-0.4);
			DrawTextString("李沛瑶、尤馨莹、李奕扬 ") ;
		}

}

void SillyFace(){
	switch(SillyNum){
		case 0:
			DrawTextString("(⊙-⊙)");
			break;
		case 1:
			DrawTextString("(⊙o⊙) wow!");
			break;
		case 2: 
			DrawTextString("/(ㄒoㄒ)/");
			break;
			
	}
		
}

