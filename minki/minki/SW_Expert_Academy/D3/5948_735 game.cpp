/*
	5948. 새샘이의 7-3-5 게임 -D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWZ2IErKCwUDFAUQ&categoryId=AWZ2IErKCwUDFAUQ&categoryType=CODE
*/

#include <iostream>
#include <vector>   
#include <algorithm> 
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, index,arr[7];
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	bool flag[300];

	while (t > 0) {
		//입력
		for (int i = 0; i < 7; i++)
			scanf("%d", &arr[i]);

		memset(&flag, 0, sizeof(flag));

		int asdf = 0;

		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 6; j++) {
				for (int k = j + 1; k < 7; k++) {
					flag[arr[i] + arr[j] + arr[k]] = true;
					asdf++;
				}
			}
		}
		printf("asdf: %d\n", asdf);
		cnt = 0;
		for (int i = 298 ; i > 0; i--){
			if (flag[i])
				if (++cnt == 5) {
					index = i;
					break;
				}
		}
		//출력
		cout << "#" << line++ << " " << index << endl;
		t--;
	}
	return 0;
}