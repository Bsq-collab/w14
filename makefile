NAME=sem
all: $(NAME).o
	gcc -o $(NAME).out $(NAME).o

$(NAME).o: $(NAME).c
	gcc -c $(NAME).c


run: all
	./$(NAME).out -c 4
	./$(NAME).out -v
	./$(NAME).out -c 3
	./$(NAME).out -v
	./$(NAME).out -r

clean:
	rm -f ./$(NAME).out
	rm -f ./$(NAME).o
