#include "sort.h"

/**
 * heaper - converts an array in a heap tree
 * @array: array to turn into heap
 * @s: size of the subtree
 * @root: index of the subtree in the heap
 * @size: size of the whole array
 */
void heaper(int *array, size_t s, size_t root, size_t size)
{
	size_t max, left, right;
	int temp;

	max = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left < s && array[left] > array[max])
		max = left;

	if (right < s && array[right] > array[max])
		max = right;

	if (max != root)
	{
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		heaper(array, s, max, size);
	}
}

/**
 * heap_sort - sorting an array using the Heap sort algorithm
 * @array: array of ints to sort
 * @size: size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heaper(array, size, (size_t)i, size);

	for (i = size - 1; i >= 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		if (i != 0)
			print_array(array, size);
		heaper(array, (size_t)i, 0, size);
	}
}
