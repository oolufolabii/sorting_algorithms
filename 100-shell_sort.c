#include "sort.h"

/**
 * shell_sort - sorting using shell sort and
 * the knauff sequence
 * @array: the array of integers
 * @size: size of the array
 *
 * Return: none
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 0, i, j;
	int tmp;

	if (size < 2)
		return;

	while ((interval = interval * 3 + 1) < size)
		;

	interval = (interval - 1) / 3;

	for (; interval > 0; interval = (interval - 1) / 3)
	{
		for (i = interval; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= interval && tmp <= array[j - interval]; j -= interval)
				array[j] = array[j - interval];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
