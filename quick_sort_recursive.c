#include "sort.h"

/**
 * quick_sort_recursive - sorts an array using quicksort
 *
 * @array: array to be sorted
 * @low: lower bound
 * @high: upper bound
 */

void quick_sort_recursive(int *array, int low, int high)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high);
		quick_sort_recursive(array, low, p - 1);
		quick_sort_recursive(array, p + 1, high);
	}
}
