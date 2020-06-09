#pragma once

#define  errormsg_kr_too_long_expression "[오류] 수식이 너무 길어 처리가 불가능합니다.\n"
#define  errormsg_kr_too_many_operands   "[오류] 연산자에 비해 연산값의 수가 많습니다.\n"
#define  errormsg_kr_too_few_operands    "[오류] 연산자에 비해 연산값의 수가 적습니다.\n"
#define  errormsg_kr_undefined_operator  "[오류] 수식에 알 수 없는 연산자가 있습니다. \n"
#define  errormsg_kr_divide_by_zero      "[오류] 나눗셈의 분모가 0 입니다\n"

const char*  errormsg_kr[]  = { errormsg_kr_too_long_expression,
                                errormsg_kr_too_many_operands,
                                errormsg_kr_too_few_operands,
                                errormsg_kr_undefined_operator,
                                errormsg_kr_divide_by_zero };