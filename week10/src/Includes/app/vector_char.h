#pragma once

#include <stdlib.h>
#include <mvc/vector.h>

typedef char element;

VECTOR_DEF(element);

FUNC_VECTOR_NEW(element);
FUNC_VECTOR_DELETE(element);
FUNC_VECTOR_AT(element);
FUNC_VECTOR_FRONT(element);
FUNC_VECTOR_BACK(element);
FUNC_VECTOR_DATA(element);
FUNC_VECTOR_EMPTY(element);
FUNC_VECTOR_SIZE(element);
FUNC_VECTOR_MAX_SIZE(element);
FUNC_VECTOR_CLEAR(element);
FUNC_VECTOR_INSERT(element);
FUNC_VECTOR_ERASE(element);
FUNC_VECTOR_PUSH_BACK(element);
FUNC_VECTOR_POP_BACK(element);
FUNC_VECTOR_SWAP(element);