/*
4522. 세상의 모든 팰린드롬 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWO6Oao6N4QDFAWw&categoryId=AWO6Oao6N4QDFAWw&categoryType=CODE
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

    string str = "" ;
    int flag = 0 ;

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        cin >> str ;

        for( int i = 0 ; i < str.length() / 2 ; i++ ) {

            if( str[i] != '?' && str[ str.length() - i - 1 ] != '?' && str[i] != str[ str.length() - i - 1 ] ) {
                flag = 1 ; break ;
            }
        }

        if( flag == 0 )
            printf( "#%d Exist\n" , T ) ;
        else
            printf( "#%d Not exist\n" , T ) ;

        str = "" ;
        flag = 0 ;
    }
    return 0 ;
}








