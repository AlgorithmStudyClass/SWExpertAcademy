string solution(string rule, string A, string B) {
	string answer = "";

	int len = rule.length();
	int a = 0, b = 0, diff, temp;

	temp = 1;
	for (int i = A.length() - 1; i >= 0; i--) {
		a += distance(rule.begin(), find(rule.begin(), rule.end(), A[i])) * temp;
		temp *= len;
	}

	temp = 1;
	for (int i = B.length() - 1; i >= 0; i--) {
		b += distance(rule.begin(), find(rule.begin(), rule.end(), B[i])) * temp;
		temp *= len;
	}

	diff = a - b;

	while (diff > 0) {
		temp = diff % len;
		diff /= len;
		answer.insert(answer.begin(), rule[temp]);
	}

	return answer;
}

int main(void) {
	printf("%s\n", solution("zothf", "otz", "hh").c_str());
	printf("%s\n", solution("ab", "ba", "a").c_str());
	printf("%s\n", solution("abcdefghij", "cba", "a").c_str());
}

int solution(vector<vector<int> > envelopes)
{
	int answer = 1, len = envelopes.size(), a, b;

	//첫 원소로 정렬
	sort(envelopes.begin(), envelopes.end());

	a = envelopes[0][0];
	b = envelopes[0][1];

	for (int i = 1; i < len; i++) {
		if (a < envelopes[i][0] && b < envelopes[i][1]) {
			answer++;
			a = envelopes[i][0];
			b = envelopes[i][1];
		}
	}

	return answer;
}

int main(void) {

	//	printf("%d\n", solution({ { 5,3 },{ 5,7 },{ 3,3 },{ 1,2 } }));
	printf("%d\n", solution({ { 3,6 },{ 2,3 },{ 7,3 },{ 1,1 },{ 8, 6 },{ 4, 5 } }));

}