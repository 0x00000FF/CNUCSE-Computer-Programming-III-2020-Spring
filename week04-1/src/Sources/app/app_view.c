#include <app/macro.h>
#include <app/app_view.h>

#pragma  warning(disable: 4996)
#include <stdio.h>


METHOD_STATIC_DEF(AppView, bool, getSolvingRequest)
{
	printf("? 방정식을 풀려면 'y', 풀이를 종료하려면 다른 아무 키나 치시오:");

	char input = 0;
	char buff[80] = { 0 };

	scanf("%s", buff);


	input = buff[0];
	return (input == 'y' || input == 'Y');
}

METHOD_STATIC_DEF(AppView, void, readCoefficient, QuadEquationProblem* problem)
{
	if (problem->equation == NULLPTR) {
		puts("[오류] 잘못된 파라메터가 전달되었습니다.");
		return;
	}

	QuadEquation* equation = problem->equation;

	printf("? 2 차항의 계수를 입력하시오: ");
	scanf("%f", &equation->c0);

	printf("? 1 차항의 계수를 입력하시오: ");
	scanf("%f", &equation->c1);

	printf("? 상수항의 계수를 입력하시오: ");
	scanf("%f", &equation->c2);
}

METHOD_STATIC_DEF(AppView, void, printEquation, QuadEquationProblem* problem)
{
	QuadEquation* equation = problem->equation;

	printf("> 주어진 방정식: ");

	if (!F32IsZero(equation->c0)) {
		printf("(%.2g)x*x", equation->c0);
	}

	if (!F32IsZero(equation->c1)) {
		if (!F32IsZero(equation->c0)) printf(" + ");
		printf("(%.2g)x", equation->c1);
	}

	if (!F32IsZero(equation->c2)) {
		if (!F32IsZero(equation->c0) || !F32IsZero(equation->c1)) printf(" + ");
		printf(" + (%.2g)", equation->c2);
	}

	puts(" = 0");
}

METHOD_STATIC_DEF(AppView, void, msg_resourceNotAllocated) 
{
	puts("[오류] 이차방정식 객체를 위한 메모리 할당에 실패하였습니다. 종료합니다.");
}

METHOD_STATIC_DEF(AppView, void, msg_coefficientIsNotValid)
{
	puts("[오류] 2 차항의 계수가 0 이어서, 이차방정식이 아닙니다.\n");
}

METHOD_STATIC_DEF(AppView, void, msg_determinantIsNotValid, QuadEquationProblem* problem)
{
	printf("> 판별식의 값: %.2g\n"
		   "[오류] 판별식의 값이 음수이어서 해가 존재하지 않습니다.\n\n"
		   , METHOD(QuadEquationProblem, problem, getDeterminant));
}

METHOD_STATIC_DEF(AppView, void, printSolution, QuadEquationProblem* problem)
{
	printf("> 방정식의 해는 다음과 같습니다:\n"
		"x1 = %.2g\n"
		"x2 = %.2g\n\n",
		problem->solution->root1,
		problem->solution->root2
	);
}

METHOD_STATIC_DEF(AppView, void, printDeterminant, QuadEquationProblem* problem)
{
	printf("> 판별식의 값: %g\n",
		METHOD(QuadEquationProblem, problem, getDeterminant)
	);
}

METHOD_STATIC_DEF(AppView, void, msg_startQuadEquation)
{
	puts("<<< 이차방정식 풀이를 시작합니다 >>>\n");
}

METHOD_STATIC_DEF(AppView, void, msg_endQuadEquation)
{
	puts("\n<<< 이차방정식 풀이를 종료합니다 >>>");
}

