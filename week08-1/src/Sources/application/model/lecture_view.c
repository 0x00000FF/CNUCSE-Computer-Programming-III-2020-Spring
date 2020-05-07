#include <model/lecture_class.h>
#include <model/lecture_view.h>

student* lecture_view_list(lecture_view* self) {
    return self->students->data;
}

int   lecture_view_total(lecture_view* self)
{
    return self->total;
}

int   lecture_view_get_grade_count(lecture_view* self, char grade) {
    if (grade == 'F') grade--;
    return self->grade_count[grade - 'A'];
}

int   lecture_view_sum_rec(lecture_view* self, int left)
{
    if (left >= self->total) return 0;

    int current_score = student_get_score(self->students->data + left);
    return current_score + lecture_view_sum_rec(self, left + 1);
}

int   lecture_view_sum(lecture_view* self)
{
    return lecture_view_sum_rec(self, 0);
}

int   lecture_view_min_rec(lecture_view* self, int left)
{
    if (left >= self->total) return 100;

    int current_score = student_get_score(self->students->data + left);
    int current_min = lecture_view_min_rec(self, left + 1);

    return current_score < current_min ? current_score : current_min;
}

int   lecture_view_min(lecture_view* self)
{
    return lecture_view_min_rec(self, 0);
}

int   lecture_view_max_rec(lecture_view* self, int left)
{
    if (left >= self->total) return 0;
    
    int current_score = student_get_score(self->students->data + left);
    int current_max = lecture_view_max_rec(self, left + 1);

    return current_score > current_max ? current_score : current_max;
}

int   lecture_view_max(lecture_view* self)
{
    return lecture_view_max_rec(self, 0);
}

float lecture_view_avg(lecture_view* self) {
    return (float)lecture_view_sum(self) / self->total;
}

int   lecture_view_above_avg(lecture_view* self)
{
    float avg   = lecture_view_avg(self);
    int   count = 0;

    while (true) {
        int score = student_get_score(self->students->data + count);
        if (score < avg) break;

        count++;
    }

    return count;
}

char  lecture_view_conv_grade(int score)
{
    return "FFFFFFDCBAA"[score / 10];
}

void  lecture_view_count_grade_rec(lecture_view* self, int grade_count[5], int left) 
{
    if (left >= self->total) return;

    int  score = student_get_score(self->students->data + left);
    char grade = lecture_view_conv_grade(score);

    if (grade == 'F') grade--;
    grade_count[grade - 'A']++;

    lecture_view_count_grade_rec(self, grade_count, left + 1);
}

void  lecture_view_count_grades(lecture_view* self)
{
    self->grade_count[0] = 0;
    self->grade_count[1] = 0;
    self->grade_count[2] = 0;
    self->grade_count[3] = 0;
    self->grade_count[4] = 0;

    lecture_view_count_grade_rec(self, self->grade_count, 0);
}


lecture_view* lecture_view_create(lecture_class* list) 
{
    if (list == NULL) return NULL;
    
    lecture_view* new_view = (lecture_view*)malloc(sizeof(lecture_view));
    
    new_view->total      = VECTOR_SIZE(student)(list);
    new_view->students   = VECTOR_NEW(student)(new_view->total);

    memcpy(VECTOR_DATA(student)(new_view->students), 
            VECTOR_DATA(student)(list), 
            new_view->total * sizeof(student));

    new_view->students->size = new_view->total;

    lecture_class_sort_score(new_view->students);
    lecture_view_count_grades(new_view);

    return new_view;
}

void lecture_view_delete(lecture_view* self)
{
    VECTOR_DELETE(student)(self->students);
    free(self);
}