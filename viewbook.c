#include"D:\ashu\library_management_in_c\search.c"
void viewbook(){
	int i=0,j,x,b;
	system("cls");
	gotoxy(25,2);
	printf("Book list ");
	gotoxy(2,5);
	printf("CATEGORY    CODE     BOOK NAME     AUTHOR     QTY     PRICE     RACKNO. ");
	j=7;
	fa=fopen("ashu.dat","rb");
	while(fread(&a,sizeof(a),1,fa)==1){
		gotoxy(2,j);
		printf("%s",a.cat);
		gotoxy(15,j);
		printf("%d",a.code);
		gotoxy(21,j);
		printf("%s",a.name);
		gotoxy(35,j);
		printf("%s",a.author);
		gotoxy(47,j);
		printf("%d",a.quantity);
		gotoxy(55,j);
		printf("%0.2f",a.price);
		gotoxy(65,j);
		printf("%d",a.rackno);
		j++;
		i=i+a.quantity;
		}
	gotoxy(10,j+5);
	printf("Total books = %d",i);
	gotoxy(10,j+7);
	printf("want to know book id?(y/n)");
	if(getch()=='y')
	{	gotoxy(10,j+9);
	    printf("enter book code from the above:");
	    scanf("%d",&b);
	    if(checkacode(b)==0)
	    {
			rewind(fa);
			while(fread(&a,sizeof(a),1,fa)==1)
			{
				if(a.code==b)
				{
					system("cls");
					gotoxy(20,5);
					printf("book code:%d",a.code);
					
					for(x=0;x<a.quantity;x++)
					{	gotoxy(20,x+7);
						printf("book id of book %d : %d",x+1,a.id[x]);
					}
				}
			}
			fclose(fa);
			gotoxy(20,x+10);
			returnfunc();
		}
			else
			{	gotoxy(10,j+11);
				printf("book with this code not available");
			}
			
				
	}
	fclose(fa);
	gotoxy(10,j+13);
	returnfunc();
	}

