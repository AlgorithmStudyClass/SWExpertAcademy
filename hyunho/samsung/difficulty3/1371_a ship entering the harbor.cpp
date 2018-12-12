/*
4371. 항구에 들어오는 배 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWMedCxalW8DFAXd&categoryId=AWMedCxalW8DFAXd&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

void change( int *checkArr , int *temp , int N , int gap ) {

    for( int i = 1 ; i < N ; i++ ) {

        if( temp[i] % gap == 1 )
            checkArr[i] = 1 ;
    }
}

bool check( int *checkArr , int N ) {

    for( int i = 1 ; i < N ; i++ ) {

        if( checkArr[i] == 0 )
            return true ;
    }
    return false ;
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0;
    while( T++ < testSize ) {

        int N = 0 ;
        scanf("%d" , &N ) ;

        int *arr = new int[ N ] ;
        for( int i = 0 ; i < N ; i++ )
            scanf("%d" , &arr[i] ) ;

        int *temp = arr ;

        int *checkArr = new int[ N ] ;
        for( int i = 0 ; i < N ; i++ )
            checkArr[i] = 0 ;

        int cnt = 0 ;
        int i = 1 ;
        while( check(checkArr , N ) ) {

            if( checkArr[i] != 1 ) {

                int gap = temp[ i ] - temp[ 0 ] ;
                change( checkArr , temp , N , gap ) ;
                cnt++ ;
            }
            i++ ;
        }
        printf("#%d %d\n" , T , cnt ) ;
    }
    return 0 ;
}






