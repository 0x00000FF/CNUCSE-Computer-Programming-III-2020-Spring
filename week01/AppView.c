#include "AppView.h"

#include <stdio.h>

#if !__PREFER_STANDARD
#include <conio.h>
#endif

void    AppView_out_msg_startSolvingLinearEquation(void) {
	puts("<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}

void    AppView_out_msg_endSolvingLinearEquation(void) {
	puts("\n<<< ���������� Ǯ�̸� �����մϴ� >>>");
}

void    AppView_out_showLinearEquation(float c0, float c1) {
	printf("> �־��� ������: (%.1f)x + (%.1f) = 0\n", c0, c1);
}

void    AppView_out_showRoot(float root) {
	printf("> �������� �ش� ������ �����ϴ�:\n"
		"x=%.1f\n\n", root);
}

void    AppView_out_msg_error_firstOrderTermCoefficientIsZero(void) {
	puts("[����] 1 ������ ����� 0 �̾, �������� Ǯ �� �����ϴ�.\n");
}

bool AppView_in_getSolvingRequest() {
	printf("? �������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�:");

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
		puts("[����] �߸��� �Ķ���Ͱ� ���޵Ǿ����ϴ�.");
		return;
	}

	printf("? 1 ������ ����� �Է��Ͻÿ�: ");
	scanf_s("%f", c0);

	printf("? ������� ����� �Է��Ͻÿ�: ");
	scanf_s("%f", c1);
}