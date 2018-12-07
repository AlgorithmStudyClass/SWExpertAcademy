/*
5603. [Professional] 건초더미 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXGEbd6cjMDFAUo&categoryId=AWXGEbd6cjMDFAUo&categoryType=CODE#
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

bool equal( int *arr  , int size ) {

    int flag = 1 ;
    int num = arr[0] ;
    for( int i = 0 ; i < size ; i++ ) {

        if( num == arr[i] ) {
            flag = 1 ;
        }
        else {
            flag = 0 ;
            break ;
        }
    }

    if( flag == 1 )
        return true ;
    else
        return false ;
}

int func( int *arr , int size) {

    int cnt = 0 ;

    while(true ) {

        if( equal( arr , size ) )
            return cnt ;

        int max = arr[0] ;
        int maxIndex = 0 ;
        int min = arr[0] ;
        int minIndex = 0 ;

        for( int i = 0 ; i < size ; i++ ) {

            if( max < arr[i] ) {
                max = arr[i] ;
                maxIndex = i ;
            }

            if( min > arr[i] ) {
                min = arr[i] ;
                minIndex = i ;
            }
        }

        arr[ maxIndex ]-- ;
        arr[ minIndex ]++ ;
        cnt++ ;
    }
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int size = 0 ;
        scanf("%d" , &size ) ;

        int *arr = new int[ size ] ;

        for( int i = 0 ; i < size ; i++ )
            scanf("%d" , &arr[i] ) ;

        int result = func( arr  , size ) ;

        printf("#%d %d\n" , T , result ) ;
    }
    return 0 ;
}








