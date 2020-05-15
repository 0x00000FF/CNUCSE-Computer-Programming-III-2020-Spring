#pragma once

#include <stdbool.h>
#include <assert.h> // assert
#include <string.h> // memcpy

#define VECTOR(type)     vector_##type
#define VECTOR_DEF(type) typedef struct { type* data; int capacity; int size; } VECTOR(type)

#define VECTOR_FUNC_NAME(type, name) __vector_##type##_##name

#define VECTOR_NEW(type)             VECTOR_FUNC_NAME(type, new)
#define FUNC_VECTOR_NEW(type)        VECTOR(type)* VECTOR_NEW(type)        (int capacity)
#define FUNC_VECTOR_NEW_IMPL(type)                                                    \
FUNC_VECTOR_NEW(type) {                                                               \
    VECTOR(type)* new_vector = (VECTOR(type)*) malloc(sizeof(VECTOR(type)));          \
                                                                                      \
    new_vector->data = (type*)calloc(capacity, sizeof(type));                         \
    new_vector->capacity = capacity;                                                  \
    new_vector->size = 0;                                                             \
                                                                                      \
    return new_vector;                                                                \
}

#define VECTOR_DELETE(type)             VECTOR_FUNC_NAME(type, delete)
#define FUNC_VECTOR_DELETE(type)        void       VECTOR_DELETE(type)     (VECTOR(type)* self)
#define FUNC_VECTOR_DELETE_IMPL(type)                                                \
FUNC_VECTOR_DELETE(type) {                                                           \
    free(self->data);                                                                \
    free(self);                                                                      \
}

#define VECTOR_AT(type)              VECTOR_FUNC_NAME(type, at)
#define FUNC_VECTOR_AT(type)         type          VECTOR_AT(type)         (VECTOR(type)* self, int at)
#define FUNC_VECTOR_AT_IMPL(type)                                                    \
FUNC_VECTOR_AT(type) {                                                               \
    assert(at < self->size);                                                         \
    return self->data[at];                                                           \
}

#define VECTOR_FRONT(type)           VECTOR_FUNC_NAME(type, front)
#define FUNC_VECTOR_FRONT(type)      type          VECTOR_FRONT(type)      (VECTOR(type)* self)
#define FUNC_VECTOR_FRONT_IMPL(type)                                                 \
FUNC_VECTOR_FRONT(type) {                                                            \
    assert(!VECTOR_EMPTY(type)(self));                                               \
    return self->data[0];                                                            \
}

#define VECTOR_BACK(type)            VECTOR_FUNC_NAME(type, back)
#define FUNC_VECTOR_BACK(type)       type          VECTOR_BACK(type)       (VECTOR(type)* self)
#define FUNC_VECTOR_BACK_IMPL(type)                                                  \
FUNC_VECTOR_BACK(type) {                                                             \
    assert(!VECTOR_EMPTY(type)(self));                                               \
                                                                                     \
    int size = VECTOR_SIZE(type)(self);                                              \
    return self->data[size - 1];                                                     \
}

#define VECTOR_DATA(type)            VECTOR_FUNC_NAME(type, data)
#define FUNC_VECTOR_DATA(type)       type*         VECTOR_DATA(type)       (VECTOR(type)* self)
#define FUNC_VECTOR_DATA_IMPL(type)                                                  \
FUNC_VECTOR_DATA(type) {                                                             \
    return self->data;                                                               \
}

#define VECTOR_EMPTY(type)           VECTOR_FUNC_NAME(type, empty)
#define FUNC_VECTOR_EMPTY(type)      bool          VECTOR_EMPTY(type)      (VECTOR(type)* self)
#define FUNC_VECTOR_EMPTY_IMPL(type)                                                 \
FUNC_VECTOR_EMPTY(type) {                                                            \
    return self->size == 0;                                                          \
}

#define VECTOR_SIZE(type)            VECTOR_FUNC_NAME(type, size)
#define FUNC_VECTOR_SIZE(type)       int           VECTOR_SIZE(type)       (VECTOR(type)* self)
#define FUNC_VECTOR_SIZE_IMPL(type)                                                  \
FUNC_VECTOR_SIZE(type) {                                                             \
    return self->size;                                                               \
}

#define VECTOR_MAX_SIZE(type)        VECTOR_FUNC_NAME(type, max_size)
#define FUNC_VECTOR_MAX_SIZE(type)   int           VECTOR_MAX_SIZE(type)   (VECTOR(type)* self)
#define FUNC_VECTOR_MAX_SIZE_IMPL(type)                                              \
FUNC_VECTOR_MAX_SIZE(type) {                                                         \
    return self->capacity;                                                           \
}

#define VECTOR_CLEAR(type)           VECTOR_FUNC_NAME(type, clear)
#define FUNC_VECTOR_CLEAR(type)      void          VECTOR_CLEAR(type)      (VECTOR(type)* self)
#define FUNC_VECTOR_CLEAR_IMPL(type)                                                 \
FUNC_VECTOR_CLEAR(type) {                                                            \
    free(self->data);                                                                \
    self->data = (type*)malloc(self->capacity * sizeof(type));                 \
}

#define VECTOR_INSERT(type)          VECTOR_FUNC_NAME(type, insert)
#define FUNC_VECTOR_INSERT(type)     void          VECTOR_INSERT(type)     (VECTOR(type)* self, type elem, int pos)
#define FUNC_VECTOR_INSERT_IMPL(type)                                                \
FUNC_VECTOR_INSERT(type) {                                                           \
    if (self->size == self->capacity) {                                              \
        type* temp = self->data;                                                  \
                                                                                     \
        self->capacity *= 2;                                                         \
        self->data = (type*)malloc(self->capacity * sizeof(type));             \
                                                                                     \
        if (self->data != NULL) {                                                    \
            memcpy(self->data, temp, self->size);                                    \
            free(temp);                                                              \
        }                                                                            \
        else {                                                                       \
            self->capacity /= 2;                                                     \
            self->data = temp;                                                       \
                                                                                     \
            return;                                                                  \
        }                                                                            \
    }                                                                                \
                                                                                     \
    for (int i = self->size; i > pos; ++i) {                                         \
        self->data[i] = self->data[i - 1];                                           \
    }                                                                                \
                                                                                     \
    self->data[pos] = elem;                                                          \
    self->size++;                                                                    \
}

#define VECTOR_ERASE(type)           VECTOR_FUNC_NAME(type, erase)
#define FUNC_VECTOR_ERASE(type)      void          VECTOR_ERASE(type)     (VECTOR(type)* self, int pos)
#define FUNC_VECTOR_ERASE_IMPL(type)                                                 \
FUNC_VECTOR_ERASE(type) {                                                            \
    for (int i = pos; i < self->size - 1; ++i) {                                     \
        self->data[i] = self->data[i + 1];                                           \
    }                                                                                \
                                                                                     \
    self->size--;                                                                    \
}


#define VECTOR_PUSH_BACK(type)       VECTOR_FUNC_NAME(type, push_back)
#define FUNC_VECTOR_PUSH_BACK(type)  void          VECTOR_PUSH_BACK(type)  (VECTOR(type)* self, type elem)
#define FUNC_VECTOR_PUSH_BACK_IMPL(type)                                             \
FUNC_VECTOR_PUSH_BACK(type) {                                                        \
    VECTOR_INSERT(type)(self, elem, self->size);                                     \
}

#define VECTOR_POP_BACK(type)        VECTOR_FUNC_NAME(type, pop_back)
#define FUNC_VECTOR_POP_BACK(type)   void          VECTOR_POP_BACK(type)   (VECTOR(type)* self)
#define FUNC_VECTOR_POP_BACK_IMPL(type)                                              \
FUNC_VECTOR_POP_BACK(type) {                                                         \
    VECTOR_ERASE(type)(self, self->size - 1);                                        \
}

#define VECTOR_SWAP(type)            VECTOR_FUNC_NAME(type, swap)
#define FUNC_VECTOR_SWAP(type)       void          VECTOR_SWAP(type)       (VECTOR(type)* self, int pos1, int pos2)
#define FUNC_VECTOR_SWAP_IMPL(type)                                                  \
FUNC_VECTOR_SWAP(type) {                                                             \
    int pos_max = self->size - 1;                                                    \
                                                                                     \
    if (pos1 > pos_max || pos2 > pos_max) {                                          \
        return;                                                                      \
    }                                                                                \
                                                                                     \
    type temp = self->data[pos1];                                                    \
    self->data[pos1] = self->data[pos2];                                             \
    self->data[pos2] = temp;                                                         \
}
