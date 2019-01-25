/*
	2166 다각형의 면적
	https://www.acmicpc.net/problem/2166
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

#define MAX_N 10002
double x[MAX_N], y[MAX_N];
int N;

double calc() {
	double ans = 0;
	x[N] = x[0];
	y[N] = y[0];

	for (int i = 0; i < N; i++)
		ans += (x[i] * y[i + 1] - x[i + 1] * y[i]) / 2;

	return fabs(ans);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &x[i], &y[i]);
	}

	printf("%.1lf\n", calc());

	return 0;
}