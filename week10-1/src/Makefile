CC=gcc
CFLAGS=-c -std=c11 -pedantic -g -W -Wall -Wpedantic -Werror -I./Includes
OBJ_FILES=getchar_direct.o app_controller.o app_controller_lib.o appview.o main.o vector_char.o stack.o
TARGET=stack

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) -o $@ $^

main.o: Sources/main.c
	$(CC) $(CFLAGS) -o $@ $^

app_controller.o: Sources/application/app_controller.c
	$(CC) $(CFLAGS) -o $@ $^
	
app_controller_lib.o: Sources/application/app_controller_lib.c
	$(CC) $(CFLAGS) -o $@ $^
	
appview.o: Sources/application/appview.c
	$(CC) $(CFLAGS) -o $@ $^

getchar_direct.o: Sources/application/getchar_direct.c
	$(CC) $(CFLAGS) -o $@ $^

vector_char.o: Sources/application/model/vector_char.c
	$(CC) $(CFLAGS) -o $@ $^

stack.o: Sources/application/model/stack.c
	$(CC) $(CFLAGS) -o $@ $^
	
