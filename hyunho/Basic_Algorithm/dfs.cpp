/*
2817. 부분 수열의 합 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7IzvG6EksDFAXB&categoryId=AV7IzvG6EksDFAXB&categoryType=CODE
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int cnt ;

void dfs( int i , int sum , int *arr , int N , int K ) {

    if( sum > K || i == N ) {

        if( sum == K )
            cnt++ ;

        return ;
    }

    dfs( i + 1 , sum + arr[i] , arr , N , K ) ;
    dfs( i + 1 , sum , arr , N , K ) ;
}

int main() {

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

    int T = 0 ;
    while( T++ < testSize ) {

        cnt = 0 ;
        int N = 0 , K = 0 ;
        scanf("%d %d" , &N , &K ) ;

        int *arr = new int[ N ] ;
        for( int i = 0 ; i < N ; i++ )
            scanf("%d" , &arr[i] ) ;

        dfs( 0 , 0 , arr , N , K ) ;

        printf("#%d %d\n" , T , cnt ) ;

    }
    return 0 ;
}



//  not DFS

// #include <stdio.h>
// #include <vector>
// using namespace std;

// int t, n, k, res;

// int main() {

//    scanf("%d", &t);
//    for (int tc = 1; tc <= t; tc++) {
//       int a[20];
//       vector<int> all;//k를 초과하지 않는 경우들을 누적시킬 벡터
//       int cnt = 0;

//       scanf("%d %d", &n, &k);
//       for (int i = 0; i < n; i++) {
//          scanf("%d", &a[i]);
//          if (a[i] == k) {
//             cnt++;
//          }
//       }

//       for (int i = 0; i < n; i++) {
//          all.push_back(a[i]);
//          int size = all.size();
//          //누적된 벡터내의 원소들과 더해 k가 되는지 확인
//          //k==sum 이면 cnt++;
//          //k<sum 이면 더해봤자 어차피 k보다 크므로 continue;
//          //k>sum 이면 vector에 sum원소 추가
//          for (int j = 0; j < size - 1; j++) {
//             int sum = a[i] + all.at(j);
//             if (sum == k) {
//                cnt++;
//             }
//             else if (sum > k) {
//                continue;
//             }
//             else {
//                all.push_back(sum);
//             }
//          }
//       }
//       printf("#%d %d\n", tc, cnt);
//    }
// }

