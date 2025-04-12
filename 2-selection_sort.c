#include "sort.h"

/**
 * selection_sort - sorts ary of ints in asc. order using the Select. sort agth
 * @array: to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t inx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		inx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[inx])
			{
				inx = j;
			}
		}
		if (inx != i)
		{
			temp = array[i];
			array[i] = array[inx];
			array[inx] = temp;

			print_array(array, size);
		}
	}
}

