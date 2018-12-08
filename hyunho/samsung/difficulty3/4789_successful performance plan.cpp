/*
4789. 성공적인 공연 기획 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWS2dSgKA8MDFAVT&categoryId=AWS2dSgKA8MDFAVT&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int countFunc( string str ) {

    int cnt = 0 ;       //  필요한 고용 사람 수
    int currentCnt = 0 ;        //  현재 치고 있는 사람 수

    for( int i = 0 ; i < str.length() ; i++ ) {

        if( str[i] != '0' ) {   //  str[i] 가 '0' 일 경우에는 더할 필요없으니 무시한다

            if( currentCnt < i ) {      //  만약 조건이 만족하지 못하여 박수를 칠 수 없는 상황이 발생할 경우
                cnt += ( i - currentCnt ) ;     //  고용 사람 수 +
                currentCnt += ( i - currentCnt ) ;      //  현재 치고 있는 사람 +
            }
            currentCnt += str[i] - '0' ;        //  입력받은 조건 만족시 박수치는 사람 수 +
        }
    }
    return cnt ;    //  고용한 사람 수
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        string str = "" ;
        cin >> str ;

        int result = countFunc( str ) ;

        printf("#%d %d\n" , T , result ) ;
    }
    return 0 ;
}








