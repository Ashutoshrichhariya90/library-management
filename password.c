#include"D:\ashu\library_management_in_c\mainmenu.c"
void Password(){
	system("cls");
	char d[25]="password protected";
	char ch,pass[10];
	int i=0,j;
	gotoxy(10,4);
	for(j=0;j<20;j++){
		delay(50);
		printf("*");
		}
	for(j=0;j<20;j++){
		delay(50);
		printf("%c",d[j]);
		}
	for(j=0;j<20;j++){
		delay(50);
		printf("*");
		}
	gotoxy(10,10);
	gotoxy(15,7);
	printf("Enter Password:");
	while(ch!=13){
		ch=getch();
		if(ch!=13&&ch!=8){
			putch('*');
			pass[i]=ch;
			i++;
			}
		}
	pass[i]='\0';
	if(strcmp(pass,password)==0){
		gotoxy(15,9);
		printf("password match");
		gotoxy(15,11);
		printf("Press any key to continue......");
		getch();
		mainmenu();
		}
	else{
		gotoxy(15,12);
		printf("Warning !! Incorrect Password");
		getch();
		Password();
		}
	}
