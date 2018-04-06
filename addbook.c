#include"D:\ashu\library_management_in_c\getdata.c"
void booksec();
void addbooks(){
	system("cls");
	int i;
	gotoxy(20,5);
	printf("SELECT CATEGERIES ");
	gotoxy(20,7);
	printf("1. COMPUTER ");
	gotoxy(20,9);
	printf("2. ELECTRONICCS ");
	gotoxy(20,11);
	printf("3. MECHANICAL ");
	gotoxy(20,13);
	printf("4. ELECTRICAL ");
	gotoxy(20,15);
	printf("5. AUTOMOBILE ");
	gotoxy(20,17);
	printf("6. Back to book section");
	gotoxy(20,22);
	printf("Enter your choice: ");
	scanf("%d",&i);
	if(i==6){
		booksec();
		}
	system("cls");
	fa=fopen("ashu.dat","ab+");
	if(getdata(i)==1){
		a.cat=catagories[i-1];
		fseek(fa,0,SEEK_END);
		fwrite(&a,sizeof(a),1,fa);
		fclose(fa);
		system("cls");
		gotoxy(21,14);
		printf("The record is successfully saved");
		gotoxy(21,16);
		printf("save any more?(y/n) :");
		if(getch()=='n'){
			mainmenu();
			}
		else{
			system("cls");
			addbooks();
			}
		}
	}
	
