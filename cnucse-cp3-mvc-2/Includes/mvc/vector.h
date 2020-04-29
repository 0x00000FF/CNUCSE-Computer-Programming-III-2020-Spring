#pragma once

#include <stdbool.h>

#define VECTOR(type)     vector_##type
#define VECTOR_DEF(type) typedef struct { type* data; int capacity; int size; } VECTOR(type)

#define VECTOR_FUNC_NAME(type, name) __vector_##type##_##name

#define VECTOR_NEW(type)             VECTOR_FUNC_NAME(type, new)
#define FUNC_VECTOR_NEW(type)        VECTOR(type)* VECTOR_NEW(type)        (int capacity)

#define VECTOR_AT(type)              VECTOR_FUNC_NAME(type, at)
#define FUNC_VECTOR_AT(type)         type          VECTOR_AT(type)         (VECTOR(type)* self, int at)

#define VECTOR_FRONT(type)           VECTOR_FUNC_NAME(type, front)
#define FUNC_VECTOR_FRONT(type)      type          VECTOR_FRONT(type)      (VECTOR(type)* self)

#define VECTOR_BACK(type)            VECTOR_FUNC_NAME(type, back)
#define FUNC_VECTOR_BACK(type)       type          VECTOR_BACK(type)       (VECTOR(type)* self)

#define VECTOR_DATA(type)            VECTOR_FUNC_NAME(type, data)
#define FUNC_VECTOR_DATA(type)       type*         VECTOR_DATA(type)       (VECTOR(type)* self)

#define VECTOR_EMPTY(type)           VECTOR_FUNC_NAME(type, empty)
#define FUNC_VECTOR_EMPTY(type)      bool          VECTOR_EMPTY(type)      (VECTOR(type)* self)

#define VECTOR_SIZE(type)            VECTOR_FUNC_NAME(type, size)
#define FUNC_VECTOR_SIZE(type)       int           VECTOR_SIZE(type)       (VECTOR(type)* self)

#define VECTOR_MAX_SIZE(type)        VECTOR_FUNC_NAME(type, max_size)
#define FUNC_VECTOR_MAX_SIZE(type)   int           VECTOR_MAX_SIZE(type)   (VECTOR(type)* self)

#define VECTOR_CLEAR(type)           VECTOR_FUNC_NAME(type, clear)
#define FUNC_VECTOR_CLEAR(type)      void          VECTOR_CLEAR(type)      (VECTOR(type)* self)

#define VECTOR_INSERT(type)          VECTOR_FUNC_NAME(type, insert)
#define FUNC_VECTOR_INSERT(type)     void          VECTOR_INSERT(type)     (VECTOR(type)* self, type elem, int pos)

#define VECTOR_ERASE(type)           VECTOR_FUNC_NAME(type, erase)
#define FUNC_VECTOR_ERASE(type)      void          VECTOR_INSERT(type)     (VECTOR(type)* self, int pos)

#define VECTOR_PUSH_BACK(type)       VECTOR_FUNC_NAME(type, push_back)
#define FUNC_VECTOR_PUSH_BACK(type)  void          VECTOR_PUSH_BACK(type)  (VECTOR(type)* self, type elem)

#define VECTOR_POP_BACK(type)        VECTOR_FUNC_NAME(type, pop_back)
#define FUNC_VECTOR_POP_BACK(type)   void          VECTOR_POP_BACK(type)   (VECTOR(type)* self)

#define VECTOR_SWAP(type)            VECTOR_FUNC_NAME(type, swap)
#define FUNC_VECTOR_SWAP(type)       void          VECTOR_SWAP(type)       (VECTOR(type)* self, int pos1, int pos2)