#include <stdio.h>

int main()
{
    int arr[10];
    int i, j, temp;
    int max, min;
    int sum = 0;
    float mean;
    float minDistance, maxDistance;

    // Step 1: Accept 10 integers
    printf("Enter 10 integers:\n");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    // Step 2: Find maximum and minimum
    max = arr[0];
    min = arr[0];

    for(i = 1; i < 10; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    // Step 3: Calculate mean
    mean = (float)sum / 10;

    printf("\nMaximum = %d", max);
    printf("\nMinimum = %d", min);
    printf("\nMean = %.2f", mean);

    // Step 4: Sort array in ascending order
    for(i = 0; i < 10; i++)
    {
        for(j = i + 1; j < 10; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Step 5: Display sorted array
    printf("\nSorted Array: ");

    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    // Step 6: Find distance of mean from minimum and maximum
    minDistance = mean - min;
    maxDistance = max - mean;

    if(minDistance < maxDistance)
    {
        printf("\nMean is closer to the minimum.");
    }
    else if(maxDistance < minDistance)
    {
        printf("\nMean is closer to the maximum.");
    }
    else
    {
        printf("\nMean is exactly midway between minimum and maximum.");
    }

    return 0;
}
