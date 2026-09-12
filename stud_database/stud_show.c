//stud_show.c
#include"header.h"
void stud_show(ST *p){		
	if(p==0)
		pf("No records present.\n");
	while(p){
	   pf("%d %s %.2f\n",p->roll, p->name, p->marks);
	   p=p->next;
	}
}


