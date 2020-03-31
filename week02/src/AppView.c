#include "App.h"
#include <stdio.h>

#if !__PREFER_STANDARD
#include <conio.h>
#endif

void    AppView_out_msg_startSolvingQuadEquation(void) {
	puts("<<< 이차방정식 풀이를 시작합니다 >>>\n");
}

void    AppView_out_msg_endSolvingQuadEquation(void) {
	puts("\n<<< 이차방정식 풀이를 종료합니다 >>>");
}

void    AppView_out_showQuadEquation(QuadEquationProblem_t problem) {
	QuadEquation_t equation = problem.equation;

	if (F32IsZero(equation.c1)) {
		printf("> 주어진 방정식: (%.1f)x * x + (%.1f) = 0\n", 
			equation.c0, equation.c2);
	} else {
		printf("> 주어진 방정식: (%.1f)x * x + (%.1f)x + (%.1f) = 0\n", 
			equation.c0, equation.c1, equation.c2);
	}
	
}

void    AppView_out_showRoot(QuadEquationProblem_t problem) {
	printf("> 방정식의 해는 다음과 같습니다:\n"
		"x1=%.1f\n" 
		"x2=%.2f\n\n", 
		problem.solution.root1,
		problem.solution.root2
		);
}

void    AppView_out_msg_error_secondOrderTermCoefficientIsZero(void) {
	puts("[오류] 2 차항의 계수가 0 이어서, 이차방정식이 아닙니다.\n");
}

void    AppView_out_msg_error_determinantIsNegative(QuadEquationProblem_t problem) {
	printf("[오류] 판별식의 값이 음수이어서 해가 존재하지 않습니다.\n"
		   "- 판별식의 값: %.1f\n\n", QuadEquationProblem_getDeterminant(&problem));
}

// from Week01
bool AppView_in_getSolvingRequest(void) {
	printf("? 방정식을 풀려면 'y', 풀이를 종료하려면 다른 아무 키나 치시오:");

	char input = 0;

#if __PREFER_STANDARD
	char buff[80] = { 0 };

#if _MSC_VER
	scanf_s("%s", buff, sizeof(buff));
#else
	scanf("%s", buff);
#endif

	input = buff[0];
#else
	input = (char)_getche();
	puts("");
#endif

	return (input == 'y' || input == 'Y');
}

void    AppView_in_getCoefficient(QuadEquationProblem_t* problem) {
	if (problem == NULL) {
		puts("[오류] 잘못된 파라메터가 전달되었습니다.");
		return;
	}

	printf("? 2 차항의 계수를 입력하시오: ");
	scanf_s("%f", &problem->equation.c0);

	printf("? 1 차항의 계수를 입력하시오: ");
	scanf_s("%f", &problem->equation.c1);

	printf("? 상수항의 계수를 입력하시오: ");
	scanf_s("%f", &problem->equation.c2);
}