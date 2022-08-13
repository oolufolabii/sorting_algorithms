#include "sort.h"

/**
 * bubble_sort - sorting an array in ascending order
 * @array: array of integers
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)

{
	unsigned int a, b;
	int temp;

	if (size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{

		for (b = 0; b < size - a - 1; b++)
		{

			if (array[b] > array[b + 1])
			{

				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
