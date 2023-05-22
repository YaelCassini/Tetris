#include "main.h"

extern TPSpeed;

char SpeedMark[10]="0";
int mark=0;
int in_speed=0;
int flag=0;

/*
函数原型：void CharEventProcess(char ch)
功能描述； 用户的字符事件响应函数 
参数描述： char ch：用户输入的字符 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：无 
*/

void CharEventProcess(char ch)
{
		uiGetChar(ch); // GUI字符输入
	    display(); //刷新显示
	
}

/*
函数原型：void CharEventProcess(char ch)
功能描述；用户的鼠标事件响应函数 
参数描述：int x：x坐标 ；int y ： y坐标； int button:鼠标按钮； int event：发生事件 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：无 
*/
void MouseEventProcess(int x, int y, int button, int event)
{
    uiGetMouse(x, y, button, event); //GUI获取鼠标
	display(); // 刷新显示
	
	
}

// 菜单演示程序
/*
函数原型：void ClearFirstMenu()
功能描述；清除一级菜单 
参数描述：无 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：无 
*/
void ClearFirstMenu() {
	show_button = 0;
	show_textbook = 0;
	display();
}
/*
函数原型：void ShowFirstMenu()
功能描述；显示一级菜单 
参数描述：无 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：无 
*/
void ShowFirstMenu() {
	show_button = 1;
	show_textbook = 1;
	display();
} 
/*
函数原型：void ShowSecondMenu(int i)
功能描述；显示二级菜单 
参数描述：int i:二级菜单代号 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：修改对应二级菜单显示标志后，刷新界面 
*/
void ShowSecondMenu(int i) {
	show_secondmenu[i] = 1;
	display();
}
/*
函数原型：void ClearSecondMenu()
功能描述；清除二级菜单 
参数描述：无 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：将所有二级菜单显示标志清空后，刷新界面 
*/
void ClearSecondMenu() {
	int i=0;
	for(i=0;i<11;i++){
		show_secondmenu[i] = 0;
	}
	display(); 	
}//清除二级菜单 

/*
函数原型：void drawMenu()
功能描述；绘制菜单栏 
参数描述：无 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：无 
*/
void drawMenu()
{
	SetPenSize(2);
	SetPointSize(1);
	static char * menuListRegular[] = { "Regular",
		"Start  | Ctrl-O", // 快捷键必须采用[Ctrl-X]格式，放在字符串的结尾
		"Pause  | Ctrl-P",
		"Quit   | Ctrl-Q" };
	static char * menuListColor[] = { "About",
		"Help   | Ctrl-H",
		"Author | Ctrl-A" };


	double fH = GetFontHeight();
	double x = 0; //fH/8;
	double y = winheight;
	double h = fH * 1.8; // 控件高度
	double w = TextStringWidth(menuListColor[0]) * 2 * 2; // 控件宽度
	double wlist = TextStringWidth(menuListColor[0]) * 2 * 2;
	double xindent = winheight / 20; // 缩进
	int    selection;
	
	
	if (show_menu) 
	{		
		// menu bar
		//drawMenuBar(0, y - h, winwidth, h);
		// Regular 菜单
		selection = menuList(GenUIID(0), x, y - h, w, wlist, h, menuListRegular, sizeof(menuListRegular) / sizeof(menuListRegular[0]));
		if (selection > 0) selectedLabel = menuListRegular[selection];
		if( selection==1 ){
			cancelTimer(1);
	            InitGameboard();
	            StartGame();
		}
		 
		if( selection==2 ){
			show_secondmenu[4] =1;
			 in_Game=0;
	         cancelTimer(1);
	         in_menu=1;
	         flag=0;
	         display();
	        
		}
		if (selection == 3)
			exit(-1); // choose to exit

		// Setting 菜单
		selection = menuList(GenUIID(0), x + w, y - h, w, wlist, h, menuListColor, sizeof(menuListColor) / sizeof(menuListColor[0]));
		if (selection > 0) selectedLabel = menuListColor[selection];
		if( selection==1 ){
				show_help=1;
				show_author=0;
			    InitGameboard();
		}
		if( selection==2 ){
				show_author=1;
				show_help=0;
			    InitGameboard();
		}		

	}

}

// 按钮演示程序
/*
函数原型：void drawButtons()
功能描述；绘制各级菜单 
参数描述：无 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：show_button==1时，显示主菜单；show_secondmenu[]==1时，显示对应的二级菜单 
*/
void drawButtons()
{
	double fH = GetFontHeight();
	double h = fH * 2 * 2;  // 控件高度
	double w = winwidth / 6 * 2; // 控件宽度
	double x = winwidth / 4 - w / 2;
	double y = winheight *0.8;
	int ii,jj; 	
	

	if (show_button) {
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
		drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
		SetPointSize(120);
		switch(times%3){
			case 0:
                SetPenColor("PunkPink");
                break;
            case 1:
            	SetPenColor("TraYellow");
            	break;
            case 2:
            	SetPenColor("AhaBlue");
            	break;
            }
		MovePen(winwidth/2+0.8,winheight/5*3);
		DrawTextString("TETRIS");
		SetPointSize(120);
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
		MovePen(winwidth/2+0.85,winheight/5*3+0.02);
		DrawTextString("TETRIS");
		SetPointSize(2);


		if (button(GenUIID(0), x, y, w, h, "Start"))
		{
			selectedLabel = "Start";
			ClearFirstMenu();
			flag=1;
			display();	
		}	
		
		if (button(GenUIID(0), x, y - 1.5* h, w, h, "Setting")) {
			selectedLabel = "Setting";
			ClearFirstMenu();
			ShowSecondMenu(2);
		}
		
		if (button(GenUIID(0), x, y - 3*h, w, h, "Ranking List"))
		{
			selectedLabel = "Ranking List";
			if(inputrank==0){
				inputranking();
				inputrank=1;
			}			
			ClearFirstMenu();
			ShowSecondMenu(6);
		}
		
		if (button(GenUIID(0), x, y - 4.5*h, w, h, "Help"))
		{
			selectedLabel = "Help";
			ClearFirstMenu();
			ShowSecondMenu(9);
		}
		
		if (button(GenUIID(0), x, y - 6 * h, w, h, "History"))
		{
			ShowSecondMenu(7);
			show_textbook=0;
			display();
		}
		
		if (button(GenUIID(0), x, y - 7.5 * h, w, h, "Quit"))
		{
			exit(-1);
		}
		
		SetPointSize(1);	
	}
	if (show_secondmenu[10])//关于本软件 
	{    
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
		drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
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
    	MovePen(2,winheight-2);
     	SetPointSize(40);
    	DrawTextString("About");
     	MovePen(2-0.03,winheight-2); 
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
     	DrawTextString("About");//大标题 
	    SetPointSize(25);
	    MovePen(2-0.03,winheight-3);
		DrawTextString("Developer");
		SetPointSize(15);
		MovePen(2-0.03,winheight-3.6);
		DrawTextString("李沛瑶  李奕扬  尤馨莹");
		MovePen(3-0.03,winheight-4);
		DrawTextString("2019.6.10");
		
		SetPenSize(5);
		if (button(GenUIID(0), x + w / 2+1, y - 6*h, w, h, "Return"))
		{
			selectedLabel = "Return";
			ClearSecondMenu();
			display();
           	ShowSecondMenu(9);//返回帮助界面 
           	display();
		}	
	}
	
	if (show_secondmenu[9]) //帮助界面 
	
	{   
		
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
		drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
        SetPenSize(5); 
		if (button(GenUIID(0), x + w / 2+0.5, y - 1.5*h, w, h, "How To Play"))
		{
			selectedLabel = "How To Play";
            ClearSecondMenu();
           	ShowSecondMenu(3); //跳转至游戏说明界面 
		}
		
		if (button(GenUIID(0), x + w / 2+0.5, y - 3 * h, w, h, "About")) {
			selectedLabel = "About";
			ClearSecondMenu();
           	ShowSecondMenu(10); //跳转至游戏说明界面 
			} 
		if (button(GenUIID(0), x + w / 2 +0.5, y - 4.5*h, w, h, "Return"))
		{
			selectedLabel = "Return";
			ClearSecondMenu();
			ShowFirstMenu();
		}
	}
	
	if (show_secondmenu[8]){

		double h2 = fH * 2 ;  // 控件高度
	    double w2 = winwidth / 5 * 2; // 控件宽度
	    double x2 = winwidth / 2 - w / 2;
	    double y2 = winheight / 2 * 1.4;
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
		drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
        SetPenSize(5);
        if (button(GenUIID(0), x2 , y2 - 3*h2-0.3, w2, h2*2, "YES"))
		{
			int i;
		
			outputhistory(ptrnew->name);
			
		    for(i=3;i>=0;i--)
			{
		    	strcpy(historyname[i+1],historyname[i]);
			}
			strcpy(historyname[0],ptrnew->name);
			
			ptrnew=(RANK*)malloc(size);
			selectedLabel = "Return Main Menu";
			ClearSecondMenu(); 
			show_button=1;
			show_textbook=1;
			in_Game=0;
			in_menu=1;
			display();
			nScore=0;      //游戏数据清零 
			level=0;
			
	        for (ii = 0; ii < HEIGHT; ii++) { 
	    	    for (jj = 0; jj < WIDTH; jj++) {
		            background[ii][jj]=0;
		        }
			} 
			
	    }
	
	    if (button(GenUIID(0), x2 , y2 - 9 * h2, w2, h2*2, "NO")) {
			selectedLabel = "NO";	
			ptrnew=(RANK*)malloc(size);
			selectedLabel = "Return Main Menu";
			ClearSecondMenu(); 
			show_button=1;
			show_textbook=1;
			in_Game=0;
			in_menu=1;
			display();
			nScore=0;      //游戏数据清零 
			level=0;
		    for (ii = 0; ii < HEIGHT; ii++) { 
	    	    for (jj = 0; jj < WIDTH; jj++) {
		            background[ii][jj]=0;
	        	}
			} 
		}
		
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

    	MovePen( x2-0.05 , y2 ); 
    	SetPointSize(50);
    	DrawTextString("Save Progress？");
    	
    	MovePen( x2 , y2 ); 
    	
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
        DrawTextString("Save Progress？");
    	
	}
	
	if (show_secondmenu[7])//历史记录选择 
	{
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
    	drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
	    SetPointSize(5);	
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

		printhistory();

		if (button(GenUIID(0), x + w / 2+1, y - 7*h, w, h,"Return Main Menu")) {
			ptrnew=(RANK*)malloc(size);
			selectedLabel = "Return Main Menu";
			ClearSecondMenu();
			show_button=1;
			
			in_Game=0;
			in_menu=1;
			show_textbook=1;
			display();
			nScore=0;      //游戏数据清零 
			level=0;
		    for (ii = 0; ii < HEIGHT; ii++) { 
	    	    for (jj = 0; jj < WIDTH; jj++) {
		            background[ii][jj]=0;
	        	}
			} 
		}
			
	}
	
	
	if (show_secondmenu[6])//排行榜 
	{
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
    	drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
	    SetPointSize(5);	
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

		printrank(head);

		if (button(GenUIID(0), x + w / 2+1, y - 7*h, w, h,"Return Main Menu")) {
			ptrnew=(RANK*)malloc(size);
			selectedLabel = "Return Main Menu";
			show_secondmenu[6]=0;
			show_secondmenu[5]=0;
			show_button=1;
			
			in_Game=0;
			in_menu=1;
			show_textbook=1;
			display();
			nScore=0;      //游戏数据清零 
			level=0;
			nSpeed=800;
			OnSpeed=800; 
		    for (ii = 0; ii < HEIGHT; ii++) { 
	        	for (jj = 0; jj < WIDTH; jj++) {
		            background[ii][jj]=0;
	        	}
			} 
		}
			
	}

	if (show_secondmenu[3])//帮助界面 
	{    
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
        
		drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
	    SetPointSize(3);
	    drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色
	    MovePen(winwidth/2-TextStringWidth("use \" up key \" to rotate the blocks")/2,winheight/4*3);
	    
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
        
		DrawTextString("Use \" up key \" to rotate the blocks") ;
		MovePen(winwidth/2-TextStringWidth("Use \" right key & left key \" to move the blocks")/2,winheight/4*3-0.2);
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
		DrawTextString("Use \" right key & left key \" to move the blocks") ;
		MovePen(winwidth/2-TextStringWidth("use \" down key \" to speed up")/2,winheight/4*3-0.4);
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
		DrawTextString("Use \" down key \" to speed up") ;
		MovePen(winwidth/2-TextStringWidth("If a whole line was filled, they will disappear")/2,winheight/4*3-0.6);
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
		DrawTextString("If a whole line was filled, they will disappear") ;
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
		SetPointSize(70);
		MovePen(winwidth/2-TextStringWidth("GOOD LUCK!")/2,winheight/4*3-1.5);
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
		DrawTextString("GOOD LUCK!");
		MovePen(winwidth/2-TextStringWidth("GOOD LUCK!")/2+0.05,winheight/4*3-1.5);
		
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
		DrawTextString("GOOD LUCK!");
		SetPointSize(1);
		SetPenSize(5); 
		if (button(GenUIID(0), x + w / 2+1, y - 4.5*h, w, h, "Return"))
		{
			selectedLabel = "Return";
			ClearSecondMenu();
           	ShowSecondMenu(9);//返回帮助界面 
		}	
	}
	
	if (show_secondmenu[2]) //设置界面 
	
	{   
		
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
		drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
	    drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色
        SetPenSize(5); 
		if (button(GenUIID(0), x + w / 2+0.5, y - 1.5*h, w, h, "Speed"))
		{
			selectedLabel = "Speed";
			in_speed+=1;
		}
		if(in_speed%2){
			SetPenSize(3); 
			if(button(GenUIID(0), x + 3*w / 2+1, y - 1.5*h, w/5, h, "  +")){
				if(TPSpeed>80){
					TPSpeed-=80;
					mark++;
				}

			}
			if(button(GenUIID(0), x + 3*w / 2+1.8, y - 1.5*h, w/5, h, "  -")){

					TPSpeed+=80;
					mark--;
			}
			MovePen(x + 3*w / 2+3.2,y - 1.5*h); 
			SetPointSize(30);
			DrawTextString(itoa(mark, SpeedMark, 10));
		}
		
		
		if (button(GenUIID(0), x + w / 2+0.5, y - 3 * h, w, h, "Color")) {
			selectedLabel = "Color";
			times++;
			switch(times%3){
				case 0:
					setButtonColors("PunkBlue","PunkBlue","PunkPink","PunkPink", 0);
					setTextBoxColors("PunkPink", "PunkPink", "PunkPink", "PunkPink", 0);
					setMenuColors("PunkBlue","PunkBlue","PunkPink","PunkPink", 0);
					break;
				case 1:
					setButtonColors("TraGold","TraGold","TraYellow","TraYellow", 0);
					setTextBoxColors("TraYellow", "TraYellow", "TraYellow", "TraYellow", 0);
					setMenuColors("TraGold","TraGold","TraYellow","TraYellow", 0);
					break;
				case 2:
                	setButtonColors("AhaWhite","AhaWhite","AhaYellow","AhaYellow", 0);
					setTextBoxColors("AhaYellow", "AhaYellow", "AhaYellow", "AhaYellow", 0);
					setMenuColors("AhaWhite","AhaWhite","AhaYellow","AhaYellow", 0);
                	break;
			} 
		}
		
		if (button(GenUIID(0), x + w / 2 +0.5, y - 4.5*h, w, h, "Return"))
		{
			selectedLabel = "Return";
			ClearSecondMenu();
			ShowFirstMenu();
		}
	}
	
	
	if (show_secondmenu[4])//暂停界面
	{    
	    double h3 = fH * 2 ;  // 控件高度
	    double w3 = winwidth / 5 * 2; // 控件宽度
	    double x3 = winwidth / 2 - w / 2;
	    double y3 = winheight / 2 * 1.4;

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
		drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
        SetPenSize(5);
	    if (button(GenUIID(0), x3, y3 - 3*h3-0.3, w3, h3*2, "Continue"))
		{
			selectedLabel = "Continue";
			in_Game=1;
			in_menu=0;
			show_secondmenu[4]=0;
			InitGameboard();
			DrawTheScreen();
			startTimer(1,OnSpeed);
			display();
		}
		
		if (button(GenUIID(0), x3 , y3 - 9 * h3, w3, h3*2, "Return Main Menu")) {
			show_secondmenu[4]=0;
			ClearFirstMenu();
			ClearSecondMenu();
			ShowSecondMenu(8);
			display();
		}
		
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
        
    	MovePen( x3 , y3 ); 
    	SetPointSize(60);
    	DrawTextString("Pause");
    	MovePen( x3 -0.05, y3 ); 
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
        
    	DrawTextString("Pause");
	}
	
	if (show_secondmenu[5])//游戏结束界面
	{     
     	double h3 = fH * 2 ;  // 控件高度
    	double w3 = winwidth / 5 * 2; // 控件宽度
    	double x3 = winwidth / 2 - w / 2;
    	double y3 = winheight / 2 * 1.4;
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
		drawRectangle(0, 0, winwidth, winheight, 1);//背景颜色 
        SetPenSize(5);
    	if (button(GenUIID(0), x3-0.05 , y3 - 3*h3-0.4, w3, h3*2, "RankList"))
	    {
			selectedLabel = "Ranking List";
			if(inputrank==0){
				inputranking();
				insert(head,ptrnew);
				inputrank=1;
			}
			ClearFirstMenu();
			ShowSecondMenu(6);
			show_secondmenu[5]=0;
			display();
		}
		
		if (button(GenUIID(0), x3 -0.05, y3 - 9 * h3-0.1, w3, h3*2, "Return Main Menu")) {
			ptrnew=(RANK*)malloc(size);
			selectedLabel = "Return Main Menu";
			show_secondmenu[6] = 0;
			show_secondmenu[5]=0;
			show_button=1;
			
			in_Game=0;
			in_menu=1;
			show_textbook=1;
			display();
			nScore=0;      //游戏数据清零 
			level=0;
		    for (ii = 0; ii < HEIGHT; ii++) { 
	    	    for (jj = 0; jj < WIDTH; jj++) {
		            background[ii][jj]=0;
	        	}
			} 
		}
		
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
        }//绘制gameover标题 
    	MovePen( x3 , y3+0.5 ); 
    	SetPointSize(70);
    	DrawTextString("GameOver");
    	MovePen( x3 -0.05, y3+0.5 ); 
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
    	DrawTextString("GameOver");
    	
    	char TheScore[100]={"0"};
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
        }  //最终得分 
    	MovePen(x3+0.5 , y3-0.3); 
    	SetPointSize(40);
    	DrawTextString("Score");
    	MovePen(x3 +0.5-0.03, y3-0.3); 
    	switch(times%3){
			case 0:
                SetPenColor("PunkPink");
                break;
            case 1:
            	SetPenColor("TraYellow");
            	break;
            case 2:
            	SetPenColor("Ahawhite");
            	break;
        }
    	DrawTextString("Score");
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
    	MovePen(x3+2.5 , y3-0.3); 
     	DrawTextString(itoa(nScore, TheScore, 10));    

	}

}

// 文本编辑演示程序
/*
函数原型：void drawEditText()
功能描述；绘制文本框 
参数描述：无 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：无
*/
void drawEditText()
{

	static char results[60] = "";
	static char results2[40] = "";
	static char memo[80] = "Please Input Your Name";
	double fH = GetFontHeight();
	double h = fH * 5; // 控件高度
	double w = winwidth / 4*1.5; // 控件宽度
	double x = winwidth*0.55;
	double y = winheight / 2 ;


    SetPointSize(25);
    switch(times%3){
			case 0:
                SetPenColor("PunkPink");
                break;
            case 1:
            	SetPenColor("TraGold");
            	break;
            case 2:
            	SetPenColor("AhaWhite");
            	break;
        }
	if (show_textbook && in_menu) {
		y -= h * 1.2;
		sprintf(ptrnew->name, "%s+%s", firstName, lastName);
		if (textbox(GenUIID(0), x, y, w, h, firstName, sizeof(firstName))){
			sprintf(results, "Your name: %s", firstName);
			sprintf(results2, "+%s", lastName);
			sprintf(ptrnew->name, "%s+%s", firstName, lastName);
		}
		
		y -= h * 1.3;
		if (textbox(GenUIID(0), x, y, w, h, lastName, sizeof(lastName))){
			sprintf(results, "Your name: %s", firstName);
			sprintf(results2, "+%s", lastName);
			sprintf(ptrnew->name, "%s+%s", firstName, lastName);
		}
		    
		drawLabel(x, y -= fH * 2, results);
		drawLabel(x+1.45, y -= fH * 2, results2);

	}
	SetPointSize(8); 

}
/*
函数原型：display()
功能描述；刷新界面 
参数描述：无 
返回值描述：无
重要局部变量定义：无
重要局部变量用途描述：无
函数算法描述：无
*/

void display()
{
		
	if(in_menu){
		// 清屏
	DisplayClear();

	
	// 绘制和处理菜单
	drawMenu();

	// 按钮
	drawButtons();


	// 编辑文本字符串
	drawEditText();

	// 将绘制的结果put到屏幕上
	//UpdateDisplay();
	
	    if(flag) {
	       in_menu=0;	
		   StartGame();
		//cancelTimer(MY_ROTATE_TIMER);
	    }
	}
	
}



