/*
3131. 100만 이하의 모든 소수    D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_6mRsasV8DFAWS&categoryId=AV_6mRsasV8DFAWS&categoryType=CODE

에라토스테네스의 체
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

void setPrime( bool *primeArr , int size ) {

    for ( int i = 2 ; i * i <= size ; i++ ) {

        if ( primeArr[i] ) {

            for ( int j = i ; j <= size / i ; j++ )
                primeArr[ j * i ] = false;
        }
    }
}

int main() {

    int size = 1000000;

    bool *primeArr = new bool[ size + 1 ];

    //처음에 모든 숫자가 소수라고 가정
    for ( int i = 2 ; i <= size ; i++ ) 
        primeArr[i] = true;

    setPrime( primeArr , size ) ;

    for ( int i = 2 ; i <= size ; i++ ) {
        if ( primeArr[i] )
            printf( "%d ", i );
    }
    printf("\n") ;

    return 0;
}





