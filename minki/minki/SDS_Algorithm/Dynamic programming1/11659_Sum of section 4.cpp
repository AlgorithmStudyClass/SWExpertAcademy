/*
	11659 구간 합 구하기 4
	https://www.acmicpc.net/problem/11659
*/

#include <iostream>
#include <vector>

using namespace std;

int N, T;
int arr[100001], sum[100001], ans;

int main()
{
	scanf("%d %d", &N, &T);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		sum[i] += sum[i - 1] + arr[i];
	}

	int a, b;
	while (T--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}

	return 0;
}