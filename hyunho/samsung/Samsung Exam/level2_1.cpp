
// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<cstdio>
// #include<stdlib.h>
// #include<string.h>
// #include<algorithm>
// using namespace std ;

// vector<int> result ;
// vector<int> missilePower ;

// void dfs( int i , int sum , int plusCnt , int M , int B ) {

//     cout << i << " , " << sum << " , " << plusCnt << endl ;

//     if( sum >= B || plusCnt >= 2 || i == M ) {

//         if( sum >= B ) {
            // vector<int>::iterator iter;
            // iter = find(result.begin(), result.end(), sum);
            // if (iter == result.end()) {

            //     cout << "답 : " << i << " , " << sum << " , " << plusCnt << endl ;
            //     result.push_back( sum ) ;
            // }
//         }

//         return ;
//     }

//     dfs( i + 1 , sum + missilePower[i] , plusCnt + 1 , M , B ) ;
//     dfs( i + 1 , sum , plusCnt , M , B ) ;
// }


// int main() {

//     int testSiz = 0 ;
//     scanf("%d" , &testSiz ) ;

//     int T = 0 ;
//     while( T++ < testSiz ) {

//         int N , M , B = 0 ;
//         scanf("%d %d %d" , &N , &M , &B ) ;

//         for( int i = 0 ; i < M ; i++ ) {

//             int tmpPower , tmpCnt = 0 ;
//             scanf("%d %d" , &tmpPower , &tmpCnt ) ;

//             for( int j = 0 ; j < tmpCnt ; j++ )
//                 missilePower.push_back( tmpPower ) ;
//         }

//         sort( missilePower.begin() , missilePower.end() ) ;
//         dfs( 0 , 0 , 0 , missilePower.size() , B ) ;
//         sort( result.begin() , result.end() ) ;

//         for( int i = 0 ; i < result.size() ; i++ )
//             cout << result[i] << " " ;
//         cout << endl ;

//         int totalResult = 0 ;
//         if( N > result.size() )
//             totalResult = -1 ;
//         else {
//             for( int i = 0 ; i < N ; i++ )
//                 totalResult += result[i] ;
//         }
//         printf("#%d %d\n" , T , totalResult ) ;

//         missilePower.clear() ;
//         result.clear() ;
//     }
//     return 0 ;
// }

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

vector<int> result ;
vector<int> missilePower ;

void dfs( int i , int sum , int plusCnt , int M , int B ) {

    if( sum >= B || plusCnt > 2 || i == M ) {

        if( sum >= B && plusCnt <= 2 ) {
            vector<int>::iterator iter;
            iter = find(result.begin(), result.end(), sum);
            if (iter == result.end()) {
                cout << "답 : " << i << " , " << sum << " , " << plusCnt << endl ;
                result.push_back( sum ) ;
            }
        }

        return ;
    }

    dfs( i + 1 , sum + missilePower[i] , plusCnt + 1 , M , B ) ;
    dfs( i + 1 , sum , plusCnt , M , B ) ;
}


int main() {

    int testSiz = 0 ;
    scanf("%d" , &testSiz ) ;

    int T = 0 ;
    while( T++ < testSiz ) {

        int N , M , B = 0 ;
        scanf("%d %d %d" , &N , &M , &B ) ;

        for( int i = 0 ; i < M ; i++ ) {

            int tmpPower , tmpCnt = 0 ;
            scanf("%d %d" , &tmpPower , &tmpCnt ) ;

            for( int j = 0 ; j < tmpCnt ; j++ )
                missilePower.push_back( tmpPower ) ;
        }

        sort( missilePower.begin() , missilePower.end() ) ;
        dfs( 0 , 0 , 0 , missilePower.size() , B ) ;
        sort( result.begin() , result.end() ) ;

        cout << "result : " ;
        for( int i = 0 ; i < result.size() ; i++ )
            cout << result[i] << " " ;
        cout << endl ;

        int totalResult = 0 ;
        if( N > result.size() )
            totalResult = -1 ;
        else {
            for( int i = 0 ; i < N ; i++ )
                totalResult += result[i] ;
        }
        printf("#%d %d\n" , T , totalResult ) ;

        missilePower.clear() ;
        result.clear() ;
    }
    return 0 ;
}












