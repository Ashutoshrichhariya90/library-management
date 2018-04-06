#include"D:\ashu\library_management_in_c\returnbook.c"
void issuebook(){
	system("cls");
	gotoxy(25,5);
	printf("ISSUE SECTION");
	gotoxy(20,7);
	printf("1.Issue book");
	gotoxy(20,9);
	printf("2.View issued books");
	gotoxy(20,11);
	printf("3.Search issued book");
	gotoxy(20,13);
	printf("4.return issued book");
	gotoxy(20,15);
	printf("5.Back to main menu");
	gotoxy(20,17);
	printf("Enter a choice");
	switch(getch()){
		case '1':{
			issue();
			}break;
		case '2':{
			system("cls");
			fi=fopen("issue.dat","rb");
			int q=7;
			gotoxy(25,2);
			printf("Issued book list");
			gotoxy(2,6);
			printf("STUDENT NAME	 ROLLNO.    ID    CODE     BOOK NAME    ISSUED DATE     DUE DATE     RETURN DATE	FINE");
			rewind(fi);
			while(fread(&ib,sizeof(ib),1,fi)==1){
			issuerecord(q);
			q++;
			}
			gotoxy(10,q+7);
			printf("Total record : %d",q-7);
			gotoxy(10,q+9);
			returnfunc();
			fclose(fi);
			}break;
		case '3':{
			searchissue();
			
			}break;
		case '4':{
			returnbook();
			}break;
		case '5':{
			mainmenu();
			}
		default:{
			gotoxy(10,19);
			printf("Wrong Entry !! please re-entered correct option");
			getch();
			issuebook();
			break;
			}
		}
	}
	

