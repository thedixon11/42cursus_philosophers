NAME = philo

SRC_DIR = src
OBJ_DIR = obj
UTILS_DIR = src/utils
UTILS_OBJ_DIR = obj/utils_obj

SRCS = main.c \
				check_values_are_right.c \
				data_initialization.c \
				dinner_is_over.c \
				sejour_at_chalet.c \
				sejour_at_chalet_utils.c \
				capis_desk.c \
				capis_desk_utils.c \
				error_inside_routine.c

UTILS = ph_atol.c \
				ph_atoi.c \
				ph_bzero.c \
				ph_calloc.c \
				ph_free.c \
				ph_isdigit.c \
				ph_itoa.c \
				ph_memset.c \
				ph_putendl_fd.c \
				ph_strjoin.c \
				ph_strlcat.c \
				ph_strlcpy.c \
				ph_strlen.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
UTILS_SRCS := $(addprefix $(UTILS_DIR)/,$(UTILS))

OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_UTILS := $(patsubst $(UTILS_DIR)/%.c,$(UTILS_OBJ_DIR)/%.o,$(UTILS_SRCS))

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -pthread
INCLUDE = -I. -I$(UTILS_DIR)

all: start $(NAME)

$(NAME): $(OBJS) $(OBJS_UTILS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(OBJS_UTILS) -o $(NAME)
	@echo "files compiled"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(UTILS_OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(UTILS_OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

start:
	@echo "compiling files ..."

clean:
	@echo "cleaning situation"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "more cleaning situation"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
