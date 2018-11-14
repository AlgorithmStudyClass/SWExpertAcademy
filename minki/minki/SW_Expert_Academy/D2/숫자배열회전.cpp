#include <iostream> // cin 사용 위해 필요 
#include <vector>	// vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>
#include <sstream>

using namespace std;

int main()
{
	int t,cnt = 1,ans,len,flag, n , temp;
	vector<vector<string>> matrix , ans_vec;
	string str,cut,temp_str;


	cin >> t;

	while (t > 0) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			matrix.push_back(vector<string>());
			ans_vec.push_back(vector<string>());
			for (int j = 0; j < n; j++) {
				cin >> str;
				istringstream iss(str);
				while (getline(iss, cut, ' ')) {
					matrix[i].push_back(cut);
				}
			}
		}

		// 1열
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				ans_vec[i].push_back(string());
				ans_vec[i][0].insert(0, matrix[j][i]);
			}
		//2열
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans_vec[i][1].insert(0, matrix[n - 1 - i][j]);

		//3열
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans_vec[i][2].insert(0, matrix[n - 1 - j][n - 1 - i]);

		printf("#%d\n", cnt++);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%s ", ans_vec[i][j].c_str());
			}
			puts("");
		}

		for (int i = 0; i < n; i++) {
			matrix[i].clear();
			ans_vec[i].clear();
		}
		t--;
	}
}