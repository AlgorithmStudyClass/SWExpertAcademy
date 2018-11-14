/*
1240. [S/W 문제해결 응용] 1일차 - 단순 2진 암호코드 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15FZuqAL4CFAYD&categoryId=AV15FZuqAL4CFAYD&categoryType=CODE#
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

        int X = 0 , Y = 0;
        scanf("%d %d" , &X , &Y ) ;

        char **arr = new char*[X] ;
        for( int i = 0 ; i < X ; i++ )
            arr[i] = new char[Y + 1 ] ;

        for( int i = 0 ; i < X ; i++ )
            scanf("%s" , arr[i] ) ;

        int beginX = 0 , beginY = 0 ;
        for( int i = 0 ; i < X ; i++ ) {
            for( int j = 0 ; j < Y ; j++ ) {

                if( arr[i][j] == '1' ) {
                    beginX = i ;
                    beginY = j ;
                    break ;
                }
            }
        }

        vector<int> result ;
        string decode[10] = { "0001101" , "0011001" , "0010011" , "0111101" , "0100011" , "0110001" , "0101111" , "0111011" , "0110111" , "0001011" } ;
        string tmp = "" ;
        int cnt = 0 ;
        for( int j = beginY - 1 ; j < beginY - 1 + 56 ; j++ ) {

            tmp += arr[beginX][j] ;

            if( ++cnt % 7 == 0 ) {

                cout << tmp << endl ;
                for( int i = 0 ; i < 10 ; i++ ) {
                    if( tmp.compare( decode[i] ) == 0  ) {
                        cout << i << endl ;
                        result.push_back( i ) ;
                    }
                }
                cnt = 0 ;
                tmp = "" ;
            }
        }

        int odd = 0 , even = 0 ;
        int sum = 0 ;
        for( int i = 0 ; i < result.size() ; i++ ) {

            sum += result[i] ;

            if( i == ( result.size() - 1 ) ) {
                even += result[i] ; break ;
            }

            if( i % 2 == 0 )
                odd += result[i] ;
            else
                even += result[i] ;
        }

        int flag = 0 ;
        if( ( odd * 3 + even ) % 10 == 0 )
            printf("#%d %d\n" , T , sum ) ;
        else
            printf("#%d 0\n" , T ) ;
    }
    return 0 ;
}





















