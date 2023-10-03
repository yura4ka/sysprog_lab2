CC = gcc
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

main: $(SRC_FILES)
	$(CC) $^ -o main