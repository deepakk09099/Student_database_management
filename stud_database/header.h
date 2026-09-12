//stud_header.h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define pf printf
typedef struct stu{
	int roll;
	char name[15];
	float marks;
	struct stu *next;
}ST;


void stud_add(ST **);
void stud_show(ST *);
void stud_save(ST *); 
void sort_with_roll(ST **);
void sort_with_name(ST **);
void sort_with_marks(ST **);
void reverseList(ST **);
void deleteAllRecords(ST **);
void deleteWithRoll(ST **);

// supportive func declarations:
int generate_roll(ST *);
void read_file_data(ST **);
int countStud(ST *);
void searchRoll(ST *p);
int searchName(ST *p);
int searchByPercentage(ST *p);

			
