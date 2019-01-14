/*
	2805 나무 자르기
	https://www.acmicpc.net/problem/2805
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, arr[1000001], M, min = 0, max = 0, answer;
	long long int sum;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (max < arr[i])
			max = arr[i];
	}

	answer = (min + max) / 2;

	//parametrix search
	while (min <= max) {
		sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] >= answer)
				sum += arr[i] - answer;
		}
		if (sum > M) {
			min = answer + 1;
			answer = (min + max) / 2;
		}
		else if (sum == M) {
			break;
		}
		else {
			max = answer - 1;
			answer = (min + max) / 2;
		}
	}

	printf("%d\n", answer);

	return 0;
}