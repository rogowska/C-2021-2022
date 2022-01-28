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
    int grades_number;
};

float convert(char *a);
float convert(char *a)
{
    int i;
    float number = 0;
    for (i = 0; i < 4; i++)
    {
        if (strcmp(&a[i], "+") == 0)
        {
            number = number + 0.25;
            a = strtok(a, "+");
        };
        if (strcmp(&a[i], "-") == 0)
        {
            number = number - 0.25;
            a = strtok(a, "-");
        };
    };
    number += atof(a);
    return number;
};

int compare(const void *s1, const void *s2);
int compare(const void *s1, const void *s2)
{
    const struct student ps1 = *(const struct student *)s1;
    const struct student ps2 = *(const struct student *)s2;
    int w;
    w = strcmp(ps1.surname, ps2.surname);
    if (w == 0)
    {
        w = strcmp(ps1.name, ps2.name);
    }
    return w;
};

void normalize(char *a);
void normalize(char *a)
{
    int i;
    a[0] = toupper(a[0]);
    for (i = 1; i <= strlen(a); i++)
    {
        a[i] = tolower(a[i]);
    }
};

int main(int argc, char **argv)
{
    float float_grade, student_sum, group_sum;
    int file_counter = argc, student_counter, i, j, grades_number, significant_grades, new_student, fscanf_returned_value;
    FILE *f;
    struct student group[30];
    char sur[30], nam[30], gr[4];
    float student_average[30];

    if (argc < 2)
    {
        fprintf(stderr, "You need to provide a file path as an argument\n");
        return 1;
    }

    /*loop over all files*/
    while (file_counter - 1 > 0)
    {
        group_sum = 0;
        f = fopen(argv[file_counter - 1], "r");
        if (f == NULL)
        {
            fprintf(stderr, "%s %s\n\n", "Unable to open the file:", argv[file_counter - 1]);
        }
        else
        {
            student_counter = 0;
            /*set all student's grade counter to 0*/
            for (i = 0; i <= 30; i++)
            {
                group[i].grades_number = 0;
            };
            /*loop till the end of file*/
            while (1)
            {
                fscanf_returned_value = fscanf(f, "%s %s %s", nam, sur, gr);
                if (fscanf_returned_value == -1)
                {
                    break;
                }
                /*every line should contain 3 strings*/
                if ((fscanf_returned_value < 3) && (fscanf_returned_value > 0))
                {
                    fprintf(stderr, "%s\n", nam);
                    fprintf(stderr, "Invalid data format, expected: \nSurname Name grade (as: 0,2,3,4,5 optionally with '+' or '-') \nDiscarding record...\n");
                }
                else
                {
                    normalize(sur);
                    normalize(nam);
                    /*new student indicator set as true*/
                    new_student = 1; 
                    for (i = 0; i < student_counter + 1; i++)
                    {
                        /*check for student in group*/ 
                        if ((!strcmp(sur, group[i].surname) && (!strcmp(nam, group[i].name))))
                        {
                            grades_number = group[i].grades_number;
                            strcpy(group[i].grades[grades_number], gr);
                            group[i].grades_number++;
                            new_student = 0;
                        }
                    }
                    /*add new student*/
                    if (new_student)
                    {
                        student_counter++;
                        strcpy(group[student_counter - 1].name, nam);
                        strcpy(group[student_counter - 1].surname, sur);
                        strcpy(group[student_counter - 1].grades[0], gr);
                        group[student_counter - 1].grades_number = 1;
                    }
                }
                if (feof(f) == 1)
                {
                    break;
                }
            }

            /*student statistic*/
            if (student_counter > 0)
            {
                qsort(group, student_counter, sizeof(struct student), compare);
                printf("Grades from the file: %s\n", argv[file_counter - 1]);
                for (i = 0; i < student_counter; i++)
                {
                    student_sum = 0;
                    /*significant_grades variable counts number of proper grades*/
                    significant_grades = group[i].grades_number;
                    printf("%s %s: ", group[i].surname, group[i].name);
                    for (j = 0; j < group[i].grades_number; j++)
                    {
                        printf("%s ", group[i].grades[j]);
                        float_grade = convert(group[i].grades[j]);
                        /*remove incorrect grade from averages*/
                        if (!(float_grade == 0) && !(float_grade >= 2 && float_grade <= 5))
                        {
                            fprintf(stderr, "%s %s %s %s\n", group[i].surname, group[i].name, group[i].grades[j], "Invalid data format, expected grade should be in range: <2,5> or 0");
                            significant_grades--;
                        }
                        else
                        {
                            student_sum += float_grade;
                        }
                    }
                    if (significant_grades <= 0)
                    {
                        printf("%s\n", "Student has no grades.");
                    }
                    else
                    {
                        student_average[i] = student_sum / (float)significant_grades;
                        printf("Student's average: %.2f\n", student_average[i]);
                        group_sum += student_average[i];
                    }
                }
                printf("Group's average: %.2f\n\n", group_sum / student_counter);
            }
        }
        file_counter--;
    }
    return 0;
}