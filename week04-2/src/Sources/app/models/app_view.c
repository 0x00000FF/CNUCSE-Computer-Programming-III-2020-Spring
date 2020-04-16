#include <app/app_view.h>
#include <stdio.h>

#pragma warning(disable: 4996)

void    AppView_out_msg_startMagicSquare(void) {
	puts("<<< ������ Ǯ�̸� �����մϴ� >>>\n");
}

void    AppView_out_msg_endMagicSquare(void) {
	puts("\n<<< ������ Ǯ�̸� �����մϴ� >>>");
}

void    AppView_msg_allocationFailed(void) {
	puts("[����] ������ ��ü �Ҵ翡 �����Ͽ����ϴ�.\n");
}

void   AppView_out_printMagicSquare(MagicSquare* ms) {
	unsigned int i, j, order = ms->order;

	printf("> Magic Square Board: Order %d\n      ", ms->order);
	for (i = 0; i < order; ++i) {
		if (i == 0) {
			for (i = 0; i < order; ++i) {
				printf(" [ %2d ]", i);
			}

			i = 0;
			puts("");
		}

		for (j = 0; j < order; ++j) {
			if (j == 0) {
				printf("[ %2d ]", i);
			}

			printf(" %6d", ms->board[i * order + j]);
		}
		puts("");
	}

	puts("");
}

void    AppView_err_msg_orderTooSmall(void) {
	puts("[����] ������ �ʹ� �۽��ϴ�. 3���� ũ�ų� ���ƾ� �մϴ�.\n");
}

void    AppView_err_msg_orderIsNotOdd(void) {
	puts("[����] ������ ¦���Դϴ�. Ȧ���̾�� �մϴ�.\n");
}

void    AppView_err_msg_orderTooLarge(void) {
	puts("[����] ������ �ʹ� Ů�ϴ�. 99���� ũ�ų� ���ƾ� �մϴ�.\n");
}

int     AppView_in_getNextOrder(void) {
	int  input = 0;

	printf("? ������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &input);

	return input;
}
