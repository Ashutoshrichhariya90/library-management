#include"D:\ashu\library_management_in_c\book.c"
void issue(){
	system("cls");
	int bi,rn;
	char another = 'y';
	while(another=='y'){
		system("cls");
		int c=0;
		gotoxy(25,4);
		printf("Issue book ");
		gotoxy(20,8);
		printf("Enter student rollno. :");
		scanf("%d",&rn);
		gotoxy(20,10);
		printf("Enter book id : ");
		scanf("%d",&bi);
		fa=fopen("ashu.dat","rb+");
		fi=fopen("issue.dat","ab+");
		fs=fopen("strecord.dat","rb");
		if(checkst(rn)==0){
			if(checkaid(bi)==0){
				if((checkirid(bi)==1)&&(a.lquantity>0)){
				if(checkicst(a.code,rn)==1){
					gotoxy(20,12);
					printf("The book record is available");
					gotoxy(20,14);
					printf("There are %d unissued books in library",a.lquantity);
					gotoxy(20,16);
					printf("The name of the book is %s",a.name);
					gotoxy(20,18);
					printf("Student name : %s",s1.sname);
					gotoxy(20,20);
					printf("Branch : %s",s1.sbranch);
					gotoxy(20,22);
					printf("Batch : %d",s1.batch);
					s1.rollno=rn;
					ib.s2=s1;
					gotoxy(20,24);
					printf("Category : %s",a.cat);
					ib.bid=bi;
					ib.fine=0;
					gotoxy(20,26);
					getdate(&ib.issued);
					printf("Issue date : %d-%d-%d",ib.issued.dd,ib.issued.mm,ib.issued.yy);
					gotoxy(20,28);
					printf("The Book of code %d and ID %d is issued",a.code,bi);
					ib.duedate.dd=ib.issued.dd+RETURNTIME;
					ib.duedate.mm=ib.issued.mm;
					ib.duedate.yy=ib.issued.yy;
					
					if(ib.issued.mm==1||ib.issued.mm==3||ib.issued.mm==5||ib.issued.mm==7||ib.issued.mm==8||ib.issued.mm==10||ib.issued.mm==12){
						if(ib.duedate.dd>31){
							ib.duedate.mm+=ib.duedate.dd/31;
							ib.duedate.dd-=31;
							}
						}
					else if(ib.issued.mm==4||ib.issued.mm==6||ib.issued.mm==9||ib.issued.mm==11){
						if(ib.duedate.dd>30){
							ib.duedate.mm+=ib.duedate.dd/30;
							ib.duedate.dd-=30;
							}
						}
					else{
						if(ib.duedate.dd>28){
							ib.duedate.mm+=ib.duedate.dd/28;
							ib.duedate.dd-=28;
						}
					}
					if(ib.duedate.mm>12){
						ib.duedate.yy+=ib.duedate.mm/12;
						ib.duedate.mm-=12;
						}
					gotoxy(20,30);
					printf("To be return :%d-%d-%d",ib.duedate.dd,ib.duedate.mm,ib.duedate.yy);
					ib.rdate.dd=0;
					ib.rdate.mm=0;
					ib.rdate.yy=0;
					//ib.b.cat=a.cat;
					//ib.s2.sbranch=s1.sbranch;
					ib.b=a;
					fseek(fi,sizeof(ib),SEEK_END);
					fwrite(&ib,sizeof(ib),1,fi);
					fclose(fi);
					fclose(fs);
					fclose(fa);
					
					//fseek(fi,sizeof(s1),SEEK_END);
					//fwrite(&s1,sizeof(s1),1,fi);
					//
					c=1;
					if(c==1){
						fa=fopen("ashu.dat","rb+");
						rewind(fa);
						while(fread(&a,sizeof(a),1,fa)==1){
						if(checkaid(bi)==0){
						a.lquantity=a.lquantity-1;
						fseek(fa,ftell(fa)-sizeof(a),0);
						fwrite(&a,sizeof(a),1,fa);
						break;
						}fclose(fa);}
					}
					gotoxy(20,32);
					printf("Issue any more?(y/n):");
					fflush(stdin);
					if(getch()=='n'){mainmenu();}
					}
				else{
				gotoxy(20,12);
				printf("can't issue");
				gotoxy(20,14);
			printf("Issue any more?(y/n):");
			fflush(stdin);
			if(getch()=='n'){mainmenu();}
				}
			}
			else{
				gotoxy(20,12);
				printf("book is already issued...");
				gotoxy(20,14);
			printf("Issue any more?(y/n):");
			fflush(stdin);
			if(getch()=='n'){mainmenu();}
				}
			}
			else{
			gotoxy(20,12);
			printf("No record found");
			gotoxy(20,14);
			printf("Issue any more?(y/n):");
			fflush(stdin);
			if(getch()=='n'){mainmenu();}
			}
		}
		else{
			gotoxy(20,12);
			printf("invalid roll no.");
			gotoxy(20,14);
			printf("Issue any more?(y/n):");
			fflush(stdin);
			if(getch()=='n'){mainmenu();}
			}
		
		
		fclose(fa);
		fclose(fs);
		fclose(fi);
		}
	}

