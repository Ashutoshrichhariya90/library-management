#include"D:\ashu\library_management_in_c\issue_a_book.c"
void searchissue(){
	system("cls");
	int d,bi,f=0;
	gotoxy(40,2);
	printf("Search issue record");
	gotoxy(20,10);
	printf("1. Search by book id");
	gotoxy(20,12);
	printf("2. Search by book code");
	gotoxy(20,14);
	printf("3. Search by student Rollno.");
	gotoxy(20,16);
	printf("4. Search by date");
	gotoxy(20,18);
	printf("5. Back to issue section");
	gotoxy(20,20);
	printf("Enter your choice ");
	fi=fopen("issue.dat","rb+");
	fa=fopen("ashu.dat","rb+");
	fs=fopen("strecord.dat","rb+");
	switch(getch()){
		case '1':{
			system("cls");
			int q=12;
			gotoxy(25,4);
			printf("Search book by id");
			gotoxy(20,6);
			printf("Enter the book id:");
			scanf("%d",&bi);
			gotoxy(20,8);
			sh();
			system("cls");
			if(checkaid(bi)==0){
				if(checkiid(bi)==0){
			gotoxy(20,6);
			printf("book id : %d",bi);
			gotoxy(2,10);
			printf("STUDENT NAME	 ROLLNO.    ID    CODE     BOOK NAME    ISSUED DATE     DUE DATE     RETURN DATE	FINE");
			rewind(fi);
			while(fread(&ib,sizeof(ib),1,fi)==1){
				if(ib.bid==bi){
					issuerecord(q);
					q++;
					}
				}
			}
				else{
					gotoxy(20,q+4);
					printf("No record found");
				}
			}
			else{
				gotoxy(20,q+4);
				printf("Invalid book id");
				}
				gotoxy(20,q+6);
				printf("Try another search?(y/n)");
				if(getch()=='y'){searchissue();}
				else{mainmenu();}
				}break;
		case '2':{
			system("cls");
			findbook='f';
			int q=12;
			gotoxy(25,4);
			printf("Search book by code");
			gotoxy(20,6);
			printf("Enter the book code:");
			scanf("%d",&d);
			gotoxy(20,8);
			sh();
			system("cls");
			if(checkacode(d)==0){
				if(checkicode(d)==0){
			gotoxy(20,6);
			printf("book  code: %d",d);
			gotoxy(2,10);
			printf("STUDENT NAME	 ROLLNO.    ID    CODE     BOOK NAME    ISSUED DATE     DUE DATE     RETURN DATE	FINE");
			rewind(fi);
			while(fread(&ib,sizeof(ib),1,fi)==1){
				if(ib.b.code==d){
					issuerecord(q);
					q++;
					findbook='t';
					}
				}
			}
				else{
					gotoxy(20,q+4);
					printf("No record found");
				}
			}
			else{
				gotoxy(20,q+4);
				printf("Invalid book code");
				}
				gotoxy(20,q+6);
				printf("Try another search?(y/n)");
				if(getch()=='y'){searchissue();}
				else{mainmenu();}
				
					
				
			}break;
			case '3':{
			system("cls");
			int q=12;
			gotoxy(25,4);
			printf("Search book by student rollno.");
			gotoxy(20,6);
			printf("Enter the student rollno.:");
			scanf("%d",&d);
			gotoxy(20,8);
			sh();
			system("cls");
			if(checkst(d)==0){
				if(checkist(d)==0){
			gotoxy(20,6);
			printf("Roll no. : %d",d);
			gotoxy(2,10);
			printf("STUDENT NAME	 ROLLNO.    ID    CODE     BOOK NAME    ISSUED DATE     DUE DATE     RETURN DATE	FINE");
			rewind(fi);
			while(fread(&ib,sizeof(ib),1,fi)==1){
				if(ib.s2.rollno==d){
					issuerecord(q);
					if(ib.rdate.dd==0){f=f+getfine(ib.duedate);}
					q++;
					}
				}
				gotoxy(20,q+4);
				printf("Total fine due: %d",f);
			}
				else{
					gotoxy(20,q+4);
					printf("No record found");
				}
			}
		else{
				gotoxy(20,q+4);
				printf("Invalid book Rollno");
				}
				
				gotoxy(20,q+6);
				printf("Try another search?(y/n)");
				if(getch()=='y'){searchissue();}
				else{mainmenu();}
				
					
				
			}break;
			case '4':{
				system("cls");
				findbook='f';
				int q=12;
				struct merodate m;
				gotoxy(25,4);
				printf("Search book by issue date");
				gotoxy(20,6);
				printf("Enter the issue date:");
				scanf("%d %d %d",&m.dd,&m.mm,&m.yy);
				gotoxy(20,8);
				sh();
				system("cls");
				if(checkdate(m)==0){
				rewind(fi);
				while(fread(&ib,sizeof(ib),1,fi)==1){
					if((ib.issued.dd==m.dd)&&(ib.issued.mm==m.mm)&&(ib.issued.yy==m.yy)){
					gotoxy(20,6);
					printf("book code : %d-%d-%d",m.dd,m.mm,m.yy);
					gotoxy(2,10);
					printf("STUDENT NAME	 ROLLNO.    ID    CODE     BOOK NAME    ISSUED DATE     DUE DATE     RETURN DATE	FINE");
					issuerecord(q);
					q++;
					findbook='t';
					}
				}
				if(findbook!='t'){
					gotoxy(20,q+4);
					printf("No record found");
				}
			}
				else{
				gotoxy(20,q+4);
				printf("Invalid date");
				}
				gotoxy(20,q+6);
				printf("Try another search?(y/n)");
				if(getch()=='y'){searchissue();}
				else{mainmenu();}
				
					
				
			}break;
			case '5':{
				issue();
				}
			default :{
				gotoxy(20,20);
				printf("Wrong entry!");
				getch();
				searchissue();
				}
		}
		fclose(fa);
		fclose(fi);
		fclose(fs);
}
