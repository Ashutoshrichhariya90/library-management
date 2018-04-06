#include"D:\ashu\library_management_in_c\viewbook.c"
void editbooks(){
	int d;
	char another = 'y';
	while(another=='y'){
		system("cls");
		gotoxy(30,4);
		printf("Edit book section");
		gotoxy(20,6);
		printf("Enter books code to be edited :");
		scanf("%d",&d);
		fa=fopen("ashu.dat","rb+");
		while(fread(&a,sizeof(a),1,fa)==1){
			if(checkacode(d)==0){
				gotoxy(20,8);
				printf("The book is available");
				gotoxy(20,10);
				printf("The book code:%d",a.code);
				gotoxy(20,12);
				printf("Enter new name:");
				scanf("%s",a.name);
				gotoxy(20,14);
				printf("Enter new Author:");
				scanf("%s",a.author);
				gotoxy(20,16);
				printf("Enter new quantity:");
				scanf("%d",&a.quantity);
				gotoxy(20,18);
				printf("Enter new price:");
				scanf("%f",&a.price);
				gotoxy(20,20);
				printf("Enter new rackno:");
				scanf("%d",&a.rackno);
				a.lquantity=a.quantity;
				system("cls");
				int m;
				gotoxy(20,6);
				printf("Enter book id");
				for(m=0;m<a.quantity;m++){
					gotoxy(20,m+8);
					printf("New Book id of book %d :",m+1);
					scanf("%d",&a.id[m]);
					}
				fseek(fa,ftell(fa)-sizeof(a),0);
				fwrite(&a,sizeof(a),1,fa);
				fclose(fa);
				}
			else{
				gotoxy(20,10);
				printf("No record found! ");
				getch();
				booksec();
				}
				
			}
		system("cls");
		gotoxy(20,15);
		printf("Modify another Record?(y/n)");
		fflush(stdin);
		another=getch();
		}
		gotoxy(15,18);
		mainmenu();
	}
