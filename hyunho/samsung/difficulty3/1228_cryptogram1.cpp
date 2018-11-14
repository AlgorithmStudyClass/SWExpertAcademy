/*
1228. [S/W 문제해결 기본] 8일차 - 암호문1 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14w-rKAHACFAYD&categoryId=AV14w-rKAHACFAYD&categoryType=CODE
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
    while( T < testSize ) {

        vector<int> numVec ;

        int size = 0 ;
        scanf("%d" , &size ) ;

        for( int i = 0 ; i < size ; i++ ) {
            int num = 0 ;
            scanf("%d" , &num ) ;
            numVec.push_back( num ) ;
        }

        int orderSize = 0 ;
        scanf("%d" , &orderSize ) ;

        int cnt = 0 ;
        while( cnt < orderSize ) {

            char ch ;
            scanf("%c" , &ch ) ;

            if( ch == 'I' ) {
                int x ;
                int y ;
                vector<int> s ;

                scanf("%d" , &x ) ;
                scanf("%d" , &y ) ;

                for( int i = 0 ; i < y ; i++ ) {
                    int inum = 0 ;
                    scanf("%d" , &inum ) ;
                    
                    numVec.insert( numVec.begin() + x++ , inum ) ;
                }
                cnt++ ;
            } else if( ch == 'D' ) {

                int x ;
                int y ;
                scanf( "%d" , &x ) ;
                scanf( "%d" , &y ) ;

                for( int i = 0 ; i < y ; i++ ) {
                    numVec.erase( numVec.begin() + x ) ;
                }
                cnt++ ;
            } else if( ch == 'A' ) {

                int y ;
                scanf("%d" , &y ) ;

                for( int i = 0 ; i < y ; i++ ) {
                    int anum = 0 ;
                    scanf("%d" , &anum ) ;
                    numVec.push_back( anum ) ;
                }
                cnt++ ;
            } else
                continue ;
        }

        printf("#%d " , ( T + 1 ) ) ;
        for( int i = 0 ; i < 10 ; i++ )
            printf("%d " , numVec[i] ) ;
        printf("\n") ;

        T++ ;
    }

    return 0 ;
}
























