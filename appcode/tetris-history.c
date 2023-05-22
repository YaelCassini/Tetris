#include "main.h"

void outputhistory(char *address)
{
	int i;
	int j;
	
	char follow[10]=".txt";
	char whole[50];
	
	strcpy(whole,address);
	strcat(whole,follow);
    
	if((fp=fopen(whole,"w"))==NULL){
		drawLabel(winwidth*0.5, winheight-5, "Can't Open History");
    }
    for(i=0;i<HEIGHT;i++){
    	for(j=0;j<WIDTH;j++){
		   fprintf(fp,"%d\n",background[i][j]); 
		}
	}
	fprintf(fp,"%d\n",nScore);
	fclose(fp);
}

void inputhistory(char *address)
{
	
	char follow[10]=".txt";
	char whole[50]="";
	int i,j;
	
	strcpy(whole,address);
	strcat(whole,follow);
	if((fp=fopen(whole,"r"))==NULL){
		drawLabel(winwidth*0.5, winheight-5, "Can't Open History");
		
    }
    else{
        
    	for(i=0;i<HEIGHT;i++){
    	for(j=0;j<WIDTH;j++){
		   fscanf(fp,"%d\n",&background[i][j]);  	   
		}	
	    }
		fscanf(fp,"%d\n",&nScore);
	//	InitConsole(); 
		//printf("%d\n",nScore);
	}
    
	fclose(fp);
    
}

void ouputhistoryname()/*输出历史纪录名册*/
{
	int i=1;
    //InitConsole(); 
    if((fp=fopen("./history.txt","a+"))==NULL){
        drawLabel(winwidth*0.5, winheight-5, "Can't Open RankingList");
		//printf ("failed\n");
    } //else {
    	//printf ("success\n");
//	}
    while((!feof(fp))&&(i<5)){
        fprintf(fp,"%s",historyname[i]);	
        i++;
	}

    fclose(fp);
}

void inputhistoryname()/*读入历史纪录名册*/
{
	int i=0;
    //InitConsole(); 
    if((fp=fopen("./history.txt","r"))==NULL){
        drawLabel(winwidth*0.5, winheight-5, "Can't Open RankingList");
		//printf ("failed\n");
    } //else {
    	//printf ("success\n");
//	}
    while((!feof(fp))&&(i<5)){
        fscanf(fp,"%s",&historyname[i]);	
        i++;
	}
//	InitConsole(); 
 //	printf("%s",historyname[4]);

    fclose(fp);
}
void printhistory()
{
	double fH = GetFontHeight();
	double h = fH * 4;  // 控件高度
	double w = winwidth*0.6; // 控件宽度
	double hisx=winwidth/2-w/2;
	double hisy=winheight;
	int i=0;
	
	
	if (button(GenUIID(0), hisx, hisy-1.5*h, w, h,historyname[0])) {

	    inputhistory(historyname[i]);
	    
	    
	        in_Game=1;
			in_menu=0;
			show_secondmenu[4]=0;
			InitGameboard();
			DrawTheScreen();
			startTimer(1,200);
			display();
	} 
	if (button(GenUIID(0), hisx, hisy-3*h, w, h,historyname[1])) {

	        inputhistory(historyname[i]);
	    
	        in_Game=1;
			in_menu=0;
			show_secondmenu[4]=0;
			InitGameboard();
			DrawTheScreen();
			startTimer(1,200);
			display();
	} 
	if (button(GenUIID(0), hisx, hisy-4.5*h, w, h,historyname[2])) {
		inputhistory(historyname[i]);
	    
	        in_Game=1;
			in_menu=0;
			show_secondmenu[4]=0;
			InitGameboard();
			DrawTheScreen();
			startTimer(1,200);
			display();
	} 
	if (button(GenUIID(0), hisx, hisy-6*h, w, h,historyname[3])) {
	    inputhistory(historyname[i]);
	    
	        in_Game=1;
			in_menu=0;
			show_secondmenu[4]=0;
			InitGameboard();
			DrawTheScreen();
			startTimer(1,200);
			display();
	} 
	if (button(GenUIID(0), hisx, hisy-7.5*h, w, h,historyname[4])) {
		inputhistory(historyname[i]);
	    
	        in_Game=1;
			in_menu=0;
			show_secondmenu[4]=0;
			InitGameboard();
			DrawTheScreen();
			startTimer(1,200);
			display();
	} 
	
/*	
	while(i<5){
		
		if (button(GenUIID(0), hisx, hisy-1.5*h, w, h,historyname[i])) {
		InitConsole(); 
	//	inputhistory(historyname[i]);
		in_menu=0;	
		StartGame();
	}
	}*/

	
}
