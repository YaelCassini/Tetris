#include "main.h"
void inputranking()/*读入排行榜*/
{
	
    //InitConsole(); 
    if((fp=fopen("./gamerank.txt","a+"))==NULL){
drawLabel(winwidth*0.5, winheight-5, "Can't Open RankingList");
		//printf ("failed\n");
    } //else {
    	//printf ("success\n");
//	}


	int cnt=0;
	while(!feof(fp)){

		ptr0=(RANK*)malloc(size); 
//		if(feof(fp))break;
		
	    fscanf(fp,"%d",&(ptr0->number));
	    printf ("%d\n", ptr0->number);
	    fscanf(fp,"%s",ptr0->name);
	    printf ("%s\n", ptr0->name);
        fscanf(fp,"%d",&(ptr0->grade));
        printf ("%d\n", ptr0->grade);
        ptr0->next=NULL;
        if(head==NULL){
        	head=ptr0;
        	ptr=head;
		}
		else{
			ptr->next=ptr0;
			ptr=ptr->next;
		}   
    }
    fclose(fp);
}
void printrank(RANK *head1)/*显示排行榜*/ 
{
	double fH = GetFontHeight();
	double h = fH * 3;  // 控件高度
	double w = winwidth / 5*4; // 控件宽度
	double rankx=winwidth/2-w/2;
	double ranky=winheight/6*5;
	
	int i=1;
    ptr=head1;
    SetPointSize(25);
    drawRank(rankx, ranky, w, h, 0, "RANK","NAME","GRADE");

	while(ptr!=NULL&&i<=10){
        drawRank(rankx, ranky-h*1.5*i, w, h, 0, itoa(ptr->number, TheNumber, 10),ptr->name,itoa(ptr->grade, TheGrade, 10));

        ptr=ptr->next;
        i++;
    }
    SetPointSize(8);
    
}
void drawRank(double x, double y, double w, double h, int fillflag, char *label1,char *label2,char *label3)
{
	double fa = GetFontAscent();
	// rect
	drawRectangle(x,y,w,h,fillflag);
	// text
	
	SetPointSize(25);
	MovePen(x+fa/2, y+h/2-fa/2);
	DrawTextString(label1);
	MovePen(x+w/5, y+h/2-fa/2);
	DrawTextString(label2);
	MovePen(x+w/4*3, y+h/2-fa/2);
	DrawTextString(label3);
	SetPointSize(2);

}
RANK *insert(RANK* head1,RANK* ptr0)
{
	RANK* ptr1;
	RANK* ptr2;
	
	int k=1;
	
	ptr2=head1;
	if(head1==NULL){
		head1=ptr0;
		ptr=ptr0;
		ptr->next=NULL;
		
	}
	else{
		while((ptr0->grade<=ptr2->grade)&&(ptr2->next!=NULL)){
			ptr1=ptr2;
			ptr2=ptr2->next;
			
		}
		if(ptr0->grade>ptr2->grade){
			if(head1==ptr2){
				ptr0->next=head1;
				head=ptr0;
			}
			else {
				ptr0->next=ptr2;
			    ptr1->next=ptr0;
			}
				
		}
		else{
			ptr2->next=ptr0;
			ptr0->next=NULL;
			ptr=ptr0;
		}
	}
	
    ptr1=head;
    
	while(ptr1!=NULL){
		ptr1->number=k;
		k++;
		ptr1=ptr1->next;
	}
	
	return head1;
}

void outputranking(RANK *head1)/*输出排行榜*/ 
{
    int i=1;
     
	if((fp=fopen("./gamerank.txt","w"))==NULL){
		drawLabel(winwidth*0.5, winheight-5, "Can't Open RankingList");
    }
        ptr=head1;
   //     InitConsole(); 
	while(ptr!=NULL&&i<=10){
  //      printf("%d\n",ptr->number);
    //	printf("%s\n",ptr->name);
      //  printf("%d\n",ptr->grade);
        
        fprintf(fp,"%d\n",ptr->number);
    	fprintf(fp,"%s\n",ptr->name);
    	if((ptr->next==NULL)||(i==10)){
    		fprintf(fp,"%d",ptr->grade);
		}
		else{
			fprintf(fp,"%d\n",ptr->grade);
		}
        
        ptr=ptr->next;
        i++;
    }
    fclose(fp);
}

