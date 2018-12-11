/*
4676. 늘어지는 소리 만들기 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWRKWITqfvIDFAV8&categoryId=AWRKWITqfvIDFAV8&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

void hyphen( int *arr , int H , int index ) {

    for( int i = 0 ; i < H ; i++ ) {
        if( arr[i] == index )
            printf("-") ;
    }
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        char text[21] = "" ;
        scanf("%s" , text ) ;
        int size = strlen( text ) ;

        int H = 0 ;
        scanf("%d" , &H ) ;

        int *arr = new int[ H ] ;
        for( int i = 0 ; i < H ; i++ )
            scanf("%d" , &arr[i] ) ;

        sort( arr , arr + H ) ;

        printf("#%d " , T ) ;
        for( int i = 0 ; i <= size ; i++ ) {
    
            hyphen( arr , H , i ) ;

            if( i != size )
                printf("%c" , text[i] ) ;
        }
        printf("\n") ;
    }
    return 0 ;
}















