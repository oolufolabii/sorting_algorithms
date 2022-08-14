#include "sort.h"


/**
 * swap - a swap function
 * 
 * @a: a pointer to a
 * @b: a pointer to b
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Implementing the selection sort algorithm
 * @array: array to sort
 * @size: size of the array;
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		
		swap(&array[i], &array[min]);

		if (i != min)
			print_array(array, size);
	}
}
