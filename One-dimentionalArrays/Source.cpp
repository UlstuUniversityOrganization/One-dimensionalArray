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
	int min = array[0];
	int max = array[0];
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
	int min = array[0];
	int max = array[0];

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

//1 element:2
//2 element : 8
//3 element : 4
//4 element : 6
//5 element : 1

void TaskD(int* array, int elementsCount, int** newArray, int* newElementsCount)
{
	int min = array[0];
	int max = array[0];

	int minId = 0;
	int maxId = 0;

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

	*newElementsCount = 0;
	for (int i = minId + 1; i < maxId; i++)
		if ((array[i] % 2) != 0)
			++* newElementsCount;
	if (maxId >= minId)
		*newElementsCount += elementsCount - ((maxId - 1) - minId);
	else
		*newElementsCount += elementsCount - ((minId - 1) - maxId);


	*newArray = new int[*newElementsCount];

	if (minId >= maxId)
	{
		int tempNum = minId;
		minId = maxId;
		maxId = tempNum;
	}

	int j = 0;
	for (int i = 0; i < elementsCount; i++)
	{
		if (i > minId && i < maxId)
		{
			if ((array[i] % 2) != 0)
			{
				(*newArray)[j] = array[i];
				j++;
			}
		}
		else
		{
			(*newArray)[j] = array[i];
			j++;
		}
	}
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
		case 'D':
		{
			int* newArray;
			int newElementsCount = -1;
			TaskD(nums, elementsCount, &newArray, &newElementsCount);

			printf("This is what you've got:\n");

			for (int i = 0; i < newElementsCount; i++)
				printf("%d ", newArray[i]);
			printf("\n\n");
			break;
		}
		}
	}

}