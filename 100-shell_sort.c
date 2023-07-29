#include "sort.h"

/**
 * shell_sort - sorts an array of integers
 * @array: array to be sorted
 * @size: size of @array
 */

void shell_sort(int *array, size_t size)
{
	size_t g = 1;
	size_t x;
	size_t y;
	int tmp;

	if (!array || size < 2)
		return;
	while (g < size / 3)
		g = g * 3 + 1;
	while (g > 0)
	{
		for (x = g; x < size; x++)
		{
			tmp = array[x];
			y = x;
			while (y >= g && array[y - g] > tmp)
			{
				array[y] = array[y - g];
				y -= g;
			}
			array[y] = tmp;
		}
		g = (g - 1) / 3;
		print_array(array, size);
	}
}
