CC := aarch64-linux-gnu-gcc
CFLAGS := --sysroot=/usr/aarch64-linux-gnu/sys-root -Wall -Werror
CFLAGS += -D_FILE_OFFSET_BITS=64

TARGET := writer
SRC := writer.c
OBJ := writer.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJ)
