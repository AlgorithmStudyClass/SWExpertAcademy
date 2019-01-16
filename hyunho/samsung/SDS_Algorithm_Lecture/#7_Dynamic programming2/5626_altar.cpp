/*
5626. 제단
https://www.acmicpc.net/problem/5626

DP
어렵
*/

#include<iostream>
using namespace std ;

int N ;
long long int D[2][5003] ;    //  [2]는 [10001] 로 하면 메모리 문제 있어서 공유 사용 , [5002] 는 가장 높이 나올 수 있는 h 는 n / 2 이다 여유있게 5002
int list[10001] ;

int main() {

    scanf("%d" , &N ) ;

    for( int i = 1 ; i <= N ; i++ )
        scanf("%d" , &list[i] ) ;

    int mod = 1000000007 ;

    if( list[1] == -1 || list[1] == 0 )
        D[0][0] = 1 ;

    // D[0][0] = ( list[1] == -1 )? 1 : ( list[1] == 0 )? 1 : 0 ;

    for( int i = 2 ; i <= N ; i++ ) {

        if( list[i] == -1 ) {
            D[1][0] = ( D[0][0] + D[0][1] ) % mod ;
            for( int j = 1 ; j <= N / 2 ; j++ )
                D[1][j] = ( D[0][j-1] + D[0][j] + D[0][j+1] ) % mod ;
        
        } else if( list[i] == 0 )
            D[1][0] = ( D[0][0] + D[0][1] ) % mod ;
        else
            D[1][list[i]] = ( D[0][list[i]-1] + D[0][list[i]] + D[0][list[i]+1] ) % mod ;

        for( int j = 0 ; j <= N/2 ; j++ ) {
            D[0][j] = D[1][j] ;
            D[1][j] = 0 ;
        }
    }

    printf("%lld\n" , D[0][0] ) ;
    return 0 ;

}






