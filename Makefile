CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = bsq
SRCS_DIR = srcs
INC_DIR = headers
SRCS = $(addprefix $(SRCS_DIR)/, main.c solve.c parser.c split.c utils.c checker.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = -I$(INC_DIR)

.PHONY: all clean fclean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)
