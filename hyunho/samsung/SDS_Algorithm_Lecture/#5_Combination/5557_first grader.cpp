/*
5557. 1학년
https://www.acmicpc.net/problem/5557

dp
*/

#include<iostream>
using namespace std ;

int N ;
int list[101] ;
long long int D[101][21] ;

int main() {

	scanf("%d" , &N ) ;

	for( int i = 1 ; i <= N ; i++ )
		scanf("%d" , &list[i] ) ;


	D[1][list[1]] = 1 ;

	for( int i = 2 ; i <= N ; i++ ) {
		for( int j = 0 ; j < 21 ; j++ ) {

			if( j + list[i] < 21 )
				D[i][j+list[i]] += D[i-1][j] ;

			if( j - list[i] >= 0 )
				D[i][j-list[i]] += D[i-1][j] ;
		}
	}

	printf("%lld\n" , D[N-1][list[N]]) ;
	return 0 ;
}







