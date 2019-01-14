/*
	1735 분수합
	https://www.acmicpc.net/problem/1735
*/

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)return a;
	else return gcd(b,(a%b));
	
	/*while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;*/
}

int main() {
	int a, b, c, d , gcd_num;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	a = a * d + b * c;
	b = b * d;
	gcd_num = gcd(a, b);
	printf("%d %d\n", a / gcd_num, b / gcd_num);


	return 0;
}
