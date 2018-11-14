using namespace std;

#include <iostream> // cin 사용 위해 필요 
#include <vector>	// vector 사용 위해 필요  
#include <algorithm> // sort 사용 위해 필요 
#include <string>
#include <numeric>

int main(void) {

	int a = 10;
	int &b = a;

	a = 11;
	b = 9;

	printf("%x %x\n", &a, &b); //같은 주소
	printf("%d %d\n", a, b); //9


	return 0;
}