#include "main.h"

void Main()
{
	// ��ʼ�����ں�ͼ��ϵͳ
	SetWindowTitle("Tetris");
	//SetWindowSize(10, 10); // ��λ - Ӣ��
	//SetWindowSize(15, 10);
	//SetWindowSize(10, 20);  // �����Ļ�ߴ粻�����򰴱�����С
	InitGraphics();
	
	// ��ô��ڳߴ�
	winwidth = GetWindowWidth();
	winheight = GetWindowHeight();

	// ע��ʱ����Ӧ����
	registerCharEvent(CharEventProcess); // �ַ�
	registerKeyboardEvent(KeyboardGameProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
	registerTimerEvent(TimerEventProcess);      // ��ʱ��

    setButtonColors("PunkBlue","PunkBlue","PunkPink","PunkPink", 0);
    setTextBoxColors("PunkPink", "PunkPink", "PunkPink", "PunkPink", 0);
    SetPenSize(1);
	// ������ʱ��
//	startTimer(MY_ROTATE_TIMER, 50);

    inputranking();
    inputrank=1;
	ptrnew=(RANK*)malloc(size);
	
	inputhistoryname();
	//InitConsole(); 
	//printf("%s",historyname[0]);
	// �򿪿���̨���������������Ϣ�����ڵ���
	// InitConsole(); 
	int n;
	Randomize();/*���������ʼ��*/
	n = RandomBlock();

}
