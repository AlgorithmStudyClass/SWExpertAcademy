/*
	5568 카드 놓기
	https://www.acmicpc.net/problem/5568
*/

#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

int N, K;
int A[10], V[10];
int pcnt;
set<int> s;

void backtrack(int cnt, int num) {
	if (cnt == K)
		s.insert(num);
	else {
		for (int i = 0; i < N; i++) {
			if (V[i] == 0) {
				V[i] = 1;
				int temp = num * 10;
				if (A[i] > 9)temp *= 10;
				backtrack(cnt + 1, temp + A[i]);
				V[i] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i<N; i++)
	{
		scanf("%d", A + i);
		V[i] = 0;
	}
	pcnt = 0;
	backtrack(0, 0);
	
	printf("%d\n", s.size());

	return 0;
}