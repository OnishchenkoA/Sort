#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void merge(int Arr[], int start, int end, int mid);

void mergeSort(int Arr[], int start, int end)
{
	int mid;
	if (start < end) {

		mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid + 1, end);
		merge(Arr, start, end, mid);
	}
}

void merge(int Arr[], int start, int end, int mid)
{
	int mergedArr[8];
	int i, j, k;
	i = start;
	k = start;
	j = mid + 1;

	while (i <= mid && j <= end) {
		if (Arr[i] < Arr[j]) {
			mergedArr[k] = Arr[i];
			k++;
			i++;
		}
		else {
			mergedArr[k] = Arr[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		mergedArr[k] = Arr[i];
		k++;
		i++;
	}

	while (j <= end) {
		mergedArr[k] = Arr[j];
		k++;
		j++;
	}

	for (i = start; i < k; i++) {
		Arr[i] = mergedArr[i];
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	int const size = 15;
	int Arr[size] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
	mergeSort(Arr, 0, size - 1);
	cout << "Отсортированный массив: ";
	for (int i = 0; i < size; i++)
	{
		cout << Arr[i] << " ";
	}
	std::cout << std::endl;
}

