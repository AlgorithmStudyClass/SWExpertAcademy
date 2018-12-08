/*
2806. N-Queen D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GKs06AU0DFAXB&categoryId=AV7GKs06AU0DFAXB&categoryType=CODE
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int cnt = 0 ;

bool promising( int i , int *col ) {

    int k = 1 ;
    bool flag = true ;

    while( k < i && flag ) {

        if( col[i] == col[k] || abs( col[i] - col[k] ) == ( i - k ) )
            flag = false ;

        k++ ;
    }
    return flag ;
}

void queens( int i , int size , int *col ) {

    for( int j = 1 ; j <= size ; j++ ) {

        col[ i ] = j ;

        if( promising( i , col ) ) {

            if( i == size ) {

                cnt++ ;
                return ;

            } else
                queens( i + 1 , size , col ) ;
        }
    }
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int size = 0 ;
        scanf("%d" , &size ) ;

        int col[20] = { 0 } ;

        queens( 1 , size , col ) ;

        printf("#%d %d\n" , T , cnt ) ;
        cnt = 0 ;

    }
    return 0 ;
}








