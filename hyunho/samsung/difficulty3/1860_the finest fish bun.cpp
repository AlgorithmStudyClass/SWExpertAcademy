/*
1860. 진기의 최고급 붕어빵
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LsaaqDzYDFAXc&categoryId=AV5LsaaqDzYDFAXc&categoryType=CODE
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int N , M , K = 0 ;
    int currentCnt = 0 ;
    vector<int> guest ;
    int flag = 0 ;

    int T = 0 ;
    while( T++ < testSize ) {

        scanf("%d %d %d" , &N , &M , &K ) ;

        for( int i = 0 ; i < N ; i++ ) {
            int tmp = 0 ;
            scanf("%d" , &tmp ) ;
            guest.push_back( tmp ) ;
        }

        sort( guest.begin() , guest.end() ) ;

        for( int i = 0 ; i < N ; i++ ) {

            currentCnt = ( guest[i] / M ) * K - i ;

            if( currentCnt <= 0 ) {
                flag = 1 ; break ;
            }
        }

        if( flag == 0 )
            printf("#%d Possible\n" , T ) ;
        else
            printf("#%d Impossible\n" , T ) ;

        currentCnt = 0 ;
        guest.clear() ;
        flag = 0 ;
    }
    return 0 ;
}









