/*
11051. 이항 계수2
https://www.acmicpc.net/problem/11051

조합론
*/

#include<iostream>
using namespace std ;

int N , K ;
int D[1001][1001] ;

int main() {

	scanf("%d %d" , &N , &K ) ;

	for( int i = 0 ; i <= N ; i++ ) {

		D[i][0] = 1 ;
		for( int j = 1 ; j <= i ; j++ )
			D[i][j] = ( D[i-1][j-1] + D[i-1][j] ) % 10007 ;
	}

	printf("%d\n" , D[N][K] ) ;
	return 0 ;
}









