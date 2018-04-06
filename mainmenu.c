#include"D:\ashu\library_management_in_c\add_student.c"
void mainmenu(){
	loaderanim();
	system("cls");
	gotoxy(25,3);
	printf("MAIN MENU");
	gotoxy(20,5);
	printf("1.Book section ");
	gotoxy(20,7);
	printf("2.Issue section ");
	gotoxy(20,9);
	printf("3.Student section.");
	gotoxy(20,11);
	printf("4.Close application ");
	gotoxy(20,13);
	t();
	gotoxy(20,15);
	printf("Enter your choice:");
	switch(getch()){
		case '1':booksec();break;
		case '2':issuebook();break;
		case '3':addst();break;
		case '4':{
			system("cls");
			gotoxy(16,3);
			printf("programmer......");
			gotoxy(16,5);
			printf("1. Ashutosh Richhariya");
			gotoxy(16,7);
			printf("mobile : 9407848061 Email-ashutosh.richhariya.90@gmail.com");
			gotoxy(10,10);
			printf("Exiting in 3 seconds......>");
			delay(3000);
			exit(0);
			}
		default:{
			gotoxy(10,23);
			printf("Wrong Entry !! please re-entered correct option");
			if(getch()){mainmenu();}
			}
		}
}
