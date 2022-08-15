#include "sort.h"

/**
 * counting_sort - sorting using the count sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *out_array, max_value, num, j, l;
	size_t i, k, m, n;

	if (size < 2)
		return;

	max_value = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max_value)
			max_value = array[i];

	count_array = malloc(sizeof(size_t) * (max_value + 1));
	out_array = malloc(sizeof(int) * size);

	for (j = 0; j <= max_value; j++)
		count_array[j] = 0;
	for (k = 0; k < size; k++)
	{
		num = array[k];
		count_array[num] += 1;
	}
	for (l = 1; l <= max_value; l++)
		count_array[l] += count_array[l - 1];
	print_array(count_array, max_value + 1);

	for (m = 0; m < size; m++)
	{
		out_array[count_array[array[m]] - 1] = array[m];

		count_array[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = out_array[n];

	free(count_array);
	free(out_array);
}
