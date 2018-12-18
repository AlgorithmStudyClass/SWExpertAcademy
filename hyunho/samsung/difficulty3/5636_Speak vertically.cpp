/*
5356. 의석이의 세로로 말해요  D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWVWgkP6sQ0DFAUO&categoryId=AWVWgkP6sQ0DFAUO&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    string result ;

    int T = 0 ;
    while( T++ < testSize ) {

        string *strArr = new string[5] ;
        int *strSize = new int[5] ;

        for( int i = 0 ; i < 5 ; i++ ) {
            cin >> strArr[i] ;
            strSize[i] = strArr[i].length() ;
        }

        sort( strSize , strSize + 5 , greater<int>() ) ;

        for( int i = 0 ; i < strSize[0] ; i++ ) {
            for( int j = 0 ; j < 5 ; j++ ) {   
                if( i < strArr[j].length() )        //  strArr[j][i] ??? 왜 안되지
                    result.push_back( strArr[j][i] ) ;
            }
        }

        printf("#%d %s\n" , T , result.c_str() ) ;

        delete []strArr ;
        result.clear() ;
    }
    return 0 ;
}




