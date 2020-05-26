CC=gcc
CFLAGS=-c -std=c11 -pedantic -g -W -Wall -Wpedantic -Werror -I./Includes
OBJ_FILES=app_controller.o app_controller_lib.o appview.o main.o vector_int.o perf_timer.o parameter_set.o unsorted_array_list.o linked_list_node.o unsorted_linked_list.o
TARGET=list_performance

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

vector_int.o: Sources/application/model/vector_int.c
	$(CC) $(CFLAGS) -o $@ $^

perf_timer.o: Sources/application/model/perf_timer.c
	$(CC) $(CFLAGS) -o $@ $^

parameter_set.o: Sources/application/model/parameter_set.c
	$(CC) $(CFLAGS) -o $@ $^

unsorted_array_list.o: Sources/application/model/unsorted_array_list.c
	$(CC) $(CFLAGS) -o $@ $^

linked_list_node.o: Sources/application/datatypes/linked_list_node.c
	$(CC) $(CFLAGS) -o $@ $^

unsorted_linked_list.o: Sources/application/datatypes/unsorted_linked_list.c
	$(CC) $(CFLAGS) -o $@ $^