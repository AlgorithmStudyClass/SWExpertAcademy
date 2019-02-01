/*
11404. 플로이드
https://www.acmicpc.net/problem/11404

플로이드 워셜
*/

#include<iostream>
using namespace std ;
#define INF 100*100000 + 1

int n , m ;
int dist[101][101] ;
int from , to , cost ;

int min( int a , int b ) {
	return ( a > b ) ? b : a ;
}

int main() {

	scanf("%d" , &n ) ;
	scanf("%d" , &m ) ;

	for( int i = 0 ; i <= n ; i++ ) {
		for( int j = 0 ; j <= n ; j++ )
			( i == j ) ? dist[i][j] = 0 : dist[i][j] = INF ;
	}

	for( int i = 0 ; i < m ; i++ ) {
		scanf("%d %d %d" , &from , &to , &cost ) ;
		dist[from][to] = min( dist[from][to] , cost ) ;
	}

	for( int k = 1 ; k <= n ; k++ ) {
		for( int i = 1 ; i <= n ; i++ ) {
			for( int j = 1 ; j <= n ; j++ ) {

				if( i != j )
					dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j] ) ;
			}
		}
	}

	for( int i = 1 ; i <= n ; i++ ) {
		for( int j = 1 ; j <= n ; j++ )
			( dist[i][j] != INF ) ? printf("%d " , dist[i][j] ) : printf("0 " ) ;
		printf("\n") ;
	}

	return 0 ;
}
