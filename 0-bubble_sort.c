#include "sort.h"

/**
 * bubble_sort - Sorts array of integers in ascending order using Bubble Sort
 *
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (!array || size < 2) /* Verifica entrada válida */
		return;

	for (i = 0; i < size - 1; i++) /* Itera sobre el array */
	{
		for (j = 0; j < size - i - 1; j++) /* Compara elementos adyacentes */
		{
			if (array[j] > array[j + 1]) /* Intercambia si están fuera de orden */
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size); /* Muestra el array tras el intercambio */
			}
		}
	}
}
