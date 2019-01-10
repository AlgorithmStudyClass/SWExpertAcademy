/*
11657. 타임 머신
https://www.acmicpc.net/problem/11657

벨만 포드 알고리즘
*/

#include<iostream>
#include<vector>
using namespace std ;
#define INF 5000000

int N , M ;
int from , to , cost ;
int path[6001][3] ;
int dist[501] ;

int main() {

	scanf("%d %d" , &N , &M ) ;

	for( int i = 0 ; i <= N ; i++ )
		dist[i] = INF ;

	for( int i = 1 ; i <= M ; i++ )
		scanf("%d %d %d" , &path[i][0] , &path[i][1] , &path[i][2] ) ;

	dist[1] = 0 ;

	for( int i = 0 ; i < N - 1 ; i++ ) {
		for( int j = 1 ; j <= M ; j++ ) {

			if( dist[ path[j][0] ] != INF && dist[ path[j][1] ] > dist[ path[j][0] ] + path[j][2] )
				dist[ path[j][1] ] = dist[ path[j][0] ] + path[j][2] ;
		}
	}

	//	cycle 생성되서 ------- 되는경우
	for( int j = 1 ; j <= M ; j++ ) {

		if( dist[ path[j][0] ] != INF && dist[ path[j][1] ] > dist[ path[j][0] ] + path[j][2] ) {
			printf("-1\n");
			return 0 ;
		}
	}

	for( int i = 2 ; i <= N ; i++ ) {

		if( dist[i] != INF )
			printf("%d\n" , dist[i] ) ;
		else
			printf("-1\n" ) ;
	}
    return 0;
}






