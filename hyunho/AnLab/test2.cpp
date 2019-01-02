#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std ;



int solution(vector<int> s){

    s = { 1 , 2 , 3 } ;
    
    int answer = 0 ;
    for( int i = 0 ; i < s.size() - 1 ; i++ ) {

        if( i % 2 == 0 )
            s[i] < s[ i + 1 ] ? answer : answer++ ;
        else
            s[i] > s[ i + 1 ] ? answer : answer++ ;
    }

    return answer ;
}

int main() {

    int num = solution( { 1 , 2 , 3 } ) ;
    cout << num << endl ;
    printf("#%d %d\n" , 1 ,3 ) ;
    return 0 ;
}













