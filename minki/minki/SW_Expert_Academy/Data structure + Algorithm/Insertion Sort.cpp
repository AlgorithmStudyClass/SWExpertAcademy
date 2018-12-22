/*
	삽입 정렬은 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 
	자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘이다.
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <string>
#include <numeric>
#include <sstream>

#define MAX_NUM 100

int input[MAX_NUM];
int num;

void insertionSort(void)
{
	int temp;
	int i;
	int j;

	for (i = 1; i < num; i++) {
		temp = input[i];
		j = i - 1;
		while ((j >= 0) && (temp < input[j])) {
			input[j + 1] = input[j];
			j--;
		}
		input[j + 1] = temp;
	}
}

void printResult(void)
{
	int i;

	for (i = 0; i < num; ++i)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
}

int main()
{
	int T;
	int test_case;
	int i;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &num);
		for (i = 0; i < num; i++)
		{
			scanf("%d", &input[i]);
		}
		insertionSort();
		printf("#%d ", test_case);
		printResult();
	}

	return 0;
}