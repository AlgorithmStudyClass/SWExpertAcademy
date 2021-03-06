/*
	6057. 그래프의 삼각형 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWczm7QaACgDFAWn&categoryId=AWczm7QaACgDFAWn&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, index;
	bool flag;
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	while (t > 0) {
		int a[5001], b[5001], c[5001], ans[5001] = { 0, }, p;
		//입력
		cin >> n;
		for (int i = 0; i < n; i++){
			scanf("%d %d", &a[i], &b[i]);
			for (int j = a[i] - 1; j < b[i]; j++)
				ans[j]++;
		}
		cin >> p;
		for (int i = 0; i < p; i++)
			scanf("%d", &c[i]);

		//출력
		printf("#%d ", line++);
		for (int i = 0; i < p; i++)
			printf("%d ",ans[c[i] - 1]);

		printf("\n");
		t--;
	}

	return 0;
}