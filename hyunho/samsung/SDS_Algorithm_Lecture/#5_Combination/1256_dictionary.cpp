/*
1256. 사전
https://www.acmicpc.net/problem/1256

*/

#include<iostream>
using namespace std ;

#define MAX_SIZE 1000000000

int N , M , K ;
int D[201][201] ;

int main() {

	scanf("%d %d %d" , &N , &M , &K ) ;

	for( int i = 0 ; i <= 200 ; i++ ) {

		D[i][0] = 1 ;
		for( int j = 1 ; j <= i ; j++ ) {
			D[i][j] = D[i-1][j-1] + D[i-1][j] ;

			if( D[i][j] > MAX_SIZE )
				D[i][j] = MAX_SIZE + 1 ;
		}
	}

	int size = N + M ;
	if( D[size][2] < K ) {
		printf("-1\n") ; return 0 ;
	}

	int cnt = 0 ;
	while( cnt < size ) {

		if( D[N+M-1][M] < K ) {	//	z경우

			printf("z") ;
			K -= D[N+M-1][M] ;
			M-- ;
		} else {

			printf("a") ;
			N-- ;
		}
		cnt++ ;
	}

	printf("\n" );
	return 0 ;
}









