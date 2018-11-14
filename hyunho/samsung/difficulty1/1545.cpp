/*
1545. 거꾸로 출력해 보아요
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV2gbY0qAAQBBAS0&categoryId=AV2gbY0qAAQBBAS0&categoryType=CODE

< input >
8

< output >
8 7 6 5 4 3 2 1 0

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

	int inputNum = 0 ;
	scanf("%d" , &inputNum ) ;

	for( int i = inputNum ; i >= 0 ; i-- )
		printf("%d " , i ) ;
	printf("\n" ) ;

	return 0 ;
}


