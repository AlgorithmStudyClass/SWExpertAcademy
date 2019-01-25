/*
	13251 조약돌 꺼내기
	https://www.acmicpc.net/problem/13251
*/

#include <iostream>
#include <vector>

using namespace std;

int M, K, arr[51];
double ans=0;

int main()
{
	scanf("%d", &M);
	int sum = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	scanf("%d", &K);

	if (M == 1 || K == 1){
		puts("1.0");
		return 0;
	}

	for (int i = 0; i < M; i++) {
		double temp = 1;
		for (int j = 0; j < K; j++) 
			temp*=(arr[i]-j)/(double)(sum-j);
		ans += temp;
	}

	if (ans == 1) {
		puts("1.0");
		return 0;
	}

	printf("%.10f\n", ans);
	return 0;
}