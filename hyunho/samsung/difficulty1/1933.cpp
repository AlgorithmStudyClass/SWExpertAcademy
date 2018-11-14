/*
1933. 간단한 N 의 약수
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PhcWaAKIDFAUq&categoryId=AV5PhcWaAKIDFAUq&categoryType=CODE

< input >
10

< output >
1 2 5 10

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

	int inputNum = 0 ;
	scanf("%d" , &inputNum ) ;

	for( int i = 1 ; i <= inputNum ; i++ ) {

		int result = inputNum % i ;
		if( result == 0 )
			printf("%d " , i ) ;
	}
	printf("\n" ) ;
	return 0 ;
}


