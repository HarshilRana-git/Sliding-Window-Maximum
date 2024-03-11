#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
    if (nums == NULL || numsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    int *res = (int *)malloc((*returnSize) * sizeof(int));
    if (res == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i <= numsSize - k; i++)
    {
        int maxVal = INT_MIN;
        for (int j = i; j < i + k; j++)
        {
            if (nums[j] > maxVal)
            {
                maxVal = nums[j];
            }
        }
        res[i] = maxVal;
    }

    return res;
}

int main()
{
    const int ARRAY_SIZE = 10;                           // Increase the size of the array
    int *nums = (int *)malloc(ARRAY_SIZE * sizeof(int)); // Allocate memory dynamically
    if (nums == NULL)
    {
        printf("Memory allocation failed.\n");
        return -1;
    }

    printf("INPUT :");
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        nums[i] = rand() % 100; // Fill array with random numbers
        printf("%d ", nums[i]);
    }

    int k = 3; // Increase the window size
    int numsSize = ARRAY_SIZE;
    int returnSize;
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int *result = maxSlidingWindow(nums, numsSize, k, &returnSize);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nCPU time taken: %f seconds\n", cpu_time_used);

    // Print the output
    printf("OUTPUT :");

    for (int i = 0; i < returnSize; ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(nums); // Free dynamically allocated memory

    return 0;
}
