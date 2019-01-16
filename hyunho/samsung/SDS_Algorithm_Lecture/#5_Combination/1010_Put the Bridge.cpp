/*
1010. 다리 놓기
https://www.acmicpc.net/problem/1010

조합론
*/

#include<iostream>
using namespace std ;

int N , M ;
int D[61][61] ;

int main() {

	for( int i = 0 ; i <= 60 ; i++ ) {

		D[i][0] = 1 ;
		for( int j = 1 ; j <= i ; j++ )
			D[i][j] = ( D[i-1][j-1] + D[i-1][j] ) ;
	}

	int testSize = 0 ;
	scanf("%d" , &testSize ) ;

	int T = 0 ;
	while( T++ < testSize ) {

		scanf("%d %d" , &N , &M ) ;
		printf("%d\n" , D[M][N] ) ;
	}

	return 0 ;
}









