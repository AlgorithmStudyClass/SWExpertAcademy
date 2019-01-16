/*
2449. 전구
https://www.acmicpc.net/problem/2449

dp
행렬의 곱 처럼 j 를 늘리면서 비교
*/

#include<iostream>
using namespace std ;

int N , K ;
int list[201] ;
int D[201][201] ;

int min_func( int a , int b ) {
	return ( a > b ) ? b : a ;
}

int main() {

	scanf("%d %d" , &N , &K ) ;

	for( int i = 1 ; i <= N ; i++ )
		scanf("%d" , &list[i] ) ;

	for( int l = 1 ; l <= N ; l++ ) {
		for( int i = 1 ; i <= N-l ; i++ ) {
			int j = i + l ;
			D[i][j] = 4000 ;
			for( int k = i ; k < j ; k++ ) {

				int tmp = D[i][k] + D[k+1][j] +( (list[i] == list[k+1])? 0 : 1 )  ;
				D[i][j] = min_func( D[i][j] , tmp ) ;
			}
		}
	}

	printf("%d\n" , D[1][N] ) ;
	return 0 ;
}




