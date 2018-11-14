/*
3431. 준환이의 운동관리
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWE_ZXcqAAMDFAV2&categoryId=AWE_ZXcqAAMDFAV2&categoryType=CODE
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

        int L = 0 , U = 0 , X = 0 ;

        scanf("%d" , &L ) ;
        scanf("%d" , &U ) ;
        scanf("%d" , &X ) ;

        int result = 0 ;
        if( X >= L && X <= U )
            result = 0 ;
        else if( X < L )
            result = L - X ;
        else
            result = -1 ;

        printf("#%d %d\n" , T , result ) ;
    }

    return 0 ;
}
























