#include <iostream>
#include <random>
#include <string>
#include<vector>
#include<math.h>
#include <array>

void printArray(int(&array)[5])
{
	for (const int &element : array)
		std::cout << element << ' ';
}
int* allocateArray(const int length)
{
	int *array1 = new int[length];
	return array1;
}
void printElements(int(&arr)[4])
{
	int length{ sizeof(arr) / sizeof(arr[0]) }; // we can now do this since the array won't decay

	for (int i{ 0 }; i < length; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
}
void printElements2(int arr[4])
{
	int length{ sizeof(arr) / sizeof(arr[0]) };
	printf("%d\n", sizeof((arr)[4]));//4

	for (int i{ 0 }; i < length; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
}
int main()
{
	int array[]{ 9, 7, 5, 3, 1 };
	std::array<int, 5>array2{9, 7, 5, 3, 1};
	printArray(array);


	return 0;
}