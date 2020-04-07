﻿#ifndef __APPVIEW_H
#define __APPVIEW_H

#include <stdbool.h>

#include "Macros.h"


void          AppView_out_msg_startMagicSquare(void);
void          AppView_out_msg_endMagicSquare(void);
void          AppView_out_printMagicSquare(BOARD_ARG(board), int order);

void          AppView_err_msg_orderTooSmall(void);
void          AppView_err_msg_orderIsNotOdd(void);
void          AppView_err_msg_orderTooLarge(void);

int  AppView_in_getNextOrder(void);

#endif