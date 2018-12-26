#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<utility>
using namespace std;

int main() {

   int testSize = 0 ;
   scanf("%d" , &testSize ) ;

   int T = 0;
   while( T++ < testSize ) {

      int N = 0 ;
      scanf("%d" , &N ) ;

      vector<vector<int> > coordinates ;

      int X , Y = 0 ;
      for( int i = 0 ; i < N ; i++ ) {
         
         coordinates.push_back( vector<int>() ) ;

         scanf("%d %d" , &X , &Y ) ;
         coordinates[i].push_back( X ) ;
         coordinates[i].push_back( Y ) ;
         coordinates[i].push_back( i + 1 ) ;
      }

      sort( coordinates.begin() , coordinates.end() ) ;

      vector<int> result ;

      int currentX = coordinates[0][0] ;
      int currentY = coordinates[0][1] ;
      result.push_back( coordinates[0][2] ) ;
      for( int i = 1 ; i < coordinates.size() ; i++ ) {

         if( currentX > coordinates[i][0] || currentY > coordinates[i][1] ) {

            currentX = coordinates[i][0] ;
            currentY = coordinates[i][1] ;
            result.push_back( coordinates[i][2] ) ;
         }
      }

      printf("#%d " , T ) ;
      for( int i = 0 ; i < result.size() ; i++ )
         printf("%d " , result[i] ) ;
      printf("\n") ;

      for (int i = 0; i < N; i++)
         coordinates[i].clear();
      coordinates.clear();
      result.clear() ;
   }
   return 0 ;
}





