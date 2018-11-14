#include <iostream> // cin ��� ���� �ʿ� 
#include <vector>	// vector ��� ���� �ʿ�  
#include <algorithm> // sort ��� ���� �ʿ� 
#include <string>
#include <numeric>

using namespace std;

//90 �� ȸ��
int main()
{
	int n, cnt = 1;
	vector<vector<int>> vec;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		vec.push_back(vector<int>());
		for (int j = 0; j < n; j++)
			vec[i].push_back(cnt++);
	}
	
	//vector ���
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++)
			printf("%3d ", vec[i][j]);
		puts("");
	}
	puts("");

	vector<vector<int> > temp(vec.size(),vector<int>(vec[0].size()));

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[0].size(); j++) {
			// Clockwise rotation
			temp[j][vec[0].size() - i - 1] = vec[i][j];
			// Counter-clockwise rotation
			//temp[vec.size()-j-1][i] = vec[i][j];
		}
	}

	vec = temp;       // set p equal to temp

	//vector ���
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++)
			printf("%3d ", vec[i][j]);
		puts("");
	}
}