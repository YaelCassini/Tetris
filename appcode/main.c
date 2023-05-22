#include "main.h"

void Main()
{
	// 初始化窗口和图形系统
	SetWindowTitle("Tetris");
	//SetWindowSize(10, 10); // 单位 - 英寸
	//SetWindowSize(15, 10);
	//SetWindowSize(10, 20);  // 如果屏幕尺寸不够，则按比例缩小
	InitGraphics();
	
	// 获得窗口尺寸
	winwidth = GetWindowWidth();
	winheight = GetWindowHeight();

	// 注册时间响应函数
	registerCharEvent(CharEventProcess); // 字符
	registerKeyboardEvent(KeyboardGameProcess);// 键盘
	registerMouseEvent(MouseEventProcess);      // 鼠标
	registerTimerEvent(TimerEventProcess);      // 定时器

    setButtonColors("PunkBlue","PunkBlue","PunkPink","PunkPink", 0);
    setTextBoxColors("PunkPink", "PunkPink", "PunkPink", "PunkPink", 0);
    SetPenSize(1);
	// 开启定时器
//	startTimer(MY_ROTATE_TIMER, 50);

    inputranking();
    inputrank=1;
	ptrnew=(RANK*)malloc(size);
	
	inputhistoryname();
	//InitConsole(); 
	//printf("%s",historyname[0]);
	// 打开控制台，方便输出变量信息，便于调试
	// InitConsole(); 
	int n;
	Randomize();/*随机函数初始化*/
	n = RandomBlock();

}
