#include <mvc/appview.h>
#include <mvc/app_controller.h>    // app_controller

#include <model/student.h>

// app_controller 생성자
app_controller* app_controller_create(int argc, char** argv)
{
	app_controller* controller = (app_controller*)malloc(sizeof(app_controller));

	controller->argc   = argc;
	controller->argv   = argv;
	controller->result = 0;

	controller->students = VECTOR_NEW(student)(MAX_STUDENTS);

	return controller;
}


// static method because self is not necessary
bool            app_controller_input_is_valid(
	student_id id,
	int score)
{
	bool valid_result = true;

	// if id is less than 10^8
	if ( !student_is_id_valid(id) ) {
		appview_err_too_long_id(id, STUDENT_ID_LENGTH);
		valid_result = false;
	}

	if (!student_is_score_valid(score)) {
		appview_err_invalid_score();
		valid_result = false;
	}

	return valid_result;
}

void            app_controller_show_statistics(app_controller* self)
{
	lecture_view* view = lecture_view_create(self->students);
	appview_out_statistics(view);
	appview_out_sorted_student_list(view);
	lecture_view_delete(view);
}

bool            app_controller_get_input(app_controller* self)
{
	student*   student;
	student_id id;
	int        score = 0;
	bool       store_result = true;

	while (store_result && appview_in_get_continue()) {
		appview_in_get_student(id, &score);

		if (app_controller_input_is_valid(id, score)) {
			student = student_create(id, score);
			VECTOR_PUSH_BACK(student)(self->students, *student);

			free(student); // prevent memory leakage
		}
	}

	appview_out_println("입력을 종료합니다.");

	return store_result;
}

// application routine 시작
void            app_controller_run   (app_controller* self)
{
	bool input_success = false;

	appview_out_println("<<< 성적 처리를 시작합니다 >>>\n");
	input_success = app_controller_get_input(self);

	if (input_success) {
		if (VECTOR_EMPTY(student)(self->students)) {
			appview_out_println("[오류] 학생 정보가 전혀 입력되지 않았습니다.");
		}
		else {
			app_controller_show_statistics(self);
		}

		self->result = 0;
	}
	else {
		appview_out_println("[오류] 성적이 정상적으로 저장되지 않았습니다.");
		self->result = -1;
	}
	
	appview_out_println("<<< 성적 처리를 종료합니다 >>>\n");
}

// app_controller 소멸자
void            app_controller_delete(app_controller* self)
{
	if (self == NULL) return;

	VECTOR_DELETE(student)(self->students);
	free(self);
}