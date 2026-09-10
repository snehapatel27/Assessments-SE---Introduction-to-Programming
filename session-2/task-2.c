#include <stdio.h>

int main()
{
    float hours[7];
    float total = 0;
    float average;
    int i;
    int highestDay = 0;
    int stars;

    // Accept study hours for 7 days
    for(i = 0; i < 7; i++)
    {
        do
        {
            printf("Enter study hours for Day %d: ", i + 1);
            scanf("%f", &hours[i]);

            if(hours[i] < 0 || hours[i] > 24)
            {
                printf("Invalid input! Enter hours between 0 and 24.\n");
            }

        } while(hours[i] < 0 || hours[i] > 24);

        total = total + hours[i];

        // Find day with highest study hours
        if(hours[i] > hours[highestDay])
        {
            highestDay = i;
        }
    }

    // Calculate average
    average = total / 7;

    // Display performance summary
    printf("\n===== PERFORMANCE SUMMARY =====\n");
    printf("Weekly Total: %.2f hours\n", total);
    printf("Daily Average: %.2f hours\n", average);
    printf("Highest Study Hours: Day %d (%.2f hours)\n",
           highestDay + 1, hours[highestDay]);

    // Display visual bars
    printf("\n===== STUDY HOURS BAR =====\n");

    for(i = 0; i < 7; i++)
    {
        stars = (int)hours[i];

        printf("Day %d: ", i + 1);

        while(stars > 0)
        {
            printf("*");
            stars--;
        }

        printf("\n");
    }

    return 0;
}
