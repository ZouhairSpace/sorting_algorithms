#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array in which the elements will be swapped.
 * @item1: The index of the first element to swap.
 * @item2: The index of the second element to swap.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_partition - Implements the Hoare partition scheme for quicksort.
 * @array: The array to be partitioned.
 * @first: The index of the first element in the range to be partitioned.
 * @last: The index of the last element in the range to be partitioned.
 * @size: The size of the array.
 * Return: The position of the last element in the range after partitioning.
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);

		do {
			finder--;
		} while (array[finder] > pivot);

		if (current >= finder)
			return (current);

		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * qs - Implements the quicksort algorithm using the Hoare partition scheme.
 * @array: The array to be sorted.
 * @first: The index of the first element in the range to be sorted.
 * @last: The index of the last element in the range to be sorted.
 * @size: The size of the array.
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - Prepares the terrain for the quicksort algorithm
 * using the Hoare partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}

