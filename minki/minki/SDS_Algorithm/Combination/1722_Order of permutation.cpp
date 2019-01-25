/*
	1722 순열의 순서
	https://www.acmicpc.net/problem/1722
*/

#include <iostream>
#include <vector>

using namespace std;

int N, cnt = 0;
int ans[21], visit[21];
long long int K, fac[21];

int main()
{
	int check,input;
	scanf("%d", &N);

	fac[0] = 1;
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
		fac[i] = fac[i - 1] * i;
	}

	scanf("%d", &check);
	if (check == 1) {
		scanf("%lld", &K);
		for (int i = 1; i <= N; i++) {
			int cnt = 1;
			for (int j = 1; j <= N; j++) {
				if (visit[j])continue;//한번 거쳤으니
				if (K <= cnt*fac[N - i]) {
					ans[i] = j;
					visit[j] = 1;
					K -= (cnt-1)*fac[N - i];
					break;
				}
				cnt++;
			}
		}
		for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
	}
	else if (check == 2) {
		K = 1;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &input);
			
			int cnt = 1;
			for (int j = 1; j <= N; j++) {
				if (visit[j])continue;//한번 거쳤으니
				if(input==j)
				{
					K += (cnt - 1)*fac[N - i];
					visit[input] = 1;
					break;
				}
				cnt++;
			}
		}
		printf("%lld\n", K);
	}

	return 0;
}