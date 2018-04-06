#include"D:\ashu\library_management_in_c\getsdata.c"
void addstudent(){
	system("cls");
	int i;
	gotoxy(20,5);
	printf("SELECT CATEGERIES ");
	gotoxy(20,7);
	printf("1. COMPUTER SCIENCE");
	gotoxy(20,9);
	printf("2. INFORMATION TECHNOLOGY");
	gotoxy(20,11);
	printf("3. ELECTRONICCS ");
	gotoxy(20,13);
	printf("4. MECHANICAL ");
	gotoxy(20,15);
	printf("5. ELECTRICAL ");
	gotoxy(20,17);
	printf("6. AUTOMOBILE ");
	gotoxy(20,19);
	printf("7. Back to Student section");
	gotoxy(20,22);
	printf("Enter your choice: ");
	scanf("%d",&i);
	if(i==7){
		addst();
		}
	system("cls");
	fs=fopen("strecord.dat","ab+");
	if(getsdata(i)==1){
		s1.sbranch=branch[i-1];
		fseek(fs,0,SEEK_END);
		fwrite(&s1,sizeof(s1),1,fs);
		fclose(fs);
		system("cls");
		gotoxy(21,14);
		printf("The record is successfully saved");
		gotoxy(21,16);
		printf("Add any more?(y/n) :");
		if(getch()=='n'){
			mainmenu();
			}
		else{
			system("cls");
			addstudent();
			}
		}
	}
