/*
9252. LCS2( 최장 공통 부분 수열 )
https://www.acmicpc.net/problem/9252

DP
*/

#include<iostream>
#include<cstring>
using namespace std ;

char str1[1001] ;
char str2[1001] ;
int D[1001][1001] ;
char ans[1001] ;

int max_func( int a , int b ) {
    return ( a > b )? a : b ;
}

int LCS_length() {

    for( int i = 0 ; i <= strlen(str1) ; i++ )
        D[i][0] = 0 ;

    for( int j = 0 ; j <= strlen(str2) ; j++ )
        D[0][j] = 0 ;

    for( int i = 1 ; i <= strlen(str1) ; i++ ) {
        for( int j = 1 ; j <= strlen(str2) ; j++ ) {

            if( str1[i-1] == str2[j-1] )
                D[i][j] = D[i-1][j-1] + 1 ;
            else
                D[i][j] = max_func( D[i-1][j] , D[i][j-1] ) ;
        }
    }

    return D[strlen(str1)][strlen(str2)] ;
}

void backTracking( int i , int j , int idx ) {

    if( i == 0 || j == 0 )
        return ;
    else if( str1[i-1] == str2[j-1] ) {
        ans[idx++] = str1[i-1] ;
        backTracking( i-1 , j-1 , idx );
    } else {

        if( D[i-1][j] > D[i][j-1] )
            backTracking( i-1 , j , idx ) ;
        else
            backTracking( i , j-1 , idx ) ;
    }

}

int main() {

    scanf("%s" , str1 ) ;
    scanf("%s" , str2 ) ;

    printf("%d\n" , LCS_length() ) ;

    backTracking( strlen(str1) , strlen(str2) , 0 ) ;

    for( int i = strlen(ans) - 1 ; i >= 0 ; i-- )
        printf("%c" , ans[i] ) ;
    printf("\n") ;

    return 0 ;
}






