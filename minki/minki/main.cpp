/*
	순열조합(permutation combination), 
	순열은 순서가 부여된 임의의 집합을 다른 순서로 뒤섞는 연산이며, 
	조합은 집합에서 일부 원소를 취해 부분 집합을 만드는 방법을 말한다.
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

#define MAX_STRING_LENGTH 10

int stackTop = 0;
char combinationStack[MAX_STRING_LENGTH];

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permutation(char *str, int l, int r) {
	if (l == r)
		printf("%s\n", str);
	else
		for (int i = l; i <= r; i++) {
			swap((str + l), (str + i));
			permutation(str, l + 1, r);
			swap((str + l), (str + i)); // backtrack
		}
}

int main()
{
	int N, K, T;
	char str[MAX_STRING_LENGTH];
	
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%s%d%d",str, &N ,&K);
		str[N] = 0; // string 길이를 N만큼
		printf("#%d\n", test_case);
		puts("permutation");
		permutation(str, 0, N - 1);
		puts("combination");
	}

	return 0;
}