/*
11660. 구간의 합5
https://www.acmicpc.net/problem/11660

dp
*/

#include<iostream>
using namespace std ;

int N , M ;
int D[1025][1025] ;
int list[1025][1025] ;

int main() {

	scanf("%d %d" , &N , &M ) ;

	for( int i = 1 ; i <= N ; i++ ) {
		for( int j = 1 ; j <= N ; j++ )
			scanf("%d" , &list[i][j] ) ;
	}

	for( int i = 0 ; i <= N ; i++ )
		D[i][0] = 0 ;
	for( int j = 0 ; j <= N ; j++ )
		D[0][j] = 0 ;

	for( int i = 1 ; i <= N ; i++ ) {
		for( int j = 1 ; j <= N ; j++ )
			D[i][j] = D[i-1][j] + D[i][j-1] - D[i-1][j-1] + list[i][j] ;
	}

	int x1 ,y1 , x2 , y2 ;
	int ans ;
	for( int i = 0 ; i < M ; i++ ) {

		scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2 ) ;

		ans = D[x2][y2] - D[x2][y1-1] - D[x1-1][y2] + D[x1-1][y1-1] ;
		printf("%d\n" , ans ) ;
	}

	return 0 ;

}












