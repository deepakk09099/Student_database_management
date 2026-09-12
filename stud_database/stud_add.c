//stud_add.c
//add a new record
#include"header.h"
void stud_add(ST **p){
	ST *new, *t, *prev=0;
	new=malloc(sizeof(ST));
	pf("Enter the name & marks\n");
	scanf("%s%f",new->name, &new->marks);
	if(*p==0){  		//first records
		new->roll=1;
		*p=new;
	}else{
		t=*p;
		prev=*p;
		new->roll=generate_roll(*p);
		if(new->roll==1){
			*p=new;
		}else{
			while(t->next!=0){
				if(t->roll>new->roll)
					break;
				prev=t;
				t=t->next;
			}
			if(t->next==0){    //last
				new->next=t->next;
				t->next=new;
			}else{             //middle
				new->next=prev->next;
				prev->next=new;
			}
		}
	}
	pf("\033[32mNew student data added successfully and their roll-num is = %d\n\033[0m", new->roll);
}


int generate_roll(ST *q){
	int i, f;
	ST *t;
	for(i=1; ; i++){
		f=0, t=q;
		while(t){	
			if(t->roll==i){
				f=1;
				break;
			}
			t=t->next;
		}
		if(f==0)
			return i;
	}
}


