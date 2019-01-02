/*
3233. 정삼각형 분할 놀이 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWAe5G8afT0DFAUw&categoryId=AWAe5G8afT0DFAUw&categoryType=CODE
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int A , B = 0 ;
        scanf("%d %d" , &A , &B ) ;

        int bottomCnt = A / B ;
        long resultCnt = 0 ;

        for( int i = 1 ; i < bottomCnt ; i++ )
            resultCnt += ( i * 2 ) ;
        resultCnt += bottomCnt ;

        printf("#%d %ld\n" , T , resultCnt ) ;
    }
    return 0 ;
}













