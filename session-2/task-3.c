#include <stdio.h>

struct Student
{
    char name[50];
    int rollno;
    float marks;
    char grade;
};

void assignGrade(struct Student *s)
{
    if (s->marks >= 90)
        s->grade = 'A';
    else if (s->marks >= 80)
        s->grade = 'B';
    else if (s->marks >= 70)
        s->grade = 'C';
    else if (s->marks >= 60)
        s->grade = 'D';
    else
        s->grade = 'F';
}

void printTopper(struct Student s[], int n)
{
    int i, top = 0;

    for (i = 1; i < n; i++)
    {
        if (s[i].marks > s[top].marks)
        {
            top = i;
        }
    }

    printf("\nTopper: %s\n", s[top].name);
    printf("Marks: %.2f\n", s[top].marks);
}

int main()
{
    struct Student s[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("\nEnter Student %d details:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Roll No: ");
        scanf("%d", &s[i].rollno);

        printf("Marks: ");
        scanf("%f", &s[i].marks);

        assignGrade(&s[i]);
    }

    printf("\n--------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n",
           "Name", "Roll No", "Marks", "Grade");
    printf("--------------------------------------------------\n");

    for (i = 0; i < 3; i++)
    {
        printf("%-20s %-10d %-10.2f %-10c\n",
               s[i].name,
               s[i].rollno,
               s[i].marks,
               s[i].grade);
    }

    printf("--------------------------------------------------\n");

    printTopper(s, 3);

    return 0;
}
