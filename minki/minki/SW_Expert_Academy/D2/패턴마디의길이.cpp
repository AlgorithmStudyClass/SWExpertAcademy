#include <iostream> // cin 사용 위해 필요 
#include <vector> // vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

int main()
{
	int t, cnt = 1, ans, len, flag;
	string str, temp, cut;

	cin >> t;

	while (t > 0) {
		ans = 0;
		cin >> str;

		for (int x = 0, y = 1; y < str.length(); y++) {

			if (str[x] == str[y]) {

				if (x == 0)    //  처음
					ans = y;

				x++;

			}
			else {
				ans = 0;
				x = 0;
			}
		}


		printf("#%d %d\n", cnt++, ans);
		t--;
	}
}