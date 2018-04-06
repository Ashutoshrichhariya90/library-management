#include<stdio.h>
#define RETURNTIME 2;
char catagories[][15]={"computer","electronics","mechanical","electrical","automobile"};
char branch[][25]={"computer science","information technology","electronics","mechanical","electrical","automobile"};
FILE *fa,*ft,*fi,*fs;


char findbook;
char findst;
char password[10]={"zoozoozoo"};
struct student{
	int rollno;
	char sname[20];
	char *sbranch;
	int batch;
	};
struct student s1;
struct merodate{
	int mm,dd,yy;
	};
struct books{
	int s;
	
	int code;
	char name[20];
	char author[20];
	int quantity;
	float price;
	int count;
	int rackno;
	char *cat;
	int id[100];
	int lquantity;
	
	};
struct books a;
struct ibook{
	struct books b;
	struct student s2;
	struct merodate issued;
	struct merodate duedate;
	struct merodate rdate;
	int fine;
	//int tfine;
	int bid;
	};
struct ibook ib;

