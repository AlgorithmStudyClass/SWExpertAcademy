using namespace std;

#include <iostream> // cin 사용 위해 필요 
#include <vector>	// vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	vector<int> supo1 ,	temp1= { 1, 2, 3, 4, 5 };
	vector<int> supo2 ,	temp2= { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> supo3 ,	temp3= { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int len = answers.size();

	for (int i = 0; i < len / 5 + 1 ; i++)
		supo1.insert(supo1.end(), temp1.begin(), temp1.end());
	for (int i = 0; i < len / 7 + 1; i++)
		supo2.insert(supo2.end(), temp2.begin(), temp2.end());
	for (int i = 0; i < len / 10 + 1; i++)
		supo3.insert(supo3.end(), temp3.begin(), temp3.end());

	vector<int> num = { 0,0,0 };
	int max = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == supo1[i]) {
			num[0]++;
			if (max < num[0])
				max = num[0];
		}
		if (answers[i] == supo2[i]){
			num[1]++;
			if (max < num[1])
				max = num[1];
		}
		if (answers[i] == supo3[i]) {
			num[2]++;
			if (max < num[2])
				max = num[2];
		}
	}

	if (max == num[0])
		answer.push_back(1);
	if (max == num[1])
		answer.push_back(2);
	if (max == num[2])
		answer.push_back(3);

	return answer;
}

int main(void) {
	vector<int> answer;
	answer = solution({ 1,2,3,4,5});
	for (int i = 0; i<answer.size(); ++i)
		std::cout << answer[i] << ' ';

	answer = solution({ 1,3,2,4,2 });
	for (int i = 0; i<answer.size(); ++i)
		std::cout << answer[i] << ' ';
}

//1번 수포자가 찍는 방식 : 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
//2번 수포자가 찍는 방식 : 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
//3번 수포자가 찍는 방식 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...