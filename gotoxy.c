#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"D:\ashu\library_management_in_c\items.c"
void mainmenu();
COORD coord ={0,0};
COORD max_res,cursor_size;
void gotoxy(int x,int y){
	coord.X=x;coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	}
void returnfunc(){
	{
		printf("press Enter to return to main menu");
		}
	a:
	if(getch()==13){
		mainmenu();
		}
	else{goto a;}
	}
void delay(unsigned int mseconds){
	clock_t goal = mseconds + clock();
	while(goal>clock());
	}
void getdate(struct merodate *da  ) {
struct tm *current;
time_t timenow;
time(&timenow);
   current = localtime(&timenow);
     da->mm = current->tm_mon+1;
     da->dd = current->tm_mday;
     da->yy = current->tm_year+1900;

}
int days(struct merodate m1){
	int i,d=0;
	
	for(i=1;i<m1.mm;i++){
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
			d=d+31;
			}
		else if(i==4||i==6||i==9||i==11){
			d=d+30;
			}
		else{d=d+28;}
		}d=d+m1.dd;
	return d;
	}

int getfine(struct merodate rd){
	struct merodate m;
	int f=0;
	getdate(&m);
	if(m.yy>rd.yy){
		f=((365-days(rd))+days(m))*2;
		}
	else if(m.mm>rd.mm){
		f=(days(m)-days(rd))*2;
		}
	else if(m.dd>rd.dd){
		f=(m.dd-rd.dd)*2;
		}
	return f;
	}
int getbfine(struct merodate rd,struct merodate m){
	int f=0;
	getdate(&m);
	if(m.yy>rd.yy){
		f=((365-days(rd))+days(m))*2;
		}
	else if(m.mm>rd.mm){
		f=(days(m)-days(rd))*2;
		}
	else if(m.dd>rd.dd){
		f=(m.dd<rd.dd)*2;
		}
	return f;
	}
int gettfine(int rn,struct merodate d){
	int fin=0;
	rewind(fi);
	while(fread(&ib,sizeof(ib),1,fi)==1){
		if((ib.s2.rollno==rn)&&(ib.rdate.dd==0)){
			fin=getfine(d);
			return fin;
			}
		}
	return fin;
	}

void issuerecord(int j){
	
		gotoxy(2,j);
		printf("%s",ib.s2.sname);
		gotoxy(19,j);
		printf("%d",ib.s2.rollno);
		gotoxy(28,j);
		printf("%d",ib.bid);
		gotoxy(35,j);
		printf("%d",ib.b.code);
		gotoxy(43,j);
		printf("%s",ib.b.name);
		gotoxy(57,j);
		printf("%d-%d-%d",ib.issued.dd,ib.issued.mm,ib.issued.yy);
		gotoxy(72,j);
		printf("%d-%d-%d",ib.duedate.dd,ib.duedate.mm,ib.duedate.yy);
		if(ib.rdate.dd!=0){
		gotoxy(88,j);
		printf("%d-%d-%d",ib.rdate.dd,ib.rdate.mm,ib.rdate.yy);
		gotoxy(105,j);
		printf("%d",getbfine(ib.duedate,ib.rdate));}
		else{
			gotoxy(105,j);
			//f=f+(getfine(ib.duedate));
		printf("%d",getfine(ib.duedate));
			}
		
	}
int checkicst(int t,int q){
	rewind(fi);
	while(fread(&ib,sizeof(ib),1,fi)==1){
		if((ib.b.code==t)&&(ib.s2.rollno==q)&&(ib.rdate.dd==0)){
			return 0;
			}
		
		}
	return 1;
	}
int checkst(int t){
	rewind(fs);
	while(fread(&s1,sizeof(s1),1,fs)==1){
		if(s1.rollno==t){
			return 0;
			}
		}
	return 1;
	}
int checkirid(int t){
	rewind(fi);
	while(fread(&ib,sizeof(ib),1,fi)==1){
			if((ib.bid==t)&&(ib.rdate.dd==0)){
				return 0;
				}
		}
	return 1;
	}
int checkireid(int t,int r){
	rewind(fi);
	while(fread(&ib,sizeof(ib),1,fi)==1){
			if((ib.bid==t)&&(ib.rdate.dd==0)&&(ib.s2.rollno==r)){
				return 0;
				}
		}
	return 1;
	}
int checkiid(int t){
	rewind(fi);
	while(fread(&ib,sizeof(ib),1,fi)==1){
			if(ib.bid==t){
				return 0;
				}
		}
	return 1;
	}
int checkicode(int t){
	rewind(fi);
	while(fread(&ib,sizeof(ib),1,fi)==1){
			if(ib.b.code==t){
				return 0;
				}
		}
	return 1;
	}
int checkist(int t){
	rewind(fi);
	while(fread(&ib,sizeof(ib),1,fi)==1){
			if(ib.s2.rollno==t){
				return 0;
				}
		}
	return 1;
	}
int checkacode(int t){
	rewind(fa);
	while(fread(&a,sizeof(a),1,fa)==1){
		if(a.code==t){
			return 0;
			}
		}
	return 1;
	}
int checkaid(int t){
	rewind(fa);
	while(fread(&a,sizeof(a),1,fa)==1){
		int m;
		for(m=0;m<a.quantity;m++){
			if(a.id[m]==t){return 0;}
		}
		}
	return 1;
	}
void loaderanim(){
	int loader;
	system("cls");
	gotoxy(20,10);
	printf("loading......");
	gotoxy(22,11);
	for(loader=1;loader<20;loader++){
		delay(100);
		printf("%c",219);
		}
	}
int t(){
	time_t t;
	time(&t);
	printf("Date and time:%s\n",ctime(&t));
	return 0;
	}
void sh(){
	printf("searching");
	int x;
	for(x=0;x<10;x++){
		delay(100);
		printf(".");
		}
	}
int checkdate(struct merodate m){
	struct merodate m1;
	getdate(&m1);
	if(m.dd>0&&m.mm>0&&m.yy>0){
	if(((m.yy<m1.yy)||((m.yy==m1.yy)&&(m.mm<m1.mm))||((m.yy==m1.yy)&&(m.mm==m1.mm)&&(m.dd<=m1.dd)))&&(m.mm<13)){
		if((m.mm==1||m.mm==3||m.mm==5||m.mm==7||m.mm==8||m.mm==10||m.mm==12)&&(m.dd<=31)){
						return 0;
						}
		else if((m.mm==4||m.mm==6||m.mm==9||m.mm==11)&&(m.dd<=30)){
						return 0;
						}
		else if((m.mm==2)&&(m.dd<=28)){
						return 0;
					}
		}
	}
	return 1;
	}


