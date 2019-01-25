/*
	1256 사전
	https://www.acmicpc.net/problem/1256
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1000000000

int n, k,m;
long long int bc[201][201];
string str;

int main(void) {
	scanf("%d %d %d", &n,&m, &k);
	
	// a를 선택하면 n+m-1Cm
	// z를 선택하면 n+m-1Cm-1

	//1 n+m-1Cm >= k 첫 'a'
	//2 n+m-1Cm < k 첫 'z'

	for (int i = 0; i <= n + m; i++) {
		bc[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
			if (bc[i][j] > MAX_N)
				bc[i][j] = 1000000001;
		}
	}

	int com = bc[n + m][m] , cnt = 0; //cnt = z체크
	if (k > com) {
		puts("-1");
		return 0;
	}
	com = bc[n + m - 1][m];
	for (int i = 1; i <= n + m; i++) {
		if (k <= com) {
			str += "a";
			com = bc[n + m - 1 - i][m - cnt];
		}
		else {
			str += "z";
			k -= com; //앞자리가 a인 갯수 제외
			com = bc[n + m - 1 -i][m - 1 - cnt++]; //하나 선택했으니 row 하나 빼고 z선택했으니 z 갯수만큼 감소
		}
	}

	printf("%s\n", str.c_str());

	return 0;
}