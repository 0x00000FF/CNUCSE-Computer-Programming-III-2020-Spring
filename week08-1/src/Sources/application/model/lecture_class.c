#include <model/lecture_class.h>

int  lecture_class_partition(lecture_class* self, int left, int right)
{
    int pivot = left;
    int pivotScore = student_get_score(self->data + pivot);

    int toLeft = right + 1;
    int toRight = left;
    
    do {
        do { toRight++; } while (student_get_score(self->data + toRight) > pivotScore);
        do { toLeft--; } while (student_get_score(self->data + toLeft) < pivotScore);
        if (toRight < toLeft) {
            VECTOR_SWAP(student)(self, toRight, toLeft);
        }
    } while (toRight < toLeft);
    VECTOR_SWAP(student)(self, pivot, toLeft);
    return toLeft;
}

void  lecture_class_qsort_rec(lecture_class* self, int left, int right)
{
    int mid;
    if (left < right) {
        mid = lecture_class_partition(self, left, right);
        lecture_class_qsort_rec(self, left, mid - 1);
        lecture_class_qsort_rec(self, mid + 1, right);
    }
}

void  lecture_class_qsort(lecture_class* self)
{
    int size = VECTOR_SIZE(student)(self);
    // ������ �����ʹ� _this->_elements[0] ���� _this->_elements[size-1] ���� �̴�
    // �� ������ �����Ѵ�
    if (size >= 2) { // ������ 2 �̻��̸�
    // �ּҰ��� ��ġ�� ã�´�
        int minPosition = 0;
        for (int i = 1; i < size; i++) {
            if (student_get_score(self->data + i) <
                student_get_score(self->data + minPosition))
            {
                minPosition = i;
            }
        }
        // �ּҰ��� ���� ������ �� ������ �ű��.
        VECTOR_SWAP(student)(self, minPosition, size - 1);
        // ������ �����Ѵ�
        lecture_class_qsort_rec(self, 0, size - 2);
    }

}

void  lecture_class_sort_score(lecture_class* self)
{
    lecture_class_qsort(self);
}