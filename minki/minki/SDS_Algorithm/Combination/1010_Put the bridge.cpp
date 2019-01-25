/*
	1010 다리놓기
	https://www.acmicpc.net/problem/1010
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 30

int t,n,m;
long long int bc[MAX_N][MAX_N];
string str;

int main(void) {
	scanf("%d", &t);
	
	for (int i = 0; i < MAX_N; i++)
	{
		bc[i][0] = 1;
		for (int j = 1; j <= i; j++) 
			bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
	}
	while (t--) {
		scanf("%d %d", &n, &m);
		if (n < m) {
			int temp = n;
			n = m;
			m = temp;
		}
		printf("%lld\n", bc[n][m]);
	}


	return 0;
}