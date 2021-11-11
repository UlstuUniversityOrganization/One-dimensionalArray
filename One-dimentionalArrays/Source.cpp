#include <stdio.h>
#include <stdlib.h>

int main()
{
	int elementsCount;
	int error = 0;

	printf("Enter elements count of the array:\n");

	error = scanf_s("%d", &elementsCount);
	if (error == 0) throw;

	int* nums = (int*)malloc(elementsCount * sizeof(int));

	printf("Enter array elements:\n");

	for (int i = 0; i < elementsCount; i++)
	{
		int tempNum = 0;

		error = scanf_s("%d", &tempNum);
		if (error == 0) throw;

		nums[i] = tempNum * -1;
	}

	printf("This is your array, but with inverted numbers:\n");

	for (int i = 0; i < elementsCount; i++)
		printf("%d ", nums[i]);
}