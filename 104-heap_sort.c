#include "sort.h"
#include <stdio.h>

/**
 * swap - A utility function to swap two integers.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 **/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * maxHeapify - The main function to heapify a Max Heap. The function
 * assumes that everything under the given root (element at index idx)
 * is already heapified.
 * @array: The array to be heapified.
 * @size: The size of the array.
 * @idx: The index of the element to be considered as the root.
 * @n: The size of the heap to run.
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;        /* Initialize largest as root */
	int left = 2 * idx + 1;   /* left = (idx << 1) + 1 */
	int right = 2 * idx + 2;  /* right = (idx + 1) << 1 */

	/* See if the left child of the root exists and is greater than the root */
	if (left < (int)n && array[left] > array[largest])
		largest = left;

	/**
	 * See if the right child of the root exists and is greater than
	 * the largest element found so far
	 */
	if (right < (int)n && array[right] > array[largest])
		largest = right;

	/* Change root if needed */
	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort - The main function to sort an array of given size
 * using the Heap Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 **/
void heap_sort(int *array, size_t size)
{
	int i;

	/**
	 * Build the heap (rearrange the array) in a bottom-up manner
	 * starting from the bottommost and rightmost internal node.
	 */
	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	/**
	 * One by one extract elements from the heap and move the
	 * current root to the end.
	 */
	for (i = (size - 1); i > 0; --i)
	{
		/**
		 * The largest item in the heap is stored at the root.
		 * Replace it with the last item of the heap, followed by reducing
		 * the size of the heap by 1.
		 */
		swap(&array[0], &array[i]);
		print_array(array, size);

		/* Finally, heapify the root of the tree. */
		maxHeapify(array, size, 0, i);
	}
}

