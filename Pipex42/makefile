NAME =pipex 
CFILES = childs_cmd.c pipex.c free_and_error.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c 
OBJECTS = $(CFILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
CC = gcc
#generating the compile files 
$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)
all: $(NAME) 
# Generating Object files 
%.o: %.c
	$(CC) $(CFLAGS) -c $< $^
clean: 
	rm -rf $(NAME) $(OBJECTS) $(BONUS_OJS)
fclean: clean 
	rm -rf $(NAME)
	
re: clean all 	