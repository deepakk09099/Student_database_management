CC=cc
target=stud_add.o  stud_del.o  stud_main.o  stud_mod.o  stud_save.o  stud_show.o

exe: $(target)
	$(CC) $(target) -o student

stud_add.o: stud_add.c
	$(CC) -c stud_add.c
stud_del.o: stud_del.c
	$(CC) -c stud_del.c
stud_main.o: stud_main.c
	$(CC) -c stud_main.c
stud_mod.o: stud_mod.c
	$(CC) -c stud_mod.c
stud_save.o: stud_save.c
	$(CC) -c stud_save.c
stud_show.o: stud_show.c
	$(CC) -c stud_show.c

clear: 
	@echo "Clearing..."
	@rm -r *.o	
