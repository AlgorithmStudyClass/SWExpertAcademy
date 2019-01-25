/*
	11660 구간 합 구하기 5
	https://www.acmicpc.net/problem/11660
*/

#include <iostream>
#include <vector>

using namespace std;

int N,T;
int arr[1025][1025],sum[1025][1025],lsum[1025];

int main()
{
	scanf("%d %d", &N,&T);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	sum[1][1] = arr[1][1];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			lsum[j] = lsum[j - 1] + arr[i][j];
			sum[i][j] = lsum[j] + sum[i-1][j];
		}
	}
	int a, b,x,y;
	while (T--) {
		scanf("%d %d %d %d", &a, &b,&x,&y);
		printf("%d\n", sum[x][y] - sum[x][b-1] - sum[a-1][y] + sum[a-1][b-1]);
	}

	return 0;
}