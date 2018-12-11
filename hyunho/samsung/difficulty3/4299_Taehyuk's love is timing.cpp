/*
4299. 태혁이의 사랑은 타이밍 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWLv6mx6htoDFAVV&categoryId=AWLv6mx6htoDFAVV&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int date = 11 ;
int hour = 11 ;
int minuate = 11 ;

int timing( int D , int H , int M ) {

    int result = 0 ;
    if( date < D ) {    //  날짜 하루이상 지남
        if( hour < H ) {
            if( minuate <= M )
                result = ( D - date ) * 1440 + ( ( ( H - hour ) * 60 ) + ( M - minuate ) ) ;
            else
                result = ( D - date ) * 1440 + ( ( ( H - hour ) * 60 ) - ( minuate - M ) ) ;
        } else if( hour == H ) {
            if( minuate <= M )
                result = ( D - date ) * 1440 + ( M - minuate ) ;
            else
                result = ( D - date ) * 1440 - ( minuate - M ) ;
        } else {
            if( minuate <= M )
                result = ( D - date ) * 1440 - ( ( ( hour - H ) * 60 ) - ( M - minuate ) ) ;
            else
                result = ( D - date ) * 1440 - ( ( ( hour - H ) * 60 ) + ( minuate - M ) ) ;
        }
    } else if( date == D ) {    // 날짜 같음
        if( hour < H ) {    //  시간 지남
            if( minuate <= M )
                result = ( H - hour ) * 60 + ( M - minuate ) ;
            else
                result = ( H - hour ) * 60 - ( minuate - M ) ;
        } else if( hour == H ) {    //  시간 같음
            if( minuate < M ) //  분 지남
                result = M - minuate ;
            else if( minuate == M ) //  분 같음
                result = 0 ; 
            else    //  분 전에 차임
                result = -1 ;
        } else    //  시간 전에 차임
            result = -1 ;
    } else    //  날짜 전에 차임
        result = -1 ;
        
    return result ;
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int D = 0 , H = 0 , M = 0 ;
        scanf( "%d %d %d" , &D , &H , &M ) ;

        int result = timing( D , H , M ) ;

        printf("#%d %d\n" , T , result ) ;
    }
    return 0 ;
}
















