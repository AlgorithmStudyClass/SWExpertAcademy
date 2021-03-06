/*
	3307. 최장 증가 부분 수열 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBOKg-a6l0DFAWr&categoryId=AWBOKg-a6l0DFAWr&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

int func(int arr[], int n) {
	int best[1001], prev[1001], i, j, max = 0;

	for (i = 0; i < n; i++)
		best[i] = 1 , prev[i] = i;

	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
			if (arr[i] > arr[j] && best[i] < best[j] + 1)
				best[i] = best[j] + 1, prev[i] = j;
				//prev[] is for backtracking the subsequence

	for (i = 0; i < n; i++)
		if (max < best[i])
			max = best[i];

	return max;
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
		cin >> n;
		
		int arr[1001];
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		printf("#%d %d\n", line++, func(arr,n));
		t--;
	}

	return 0;
}