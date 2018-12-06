/*
3456. 직사각형 길이 찾기 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWFPmsqqALwDFAV0&categoryId=AWFPmsqqALwDFAV0&categoryType=CODE
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

        int arr[3] = { 0 } ;

        for( int i = 0 ; i < 3 ; i++ )
            scanf("%d" , &arr[i] ) ;

        int num = arr[0] ;
        int flag = 0 ;
        int index = 0 ;
        for( int i = 1 ; i < 3 ; i++ ) {

            if( num == arr[i] ) {
                flag++ ;
                index = i ;
            }
        }

        if( flag == 0 || flag != 1 )
            printf("#%d %d\n" , T , arr[0] ) ;
        else {
            for( int i = 0 ; i < 3 ; i++ ) {

                if( i != 0 && i != index )
                    printf("#%d %d\n" , T , arr[i] ) ;
            }
        }
    }
    return 0 ;
}












