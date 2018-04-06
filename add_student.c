#include"D:\ashu\library_management_in_c\view_student.c"
void addst(){
	system("cls");
	gotoxy(25,5);
	printf("Student section");
	gotoxy(20,8);
	printf("1.Add student record");
	gotoxy(20,10);
	printf("2.Delete student record");
	gotoxy(20,12);
	printf("3.Search student record");
	gotoxy(20,14);
	printf("4.view student record");
	gotoxy(20,16);
	printf("5.Back to main menu");
	gotoxy(20,18);
	printf("Enter your choice");
	fflush(stdin);
	switch(getch()){
		case '1':addstudent();break;
		case '2':{
		system("cls");
		int d;
		char another = 'y';
		while(another == 'y'){
			system("cls");
			findst='f';
			gotoxy(20,5);
			printf("Enter rollno : ");
			scanf("%d",&d);
			fs=fopen("strecord.dat","rb+");
			rewind(fs);
			while(fread(&s1,sizeof(s1),1,fs)==1){
				if(s1.rollno==d){
					gotoxy(20,9);
					printf("The student is in record	");
					gotoxy(20,11);
					printf("name is %s",s1.sname);
					gotoxy(20,13);
					printf("branch is %s",s1.sbranch);
					gotoxy(20,15);
					printf("batch is %d",s1.batch);
					findst='t';
					}
				}
			if(findst!='t'){
				gotoxy(20,15);
				printf("No record found modify the search");
				getch();
				addst();
				}
			if(findst=='t'){
				gotoxy(20,17);
				printf("do you want to delete it?(y/n)");
				if(getch()=='y'){
					ft=fopen("strecord1.dat","wb+");
					rewind(fs);
					while(fread(&s1,sizeof(s1),1,fs)==1){
						if(s1.rollno!=d){
							fseek(ft,0,SEEK_CUR);
							fwrite(&s1,sizeof(s1),1,ft);
							}
						}
					fclose(ft);
					fclose(fs);
					remove("strecord.dat");
					rename("strecord1.dat","strecord.dat");
					fs = fopen("strecord.dat","rb+");
					if(findst=='t'){
						system("cls");
						gotoxy(20,15);
						printf("The record is successfully deleted");
						gotoxy(20,17);
						printf("Delete another record?(y/n)");
						}
					fclose(fs);
					}
			else{addst();}
			fflush(stdin);
			another=getch();
			}
		}
		gotoxy(10,21);
		mainmenu();
			}break;
		case '3':{
			char another='y';
			while(another=='y'){
			int rn;
			system("cls");
			char findst='f';
			gotoxy(25,6);
			printf("Search Student");
			gotoxy(20,9);
			printf("Enter the roll no:");
			scanf("%d",&rn);
			gotoxy(20,11);
			fs=fopen("strecord.dat","rb+");
			sh();
			rewind(fs);
			while(fread(&s1,sizeof(s1),1,fs)==1){
				if(s1.rollno==rn){
					system("cls");
					gotoxy(25,6);
					printf("Search Student");
					gotoxy(20,8);
					printf("The Student is in record.");
					gotoxy(20,10);
					printf("Roll no. : %d",s1.rollno);
					gotoxy(20,12);
					printf("name is %s",s1.sname);
					gotoxy(20,14);
					printf("branch is %s",s1.sbranch);
					gotoxy(20,16);
					printf("batch is %d",s1.batch);
					findst='t';
					}
				}
				if(findst!='t'){
					system("cls");
					gotoxy(20,16);
					printf("No record found");
				}
					gotoxy(20,18);
				printf("Try another search?(y/n)");
				another=getch();
				}
				fclose(fs);
				mainmenu();
			}break;
		case '4':viewst();break;
		case '5':{
			mainmenu();
			}break;
		default:{
			gotoxy(10,26);
			printf("Wrong Entry !! please re-entered correct option");
			getch();
			addst();
			}
			
		}
	}
