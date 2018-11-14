/*
1289. 원재의 메모리 복구하기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV19AcoKI9sCFAZN&categoryId=AV19AcoKI9sCFAZN&categoryType=CODE
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
    while( T < testSize ) {

        char tmpText[100] = "" ;
        scanf( "%s" , tmpText ) ;

        string str = string( tmpText ) ;

        char *text = new char[ str.length() + 1 ] ;
        strcpy( text , str.c_str() ) ;

        char *answer = new char[ str.length() + 1 ] ;

        for( int i = 0 ; i < str.length() ; i++ )
            answer[i] = '0' ;

        int cnt = 0 ;

        for( int i = 0 ; i < str.length() ; i++ ) {

            if( !strcmp( text , answer ) )
                break ;

            for( int j = i ; j < str.length() ; j++ ) {

                if( j == i ) {
                    if( text[i] == answer[j] )
                        break ;
                    else {
                        answer[j] = text[i] ;
                        cnt++ ;
                        continue ;
                    }
                }
                answer[j] = text[i] ;
            }
        }

        printf("#%d %d\n" , ( T + 1 ) , cnt ) ;

        T++ ;
    }

    return 0 ;
}
























