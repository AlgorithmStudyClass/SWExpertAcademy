/*
5986. 새샘이와 세 소수 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWaJ3q8qV-4DFAUQ&categoryId=AWaJ3q8qV-4DFAUQ&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

// int numArr[7] ;
// vector<int> result ;

// void dfs( int i , int sum , int plusCnt ) {

//     if( i == 7 || plusCnt == 3 ) {

//         if( plusCnt == 3 ) {

//             vector<int>::iterator iter;
//             iter = find(result.begin(), result.end(), sum);
//             if (iter == result.end())
//                 result.push_back( sum ) ;
//         }
//         return ;
//     }

//     dfs( i + 1 , sum + numArr[i] , plusCnt + 1 ) ;
//     dfs( i + 1 , sum , plusCnt ) ;
// }

// int main() {

//     int testSize = 0;
//     scanf("%d" , &testSize ) ;

//     int T = 0 ;
//     while( T++ < testSize ) {

//         for( int i = 0 ; i < 7 ; i++ )
//             scanf("%d" , &numArr[i] ) ;

//         dfs( 0 , 0 , 0 ) ;
//         sort( result.begin() , result.end() , greater<int>() ) ;

//         printf("#%d %d\n" , T , result[4] ) ;
//         result.clear() ;
//     }
//     return 0 ;
// }

int main() {

    int numArr[7] = { 0 , } ;
    bool sum[298] ;

    int testSize = 0;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        memset(&sum,  false , sizeof(sum));

        for( int i = 0 ; i < 7 ; i++ )
            scanf("%d" , &numArr[i] ) ;

        for( int i = 0 ; i < 5 ; i++ ) {
            for( int j = i + 1 ; j < 6 ; j++ ) {
                for( int k = j + 1 ; k < 7 ; k++ )
                    sum[ numArr[i] + numArr[j] + numArr[k] ] = true ;
            }
        }

        /*
        int cc = 0 ;
        for( int i = 0 ; i < 7 ; i++ ) {
            for( int j = 0 ; j < 7 ; j++ ) {
                for( int k = 0 ; k < 7 ; k++ )
                    cout << ++cc << endl ;
            }
        }

        => 7개 숫자 중복해서 조합이라서 7 * 6 * 5 가 답 아님?? 

        */

        int cnt = 0 ;
        for( int i = 297 ; i >= 3 ; i-- ) {

            if( sum[i] == true ) {
                if( ++cnt == 5 ) {
                    printf("#%d %d\n" , T , i ) ; break ;
                }
            }
        }
    }
    return 0 ;
}










