#define _CRT_SECURE_NO_WARNINGS // disable C4996

#include <stdio.h>
#include <conio.h>
#include <app/view/appview.h>

METHOD_STATIC_DEF(AppView, void, WriteLine, const char* str)
{
	puts(str);
}

METHOD_STATIC_DEF(AppView, void, out_average, float avg)
{
	printf("����� %f�� �Դϴ�.\n", avg);
}

METHOD_STATIC_DEF(AppView, void, out_aboveAvg, int count)
{
	printf("����̻� �л��� ��� %d���Դϴ�.\n", count);
}

METHOD_STATIC_DEF(AppView, void, out_max, int max)
{
	printf("�ְ����� %d�� �Դϴ�.\n", max);
}

METHOD_STATIC_DEF(AppView, void, out_min, int min)
{
	printf("�������� %d�� �Դϴ�.\n", min);
}

METHOD_STATIC_DEF(AppView, void, out_gradeCount, int grades[5])
{
	for (int i = 0; i < 5; ++i) {
		char grade = (char)i + 'A';
		if (grade == 'E') grade++;

		printf("%c ������ %d�� �Դϴ�.\n", grade, grades[i]);
	}

	puts("");
}

METHOD_STATIC_DEF(AppView, void, out_studentInfo, int score, char grade)
{
	printf("����: %d  ����: %c\n", score, grade);
}

METHOD_STATIC_DEF(AppView, void, error_scoreOutofRange)
{
	METHOD_STATIC(AppView, WriteLine, "[����] 0���� �۰ų� 100���� Ŀ��, �������� ������ �ƴմϴ�.\n");
}

METHOD_STATIC_DEF(AppView, void, error_noRecordInput)
{
	METHOD_STATIC(AppView, WriteLine, "[����] �л� ������ ���� �Էµ��� �ʾҽ��ϴ�.\n");
}

METHOD_STATIC_DEF(AppView, char, getch)
{
	return _getche();
}

METHOD_STATIC_DEF(AppView, bool, inputContinuable)
{
	printf("? ������ �Է��Ϸ��� 'Y'�� , �Է��� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: ");
	char answer = METHOD_STATIC(AppView, getch);
	puts("");

	return (answer == 'Y' || answer == 'y');
}

METHOD_STATIC_DEF(AppView, int, inputScore)
{
	int score;

	printf("- ������ �Է��Ͻÿ�: ");
	scanf("%d", &score);
	
	return score;
}