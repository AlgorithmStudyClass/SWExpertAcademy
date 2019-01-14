/*
	6588 골드바흐의 추측
	https://www.acmicpc.net/problem/6588
*/

#include <iostream>
#include <cmath>

using namespace std;

#define MAX_N 1000001

int check[MAX_N], prime[MAX_N];

int main() {
	int n, a, b, cnt = 0;
	for (int i = 2; i < MAX_N; i++)
		check[i] = i;

	for (int i = 2; i < sqrt(MAX_N); i++) {
		if (!check[i])continue;

		prime[cnt++] = i;
		for (int j = i; i*j <= MAX_N - 1; j++) {
			check[i*j] = 0;
		}
	}

	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		for (int i = 0; i <= cnt; i++) {
			if (check[n - prime[i]]) {
				printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
				break;
			}
		}
	}
	return 0;
}
