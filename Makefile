NAME =pipex 
CFILES = childs_cmd.c pipex.c free_and_error.c  ft_split.c  helpers.c
OBJECTS = $(CFILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
CC = gcc
#generating the compile files 
$(NAME): $(OBJECTS)
	@echo "------CREATING-----" $(NAME) 	
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	
all: $(NAME) 
# Generating Object files 
%.o: %.c
	@echo " ---- Creating" [ $@ ] " -----"
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean: 
	rm -rf $(NAME) $(OBJECTS) $(BONUS_OJS) 
fclean: clean 
	rm -rf $(NAME)
	
re: clean all 	