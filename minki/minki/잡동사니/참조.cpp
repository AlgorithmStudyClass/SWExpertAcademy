using namespace std;

#include <iostream> // cin ��� ���� �ʿ� 
#include <vector>	// vector ��� ���� �ʿ�  
#include <algorithm> // sort ��� ���� �ʿ� 
#include <string>
#include <numeric>

int main(void) {

	int a = 10;
	int &b = a;

	a = 11;
	b = 9;

	printf("%x %x\n", &a, &b); //���� �ּ�
	printf("%d %d\n", a, b); //9


	return 0;
}