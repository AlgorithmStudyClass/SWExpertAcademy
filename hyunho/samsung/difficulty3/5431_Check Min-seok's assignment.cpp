/*
5431. 민석이의 과제 체크하기 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWVl3rWKDBYDFAXm&categoryId=AWVl3rWKDBYDFAXm&categoryType=CODE
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
    scanf("%d " , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int N = 0 , K = 0 ;
        scanf("%d %d" , &N , &K ) ;

        vector<int> result ;

        for( int i = 0 ; i < K ; i++ ) {
            int tmpNum = 0 ;
            scanf("%d" , &tmpNum ) ;
            result.push_back( tmpNum ) ;
        }

        printf("#%d " , T ) ;
        for( int i = 1 ; i <= N ; i++ ) {

            vector<int>::iterator iter;                                             //  find 
            iter = find(result.begin(), result.end(), i );
            if (iter == result.end()) //  없음
                printf("%d " , i ) ;
        }
        printf("\n" ) ;
    }
    return 0 ;
}






















