/*
11049. 행렬 곱셈 순서
https://www.acmicpc.net/problem/11049

dp
D[i][j] : i행에서 j행까지 곱했을 때 최소 곱셈연산 수
*/


#include<iostream>
using namespace std ;

int N ;
int list[501][3] ;
int D[501][501] ;

int main() {

	scanf("%d" , &N ) ;

	for( int i = 1 ; i <= N ; i++ )
		scanf("%d %d" , &list[i][1] , &list[i][2] ) ;

	for( int i = 1 ; i < N ; i++ )
		D[i][i+1] = list[i][1] * list[i][2] * list[i+1][2] ;

	for ( int l=2; l<=N; l++ ) {
        for ( int i=1; i<=N-l; i++ ) {
            int j = i + l;
            for ( int k=i; k<j; k++ ) {
                int c = D[i][k] + D[k+1][j] + (list[i][1] * list[k][2] * list[j][2]);
                if ( D[i][j] == 0 || D[i][j] > c ) D[i][j] = c;
            }
        }
    }

    printf("%d\n" , D[1][N] ) ;
    return 0 ;
}












