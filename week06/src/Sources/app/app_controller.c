#include <app/app_controller.h>

METHOD_STATIC_DEF(AppController, AppController*, create, int argc, char* argv[])
{
	AppController* controller = NEW(AppController);

	controller->arg_count   = argc;
	controller->arg_list    = argv;
	controller->lc          = METHOD_STATIC(LectureClass, create, MAX_NUMBER_OF_STUDENTS);

	return controller;
}

METHOD_DEF(AppController, void, showStudentList)
{
	int size  = METHOD(LectureClass, self->lc, size);
	int* list = METHOD(LectureClass, self->lc, list);

	METHOD_STATIC(AppView, WriteLine, "�л����� ������ ����Դϴ�.");

	for (int i = 0; i < size; ++i) {
		int score = METHOD(LectureClass, self->lc, at, i);
		char grade = METHOD_STATIC(LectureClass, grade, score);

		METHOD_STATIC(AppView, out_studentInfo, score, grade);
	}
}

METHOD_DEF(AppController, void, showStatistics)
{
	METHOD_STATIC(AppView, out_average, METHOD(LectureClass, self->lc, average));
	METHOD_STATIC(AppView, out_aboveAvg, METHOD(LectureClass, self->lc, aboveAverage));
	METHOD_STATIC(AppView, out_max, METHOD(LectureClass, self->lc, max));
	METHOD_STATIC(AppView, out_min, METHOD(LectureClass, self->lc, min));

	int grades[5];
	METHOD(LectureClass, self->lc, grades, grades);
	METHOD_STATIC(AppView, out_gradeCount, grades);
}

METHOD_DEF(AppController, bool, getInput)
{
	bool inputResult = false;
	
	while (!METHOD(LectureClass, self->lc, is_full) &&
			METHOD_STATIC(AppView, inputContinuable))
	{
		int score = METHOD_STATIC(AppView, inputScore);

		if (!METHOD_STATIC(LectureClass, scoreValid, score)) {
			METHOD_STATIC(AppView, error_scoreOutofRange);
		}
		else {
			inputResult = METHOD(LectureClass, self->lc, add, score);
		}
	}

	if (METHOD(LectureClass, self->lc, empty)) {
		METHOD_STATIC(AppView, error_noRecordInput);
	}

	METHOD_STATIC(AppView, WriteLine, "�Է��� �����մϴ�.");

	return inputResult;
}

METHOD_DEF(AppController, void, run)
{
	bool inputSuccess = false;

	METHOD_STATIC(AppView, WriteLine, "<<< ���� ó���� �����մϴ� >>>\n");
	inputSuccess = METHOD(AppController, self, getInput);

	if (inputSuccess) {
		if (METHOD(LectureClass, self->lc, empty)) {
			METHOD_STATIC(AppView, WriteLine, "[����] �л� ������ ���� �Էµ��� �ʾҽ��ϴ�.");
		}
		else {
			METHOD(AppController, self, showStatistics);

			METHOD(LectureClass, self->lc, sort_score);
			METHOD(AppController, self, showStudentList);
		}

		self->result = 0;
	} else {
		METHOD_STATIC(AppView, WriteLine, "[����] ������ ���������� ������� �ʾҽ��ϴ�.");
		self->result = -1;
	}

	METHOD_STATIC(AppView, WriteLine, "<<< ���� ó���� �����մϴ� >>>\n");
}

METHOD_DEF(AppController, int, get_return)
{
	return self->result;
}

METHOD_DEF(AppController, void, destroy)
{
	if (self->lc != NULLPTR)
		METHOD(LectureClass, self->lc, destroy);
}