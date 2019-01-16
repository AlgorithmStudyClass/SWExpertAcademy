/*
5582. LCS3( 최장 공통 부분 수열 )
https://www.acmicpc.net/problem/5582

LCS
추가로 문자열 출력하는것까지 만들었음
*/

#include<iostream>
#include<cstring>
using namespace std ;

char str1[4001] ;
char str2[4002] ;
int D[4001][4001] ;
int ans ;
char ansStr[4001] ;

int max_func( int a , int b ) {
    return ( a > b )? a : b ;
}

int main() {

    scanf("%s" , str1 ) ;
    scanf("%s" , str2 ) ;

    for( int i = 0 ; i <= strlen(str1) ; i++ )
        D[i][0] = 0 ;
    for( int j = 0 ; j <= strlen(str2) ; j++ )
        D[0][j] = 0 ;

    int idxX , idxY ;
    idxX = idxY = -1 ;

    for( int i = 1 ; i <= strlen(str1) ; i++ ) {
        for( int j = 1 ; j <= strlen(str2) ; j++ ) {

            if( str1[i-1] == str2[j-1] ) {

                D[i][j] = D[i-1][j-1] + 1 ;

                // ans = max_func( ans , D[i][j] ) ;

                if( ans < D[i][j] ) {
                    ans = D[i][j] ;
                    idxX = i ; idxY = j ;   //  최대일경우의 index i , j 저장
                }

            }
        }
    }

    printf("%d\n" , ans ) ;

    //  최대일경우 index 에서 대각선으로 올라가면서 문자열 저장
    int ii = 0 ;
    while( D[idxX][idxY] > 0 ) {

        ansStr[ii++] = str1[idxX-1] ;
        idxX-- ; idxY-- ;
    }

    //  문자열 거꾸로 출력
    for( int i = strlen(ansStr) - 1 ; i >= 0 ; i-- )
        printf("%c" , ansStr[i] ) ;
    printf("\n") ;

    return 0 ;
}







