/*
	5986. 새샘이와 세 소수 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7IzvG6EksDFAXB&categoryId=AV7IzvG6EksDFAXB&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>
#include <cstring>

#define MAX 999
int table[1000]; // 소수확인정보
int visit[1001][1001];

using namespace std;

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, number;
	bool flag, flag2;
	vector<int> vec, temp_vec, ans_vec;
	vector<vector<int>> vec_vec;
	string str, temp_str;

	table[MAX] = 1; // 1은 소수 아닌것
	for (int i = 2; i <= 499; i++)
	{
		temp = 2;
		while (i*temp <= MAX)
		{
			table[i*temp] = 1;
			temp++;
		}
	}

	cin >> t;

	while (t > 0) {
		//입력    
		cin >> n;

		ans = 0;
		for (int a = 2; a <= n - 4; a++)
		{
			for (int b = 2; b <= n - a - 2; b++)
			{
				int c = n - a - b;
				if (!table[a] && !table[b] && !table[c] && !visit[a][b] && !visit[a][c])
				{
					ans++;
					visit[a][b] = visit[b][a] = 1;
					visit[a][c] = visit[c][a] = 1;
				}
			}
		}
		memset(visit, 0, sizeof(visit));

		//출력
		printf("#%d %d\n", line++, ans);
		t--;
	}

	return 0;
}