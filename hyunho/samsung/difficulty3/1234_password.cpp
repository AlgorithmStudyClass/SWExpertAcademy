/*
1234. [S/W 문제해결 기본] 10일차 - 비밀번호 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14_DEKAJcCFAYD&categoryId=AV14_DEKAJcCFAYD&categoryType=CODE
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

        int textSize = 0 ;
        scanf("%d" , &textSize ) ;

        char *charNum = new char[ textSize ] ;
        scanf("%s" , charNum ) ;

        vector<int> pw ;
        for( int i = 0 ; i < textSize ; i++ )
            pw.push_back( charNum[i] - '0' ) ;


        int flag = 1 ;
        while( flag ) {

            flag = 0 ;
            for( int i = 1 ; i < pw.size() ; i++ ) {

                if( pw[i-1] == pw[i] ) {
                    pw.erase( pw.begin() + ( i - 1 ) , pw.begin() + ( i + 1 ) ) ;
                    flag = 1 ;
                    break ;
                }
            }
        }

        printf("#%d " , T ) ;
        for( int i = 0 ; i < pw.size() ; i++ )
            printf("%d" , pw[i] ) ;
        printf("\n" ) ;

        pw.clear() ;

    }
    return 0 ;
}


