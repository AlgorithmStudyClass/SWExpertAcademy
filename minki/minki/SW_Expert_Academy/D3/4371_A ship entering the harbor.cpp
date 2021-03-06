/*
	4371. 항구에 들어오는 배 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWMedCxalW8DFAXd&categoryId=AWMedCxalW8DFAXd&categoryType=CODE
*/

#include <iostream>
#include <vector>   
#include <algorithm> 
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int func(vector<int> vec, int n) {
	int temp , i , max = vec[n - 1];

	for (i = 1; i < n; i++) {
		temp = vec[1] - vec[0];
		
		for (int j = 1;vec[0] + j*temp <= max; j++) {
			if (std::find(vec.begin(), vec.end(), vec[0] + j * temp) != vec.end()) {
				vector <int> ::iterator iter = std::find(vec.begin(), vec.end(), vec[0] + j * temp);
				vec.erase(iter);
			}
		}

		if (vec.size() == 1)
			break;
	}

	return i;
}

int main()
{
	int t, line = 1, len, n, m, k, temp, sum, max, cnt, index;
	vector<int> vec, temp_vec; 
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	while (t > 0) {
		//입력
		cin >> n;
		for (int i = 0; i < n; i++){
			scanf("%d", &temp);
			vec.push_back(temp);
		}

		//출력
		printf("#%d %d\n", line++, func(vec , n));
		vec.clear();
		t--;
	}

	return 0;
}