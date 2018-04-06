#include"D:\ashu\library_management_in_c\edit.c"
void booksec(){
	//loaderanim();
	system("cls");
	gotoxy(25,3);
	printf("BOOK SECTION");
	gotoxy(20,5);
	printf("1. Add book ");
	gotoxy(20,7);
	printf("2. Delete books ");
	gotoxy(20,9);
	printf("3. Search books ");
	gotoxy(20,11);
	printf("4. View book list ");
	gotoxy(20,13);
	printf("5. Edit books record ");
	gotoxy(20,15);
	printf("6. Back to main menu");
	gotoxy(20,17);
	t();
	gotoxy(20,21);
	printf("Enter your choice:");
	switch(getch()){
		case '1':addbooks();break;
		case '2':deletebook();break;
		case '3':searchbook();break;
		case '4':viewbook();break;
		case '5':editbooks();break;
		case '6':mainmenu();break;
		default:{
			gotoxy(10,23);
			printf("Wrong Entry !! please re-entered correct option");
			if(getch()){booksec();}
			}
		}
}
