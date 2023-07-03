#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Sheik(int* arr, int size)
{
	int left = 0, right = size - 1, flag = 1; // левая и правая границы сортируемой области массива// флаг наличия перемещений
	int t = 0, t1 = 0;
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++) //двигаемся слева направо
		{
			if (arr[i] > arr[i + 1]) // если следующий элемент меньше текущего,
			{ // меняем их местами
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				flag = 1; // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--) //двигаемся справа налево
		{
			if (arr[i - 1] > arr[i]) // если предыдущий элемент больше текущего,
			{ // меняем их местами
				t1 = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = t1;
				flag = 1; // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}

int main()
{
	int size = 0; //инцилизация размера массива
	printf("Enter the size of the array:");
	scanf("%d", &size); //ввод размерности массива

	int* arr = (int*)malloc(size * sizeof(int)); //динамическое выделение памяти массива

	FILE* file = fopen("rannum.txt", "w"); //открытие файла для записи
	srand(time_t(NULL));
	if (file == NULL) {
		printf("Error opening file.\n");
		return 1;
	}
	for (int i = 0; i < size; i++) //цикл для заполнения массива и файла случайными числами
	{
		int randomNumber = rand() % 100;
		fprintf(file, "%d\n", randomNumber);
		arr[i] = randomNumber;
	}

	fclose(file); //закрытие файла

	time_t start = clock();//начало отсчета времени

	Sheik(arr, size); //запуск функции сортировки

	time_t stop = clock();//конец отсчета времени

	FILE* outputFile = fopen("result.txt", "w"); //открытие файла, для записи, для вывода результата
	if (file == NULL) {
		printf("Error opening file.\n");
		return 1;
	}
	for (int i = 0; i < size; i++)
	{
		fprintf(outputFile, "%d\n", arr[i]); //запись в файл каждого элемента массива
	}

	fclose(outputFile);//закрытиек файла

	double time = ((stop - start) / 1000.0); //время сортировки
	printf("working time: %.3lf \n", time);//вывод времени сортировки 

	free(arr);//освобождение памяти
	printf("Generated array: rannum.txt\n");
	printf("Sorted array: result.txt");

	return 0;
}