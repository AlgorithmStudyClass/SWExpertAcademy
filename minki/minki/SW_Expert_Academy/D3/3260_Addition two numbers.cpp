/*
	3260. 두 수의 덧셈 - D3
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBC1lOad9IDFAWr&categoryId=AWBC1lOad9IDFAWr&categoryType=CODE
*/

#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <cstring>
#include <numeric>
#include <sstream>

using namespace std;

string func(string str1, string str2) {
	long long int len1 = str1.length(), len2 = str2.length();
	long long int i;
	int temp1, temp2;

	//무조건 str1이 더 짧을 때 가정
	if (len1 > len2) {
		swap(str1, str2);
		swap(len1, len2);
	}

	string ans = str2;
	ans.insert(ans.begin(), '0');
	len2++;

	for (i = 1; i <= len1; i++) {
		temp1 = str1[len1 - i] - '0';
		temp2 = ans[len2 - i] - '0';

		//자리 수 더했을 때 10 이상이면
		if (temp1 + temp2 >= 10) {
			ans[len2 - i] = temp1 + temp2 - 10 + '0';
			int cnt = 1;
			//앞의 숫자가 9면 또 더해야하므로
			if (ans[len2 - i - cnt] == '9') {
				while (ans[len2 - i - cnt] == '9') {
					ans[len2 - i - cnt] = '0';
					cnt++;
				}
				ans[len2 - i - cnt]++;
			}
			else
				ans[len2 - i - cnt]++;
		}
		else
			ans[len2 - i] = temp1 + temp2 + '0';
	}

	if (ans[0] == '0')
		ans.erase(ans.begin(), ans.begin() + 1);

	return ans;
}

int main()
{
	int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, index;
	bool flag;
	vector<int> vec, temp_vec;
	string str, temp_str;
	vector<string> str_vec, ans_vec;

	cin >> t;

	while (t > 0) {
		string str1, str2;
		//입력
		cin >> str1 >> str2;

		//출력
		printf("#%d %s", line++,func(str1,str2).c_str());
		printf("\n");
		t--;
	}

	return 0;
}