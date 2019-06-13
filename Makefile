# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlandema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by tlandema          #+#    #+#              #
#    Updated: 2019/06/13 05:23:13 by tlandema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft/includes

LIB = -lft

LIBFT = libft

LIB_PATH = -L./$(LIBFT)

INC = includes

OBJS_PATH = obj

#/********************PUSH_STUFF****************\

PUSH_NAME = push_swap

PUSH_PATH = srcs/push

PUSH = mainy.c \
	   small_sort.c \
	   quickie.c

PUSH_OBJS = $(PUSH:.c=.o)

D_PUSH_OBJS = $(addprefix $(OBJS_PATH)/, $(PUSH_OBJS))

#\**********************************************/


#/********************CHECK_STUFF***************\

CHECK_NAME = checker

CHECK_PATH = srcs/checker

CHECK = checker.c \
		main.c 

CHECK_OBJS = $(CHECK:.c=.o)

D_CHECK_OBJS = $(addprefix $(OBJS_PATH)/, $(CHECK_OBJS))

#\**********************************************/


#/*********************BOTH_STUFF****************\

BOTH_PATH = srcs/operator

BOTH =	pile_pusher.c \
		is_sorted.c \
		freerror.c \
		get_arg.c \
		delete.c \
		stock.c \
		rra.c \
		rrb.c \
		rrr.c \
		sa.c \
		sb.c \
		ss.c \
		ra.c \
		rb.c \
		rr.c \
		pa.c \
		pb.c

BOTH_OBJS = $(BOTH:.c=.o)

D_BOTH_OBJS = $(addprefix $(OBJS_PATH)/, $(BOTH_OBJS))

#\***********************************************/

D_LIB = libft/libft.a

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test_r
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(BACK_COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	rm -f $@.log 2> /dev/null; \
	exit $$RESULT
endef

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(BACK_COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

all: $(PUSH_NAME) $(CHECK_NAME)

$(PUSH_NAME): $(INC) $(D_PUSH_OBJS) $(D_BOTH_OBJS) $(D_LIB)
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(PUSH_NAME) $(D_PUSH_OBJS) $(D_BOTH_OBJS) $(LIB_PATH) $(LIB))

$(CHECK_NAME): $(INC) $(D_CHECK_OBJS) $(D_BOTH_OBJS) $(D_LIB)
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(CHECK_NAME) $(D_CHECK_OBJS) $(D_BOTH_OBJS) $(LIB_PATH) $(LIB))

$(OBJS_PATH)/%.o: $(CHECK_PATH)/%.c
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I$(LIB_PATH))

$(OBJS_PATH)/%.o: $(PUSH_PATH)/%.c  
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I$(LIB_PATH))

$(OBJS_PATH)/%.o: $(BOTH_PATH)/%.c  
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I$(LIB_PATH))

$(D_LIB) :
	@make -C libft

norme:
	@$(call run_and_test_r, norminette | grep -v 'Warning: Not a valid file' | grep -B 1 -e 'Error' -e 'Warning')

clean:
	@$(call run_and_test, rm -f $(D_PUSH_OBJS) $(D_BOTH_OBJS) $(D_CHECK_OBJS) && make clean -C libft)

fclean: clean
	@$(call run_and_test, rm -f $(PUSH_NAME) $(CHECK_NAME) && rm -f libft/libft.a)

re: fclean all
