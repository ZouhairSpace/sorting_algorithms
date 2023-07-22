#include "sort.h"
#include <stdio.h>

/**
 * _calloc - Allocates memory for an array and initializes it to 0
 * @nmemb: Number of elements in the array
 * @size: Size of each element in bytes
 * Return: Pointer to the allocated memory, or NULL if it fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    unsigned int i = 0;
    char *memory_block;

    if (nmemb == 0 || size == 0)
        return (NULL);

    memory_block = malloc(nmemb * size);
    if (memory_block == NULL)
        return (NULL);

    for (i = 0; i < (nmemb * size); i++)
        memory_block[i] = 0;

    return (memory_block);
}

/**
 * merge - Merges two sorted arrays into one sorted array
 * @arr: Original array to merge
 * @tmp: Temporary array used in the merge process
 * @start: Starting index of the left sub-array
 * @mid: Middle index between the left and right sub-arrays
 * @end: Ending index of the right sub-array
 */
void merge(int *arr, int *tmp, int start, int mid, int end)
{
    /* Sizes and temporary arrays */
    int size_left = mid - start + 1, size_right = end - mid;
    int *left_array, *right_array;

    /* Counters */
    int left, right, i = start;

    left_array = &tmp[0];
    right_array = &tmp[size_left];

    /* Copy data to the temporary arrays */
    for (left = 0; left < size_left; left++)
        left_array[left] = arr[start + left];
    for (right = 0; right < size_right; right++)
        right_array[right] = arr[mid + 1 + right];

    left = 0;
    right = 0;

    /* Merge the temporary arrays back into the original array */
    while (left < size_left && right < size_right)
    {
        if (left_array[left] <= right_array[right])
            arr[i] = left_array[left++];
        else
            arr[i] = right_array[right++];
        i++;
    }

    /* Copy the remaining elements of the left array, if any */
    while (left < size_left)
        arr[i++] = left_array[left++];

    /* Copy the remaining elements of the right array, if any */
    while (right < size_right)
        arr[i++] = right_array[right++];

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left_array, size_left);
    printf("[right]: ");
    print_array(right_array, size_right);
    printf("[Done]: ");
    print_array(&arr[start], size_left + size_right);
}

/**
 * mergesort - Recursive function that applies the merge sort algorithm
 * @array: Array to be sorted
 * @tmp: Temporary array used in the merge process
 * @start: Starting index of the sub-array to be sorted
 * @end: Ending index of the sub-array to be sorted
 */
void mergesort(int *array, int *tmp, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(array, tmp, start, mid);
        mergesort(array, tmp, mid + 1, end);
        merge(array, tmp, start, mid, end);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *tmp;

    if (!array || size < 2)
        return;

    tmp = _calloc(size, sizeof(int));
    if (!tmp)
        return;

    mergesort(array, tmp, 0, size - 1);
    free(tmp);
}
