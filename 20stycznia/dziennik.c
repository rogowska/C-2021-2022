/*Oliwia Rogowska*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct student
{
    char name[30];
    char surname[30];
    char grades[30][4];
    int grades_number = 0;
};

float convert(char *a);
float convert(char *a)
{
    if (/* condition */)
    {
        /* code */
    }
};

int compare(struct student s1, struct student s2);
int compare(struct student s1, struct student s2)
{
    int w;
    w = strcmp(s1.surname, s2.surname);
    if (w == 0)
    {
        w = strcmp(s1.name, s2.name);
    }
    return w;
};

void normalize(char *a);
void normalize(char *a)
{
    int i;
    a[0] = toupper(a[0]);
    for (i = 1; i <= strlen(a); tolower(a[i]))
    {
    }
};

int main(int argc, char **argv)
{
    float o, sum, group_sum;
    int a = argc, student_counter, i, j, grades_number, significant_grades;
    FILE *f;
    struct student group[30];
    char sur[30], nam[30], gr[4];
    float student_average[30];
    if (argc < 2)
    {
        fprintf(stderr, "You need to provide a file path as an argument\n");
        return 1;
    }
    while (a > 0)
    {
        student_counter = 0;
        f = fopen(argv[a], "r");
        if (f == NULL)
        {
            fprintf(stderr, "File is empty\n");
            continue;
        }
        while (!feof(f))
        {
            scanf("%s %s %s", nam, sur, gr);
            normalize(sur);
            normalize(nam);
            student_counter++;
            for (i = 0; i < student_counter; i++)
            {
                if ((!strcmp(sur, group[i].surname) && (!strcmp(nam, group[i].name))))
                {
                    grades_number = group[i].grades_number;
                    group[i].grades[grades_number] = gr;
                    grades_number++;
                }
                else
                {
                    student_counter--;
                    group[i + 1].name = nam;
                    group[i + 1].surname = sur;
                    group[i + 1].grades[0] = gr;
                }
                group[i].grades_number = grades_number;
            }
        }

        qsort(group, student_counter, sizeof(struct student), compare);
        printf("Grades from the file: %s\n", argv[a]);
        for (i = 0; i < student_counter; i++)
        {
            sum = 0;
            significant_grades = group[i].grades_number;
            printf("%s %s:", group[i].surname, group[i].name);
            for (j = 0; j < group[i].grades_number; j++)
            {
                printf("%s ", group[i].grades[j]);
                o = convert(group[i].grades[j]);
                if (o < 0)
                {
                    significant_grades--;
                }
                else
                {
                    sum += o;
                }
            }
            student_average[i] = sum / (float)significant_grades;
            printf("Student's average:%.2f\n", student_average[i]);
            group_sum += student_average[i];
        }
        printf("Group's average: %5f\n", group_sum/student_counter);
    }
    return 0;
}