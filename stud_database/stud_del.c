//stud_del.c
#include"header.h"
void deleteAllRecords(ST **p){
	ST *del;
	if(*p==0){
		pf("No records present.\n");
		return;
	}
	while(*p){
		del=*p;
		*p=(*p)->next;
		free(del);
	}
	pf("\033[32mAll records deleted successfully\n\033[0m");
}


void deleteWithRoll(ST **p){
	if(*p==0){
		pf("No records present\n");
		return;
	}
	int roll;
	pf("Enter the roll-num which you want to delete : ");
	scanf("%d", &roll);
	ST *prev, *del=*p;
	while(del){
		if(del->roll==roll){
			if(del==*p)
				*p=del->next;
			else
				prev->next=del->next;
			free(del);
			pf("\033[32mThis records deleted successfully\n\033[0m");
			return;
		}
		prev=del;
		del=del->next;
	}
	pf("\033[36mThis roll no is not present in records\n\033[0m");
}

