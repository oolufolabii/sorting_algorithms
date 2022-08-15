#include "sort.h"

/**
 * count_sort_LSD - count sort using LSD
 * @array: array to sort
 * @size: size of the array
 * @lsd: least significant digit
 */

void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_array[10] = {0}, *out_array, l, m;
	size_t k, n;

	out_array = malloc(sizeof(int) * size);

	for (k = 0; k < size; k++)
		count_array[(array[k] / lsd) % 10]++;
	for (l = 1; l < 10; l++)
		count_array[l] += count_array[l - 1];

	for (m = size - 1; m >= 0; m--)
	{
		out_array[count_array[(array[m] / lsd) % 10] - 1] = array[m];
		count_array[(array[m] / lsd) % 10]--;
	}

	for (n = 0; n < size; n++)
		array[n] = out_array[n];

	free(out_array);
}

/**
 * radix_sort - sorting an array using the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}
