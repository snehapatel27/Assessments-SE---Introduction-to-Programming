//### Boundary Testing and Bug Fix

//I tested the C program using three boundary inputs.

/***(a) All 10 values identical**

Input:

```text
5 5 5 5 5 5 5 5 5 5
```

Output:

```text
Maximum = 5
Minimum = 5
Mean = 5.00
Sorted Array: 5 5 5 5 5 5 5 5 5 5
Mean is equal to both minimum and maximum.
```

**(b) Mix of positive and negative integers**

Input:

```text
-10 -5 0 5 10 15 -15 20 -20 25
```

Output:

```text
Maximum = 25
Minimum = -20
Mean = 2.50
Sorted Array: -20 -15 -10 -5 0 5 10 15 20 25
Mean is closer to the maximum.
```

**(c) Mean exactly between minimum and maximum**

Input:

```text
10 20 20 20 20 20 20 20 20 30
```

Output:

```text
Maximum = 30
Minimum = 10
Mean = 20.00
Sorted Array: 10 20 20 20 20 20 20 20 20 30
Mean is exactly midway between minimum and maximum.


### Bug / Edge Case Found

I found an edge case when all 10 values are identical. In this case, the minimum, maximum, and mean are all the same. The original program incorrectly reports that the mean is exactly midway between the minimum and maximum.

I fixed it by adding a separate condition:

```c
if(min == max)
{
    printf("\nMean is equal to both minimum and maximum.");
}
else if(minDistance < maxDistance)
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
```

After this fix, the program correctly handles all three boundary cases.*/


//Add the complete corrected C program:=
#include <stdio.h>

int main()
{
    int arr[10];
    int i, j, temp;
    int max, min;
    int sum = 0;
    float mean;
    float minDistance, maxDistance;

    // Step 1: Accept exactly 10 integers
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

    // Step 3: Calculate arithmetic mean
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

    // Step 6: Compare mean with minimum and maximum
    minDistance = mean - min;
    maxDistance = max - mean;

    if(min == max)
    {
        printf("\nMean is equal to both minimum and maximum.");
    }
    else if(minDistance < maxDistance)
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
