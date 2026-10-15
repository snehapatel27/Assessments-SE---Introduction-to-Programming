#include <stdio.h>

struct StudyLog
{
    char subject[40];
    float hours[7];
};

// Function to display weekly report
void weeklyReport(struct StudyLog logs[], int count)
{
    int i, j;
    float total, average;
    int dots;

    printf("\n WEEKLY REPORT \n");

    for(i = 0; i < count; i++)
    {
        total = 0;

        for(j = 0; j < 7; j++)
        {
            total = total + logs[i].hours[j];
        }

        average = total / 7;

        printf("\nSubject: %s", logs[i].subject);
        printf("\nWeekly Total: %.2f hours", total);
        printf("\nDaily Average: %.2f hours\n", average);

        printf("Progress Chart:\n");

        for(j = 0; j < 7; j++)
        {
            dots = (int)logs[i].hours[j];

            printf("Day %d: ", j + 1);

            while(dots > 0)
            {
                printf("*");
                dots--;
            }

            printf("\n");
        }
    }
}

// Function to save data into file
void saveData(struct StudyLog logs[], int count)
{
    FILE *fp;
    int i, j;

    fp = fopen("productivity_log.txt", "w");

    if(fp == NULL)
    {
        printf("\nFile could not be opened.");
        return;
    }

    for(i = 0; i < count; i++)
    {
        fprintf(fp, "%s", logs[i].subject);

        for(j = 0; j < 7; j++)
        {
            fprintf(fp, ",%.2f", logs[i].hours[j]);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("\nData saved successfully to productivity_log.txt\n");
}

int main()
{
    struct StudyLog logs[3] =
    {
        {"C Programming", {0, 0, 0, 0, 0, 0, 0}},
        {"PHP", {0, 0, 0, 0, 0, 0, 0}},
        {"HTML CSS", {0, 0, 0, 0, 0, 0, 0}}
    };

    int choice;
    int subject;
    int day;
    float hours;

    do
    {
        printf("\n\n STUDENT PRODUCTIVITY TRACKER \n");
        printf("1. Log Today's Study Hours\n");
        printf("2. View Weekly Report\n");
        printf("3. Save & Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nSelect Subject:\n");
            printf("1. C Programming\n");
            printf("2. PHP\n");
            printf("3. HTML CSS\n");

            printf("Enter subject number: ");
            scanf("%d", &subject);

            printf("Enter day number (1-7): ");
            scanf("%d", &day);

            if(subject >= 1 && subject <= 3 &&
               day >= 1 && day <= 7)
            {
                printf("Enter study hours: ");
                scanf("%f", &hours);

                logs[subject - 1].hours[day - 1] = hours;

                printf("Study hours logged successfully!\n");
            }
            else
            {
                printf("Invalid subject or day number.\n");
            }
        }
        else if(choice == 2)
        {
            weeklyReport(logs, 3);
        }
        else if(choice == 3)
        {
            saveData(logs, 3);
            printf("Thank you! Program exited.\n");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 3);

    return 0;
}
