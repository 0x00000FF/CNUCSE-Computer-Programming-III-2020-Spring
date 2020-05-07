#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

#include <mvc/appview.h>
#include <model/student.h>

void    appview_out_println(const char* str)
{
    puts(str);
}

void    appview_out_end_of_input()
{
    appview_out_println("입력을 종료합니다.");
}

void    appview_out_statistics(lecture_view* view)
{
    printf("평균 점수는 %.1f 입니다.\n"
           "평균 이상인 학생은 모두 %d명 입니다.\n"
           "최고점은 %d점 입니다.\n"
           "최저점은 %d점 입니다.\n\n", 
            lecture_view_avg(view),
            lecture_view_above_avg(view),
            lecture_view_max(view),
            lecture_view_min(view));

    printf("A 학점은 모두 %3d명 입니다.\n"
            "B 학점은 모두 %3d명 입니다.\n"
            "C 학점은 모두 %3d명 입니다.\n"
            "D 학점은 모두 %3d명 입니다.\n"
            "F 학점은 모두 %3d명 입니다.\n",
            lecture_view_get_grade_count(view, 'A'),
            lecture_view_get_grade_count(view, 'B'),
            lecture_view_get_grade_count(view, 'C'),
            lecture_view_get_grade_count(view, 'D'),
            lecture_view_get_grade_count(view, 'F'));
}

void     appview_out_student_info(const student_id id, int score, char grade)
{
    printf("학번:%s, 점수:%d, 학점:%c\n", id, score, grade);
}

void    appview_out_sorted_student_list(lecture_view* view)
{
    student* student_list = lecture_view_list(view);
    appview_out_println("학생들의 성적순 목록입니다.");

    for (int i = 0; i < lecture_view_total(view); ++i) {
        int score = student_get_score(student_list + i);
        appview_out_student_info(
            student_get_student_id(student_list + i),
            score,
            lecture_view_conv_grade(score));
    }
}

void    appview_err_too_long_id(student_id id, int max_length)
{
    printf("[오류] 학번 %s의 길이가 너무 깁니다. 최대 %d자 입니다.\n", id, max_length);
}

void    appview_err_invalid_score()
{
    appview_out_println("[오류] 0보다 작거나 100보다 커서, 정상적인 점수가 아닙니다.\n");
}

char    appview_getch()
{
    return _getche();
}

bool    appview_in_get_continue()
{
    printf("? 성적을 입력하려면 'Y'를 , 입력을 종료하려면 다른 아무 키나 치시오: ");
    char answer = appview_getch();
    puts("");

    return (answer == 'Y' || answer == 'y');
}

void     appview_in_get_student(student_id id, int* out_score) 
{
    bool result = true;

    printf("- 학번을 입력하시오: ");
    scanf("%s", id);

    printf("- 점수를 입력하시오: ");
    scanf("%d", out_score);
}
