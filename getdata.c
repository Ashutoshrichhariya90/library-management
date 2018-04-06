#include"D:\ashu\library_management_in_c\gotoxy.c"
int getdata(int i){
	int t;
	gotoxy(20,3);
	printf("Enter the information below ");
	gotoxy(20,5);
	printf("Category : ");
	printf("%s",catagories[i-1]);
	gotoxy(20,7);
	printf("Book code : ");
	scanf("%d",&t);
	if(checkacode(t)==0){
		gotoxy(20,13);
		printf("The book code already exists");
		getch();
		mainmenu();
		return 0;
		}
	a.code=t;
	gotoxy(20,9);
	printf("Book name: ");
	scanf("%s",a.name);
	gotoxy(20,11);
	printf("Author : ");
	scanf("%s",a.author);
	gotoxy(20,13);
	printf("Quantity : ");
	scanf("%d",&a.quantity);
	a.lquantity=a.quantity;
	gotoxy(20,15);
	printf("Price : ");
	scanf("%f",&a.price);
	gotoxy(20,17);
	printf("Rack number : ");
	scanf("%d",&a.rackno);
	a.s=0;
	system("cls");
	int m;
	gotoxy(20,6);
	printf("Enter book id");
	for(m=0;m<a.quantity;m++){
		gotoxy(20,m+10);
		printf("Book id of book %d :",m+1);
		scanf("%d",&a.id[m]);
		}
	return 1;
	}
