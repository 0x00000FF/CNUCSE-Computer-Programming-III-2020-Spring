#include <app/macro.h>
#include <app/app_view.h>

#pragma  warning(disable: 4996)
#include <stdio.h>


METHOD_STATIC_DEF(AppView, bool, getSolvingRequest)
{
	printf("? �������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�:");

	char input = 0;
	char buff[80] = { 0 };

	scanf("%s", buff);


	input = buff[0];
	return (input == 'y' || input == 'Y');
}

METHOD_STATIC_DEF(AppView, void, readCoefficient, QuadEquationProblem* problem)
{
	if (problem->equation == NULLPTR) {
		puts("[����] �߸��� �Ķ���Ͱ� ���޵Ǿ����ϴ�.");
		return;
	}

	QuadEquation* equation = problem->equation;

	printf("? 2 ������ ����� �Է��Ͻÿ�: ");
	scanf("%f", &equation->c0);

	printf("? 1 ������ ����� �Է��Ͻÿ�: ");
	scanf("%f", &equation->c1);

	printf("? ������� ����� �Է��Ͻÿ�: ");
	scanf("%f", &equation->c2);
}

METHOD_STATIC_DEF(AppView, void, printEquation, QuadEquationProblem* problem)
{
	QuadEquation* equation = problem->equation;

	printf("> �־��� ������: ");

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
	puts("[����] ���������� ��ü�� ���� �޸� �Ҵ翡 �����Ͽ����ϴ�. �����մϴ�.");
}

METHOD_STATIC_DEF(AppView, void, msg_coefficientIsNotValid)
{
	puts("[����] 2 ������ ����� 0 �̾, ������������ �ƴմϴ�.\n");
}

METHOD_STATIC_DEF(AppView, void, msg_determinantIsNotValid, QuadEquationProblem* problem)
{
	printf("> �Ǻ����� ��: %.2g\n"
		   "[����] �Ǻ����� ���� �����̾ �ذ� �������� �ʽ��ϴ�.\n\n"
		   , METHOD(QuadEquationProblem, problem, getDeterminant));
}

METHOD_STATIC_DEF(AppView, void, printSolution, QuadEquationProblem* problem)
{
	printf("> �������� �ش� ������ �����ϴ�:\n"
		"x1 = %.2g\n"
		"x2 = %.2g\n\n",
		problem->solution->root1,
		problem->solution->root2
	);
}

METHOD_STATIC_DEF(AppView, void, printDeterminant, QuadEquationProblem* problem)
{
	printf("> �Ǻ����� ��: %g\n",
		METHOD(QuadEquationProblem, problem, getDeterminant)
	);
}

METHOD_STATIC_DEF(AppView, void, msg_startQuadEquation)
{
	puts("<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}

METHOD_STATIC_DEF(AppView, void, msg_endQuadEquation)
{
	puts("\n<<< ���������� Ǯ�̸� �����մϴ� >>>");
}

