#include "sort.h"

/**
 * swap - swaps the positions of two elements in an array
 * @arr: array
 * @pos1: array element
 * @pos2: array element
 */
void swap(int *arr, int pos1, int pos2)
{
	int temp;

	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @arr_size: size of the array
 * @arr: list with numbers
 */
void shell_sort(int *arr, size_t arr_size)
{
	size_t gap = 1, i, index = 0;

	if (arr == NULL || arr_size < 2)
		return;
	while (gap < arr_size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < arr_size; i++)
			for (index = i; index >= gap && (arr[index] < arr[index - gap]); index -= gap) 
				swap(arr, index, index - gap);
		print_array(arr, arr_size);
		gap /= 3;
	}
}

