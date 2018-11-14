/*
4406. 모음이 보이지 않는 사람
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWNcD_66pUEDFAV8&categoryId=AWNcD_66pUEDFAV8&categoryType=CODE
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

        char text[51] = "" ;
        char result[51] = "" ;
        scanf("%s" , &text ) ;

        for( int x = 0 , i = 0 ; i < strlen( text ) ; i++ ) {

            if( text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' )
                continue ;
            else
                result[x++] = text[i] ;
        }

        printf("#%d %s\n" , T , result ) ;
    }
    return 0 ;
}























