#include "sort.h"

/**
 * _max - returns the maximum value in an array
 * @array: given array
 * @size: size of @array
 *
 * Return: The maximum value
 */

int _max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - counting sort of an array by some digit
 *
 * @array: given array
 * @size: size of @array
 * @exp: exponent
 */

void counting_sort(int *array, size_t size, int exp)
{
	int *out = malloc(sizeof(int) * size);
	int cnt[10] = {0};
	size_t i;
	int j;

	if (!out)
	{
		fprintf(stderr, "Memory allocation error\n");
		return;
	}
	for (i = 0; i < size; i++)
		cnt[(array[i] / exp) % 10]++;
	for (j = 1; j < 10; j++)
		cnt[j] += cnt[j - 1];
	for (j = size - 1; j >= 0; j--)
	{
		out[cnt[(array[j] / exp) % 10] - 1] = array[j];
		cnt[(array[j] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = out[i];
	free(out);
}

/**
 * radix_sort - sorts an array of integers
 *
 * @array: The array to be sorted
 * @size: size of @array
 */

void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (size < 2 || !array)
		return;
	max = _max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
	}
	print_array(array, size);
}
