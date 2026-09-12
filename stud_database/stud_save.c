//stud_save.c

#include"header.h"
// file ko read krne k liye
void read_file_data(ST **p){
	FILE *fp=fopen("stud_data.txt","r");
	ST *last;
	while(1){
		ST *new=malloc(sizeof(ST));
		if((fscanf(fp,"%d%s%f", &new->roll, new->name, &new->marks))==-1)
			break;
		new->next=0;
		if(*p==0){
			*p=new;
		}else{
			last=*p;
			while(last->next)
				last=last->next;
			last->next=new;
		}
	}
	pf("\033[32mFile read successfully\n\033[0m");
	fclose(fp);
}


// save data in file
void stud_save(ST *p){
	if(p==0){
		pf("No records present\n");
		return;
	}
	FILE *fp=fopen("stud_data.txt","w");
	while(p){
		fprintf(fp,"%d %s %.2f\n", p->roll, p->name, p->marks);
		p=p->next;
	}
	pf("\033[32mFile saved successfully\n\033[0m");
	fclose(fp);
}



void sort_with_roll(ST **p){
	ST *p1, *p2, t;
	if(*p==0){
		pf("No records present.\n");
		return;
	}
	int i, j, c=countStud(*p);
	p1=*p;
	for(i=0; i<c-1; i++){
		p2=p1->next;
		for(j=0; j<c-1-i; j++){
			if((p1->roll)>(p2->roll)){
				t.roll=p1->roll;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;
				p1->roll=p2->roll;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;
				p2->roll=t.roll;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	pf("\033[32mData shorted with roll successfully\n\033[0m");
}


void sort_with_name(ST **p){
	ST *p1, *p2, t;
	if(*p==0){
		pf("No records present.\n");
		return;
	}
	int i, j, c=countStud(*p);
	p1=*p;
	for(i=0; i<c-1; i++){
		p2=p1->next;
		for(j=0; j<c-1-i; j++){
			if((strcmp(p1->name, p2->name))>0){
				t.roll=p1->roll;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;
				p1->roll=p2->roll;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;
				p2->roll=t.roll;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	pf("\033[32mData shorted with name successfully\n\033[0m");
}


void sort_with_marks(ST **p){
	ST *p1, *p2, t;
	if(*p==0){
		pf("No records present.\n");
		return;
	}
	int i, j, c=countStud(*p);
	p1=*p;
	for(i=0; i<c-1; i++){
		p2=p1->next;
		for(j=0; j<c-1-i; j++){
			if((p1->marks)>(p2->marks)){
				t.roll=p1->roll;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;
				p1->roll=p2->roll;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;
				p2->roll=t.roll;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	pf("\033[32mData shorted with percentage successfully\n\033[0m");
}


void reverseList(ST **p){
	ST *t=*p;
	if(*p==0){
		pf("No records present\n");
		return;
	}
	int i=0, c=countStud(*p);
	ST **new=malloc(sizeof(ST *) * c);
	while(t){
		new[i++]=t;
		t=t->next;
	}
	for(i=c-1; i>0; i--)
		new[i]->next=new[i-1];
	new[0]->next=0;    // tail
	*p=new[c-1];       // head
	pf("\033[32mLink reversed successfully\n\033[0m");
}


int countStud(ST *p){
	int c=0;
	while(p)
	   c++, p=p->next;
	return c;
}

