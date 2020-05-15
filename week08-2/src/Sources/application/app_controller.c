#include <mvc/appview.h>
#include <mvc/app_controller.h>    // app_controller

#include <app/perf_timer.h>
#include <app/message.h>

#include <stdio.h>   // sprintf

void            app_controller_init_performance_measurement(app_controller* self)
{
	parameter_set_set_min_test_size(self->parameter_set, MIN_TEST_SIZE);
	parameter_set_set_interval_size(self->parameter_set, INTERVAL_SIZE);
	parameter_set_set_number_of_tests_size(self->parameter_set, NUMBER_OF_TESTS);

	int max_test_size = MIN_TEST_SIZE * INTERVAL_SIZE * (NUMBER_OF_TESTS - 1);
	self->test_data = VECTOR_NEW(element)(max_test_size);
}

// app_controller 생성자
app_controller* app_controller_create(int argc, char** argv)
{
	app_controller* controller = (app_controller*)malloc(sizeof(app_controller));

	controller->argc   = argc;
	controller->argv   = argv;
	controller->result = 0;

	controller->parameter_set = parameter_set_new();
	app_controller_init_performance_measurement(controller);

	return controller;
}

double  	    app_controller_time_for_unsorted_array_list_remove_max(app_controller* self, unsorted_array_list* list_for_test, int test_size)
{
	if (self == NULL) return -1; //error: unused parameter ‘self’ [-Werror=unused-parameter]
	
	perf_timer* perf_timer = perf_timer_new();

	double duration = 0;
	for (int i = 0; i < test_size; ++i) {
		perf_timer_start(perf_timer);

		unsorted_array_list_remove_max(list_for_test);

		perf_timer_stop(perf_timer);
		duration += perf_timer_duration(perf_timer);
	}

	perf_timer_delete(perf_timer);

	return duration;
}

double          app_controller_time_for_unsorted_array_list_min(app_controller* self, unsorted_array_list* list_for_test, int test_size)
{
	if (self == NULL) return -1; //error: unused parameter ‘self’ [-Werror=unused-parameter]

	perf_timer* perf_timer = perf_timer_new();

	double duration = 0;
	for (int i = 0; i < test_size; ++i) {
		perf_timer_start(perf_timer);

		unsorted_array_list_min(list_for_test);

		perf_timer_stop(perf_timer);
		duration += perf_timer_duration(perf_timer);
	}

	perf_timer_delete(perf_timer);

	return duration;
}

double          app_controller_time_for_unsorted_array_list_add(app_controller* self, unsorted_array_list* list_for_test, int test_size)
{
	perf_timer*  perf_timer = perf_timer_new();
	
	double duration = 0;
	for (int i = 0; i < test_size; ++i) {
		perf_timer_start(perf_timer);

		unsorted_array_list_add(list_for_test, VECTOR_AT(element)(self->test_data, i));

		perf_timer_stop(perf_timer);
		duration += perf_timer_duration(perf_timer);
	}

	perf_timer_delete(perf_timer);

	return duration;
}

double  	    app_controller_time_for_sorted_array_list_remove_max(app_controller* self, sorted_array_list* list_for_test, int test_size)
{
	if (self == NULL) return -1; //error: unused parameter ‘self’ [-Werror=unused-parameter]

	perf_timer* perf_timer = perf_timer_new();

	double duration = 0;
	for (int i = 0; i < test_size; ++i) {
		perf_timer_start(perf_timer);

		sorted_array_list_remove_max(list_for_test);

		perf_timer_stop(perf_timer);
		duration += perf_timer_duration(perf_timer);
	}

	perf_timer_delete(perf_timer);

	return duration;
}

double          app_controller_time_for_sorted_array_list_min(app_controller* self, sorted_array_list* list_for_test, int test_size)
{
	if (self == NULL) return -1; //error: unused parameter ‘self’ [-Werror=unused-parameter]

	perf_timer* perf_timer = perf_timer_new();

	double duration = 0;
	for (int i = 0; i < test_size; ++i) {
		perf_timer_start(perf_timer);

		sorted_array_list_min(list_for_test);

		perf_timer_stop(perf_timer);
		duration += perf_timer_duration(perf_timer);
	}

	perf_timer_delete(perf_timer);

	return duration;
}

double          app_controller_time_for_sorted_array_list_add(app_controller* self, sorted_array_list* list_for_test, int test_size)
{
	perf_timer*  perf_timer = perf_timer_new();
	
	double duration = 0;
	for (int i = 0; i < test_size; ++i) {
		perf_timer_start(perf_timer);

		sorted_array_list_add(list_for_test, VECTOR_AT(element)(self->test_data, i));

		perf_timer_stop(perf_timer);
		duration += perf_timer_duration(perf_timer);
	}

	perf_timer_delete(perf_timer);

	return duration;
}

void            app_controller_generate_test_data_by_random_numbers(app_controller* self)
{
    int max_test_size = MIN_TEST_SIZE + INTERVAL_SIZE * (NUMBER_OF_TESTS - 1);
	srand((unsigned) time(NULL));
	
	for (int i = 0; i < max_test_size; ++i) {
		VECTOR_PUSH_BACK(element)(self->test_data, rand());
	}
}

void            app_controller_show_results(int test_size, double time_for_add, double time_for_min, double time_for_remove_max)
{
	char buffer[256];

	sprintf(buffer, "크기: %6d,  삽입: %6ld, 최소값얻기: %7ld, 최대값삭제: %7ld", 
					test_size, (long) time_for_add, (long) time_for_min, (long) time_for_remove_max);
	appview_out(buffer);
}

// application routine 시작
void            app_controller_run   (app_controller* self)
{
	appview_out(MSG_start_performance_measuring);

	app_controller_generate_test_data_by_random_numbers(self);
	appview_out(MSG_title_for_unsorted_array_list);

	int                  test_size     = parameter_set_get_min_test_size(self->parameter_set);
	unsorted_array_list* list_for_test; // not to initialize to initialize in loop
	
	// 무순 리스트 테스트 개시
	for (; test_size <= parameter_set_max_test_size(self->parameter_set); 
		   test_size += parameter_set_get_interval_size(self->parameter_set)) {
		list_for_test = VECTOR_NEW(element)(test_size);
	
		double  time_for_add = app_controller_time_for_unsorted_array_list_add(self, list_for_test, test_size);
		double  time_for_min = app_controller_time_for_unsorted_array_list_min(self, list_for_test, test_size);
		double  time_for_remove_max = app_controller_time_for_unsorted_array_list_remove_max(self, list_for_test, test_size);

		app_controller_show_results(test_size, time_for_add, time_for_min, time_for_remove_max);
		
		VECTOR_DELETE(element)(list_for_test);
	}


	appview_out(MSG_title_for_sorted_array_list);

	// 순서 리스트 테스트 개시
	for (test_size  = parameter_set_get_min_test_size(self->parameter_set); 
	     test_size <= parameter_set_max_test_size(self->parameter_set);
		 test_size += parameter_set_get_interval_size(self->parameter_set)) {
		list_for_test = VECTOR_NEW(element)(test_size);

		double  time_for_add = app_controller_time_for_sorted_array_list_add(self, list_for_test, test_size);
		double  time_for_min = app_controller_time_for_sorted_array_list_min(self, list_for_test, test_size);
		double  time_for_remove_max = app_controller_time_for_sorted_array_list_remove_max(self, list_for_test, test_size);

		app_controller_show_results(test_size, time_for_add, time_for_min, time_for_remove_max);

		VECTOR_DELETE(element)(list_for_test);
	}

	appview_out(MSG_end_performance_measuring);
}

// app_controller 소멸자
void            app_controller_delete(app_controller* self)
{
	if (self == NULL) return;

	// vector 해제
	VECTOR_DELETE(element)(self->test_data);
	free(self);
}