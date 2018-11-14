#include <iostream> // cin 사용 위해 필요 
#include <vector>	// vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>


using namespace std;

int main()
{
	int t, line = 1, len, flag, n, k, temp, sum, max, mode, cnt;
	vector<int> arr, temp_arr, ans_vec;
	string str;
	long long int ans;

	cin >> t;

	while (t > 0) {
		cin >> n;
		ans = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			arr.push_back(temp);
		}

		cnt = 1;
		temp = 0;

		while (!arr.empty()) {
			max = *max_element(arr.begin(), arr.end());
			temp = 0;
			cnt = 1;
			for (int i = 0; i < n; i++) {
				if (arr[i] == max) {
					ans += arr[i] * (cnt - 1) - temp;
					arr.erase(arr.begin(), arr.begin() + i + 1);
					cnt = 1;
					temp = 0;
					break;
				}
				temp += arr[i];
				cnt++;
			}
		}

		printf("#%d %lld\n", line++, ans);
		arr.clear();
		t--;
	}

	return 0;
}