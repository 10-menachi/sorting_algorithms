#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * @array: given array
 * @size: size of @array
 *
 */

void bubble_sort(int *array, size_t size)
{
	int sw;
	int tmp;
	size_t i, j;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		sw = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				sw = 1;
				print_array(array, size);
			}
		}
		if (sw == 0)
			break;
	}
}
