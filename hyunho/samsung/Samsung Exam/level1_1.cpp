
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std ;

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        int N = 0 ;
        scanf("%d" , &N ) ;

        string inputStr = "";
        for( int i = 0 ; i < N ; i++ ) {
            string tmp = "" ;
            cin >> tmp ;
            inputStr += tmp ;
        }

        int flag = 0 ;
        string result = "" ;
        result.insert( 0 , inputStr , 0 , 1 ) ;

        for( int i = 1 ; i < N ; i++ ) {

            if( result[0] <= inputStr[i] )
                result.insert( 0 , inputStr , i , 1 ) ;
            else
                result.insert( i , inputStr , i , 1 ) ;
        }

        printf("#%d %s\n" , T , result.c_str() ) ;
    }
    return 0 ;
}





// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<cstdio>
// #include<stdlib.h>
// #include<string>
// #include<algorithm>
// using namespace std ;

// string result ;

// void dfs( string str , int index , string inputStr , int N ) {

//     if( index == 0 )
//         str += inputStr[0] ;

//     if( index == N - 1 ) {

//         if( result < str )
//             result = str ;
//         return ;
//     }

//     if( str[0] <= inputStr[ index + 1 ])
//         dfs( inputStr[index + 1] + str , index + 1 , inputStr , N ) ;
//     if( str[0] > inputStr[ index + 1 ])
//         dfs( str + inputStr[index + 1] , index + 1 , inputStr , N ) ;
// }

// int main() {

//     int testSize = 0 ;
//     scanf("%d" , &testSize ) ;

//     int T = 0 ;
//     while( T++ < testSize ) {

//         int N = 0 ;
//         scanf("%d" , &N ) ;

//         string inputStr = "";
//         for( int i = 0 ; i < N ; i++ ) {
//             string tmp = "" ;
//             cin >> tmp ;
//             inputStr += tmp ;
//         }

//         dfs( "" , 0 , inputStr , N ) ;
//         printf("#%d %s\n" , T , result.c_str() ) ;
//         result = "" ;
//     }
//     return 0 ;
// }




