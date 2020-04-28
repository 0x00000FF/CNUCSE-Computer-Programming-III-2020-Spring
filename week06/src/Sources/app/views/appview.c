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
	printf("평균은 %f점 입니다.\n", avg);
}

METHOD_STATIC_DEF(AppView, void, out_aboveAvg, int count)
{
	printf("평균이상 학생은 모두 %d명입니다.\n", count);
}

METHOD_STATIC_DEF(AppView, void, out_max, int max)
{
	printf("최고점은 %d점 입니다.\n", max);
}

METHOD_STATIC_DEF(AppView, void, out_min, int min)
{
	printf("최저점은 %d점 입니다.\n", min);
}

METHOD_STATIC_DEF(AppView, void, out_gradeCount, int grades[5])
{
	for (int i = 0; i < 5; ++i) {
		char grade = (char)i + 'A';
		if (grade == 'E') grade++;

		printf("%c 학점은 %d명 입니다.\n", grade, grades[i]);
	}

	puts("");
}

METHOD_STATIC_DEF(AppView, void, out_studentInfo, int score, char grade)
{
	printf("점수: %d  학점: %c\n", score, grade);
}

METHOD_STATIC_DEF(AppView, void, error_scoreOutofRange)
{
	METHOD_STATIC(AppView, WriteLine, "[오류] 0보다 작거나 100보다 커서, 정상적인 점수가 아닙니다.\n");
}

METHOD_STATIC_DEF(AppView, void, error_noRecordInput)
{
	METHOD_STATIC(AppView, WriteLine, "[오류] 학생 정보가 전혀 입력되지 않았습니다.\n");
}

METHOD_STATIC_DEF(AppView, char, getch)
{
	return _getche();
}

METHOD_STATIC_DEF(AppView, bool, inputContinuable)
{
	printf("? 성적을 입력하려면 'Y'를 , 입력을 종료하려면 다른 아무 키나 치시오: ");
	char answer = METHOD_STATIC(AppView, getch);
	puts("");

	return (answer == 'Y' || answer == 'y');
}

METHOD_STATIC_DEF(AppView, int, inputScore)
{
	int score;

	printf("- 점수를 입력하시오: ");
	scanf("%d", &score);
	
	return score;
}