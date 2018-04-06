#include"D:\ashu\library_management_in_c\issue.c"
void addst();
int getsdata(int i){
	int t;
	gotoxy(20,3);
	printf("Enter the information below ");
	gotoxy(20,5);
	printf("Branch : ");
	printf("%s",branch[i-1]);
	gotoxy(20,7);
	printf("Roll no. : ");
	scanf("%d",&t);
	if(checkst(t)==0){
		gotoxy(20,13);
		printf("The student details in record");
		getch();
		addst();
		return 0;
		}
	s1.rollno=t;
	gotoxy(20,9);
	printf("Student name: ");
	scanf("%s",s1.sname);
	gotoxy(20,11);
	printf("Batch: ");
	scanf("%d",&s1.batch);
	return 1;
	}

