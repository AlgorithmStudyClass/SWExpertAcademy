/*
2817. 부분 수열의 합 - D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7IzvG6EksDFAXB&categoryId=AV7IzvG6EksDFAXB&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

int func(int arr[], int n, int k) {
	int ans = 0;


	return ans;
}

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, number;
	bool flag, flag2;
	vector<int> vec, temp_vec, ans_vec;
	vector<vector<int>> vec_vec;
	string str, temp_str;

	cin >> t;

	while (t > 0) {
		//입력    
		cin >> n >> k;

		int arr[1001];

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		printf("#%d %d\n", line++, func(arr, n, k));
		t--;
	}

	return 0;
}