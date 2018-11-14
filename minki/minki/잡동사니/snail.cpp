#include <iostream> // cin 사용 위해 필요 
#include <vector>	// vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>

using namespace std;

//달팽이
int main()
{
	int n, cnt = 1, temp;
	int arr[100][100];

	//n은 2차원 벡터의 크기
	scanf("%d", &n);

	//	시계	123
	//			894
	//			765

	//	공략
	//	n = 5
	//  5 4 4 3
	//  3 2 2 1
	//  1

	for (int i = 0; i < (n / 2) + 1; i++) {
		for (int j = i; j < n - i; j++)  // 왼쪽 ->오른쪽
			arr[i][j] = cnt++;
		for (int j = i + 1; j < n - i; j++)  // 위   -> 아래
			arr[j][n - i - 1] = cnt++;
		for (int j = i + 1; j < n - i; j++)  // 오른쪽->왼쪽
			arr[n - i - 1][n - j - 1] = cnt++;
		for (int j = i + 1; j < n - i - 1; j++)  // 아래 -> 위
			arr[n - j - 1][i] = cnt++;
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			printf("%5d", arr[i][j]);
		}
		puts("");
	}
	puts("");

	//	반시계	187
	//			296
	//			345

	cnt = 1;

	for (int i = 0; i < (n / 2) + 1; i++) {
		for (int j = i; j < n - i; j++)  // 위   -> 아래
			arr[j][i] = cnt++;
		for (int j = i + 1; j < n - i; j++)  // 왼쪽 ->오른쪽
			arr[n - i - 1][j] = cnt++;
		for (int j = i + 1; j < n - i; j++)  // 아래 -> 위
			arr[n - j - 1][n - i - 1] = cnt++;
		for (int j = i + 1; j < n - i - 1; j++)  // 오른쪽->왼쪽
			arr[i][n - j - 1] = cnt++;
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			printf("%5d", arr[i][j]);
		}
		puts("");
	}
}