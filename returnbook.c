#include"D:\ashu\library_management_in_c\searchissue.c"
void returnbook(){
	system("cls");
	int bi,rn;
	char another = 'y';
	while(another=='y'){
		system("cls");
		int c=0;
		gotoxy(25,4);
		printf("Return book");
		gotoxy(20,8);
		printf("Enter student rollno. :");
		scanf("%d",&rn);
		gotoxy(20,10);
		printf("Enter book id : ");
		scanf("%d",&bi);
		fa=fopen("ashu.dat","rb+");
		fi=fopen("issue.dat","rb+");
		fs=fopen("strecord.dat","rb");
		if(checkst(rn)==0){
			if(checkaid(bi)==0){
				if((checkireid(bi,rn)==0)){
					gotoxy(20,12);
					printf("The book record is available");
					gotoxy(20,14);
					printf("The name of the book is %s",ib.b.name);
					gotoxy(20,16);
					printf("Student name : %s",ib.s2.sname);
					gotoxy(20,18);
					printf("Branch : %s",ib.s2.sbranch);
					gotoxy(20,20);
					printf("Batch : %d",ib.s2.batch);
					gotoxy(20,22);
					printf("Category : %s",ib.b.cat);
					gotoxy(20,24);
					//free(&ib.rdate);
					
					printf("Issue date : %d-%d-%d",ib.issued.dd,ib.issued.mm,ib.issued.yy);
					gotoxy(20,26);
					printf("Due date :%d-%d-%d",ib.duedate.dd,ib.duedate.mm,ib.duedate.yy);
					gotoxy(20,28);
					int f;
					f=gettfine(rn,ib.duedate);
					ib.fine=f;
					printf("Fine : %d",f);
					if(f!=0){
						gotoxy(60,28);
						printf("Clear fine(y/n):");
						if(getch()=='n'){mainmenu();}
						}
					gotoxy(20,30);
					getdate(&ib.rdate);
					printf("Return date :%d-%d-%d",ib.rdate.dd,ib.rdate.mm,ib.rdate.yy);
					gotoxy(20,32);
					printf("Book returned");
					fseek(fi,ftell(fi)-sizeof(ib),0);
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
					}fclose(fa);
					}
				}
					gotoxy(20,34);
					printf("Return any more?(y/n):");
					fflush(stdin);
					if(getch()=='n'){mainmenu();}
					}
			else{
			gotoxy(20,12);
			printf("No record found");
			gotoxy(20,14);
			printf("Return any more?(y/n):");
			fflush(stdin);
			if(getch()=='n'){mainmenu();}
			}
		}
		else{
			gotoxy(20,12);
			printf("invalid book id");
			gotoxy(20,14);
			printf("Return any more?(y/n):");
			fflush(stdin);
			if(getch()=='n'){mainmenu();}
			}
		}
		else{
			gotoxy(20,12);
			printf("invalid roll no.");
			gotoxy(20,14);
			printf("Return any more?(y/n):");
			fflush(stdin);
			if(getch()=='n'){mainmenu();}
			}
		
		
		fclose(fa);
		fclose(fs);
		fclose(fi);
		}
	}
