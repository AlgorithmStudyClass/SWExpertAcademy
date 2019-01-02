/*
3750. Digit sum D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPiSYKAD0DFAUn&categoryId=AWHPiSYKAD0DFAUn&categoryType=CODE
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

int result ;

void func( int firstNum ) {

    int length = (int)log10(firstNum) + 1 ;
    
    if( length == 1 )
        result = firstNum ;
    else {

        int tmpNum = 0 ;
        for( int i = 0 , index = pow( 10 , length - 1 ) ; i < length ; i++ ) {

            tmpNum += firstNum / index ;
            firstNum %= index ;
            index /= 10 ;
        }
        func( tmpNum ) ;
    }
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        char str[20] ;
        scanf("%s" , str ) ;

        int firstNum = 0 , index = 0 ;

        while( str[index] )
            firstNum += str[index++] - '0' ;

        func( firstNum ) ;

        printf("#%d %d\n" , T , result ) ;
    }
    return 0 ;
}














