/*
11050. 이항 계수1
https://www.acmicpc.net/problem/11050

조합론
*/

#include<iostream>
using namespace std ;

int N , K ;
int D[11][11] ;

int main() {

	scanf("%d %d" , &N , &K ) ;

	for( int i = 0 ; i <= N ; i++ ) {

		D[i][0] = 1 ;
		for( int j = 1 ; j <= i ; j++ )
			D[i][j] = D[i-1][j-1] + D[i-1][j] ;
	}

	printf("%d\n" , D[N][K] ) ;
	return 0 ;
}









