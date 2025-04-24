NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
PARS = parcing
LIB = libft
EXEC = execution

SOURCES = minishell.c \
	$(LIB)/ft_split.c $(LIB)/ft_substr.c $(LIB)/ft_strlen.c $(LIB)/ft_strdup.c $(LIB)/ft_strndup.c $(PARS)/tokenize.c \
	$(LIB)/ft_isalnum.c $(LIB)/ft_isalpha.c $(LIB)/ft_isdigit.c $(LIB)/ft_strcmp.c \
	$(PARS)/gc.c $(PARS)/helpers.c $(PARS)/signals.c \

OBJECTS = $(SOURCES:.c=.o)

READLINE_COMPILE = -I$(shell brew --prefix readline)/include
READLINE_LINK = -lreadline -L$(shell brew --prefix readline)/lib

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(READLINE_LINK)
	@echo "##<<  The Make Is Done  >>##"
	
%.o: %.c minishell.h
	@$(CC) $(CFLAGS) $(READLINE_COMPILE) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@echo "##<<  The Clean Is Done  >>##"
fclean: clean
	@rm -rf $(NAME)
	@echo "##<<  The Full Clean Is Done  >>##"

re: all clean
