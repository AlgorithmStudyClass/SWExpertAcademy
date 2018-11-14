/*
1206. [S/W 문제해결 기본] 1일차 - View
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh&categoryId=AV134DPqAA8CFAYh&categoryType=CODE
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

        int size = 0 ;
        scanf("%d" , &size ) ;

        int *arr = new int[ size ] ;

        for( int i = 0 ; i < size ; i++ )
            scanf("%d" , &arr[i] ) ;

        int cnt = 0 ;
        for( int i = 2 ; i < size - 2 ; i++ ) {

            vector<int> result ;

            result.push_back( arr[ i - 2 ] ) ;
            result.push_back( arr[ i - 1 ] ) ;
            result.push_back( arr[ i + 1 ] ) ;
            result.push_back( arr[ i + 2 ] ) ;

            int maxTest = *max_element( result.begin() , result.end() ) ;

            int tmp = 0 ;
            if( arr[i] > maxTest )
                tmp = arr[i] - maxTest ;
            
            if( tmp > 0 )
                cnt += tmp ;

        }

        printf("#%d %d\n" , T , cnt ) ;
    }
    return 0 ;
}




















