#include "sort.h"

/**
 * quick_sort - sorts an array of integers
 *
 * @array: array to be sorted
 * @size: size of @array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1);
}
