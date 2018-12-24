/*
	5215. 햄버거 다이어트 D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWT-lPB6dHUDFAVT&categoryId=AWT-lPB6dHUDFAVT&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

#define MAX_CAL 10000
#define MAX_NUM 20

int l; //제한 칼로리
int p[MAX_NUM +1][MAX_CAL +2];
int ta[MAX_NUM + 1], k[MAX_NUM + 1];

int MAX(int a, int b) {
	return a < b ? b : a;
}

int main()
{
	int t, ans, line = 1, len, n, m, temp, sum, max, cnt, number;
	bool flag, flag2;
	std::vector<int> vec, temp_vec, ans_vec;
	std::vector<std::vector<int>> vec_vec;
	std::string str, temp_str;

	std::cin >> t;

	while (t > 0) {
		// dp knapscak 
		// i, l =0 -> 0
		// ki >= l -> p(i-1,l)
		// ki < l  -> max(p(i-1,l) , pi + p(i-1,l-ki))

		//입력
		scanf("%d %d", &n, &l);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &ta[i + 1], &k[i + 1]); // 점수, 칼로리
		}

		for (int i = 0; i <= l; i++)
			p[0][i] = 0;
		
		for (int i = 1; i <= n; i++) {
			p[i][0] = 0;
			for (int j = 1; j <= l; j++) {
				if (k[i] <= j) {
					p[i][j] = MAX(p[i - 1][j], ta[i] + p[i - 1][j - k[i]]);
				}
				else
					p[i][j] = p[i - 1][j];
			}
		}

		//출력
		printf("#%d %d\n",line++, p[n][l]);
		t--;
	}

	return 0;
}