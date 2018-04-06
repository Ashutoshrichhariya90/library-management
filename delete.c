#include"D:\ashu\library_management_in_c\addbook.c"
void deletebook(){
	system("cls");
	gotoxy(25,4);
	printf("Delete section");
	gotoxy(20,10);
	printf("1.Delete by book code.");
	gotoxy(20,12);
	printf("2.Delete by book id.");
	gotoxy(20,14);
	printf("3.Return to Book section.");
	gotoxy(20,18);
	printf("Enter your choice :");
	switch(getch()){
		case '1':{
		system("cls");
		int d;
		char another = 'y';
		while(another == 'y'){
			system("cls");
			findbook='f';
			gotoxy(20,5);
			printf("Enter book code to delete : ");
			scanf("%d",&d);
			fa=fopen("ashu.dat","rb+");
			rewind(fa);
			while(fread(&a,sizeof(a),1,fa)==1){
				if(a.code==d){
					gotoxy(20,9);
					printf("The book is available in record	");
					gotoxy(20,11);
					printf("Book name is %s",a.name);
					gotoxy(20,13);
					printf("Rack number is %d",a.rackno);
					findbook='t';
					}
				}
			if(findbook!='t'){
				gotoxy(20,15);
				printf("No record found modify the search");
				getch();
				deletebook();
				}
			if(findbook=='t'){
				gotoxy(20,15);
				printf("do you want to delete it?(y/n)");
				if(getch()=='y'){
					ft=fopen("ashu1.dat","wb+");
					rewind(fa);
					while(fread(&a,sizeof(a),1,fa)==1){
						if(a.code!=d){
							fseek(ft,0,SEEK_CUR);
							fwrite(&a,sizeof(a),1,ft);
							}
						}
					fclose(ft);
					fclose(fa);
					remove("ashu.dat");
					rename("ashu1.dat","ashu.dat");
					fa = fopen("ashu.dat","rb+");
					if(findbook=='t'){
						system("cls");
						gotoxy(20,15);
						printf("The record is successfully deleted");
						gotoxy(20,17);
						printf("Delete another record?(y/n)");
						}
					}
			else{deletebook();}
			fflush(stdin);
			another=getch();
			}
		}
		gotoxy(10,21);
		mainmenu();
	}break;
	case '2':{
		system("cls");
		int d,c;
		char another = 'y';
		while(another == 'y'){
			system("cls");
			findbook='f';
			gotoxy(20,5);
			printf("Enter book ID to delete : ");
			scanf("%d",&d);
			fa=fopen("ashu.dat","rb+");
			rewind(fa);
			while(fread(&a,sizeof(a),1,fa)==1){
				for(c=0;c<a.quantity;c++){
					if(*(a.id+c)==d){
						gotoxy(20,9);
						printf("The book is available in record	");
						gotoxy(20,11);
						printf("Book name is %s",a.name);
						gotoxy(20,13);
						printf("Rack number is %d",a.rackno);
						findbook='t';
						}
					}
				}
			if(findbook!='t'){
				gotoxy(20,15);
				printf("No record found modify the search");
				getch();
				deletebook();
				}
			if(findbook=='t'){
				gotoxy(20,15);
				printf("do you want to delete it?(y/n)");
				if(getch()=='y'){
					ft=fopen("ashu1.dat","rb+");
					rewind(fa);
					while(fread(&a,sizeof(a),1,fa)==1){
						for(c=0;c<a.quantity;c++){
							if(a.id[c]==d){
								int x;
								for(x=c;x<a.quantity-1;x++){
									
									
									a.id[x]=a.id[x+1];
									}	
								a.quantity=a.quantity-1;
								a.lquantity=a.lquantity-1;
								
								}
							}
						}
					fseek(fa,ftell(fa)-sizeof(a),0);
								fwrite(&a,sizeof(a),1,fa);	
					fclose(ft);
					fclose(fa);
					//remove("ashu.dat");
					//rename("ashu1.dat","ashu.dat");
					fa = fopen("ashu.dat","rb+");
					if(findbook=='t'){
						system("cls");
						gotoxy(20,15);
						printf("The record is successfully deleted");
						gotoxy(20,17);
						printf("Delete another record?(y/n)");
						}
				}	
			else{deletebook();}
			fflush(stdin);
			another=getch();
			}
		}
		
		gotoxy(10,21);
		mainmenu();
		}break;
	case '3':{
		booksec();
		}
	default:{
		gotoxy(20,20);
		printf("Wrong Entry !! please re-entered correct option");
		getch();
		deletebook();
		}break;}
}

