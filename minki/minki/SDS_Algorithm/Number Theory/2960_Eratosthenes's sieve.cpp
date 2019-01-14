/*
	2960 에라토스테네스의 체
	https://www.acmicpc.net/problem/2960
*/

#include <iostream>

using namespace std;

int main() {
	int n, k,cnt=0,ans;
	int arr[1001];

	scanf("%d %d", &n, &k);

	for (int i = 2; i <= n; i++)
		arr[i] = i;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; i*j <= n; j++) {
			if (arr[i*j] != 0) {
				arr[i*j] = 0;
				printf("%d ", i*j);
				cnt++;
				if (cnt == k) {
					ans = i * j;
					break;
				}
			}
		}
		if (cnt == k)
			break;
	}
	printf("\n");
	printf("%d\n", ans);

	return 0;
}
