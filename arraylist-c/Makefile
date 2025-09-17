
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -O2 -std=c11
BUILD   := build
BIN     := $(BUILD)/bin
OBJ     := $(BUILD)/obj
SRC     := src
TARGET  := $(BIN)/arraylist_demo

SRCS    := $(SRC)/arraylist.c $(SRC)/main.c
OBJS    := $(SRCS:$(SRC)/%.c=$(OBJ)/%.o)

.PHONY: all init run clean distclean

all: init $(TARGET)

init:
	@mkdir -p $(BIN) $(OBJ)

$(OBJ)/%.o: $(SRC)/%.c $(SRC)/arraylist.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

run: all
	@$(TARGET)

clean:
	@rm -rf $(OBJ) $(BIN)

distclean: clean
	@rm -rf $(BUILD)
