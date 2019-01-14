/*
	11653 소인수분해
	https://www.acmicpc.net/problem/11653
*/

#include <iostream>

using namespace std;

#define MAX_N 10000001

bool check[MAX_N];
int prime[MAX_N];

int main() {
	int n, prime_cnt = 0;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) check[i] = true;
	for (int i = 2; i <= n; i++)
	{
		if (check[i])
		{
			prime[prime_cnt++] = i; 
			for (int j = 2; i*j <= n; j++)
				check[i*j] = false;
		}
	}

	int index = 0;
	while (n != 1 && index<prime_cnt) {
		if (n%prime[index] == 0) {
			n /= prime[index];
			printf("%d\n", prime[index]);
		}
		else
			index++;
	}

	return 0;
}