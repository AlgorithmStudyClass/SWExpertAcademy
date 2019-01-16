/*
13251. 조약돌 꺼내기
https://www.acmicpc.net/problem/13251

dp
*/

#include<iostream>
using namespace std ;

int M ;
int list[51] ;
int K ;
double probability[51] ;
double ans ;

int main() {

	scanf("%d" , &M ) ;

	int totalCnt = 0 ;
	for( int i = 0 ; i < M ; i++ ) {
		scanf("%d" , &list[i] ) ;
		totalCnt += list[i] ;
	}

	scanf("%d" , &K ) ;

	for( int i = 0 ; i < M ; i++ ) {

		if( list[i] >= K ) {

			probability[i] = 1.0 ;
			for( int j = 0 ; j < K ; j++ )
				probability[i] *= (double)( list[i] - j ) / ( totalCnt - j ) ;
		}
		ans += probability[i] ;
	}

	printf("%.16lf\n" , ans ) ;
	return 0 ;
}















