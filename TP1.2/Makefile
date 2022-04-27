CC=gcc
CFLAGS=-Wall -Wextra -Werror
CPPFLAGS=-I$(HEADER_DIR)
EXEC=main
HEADER_DIR=include/
OBJS_DIR=objs/
SRC_DIR=src/
BIN_DIR=bin/

SRC_FILES:= $(shell find src/ -type f -name "*.c")
OBJS_LIST_FILES:= $(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRC_FILES))

$(BIN_DIR)$(EXEC): $(OBJS_DIR)main.o $(OBJS_LIST_FILES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR)main.o: $(SRC_DIR)main.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

run:
	make -s $(BIN_DIR)$(EXEC)
	cd $(BIN_DIR) && ./$(EXEC)

clean:
	rm -rf $(OBJS_DIR) $(BIN_DIR)