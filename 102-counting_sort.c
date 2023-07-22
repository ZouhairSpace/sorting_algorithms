#include "sort.h"
#include <stdio.h>

/**
 * _calloc - Allocates memory for an array, initialized to 0
 * @nmemb: Number of elements
 * @size: Size of each element in bytes
 * Return: Pointer to the allocated memory, or NULL if fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    unsigned int i = 0;
    char *ptr;

    if (nmemb == 0 || size == 0)
        return (NULL);

    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);

    for (i = 0; i < (nmemb * size); i++)
        ptr[i] = 0;

    return (ptr);
}

/**
 * counting_sort - Sorts an array of integers using counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int index, maximum = 0, *counter = NULL, *tmp = NULL;
    size_t i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum number in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > maximum)
            maximum = array[i];
    }

    /* Allocate memory for the counters and temporary array */
    counter = _calloc(maximum + 1, sizeof(int));
    tmp = _calloc(size, sizeof(int));

    /* Count the occurrences of each element */
    for (i = 0; i < size; i++)
    {
        counter[array[i]]++;
    }

    /* Get the cumulative counts */
    for (index = 1; index <= maximum; index++)
    {
        counter[index] += counter[index - 1];
    }

    print_array(counter, maximum + 1);

    /* Sort the elements into the temporary array */
    for (i = 0; i < size; i++)
    {
        tmp[counter[array[i]] - 1] = array[i];
        counter[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
    {
        array[i] = tmp[i];
    }

    free(tmp);
    free(counter);
}

