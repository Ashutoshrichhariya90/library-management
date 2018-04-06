#include"D:\ashu\library_management_in_c\issue_a_book.c"
void viewissue(){
	system("cls");
	fi=fopen("issue.dat","rb");
	int q=7;
	gotoxy(25,2);
	printf("Issued book list");
	issuerecord(&q);
		gotoxy(5,q+4);
		printf("Total record : %d",q-7);
		fclose(fi);
		gotoxy(5,q+8);
		returnfunc();
	}

