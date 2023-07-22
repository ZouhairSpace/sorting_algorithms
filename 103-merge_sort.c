#include "sort.h"
#include <stdio.h>

/**
 * _calloc - This is a custom implementation of the calloc function.
 * @nmemb: Number of elements to allocate memory for.
 * @size: Size of each element in bytes.
 * Return: Pointer to the memory allocated, or NULL if it fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    unsigned int i = 0;
    char *p;

    if (nmemb == 0 || size == 0)
        return (NULL);
    p = malloc(nmemb * size);
    if (p == NULL)
        return (NULL);
    for (i = 0; i < (nmemb * size); i++)
        p[i] = '\0';
    return (p);
}

/**
 * merge - Merge two subarrays into the main array.
 * @arr: The main array containing the subarrays to be merged.
 * @tmp: Temp array used in the merge process to optimize system calls.
 * @start: Index of the first element in the range to be merged.
 * @mid: Index of the middle element in the range to be merged.
 * @end: Index of the last element in the range to be merged.
 **/
void merge(int *arr, int *tmp, int start, int mid, int end)
{
    /* Sizes and temporary arrays */
    int size_left = mid - start + 1, size_right = end - mid;
    int *array_left, *array_right;
    /* Counters */
    int left, right, i = 0;

    array_left = &tmp[0];
    array_right = &tmp[size_right];
    for (left = 0; left < size_left; left++)
        array_left[left] = arr[start + left];
    for (right = 0; right < size_right; right++)
        array_right[right] = arr[mid + 1 + right];
    left = 0, right = 0, i = start;
    /* Merging temporary arrays back into the main array */
    while (left < size_left && right < size_right)
    {
        if (array_left[left] <= array_right[right])
            arr[i] = array_left[left], left++;
        else
            arr[i] = array_right[right], right++;
        i++;
    }
    /* Merging the remaining left array back into the main array */
    while (left < size_left)
        arr[i] = array_left[left], left++, i++;
    /* Merging the remaining right array back into the main array */
    while (right < size_right)
        arr[i] = array_right[right], right++, i++;
    printf("Merging...\n");
    printf("[left]: ");
    print_array(array_left, left);
    printf("[right]: ");
    print_array(array_right, right);
    printf("[Done]: ");
    print_array(&arr[start], left + right);
}

/**
 * mergesort - Recursive function that sorts an array of integers
 * in ascending order using the Merge sort algorithm.
 * @array: Array of integers to be sorted.
 * @tmp: Temp array used in the merge process to optimize system calls.
 * @start: Index of the first element in the range to be sorted.
 * @end: Index of the last element in the range to be sorted.
 * Return: void
 */
void mergesort(int *array, int *tmp, int start, int end)
{
    int mid;

    mid = (start + end) / 2;
    if ((start + end) % 2 == 0)
        mid--;
    if (mid >= start)
    {
        mergesort(array, tmp, start, mid);
        mergesort(array, tmp, mid + 1, end);
        merge(array, tmp, start, mid, end);
    }
}

/**
 * merge_sort - Function that sorts an array of integers
 * in ascending order using the Merge sort algorithm.
 * @size: Size of the array to be sorted.
 * @array: Array of integers to be sorted.
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
    int *tmp;

    if (!array || size < 2)
        return;
    tmp = _calloc(size, sizeof(int));
    mergesort(array, tmp, 0, size - 1);
    free(tmp);
}

