/*
	2003 수들의 합 2
	https://www.acmicpc.net/problem/2003
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	int arr[10001],temp,answer=0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		temp = 0;
		for (int j = i; j < N; j++) {
			temp += arr[j];
			if (temp == M) {
				answer++;
				break;
			}
			else if (temp > M)
				break;
		}
	}

	printf("%d\n", answer);

	return 0;
}