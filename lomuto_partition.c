#include "sort.h"

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
