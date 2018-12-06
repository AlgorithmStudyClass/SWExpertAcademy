/*
4466. 최대 성적표 만들기 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWOUfCJ6qVMDFAWg&categoryId=AWOUfCJ6qVMDFAWg&categoryType=CODE
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

        int N = 0 , K = 0 ;
        scanf("%d %d" , &N , &K ) ;

        int *examArr = new int[ N ] ;
        for( int i = 0 ; i < N ; i++ )
            scanf("%d" , &examArr[i] ) ;

        sort(examArr, examArr + N , greater<int>());
        
        int sum = 0 ;
        for( int i = 0 ; i < K ; i++ )
            sum += examArr[i] ;

        printf("#%d %d\n" , T , sum ) ;
    }
    return 0 ;
}

















