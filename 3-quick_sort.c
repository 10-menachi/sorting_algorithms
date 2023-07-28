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

/**
 * lomuto_partition - lomuto partition scheme for quick sort
 * @array: array to be partitioned
 * @low: lower bound
 * @high: upper bound
 *
 * Return: index of partition pivot
 */

int lomuto_partition(int *array, int low, int high)
{
	int p = array[high];
	int x = low - 1, y, tmp;

	for (y = low; y < high; y++)
	{
		if (array[y] < p)
		{
			x++;
			if (x != y)
			{
				tmp = array[x];
				array[x] = array[y];
				array[y] = tmp;
				print_array(array, high + 1);
			}
		}
	}
	if (x + 1 != high)
	{
		tmp = array[x + 1];
		array[x + 1] = array[high];
		array[high] = tmp;
		print_array(array, high + 1);
	}
	return (x + 1);
}

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
