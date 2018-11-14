#include <iostream> // cin 사용 위해 필요 
#include <vector>	// vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
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