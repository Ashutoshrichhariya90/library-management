#include"D:\ashu\library_management_in_c\strecord.c"
void viewst(){
	int j;
	system("cls");
	gotoxy(25,1);
	printf("Student list ");
	gotoxy(2,2);
	printf("BRANCH    		    ROLLNO      NAME          BATCH  ");
	j=4;
	fs=fopen("strecord.dat","rb");
	while(fread(&s1,sizeof(s1),1,fs)==1){
		gotoxy(2,j);
		printf("%s",s1.sbranch);
		gotoxy(30,j);
		printf("%d",s1.rollno);
		gotoxy(40,j);
		printf("%s",s1.sname);
		gotoxy(55,j);
		printf("%d",s1.batch);
		j++;
		}
	gotoxy(3,j+5);
	printf("Total students = %d",j-4);
	fclose(fs);
	gotoxy(3,j+7);
	returnfunc();
}
