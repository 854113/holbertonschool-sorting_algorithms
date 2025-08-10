#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t route, count;
	int tmp;

	for (route = 0; route < size - 1; route++)
	{
		for (count = 0; count < size - 1 - route; count++)
		{
			if (array[count] > array[count + 1])
			{
				tmp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
