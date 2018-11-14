/*
1213. [S/W 문제해결 기본] 3일차 - String D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14P0c6AAUCFAYi&categoryId=AV14P0c6AAUCFAYi&categoryType=CODE
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 10 ;

    int T = 0 ;
    while( T++ < testSize ) {

        scanf("%d" , &T ) ;

        string tmpFindText = "" ;
        cin >> tmpFindText ;
        string tmpText = "" ;
        cin >> tmpText ;

        char *findText = new char[ tmpFindText.length() + 1 ] ;
        strcpy( findText , tmpFindText.c_str() ) ;
        char *text = new char[ tmpText.length() + 1 ] ;
        strcpy( text , tmpText.c_str() ) ;

        int cnt = 0 ;
        for( int x = 0 , i = 0 ; i < strlen( text ) ; i++ ) {

            if( text[i] == findText[x] ) {

                if( x == strlen( findText ) - 1 ) {
                    cnt++ ;
                    x = 0 ;
                } else
                    x++ ;
            } else if( x != 0 ) {
                if( text[i] == findText[x-1] )
                    continue ;
                else
                    x = 0 ;
            } else
                x = 0 ;
        }
        printf("#%d %d\n" , T , cnt ) ;
    }
    return 0 ;
}
























