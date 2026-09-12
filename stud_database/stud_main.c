// stud_main.c
#include"header.h"
void main(){
	int c, f;
	char op, ch; 
	ST *head=0;
	pf("********************************** STUDENT RECOD MENU **********************************\n");
	read_file_data(&head);
	sort_with_roll(&head);
	
	while(1){
		pf("\n\033[33ma/A:add new record\nd/D:delete a record\ns/S:show the list\nm/M:modify a record\nv/V:save\ne/E:exit\nt/T:sort the list\nl/L:delete all the records\nr/R:reverse the list\n\033[0m\nEnter your choice : ");
		scanf(" %c",&op);
		switch(op){
			case 'a':
			case 'A': stud_add(&head); break;

			case 'd':
			case 'D': //stud_del(&head); break;
				  while(1){                  
					  pf("\nR/r : Enter roll to delete\nN/n : Enter name to delete\nEnter your choice : ");
					  scanf(" %c",&ch);
					  if(ch=='R'||ch=='r'){
						deleteWithRoll(&head); break;   //done
					  }else if(ch=='N'||ch=='n'){
						  f=searchName(head);           //done
						  if(f)
							  deleteWithRoll(&head); break;
					  }else
						  pf("\n\033[31mWrong option! Enter valid choice.\n\033[0m");
				  }break;
			case 's':
			case 'S': stud_show(head); break;   

			case 'm':
			case 'M': //stud_mod(&head); break;  
				  while(1){                  //done
					  pf("\nR/r : to search a rollno\nN/n : to search a name \nP/p : percentage based\nEnter your choice : ");
					  scanf(" %c",&ch);
					  if(ch=='R'||ch=='r'){
						  searchRoll(head); break;
					  }else if(ch=='N'||ch=='n'){
						  f=searchName(head);
						  if(f)
							  searchRoll(head); break;
					  }else if(ch=='P'||ch=='p'){
						  f=searchByPercentage(head);
						  if(f)
							  searchRoll(head); break;
					  }else
						  pf("\n\033[31mWrong option! Enter valid choice.\n\033[0m");
				  }break;
			case 'v':
			case 'V': stud_save(head); break;   

			case 'e':  
			case 'E': while(1){                  //done
					  pf("\nS/s : Save and exit\nE/e : Exit without saving\nEnter your choice : ");
					  scanf(" %c",&ch);
					  if(ch=='S'||ch=='s'){
						  stud_save(head); exit(0);
					  }else if(ch=='E'||ch=='e')
						  exit(0);
					  else
						  pf("\n\033[31mWrong option! Enter valid choice.\n\033[0m");
				  }break;
			case 't': 
			case 'T': //stud_sort(&head); break;      //done
				  while(1){
					  pf("\nR/r : Sort with roll\nN/n : Sort with name\nP/p : Sort with percentage\nEnter your choice : ");
					  scanf(" %c",&ch);
					  if(ch=='R'||ch=='r'){
						  sort_with_roll(&head); break;
					  }else if(ch=='N'||ch=='n'){
						  sort_with_name(&head); break;
					  }else if(ch=='P'||ch=='p'){
						  sort_with_marks(&head); break;
					  }else
						  pf("\n\033[31mWrong option! Enter valid choice.\n\033[0m");
				  }break;
			case 'l':
			case 'L': deleteAllRecords(&head); break;  
			case 'r':
			case 'R': reverseList(&head); break;         

			default : pf("\033[31mWrong option!\nEnter valid option.\n\033[0m");
		}
	}
}


