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

void func( string num ) {

    int length = num.length() ;
    
    if( length == 1 )
        result = atoi(num.c_str() ) ;
    else {

        string tmpNum ;
        long long int tmp = 0 ;
        for( int i = 0 ; i < length ; i++ )
            tmp += num[i] - '0' ;

        tmpNum = to_string(tmp) ;
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
        string num = string( str ) ;

        func( num ) ;

        printf("#%d %d\n" , T , result ) ;
    }
    return 0 ;
}












