#include <stdio.h>
#include <stdlib.h>

void PrintGap()
{
	printf("\n");
	printf("\n");
	printf("-----------------------------\n");
	printf("\n");
}

void TaskA(int* array, int elementsCount)
{
	printf("This is your array, but with inverted numbers:\n");

	for (int i = 0; i < elementsCount; i++)
		printf("%d ", array[i] * -1);
	PrintGap();
}
void TaskB(int* array, int elementsCount)
{
	int min = 999999999;
	int max = -999999999;
	for (int i = 0; i < elementsCount; i++)
	{
		if (array[i] < min) min = array[i];
		if (array[i] > max) max = array[i];
	}

	printf("Min value: %d\n", min);
	printf("Max value: %d\n", max);
	PrintGap();
}
void TaskC(int* array, int elementsCount)
{
	int min = 999999999;
	int max = -999999999;

	int minId = -1;
	int maxId = -1;

	for (int i = 0; i < elementsCount; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			minId = i;
		}

		if (array[i] > max)
		{
			max = array[i];
			maxId = i;
		}
	}

	for (int i = minId + 1; i < maxId; i++)
		if ((array[i] % 2) == 0)
			printf("%d ", array[i]);
	PrintGap();
}
void TaskD(int* array, int elementsCount)
{
	int min = 999999999;
	int max = -999999999;

	int minId = -1;
	int maxId = -1;

	for (int i = 0; i < elementsCount; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
			minId = i;
		}

		if (array[i] > max)
		{
			max = array[i];
			maxId = i;
		}
	}

	for (int i = minId + 1; i < maxId; i++)
		if ((array[i] % 2) != 0)
			printf("%d ", array[i]);
	PrintGap();
}

void CreateArray(int** array, int* elementsCount)
{
	int error = 0;
	printf("Enter elements count of the array:\n");

	error = scanf_s("%d", elementsCount);
	if (error == 0) throw;

	printf("\n");

	(*array) = (int*)malloc((*elementsCount) * sizeof(int));

	printf("Enter array elements:\n");

	for (int i = 0; i < *elementsCount; i++)
	{
		printf("%d element:", i + 1);
		error = scanf_s("%d", &((*array)[i]));
		if (error == 0) throw;
	}
	printf("\n");
}
int main(int* array, int elementsCount)
{
	while (true)
	{
		int error = 0;

		printf("What do you want the programm to do?\n");
		printf("	A. Invert numbers of the array\n");
		printf("	B. Output min and max numbers of the array \n");
		printf("	C. Output even numbers of the array between min and max\n");
		printf("	D. Output not even numbers of the array between min and max\n");
		printf("	E. Quit the programm\n");

		char answer[2];
		
		error = scanf_s("%s", answer, 2);
		printf("\n");

		system("cls");

		if (answer[0] == 'E')
			break;

		int elementsCount;
		int* nums;

		CreateArray(&nums, &elementsCount);
		
		switch (answer[0])
		{
			case 'A': TaskA(nums, elementsCount); break;
			case 'B': TaskB(nums, elementsCount); break;
			case 'C': TaskC(nums, elementsCount); break;
			case 'D': TaskD(nums, elementsCount); break;
		}
	}

}