#include <iostream> // cin ��� ���� �ʿ� 
#include <vector>	// vector ��� ���� �ʿ�  
#include <algorithm> // sort ��� ���� �ʿ� 
#include <string>
#include <numeric>

using namespace std;


int main()
{
	int n;
	string str;
	getline(cin, str);
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	//for (auto & c: str) c = toupper(c);
	printf("%s", str.c_str());
}