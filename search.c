#include"D:\ashu\library_management_in_c\delete.c"
void searchbook(){
	system("cls");
	int d,bc;
	gotoxy(40,6);
	printf("Search book");
	gotoxy(20,10);
	printf("1. Search by CODE");
	gotoxy(20,12);
	printf("2. Search by bookID");
	gotoxy(20,14);
	printf("3. Back to book section");
	gotoxy(20,20);
	printf("Enter your choice ");
	fa=fopen("ashu.dat","rb+");
	rewind(fa);
	switch(getch()){
		case '1':{
			system("cls");
			findbook='f';
			gotoxy(25,4);
			printf("Search book by code");
			gotoxy(20,6);
			printf("Enter the book code:");
			scanf("%d",&bc);
			gotoxy(20,8);
			sh();
			while(fread(&a,sizeof(a),1,fa)==1){
				if(a.code==bc){
					system("cls");
					gotoxy(25,4);
					printf("Search book by code");
					gotoxy(20,6);
					printf("The book is available.");
					gotoxy(20,8);
					printf("Category : %s",a.cat);
					gotoxy(20,10);
					printf("code: %d",a.code);
					gotoxy(20,12);
					printf("Name: %s",a.name);
					gotoxy(20,14);
					printf("Author: %s",a.author);
					gotoxy(20,16);
					printf("Quantity: %d",a.quantity);
					gotoxy(20,18);
					printf("Price: Rs.%0.2f",a.price);
					gotoxy(20,20);
					printf("Rack number: %d",a.rackno);
					findbook='t';
					}
				}
				if(findbook!='t'){
					system("cls");
					gotoxy(20,15);
					printf("No record found");
					gotoxy(20,17);
				printf("Try another search?(y/n)");
				if(getch()=='y'){searchbook();}
				else{mainmenu();}
				}
				gotoxy(20,22);
				printf("Try another search?(y/n)");
				if(getch()=='y'){searchbook();}
				else{mainmenu();}
				}break;
		case '2':{
			system("cls");
			findbook='f';
			gotoxy(25,4);
			printf("Search book by ID");
			gotoxy(20,6);
			printf("Enter the book id:");
			scanf("%d",&d);
			gotoxy(20,8);
			//printf("searching");
			sh();
			while(fread(&a,sizeof(a),1,fa)==1){
				int c;
				for(c=0;c<a.quantity;c++){
					if(*(a.id+c)==d){
						system("cls");
						gotoxy(25,4);
						printf("Search book by ID");
						gotoxy(20,6);
						printf("The book is available.");
						gotoxy(20,8);
						printf("Book id : %d",*(a.id+c));
						gotoxy(20,10);
						printf("Category : %s",a.cat);
						gotoxy(20,12);
						printf("code: %d",a.code);
						gotoxy(20,14);
						printf("Name: %s",a.name);
						gotoxy(20,16);
						printf("Author: %s",a.author);
						gotoxy(20,18);
						printf("Price: Rs.%0.2f",a.price);
						gotoxy(20,20);
						printf("Rack number: %d",a.rackno);
						findbook='t';
						
						}
					}
				}
				if(findbook!='t'){
					system("cls");
					gotoxy(20,15);
					printf("No record found");
					gotoxy(20,17);
				printf("Try another search?(y/n)");
				if(getch()=='y'){searchbook();}
				else{mainmenu();}
				}
				gotoxy(20,22);
				printf("Try another search?(y/n)");
				if(getch()=='y'){searchbook();}
				else{mainmenu();}
				
					
				
			}break;
			
			case '3':{booksec();}break;
			default :{ 
				gotoxy(20,22);
				printf("Wrong Entry !! please re-entered correct option");
				getch();
			
				searchbook();
				}
		}
		fclose(fa);
	}
	
