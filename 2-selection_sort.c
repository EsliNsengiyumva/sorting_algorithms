#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array
 * @size: The size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int tmp;

	for (j = 0; j < size - 1; j++)
	{
		min_idx = j;
		for (i = j + 1; i < size; i++)
		{
			if (array[i] < array[min_idx])
				min_idx = i;
		}

		if (min_idx != j)
		{
			tmp = array[j];
			array[j] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
