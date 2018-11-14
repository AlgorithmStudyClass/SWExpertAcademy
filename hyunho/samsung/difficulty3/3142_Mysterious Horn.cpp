/*
3142. 영준이와 신비한 뿔의 숲 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_6xWk6sbADFAWS&categoryId=AV_6xWk6sbADFAWS&categoryType=CODE
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int N = 0 , M = 0 ;
        scanf("%d %d" , &N ,&M ) ;

        int X = 2 * M - N ;
        int Y = N - M ;

        printf("#%d %d %d \n" , T , X , Y ) ;
    }

    return 0 ;
}























