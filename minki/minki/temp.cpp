/*
2817. �κ� ������ �� - D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7IzvG6EksDFAXB&categoryId=AV7IzvG6EksDFAXB&categoryType=CODE
*/

#include <iostream> // cin ��� ���� �ʿ� 
#include <vector> // vector ��� ���� �ʿ�  
#include <algorithm> // sort ��� ���� �ʿ� 
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
		//�Է�    
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