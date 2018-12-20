/*
	4522. 세상의 모든 팰린드롬 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWO6Oao6N4QDFAWw&categoryId=AWO6Oao6N4QDFAWw&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>
#include <cstring>

using namespace std;

int main()
{
	int t, line = 1, len, n, m, k, temp, sum, max, number;
	bool flag, flag2;
	vector<int> vec, temp_vec, ans_vec;
	vector<vector<int>> vec_vec;
	string str, temp_str;

	cin >> t;

	n = 1000000;

	bool *primeArray = new bool [n + 1];
	for (int i = 2; i <= n; i++) 
		primeArray[i] = true;

	for (int i = 2; i * i <= n+1; i++) {
		if (primeArray[i])
			for (int j = i; i + j <= n+1; j += i)
				primeArray[i + j] = false;
	}

	while (t > 0) {
		//입력    
		int a, b, d, ans = 0;
		scanf("%d %d %d", &d,&a, &b);

		for (int i = a; i <= b; i++) {
			if (primeArray[i]) {
				if(check(to_string(i),d))
					ans++;
			}
		}
		
		//출력
		printf("#%d %d\n", line++, ans);
		t--;
	}

	return 0;
}