#include <stdlib.h>
#include <app/model/lecture_class.h>

#define SWAP(T, a, b) {                   \
     T* _a = &a;                          \
     T* _b = &b;                          \
     T  _temp = *_a;                      \
	 *_a = *_b;                           \
     *_b = _temp;                         \
}

METHOD_STATIC_DEF(LectureClass, LectureClass*, create, int capacity)
{
	LectureClass* lc = NEW(LectureClass);

	lc->last = -1;

	lc->capacity = capacity;
	lc->scores   = NEW_ARR(int, capacity);

	return lc;
}

METHOD_STATIC_DEF(LectureClass, char, grade, int score)
{
	return "FFFFFFDCBAA"[score / 10];
}

METHOD_STATIC_DEF(LectureClass, bool, scoreValid, int score)
{
	return (score >= 0 && score <= 100);
}

METHOD_DEF(LectureClass, void, destroy)
{
	if (self->scores != NULLPTR)
		DELETE(self->scores);
}

METHOD_DEF(LectureClass, int, capacity)
{
	return self->capacity;
}

METHOD_DEF(LectureClass, int, size)
{
	return self->last + 1;
}

METHOD_DEF(LectureClass, bool, empty)
{
	return self->last == -1;
}

METHOD_DEF(LectureClass, bool, is_full)
{
	return METHOD(LectureClass, self, size) == self->capacity;
}

METHOD_DEF(LectureClass, bool, add, int score)
{
	if (METHOD(LectureClass, self, is_full)) {
		return false;
	}

	self->scores[++self->last] = score;
	return true;
}

METHOD_DEF(LectureClass, int, at, int pos) {
	if (pos > self->last) {
		return -1;
	}

	return self->scores[pos];
}

METHOD_DEF(LectureClass, int, sort_quick_part, int left, int right) {
	int pivot = left;
	int pivotScore = self->scores[pivot];
	right++;
	do {
		do { left++; } while (self->scores[left] > pivotScore);
		do { right--; } while (self->scores[right] < pivotScore);
		if (left < right) {
			SWAP(int, self->scores[left], self->scores[right]);
		}
	} while (left < right);
	SWAP(int, self->scores[pivot], self->scores[right]);
	return right;
}

METHOD_DEF(LectureClass, void, sort_quick_rec, int left, int right) {
	if (left < right) {
		int mid = METHOD(LectureClass, self, sort_quick_part, left, right);
		METHOD(LectureClass, self, sort_quick_rec, 0, mid - 1);
		METHOD(LectureClass, self, sort_quick_rec, mid + 1, right);
	}
}

METHOD_DEF(LectureClass, void, sort_score) {
	int size = self->last + 1;
	
	// 정렬할 데이터는 _this->_elements[0] 부터 _this->_elements[size-1] 까지 이다
	// 퀵 정렬을 실행한다
	if (size >= 2) { // 개수가 2 이상이면
	// 최소값의 위치를 찾는다
		int minPosition = 0;
		for (int i = 1; i < size; i++) {
			if (self->scores[i] < self->scores[minPosition]) {
				minPosition = i;
			}
		}
		// 최소값을 원소 구간의 맨 끝으로 옮긴다.
		SWAP(int, self->scores[minPosition], self->scores[size - 1]);
		// 정렬을 시작한다
		METHOD(LectureClass, self, sort_quick_rec, 0, size - 2);
	}

}

METHOD_DEF(LectureClass, int, min_rec, int left, int right) {
	if (left > right) return 100;
	
	int min_sofar = METHOD(LectureClass, self, min_rec, left + 1, right);
	return self->scores[left] < min_sofar ? self->scores[left] : min_sofar;
}

METHOD_DEF(LectureClass, int, min) {
	if (METHOD(LectureClass, self, empty)) return -1;
	return METHOD(LectureClass, self, min_rec, 0, self->last);
}

METHOD_DEF(LectureClass, int, max_rec, int left, int right) {
	if (left > right) return 0;

	int max_sofar = METHOD(LectureClass, self, max_rec, left + 1, right);
	return self->scores[left] > max_sofar ? self->scores[left] : max_sofar;
}

METHOD_DEF(LectureClass, int, max) {
	if (METHOD(LectureClass, self, empty)) return -1;
	return METHOD(LectureClass, self, max_rec, 0, self->last);
}

METHOD_DEF(LectureClass, int*, list) {
	return self->scores;
}

METHOD_DEF(LectureClass, int, sum_rec, int left, int right) {
	if (left > right) return 0;
	return self->scores[left] + METHOD(LectureClass, self, sum_rec, left+1, right);
}

METHOD_DEF(LectureClass, int, sum) {
	return METHOD(LectureClass, self, sum_rec, 0, self->last);
}

METHOD_DEF(LectureClass, int, aboveAverage) {
	int   size  = METHOD(LectureClass, self, size);
	int   count = 0;
	float avg   = METHOD(LectureClass, self, average);

	for (int i = 0; i < size; ++i) {
		if (self->scores[i] > avg) count++;
	}

	return count;
}

METHOD_DEF(LectureClass, float, average) {
	int sum = METHOD(LectureClass, self, sum);
	return (float)sum / METHOD(LectureClass, self, size);
}

METHOD_DEF(LectureClass, void, grades, int gradeList[5]) {
	int   size = METHOD(LectureClass, self, size);

	// init
	gradeList[0] = 0;
	gradeList[1] = 0;
	gradeList[2] = 0;
	gradeList[3] = 0;
	gradeList[4] = 0;

	for (int i = 0; i < size; ++i) {
		char grade = METHOD_STATIC(LectureClass, grade, self->scores[i]);
		if (grade == 'F') grade--;
		
		gradeList[grade - 'A']++;
	}
}