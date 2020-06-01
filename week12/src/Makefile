CC=gcc
CFLAGS=-c -std=c11 -pedantic -g -W -Wall -Wpedantic -Werror -I./Includes
OBJ_FILES=getchar_direct.o app_controller.o app_controller_lib.o appview.o main.o vector_int.o stack.o postfix.o message.o
TARGET=postfix

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

vector_int.o: Sources/application/model/vector_int.c
	$(CC) $(CFLAGS) -o $@ $^

stack.o: Sources/application/model/stack.c
	$(CC) $(CFLAGS) -o $@ $^

linked_list_node.o: Sources/application/datatypes/linked_list_node.c
	$(CC) $(CFLAGS) -o $@ $^

unsorted_linked_list.o: Sources/application/datatypes/unsorted_linked_list.c
	$(CC) $(CFLAGS) -o $@ $^

postfix.o: Sources/application/model/postfix.c
	$(CC) $(CFLAGS) -o $@ $^	

message.o: Sources/application/model/message.c
	$(CC) $(CFLAGS) -o $@ $^
