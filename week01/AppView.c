#include "AppView.h"

#include <stdio.h>

#if !__PREFER_STANDARD
#include <conio.h>
#endif

void    AppView_out_msg_startSolvingLinearEquation(void) {
	puts("<<< 일차방정식 풀이를 시작합니다 >>>\n");
}

void    AppView_out_msg_endSolvingLinearEquation(void) {
	puts("\n<<< 일차방정식 풀이를 종료합니다 >>>");
}

void    AppView_out_showLinearEquation(float c0, float c1) {
	printf("> 주어진 방정식: (%.1f)x + (%.1f) = 0\n", c0, c1);
}

void    AppView_out_showRoot(float root) {
	printf("> 방정식의 해는 다음과 같습니다:\n"
		"x=%.1f\n\n", root);
}

void    AppView_out_msg_error_firstOrderTermCoefficientIsZero(void) {
	puts("[오류] 1 차항의 계수가 0 이어서, 방정식을 풀 수 없습니다.\n");
}

bool AppView_in_getSolvingRequest(void) {
	printf("? 방정식을 풀려면 'y', 풀이를 종료하려면 다른 아무 키나 치시오:");

#if __PREFER_STANDARD
	char input = 0;
	char buff[80] = { 0 };

#if _MSC_VER
	scanf_s("%s", buff, sizeof(buff));
#else
	scanf("%s", buff);
#endif

	input = buff[0];
#else
	input = (char)_getch();
	puts();
#endif

	return (input == 'y' || input == 'Y');
}

void    AppView_in_getCoefficient(float* c0, float* c1) {
	if (c0 == NULL || c1 == NULL) {
		puts("[오류] 잘못된 파라메터가 전달되었습니다.");
		return;
	}

	printf("? 1 차항의 계수를 입력하시오: ");
	scanf_s("%f", c0);

	printf("? 상수항의 계수를 입력하시오: ");
	scanf_s("%f", c1);
}