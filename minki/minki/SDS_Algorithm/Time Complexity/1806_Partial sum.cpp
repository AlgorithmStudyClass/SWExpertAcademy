/*
	1806 부분합
	https://www.acmicpc.net/problem/1806
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M, arr[100001], answer = 1, right = 0;
	long long int sum = 0;
	bool flag = false;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	answer = N;

	for (int i = 0; i < N; i++) {
		while (right < N && sum < M)
			sum += arr[right++];

		if (sum >= M) {
			flag = true;
			if (answer > right - i)
				answer = right - i;
		}

		sum -= arr[i];
	}

	if (!flag)
		answer = 0;

	printf("%d\n", answer);

	return 0;
}