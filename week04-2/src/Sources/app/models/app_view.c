#include <app/app_view.h>
#include <stdio.h>

#pragma warning(disable: 4996)

void    AppView_out_msg_startMagicSquare(void) {
	puts("<<< 마방진 풀이를 시작합니다 >>>\n");
}

void    AppView_out_msg_endMagicSquare(void) {
	puts("\n<<< 마방진 풀이를 종료합니다 >>>");
}

void    AppView_msg_allocationFailed(void) {
	puts("[오류] 마방진 객체 할당에 실패하였습니다.\n");
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
	puts("[오류] 차수가 너무 작습니다. 3보다 크거나 같아야 합니다.\n");
}

void    AppView_err_msg_orderIsNotOdd(void) {
	puts("[오류] 차수가 짝수입니다. 홀수이어야 합니다.\n");
}

void    AppView_err_msg_orderTooLarge(void) {
	puts("[오류] 차수가 너무 큽니다. 99보다 크거나 같아야 합니다.\n");
}

int     AppView_in_getNextOrder(void) {
	int  input = 0;

	printf("? 마방진 차수를 입력하시오: ");
	scanf("%d", &input);

	return input;
}
