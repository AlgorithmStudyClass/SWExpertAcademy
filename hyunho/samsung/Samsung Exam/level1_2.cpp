
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

bool isEmpty( int *tmpCarColor , int M ) {

    for( int i = 1 ; i < M + 1 ; i++ ) {

        if( tmpCarColor[i] != 0 )
            return true ;
    }
    return false ;
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int N , M = 0 ;
        scanf("%d %d" , &N , &M ) ;

        int criminalCarCnt = 0 ;
        int carColor[51] = { 0 , } ;
        for( int i = 1 ; i < M + 1 ; i++ ) {
            scanf("%d" , &carColor[i] ) ;
            criminalCarCnt += carColor[i] ;
        }

        int tolgate[1001] = { 0 , } ;
        for( int i = 0 ; i < N ; i++ )
            scanf("%d" , &tolgate[i] ) ;

        int tmpCarColor[51] ;
        copy(carColor, carColor + 51, tmpCarColor);

        int flagIndex = 0 ;

        for( int i = 0 ; i <= N - criminalCarCnt ; i++ ) {

            for( int j = i ; j < i + criminalCarCnt ; j++ )
                tmpCarColor[ tolgate[j] ] -= 1 ;

            if( !isEmpty( tmpCarColor , M ) ) {
                flagIndex = i + 1 ; break ;
            } else
                copy(carColor, carColor + 51, tmpCarColor);
        }
        printf("#%d %d\n" , T , flagIndex ) ;
    }
    return 0 ;
}












