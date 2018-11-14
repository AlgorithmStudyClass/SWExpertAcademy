using namespace std;

#include <iostream> // cin 사용 위해 필요 
#include <vector>	// vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>

#define N 5
#define INFTY 100000
int c[N + 1][N + 2] = { -1, -1, -1, -1, -1, -1, -1, -1, 7, 3, 5, 6, 1, -1, -1, 2, 6, 7, 0, 2, -1, -1, 3, 5, 7, 8, 2, -1, -1, 7, 6, 1, 1, 4, -1, -1, 6, 7, 4, 7, 8, -1 };
int p[N + 1][N + 2], q[N + 1][N + 2];
int min3(int a, int b, int c) {
	int answer = a;
	if (a > b) 
		answer = b > c ? c : b;
	else 
		answer = a > c ? c : a;
	return answer;
}
void ComputeCBCosts(int n) {
	int i, j, min;
	for (i = 1; i <= n; i++) q[1][i] = c[1][i];
	for (i = 1; i <= n; i++) {
		q[i][0] = INFTY; q[i][n + 1] = INFTY;
	}
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			min = min3(q[i - 1][j - 1], q[i - 1][j],
				q[i - 1][j + 1]);
			q[i][j] = min + c[i][j];
			if (min == q[i - 1][j - 1]) p[i][j] = -1;
			else if (min == q[i - 1][j]) p[i][j] = 0;
			else p[i][j] = 1;
		}
	}
}
void PrintShortestPath(int n, int imin) {
	printf(" (%d, %d) <-", n, imin);
	if (n == 2)
		printf(" (%d, %d)\n", 1, imin + p[n][imin]);
	else
		PrintShortestPath(n - 1, imin + p[n][imin]);
}
void ComputeCBShortestPath(int n) {
	int i, imin, min;
	ComputeCBCosts(n);
	imin = 1; min = q[n][1];
	for (i = 2; i <= n; i++) {
		if (q[n][i] < min) {
			imin = i; min = q[n][i];
		}
	}
	printf("*** The cost of the shortest path is%d.\n", q[n][imin]);
		PrintShortestPath(n, imin);
}
void main(void) {
	int n;
	n = N;
	ComputeCBShortestPath(n);
}