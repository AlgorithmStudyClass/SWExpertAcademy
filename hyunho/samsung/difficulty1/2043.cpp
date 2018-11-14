/*
2043. 서랍의 비밀번호 
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QJ_8KAx8DFAUq&categoryId=AV5QJ_8KAx8DFAUq&categoryType=CODE

< input >
123 100

< output >
24

*/
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main() {

	int P = 0 , K = 0 ;
	scanf("%d" , &P ) ;
	scanf("%d" , &K ) ;

	int resultNum = 0 ;
	if( P >= K )	//	정답이 더 크거나 같을경우
		resultNum = P - K + 1 ;
	else {
		resultNum = ( 999 - K + 1 ) + ( P + 1 ) ;
	}

	printf("%d\n" , resultNum ) ;


	return 0 ;
}


