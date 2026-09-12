// stud_mod.c
#include"header.h"

void searchRoll(ST *p){
	if(p==0){
		pf("No records are present\n");
		return;
	}
	int r;
	pf("Enter the roll which you wanted to modify : ");
	scanf("%d",&r);
	while(p){
		if(p->roll==r){
			pf("Enter new name and marks.\n");
			scanf("%s%f",p->name, &p->marks);
			pf("\033[32mData modified successfully\n\033[0m");
			return;
		}
		p=p->next;
	}
	pf("\033[36mThis roll-num is not present\n\033[0m");
}

// same name k jitne stud honge sab dikh jayega
int searchName(ST *p){
	int f=0;
	if(p==0){
		pf("No records are present\n");
		return 0;
	}else{
		char n[20];
		pf("Enter the name which you wanted to modify : ");
		scanf("%s",n);
		while(p){
			if(strcmp(p->name,n)==0){
				pf("%d %s %.2f\n", p->roll, p->name, p->marks);
				f++;
			}
			p=p->next;
		}
		if(f==0){
			pf("\033[36mThis name is not present\n\033[0m");
			return 0;
		}
	}
	return f;
}


// same percentage k jitne stud honge sab dikh jayega
int searchByPercentage(ST *p){
	int f=0;
	float r;
	if(p==0){
		pf("No records are present\n");
		return 0;
	}else{
		char n[20];
		pf("Enter the percentage which you wanted to modify : ");
		scanf("%f",&r);
		while(p){
			if(p->marks==r){
				pf("%d %s %.2f\n", p->roll, p->name, p->marks);
				f++;
			}
			p=p->next;
		}
		if(f==0){
			pf("\033[36mNo-one having this percentage\n\033[0m");
			return 0;
		}
	}
	return f;
}



