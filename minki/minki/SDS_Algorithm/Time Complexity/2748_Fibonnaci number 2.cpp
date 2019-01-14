/*
	2748 피보나치 수 2
	https://www.acmicpc.net/problem/2748
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator* (matrix &a, matrix &b) {
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			for (int k = 0; k<n; k++)
				c[i][j] += a[i][k] * b[k][j];
	return c;
}

long long fibonacci(int n)
{
	matrix res = { { 1, 0 },{ 0, 1 } };
	matrix fib = { { 1, 1 },{ 1, 0 } };
	while (n) {
		if (n % 2 == 1) res = res * fib;
		fib = fib * fib;
		n *= 0.5;
	}
	return res[0][1];
}


int main() {
	int N;
	long long int arr[100];

	scanf("%d", &N);

	//sol1 O(N)
	/*
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= N; i++)
	arr[i] = arr[i - 1] + arr[i - 2];
	*/

	//sol2
	printf("%lld\n", fibonacci(N));

	return 0;
}