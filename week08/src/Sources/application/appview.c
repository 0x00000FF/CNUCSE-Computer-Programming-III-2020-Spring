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
    appview_out_println("�Է��� �����մϴ�.");
}

void    appview_out_statistics(lecture_view* view)
{
    printf("��� ������ %.1f �Դϴ�.\n"
           "��� �̻��� �л��� ��� %d�� �Դϴ�.\n"
           "�ְ����� %d�� �Դϴ�.\n"
           "�������� %d�� �Դϴ�.\n\n", 
            lecture_view_avg(view),
            lecture_view_above_avg(view),
            lecture_view_max(view),
            lecture_view_min(view));

    printf("A ������ ��� %3d�� �Դϴ�.\n"
            "B ������ ��� %3d�� �Դϴ�.\n"
            "C ������ ��� %3d�� �Դϴ�.\n"
            "D ������ ��� %3d�� �Դϴ�.\n"
            "F ������ ��� %3d�� �Դϴ�.\n",
            lecture_view_get_grade_count(view, 'A'),
            lecture_view_get_grade_count(view, 'B'),
            lecture_view_get_grade_count(view, 'C'),
            lecture_view_get_grade_count(view, 'D'),
            lecture_view_get_grade_count(view, 'F'));
}

void     appview_out_student_info(const student_id id, int score, char grade)
{
    printf("�й�:%s, ����:%d, ����:%c\n", id, score, grade);
}

void    appview_out_sorted_student_list(lecture_view* view)
{
    student* student_list = lecture_view_list(view);
    appview_out_println("�л����� ������ ����Դϴ�.");

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
    printf("[����] �й� %s�� ���̰� �ʹ� ��ϴ�. �ִ� %d�� �Դϴ�.\n", id, max_length);
}

void    appview_err_invalid_score()
{
    appview_out_println("[����] 0���� �۰ų� 100���� Ŀ��, �������� ������ �ƴմϴ�.\n");
}

char    appview_getch()
{
    return _getche();
}

bool    appview_in_get_continue()
{
    printf("? ������ �Է��Ϸ��� 'Y'�� , �Է��� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: ");
    char answer = appview_getch();
    puts("");

    return (answer == 'Y' || answer == 'y');
}

void     appview_in_get_student(student_id id, int* out_score) 
{
    bool result = true;

    printf("- �й��� �Է��Ͻÿ�: ");
    scanf("%s", id);

    printf("- ������ �Է��Ͻÿ�: ");
    scanf("%d", out_score);
}
