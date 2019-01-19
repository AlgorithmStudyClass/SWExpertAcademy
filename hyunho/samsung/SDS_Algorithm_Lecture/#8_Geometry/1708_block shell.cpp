/*
 1708. 블록 껍질
 https://www.acmicpc.net/problem/1708
 
 블록껍질
 Graham scan
 */
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std ;

struct Col {
    
    int x , y ;
    
    bool operator >( const Col &ref ) const {
        
        return ( this->x >= ref.x && this->y >= ref.y )? true : false ;
    }
    
    void print() const {
        cout << this->x << " , " << this->y << endl ;
    }
} ;

int N ;
Col list[100001] ;
int idx ;
int ansArr[100001] ;
int ans ;

long long int ccw( Col a , Col b , Col c ) {
    
    long long int ret = (long long int ) a.x * b.y +(long long int ) b.x * c.y +(long long int ) c.x * a.y  - ( (long long int )b.x * a.y +(long long int ) c.x * b.y + (long long int )a.x * c.y )  ;
    
    return ( ret == 0 )? 0 : ( ret > 0 )? 1 : -1 ;
}

int comp( const Col &a , const Col &b ) {
    
    int ret = ccw( list[1] , a , b ) ;
    
    if( ret != 0 )
        return (ret > 0)? 1 : -1 ;
    else {
        //    거리 가까운거 넣겠다
        long long int d1 = (long long int)( a.x - list[1].x ) * ( a.x - list[1].x ) + (long long int)( a.y - list[1].y ) * ( a.y - list[1].y ) ;
        long long int d2 = (long long int)( b.x - list[1].x ) * ( b.x - list[1].x ) + (long long int)( b.y - list[1].y ) * ( b.y - list[1].y )  ;
        return ( d1 < d2 )? 1 : -1 ;
    }
}

int main() {
    
    scanf("%d" , &N ) ;
    
    Col minXY ;
    minXY.x = 40001 ;
    minXY.y = 40001 ;
    
    for( int i = 1 ; i <= N ; i++ ) {
        scanf("%d %d" , &list[i].x , &list[i].y ) ;
        
        if( minXY > list[i] ) {
            minXY = list[i] ;
            idx = i ;
        }
    }
    
    swap( list[1] , list[idx] ) ;
    sort( list + 2 , list + N + 1 , comp ) ;
    
    cout << endl ;
    for( int i = 1 ; i <= N ; i++ )	
        list[i].print() ;
    cout << endl ;
    
    stack<int> stack ;
    stack.push( 1 ) ;
    stack.push( 2 ) ;
    for( int i = 3 ; i <= N ; i++ ) {
        
        int second = 0 ;
        int first = 0 ;
        if( stack.size() == 1 ) {
            stack.push( i ) ;
            continue ;
        }
        else {
            second = stack.top() ; stack.pop() ;
            first = stack.top() ; stack.pop() ;
            stack.push( first ) ;
            stack.push( second ) ;
        }
        
        if( ccw( list[first] , list[second] , list[i] ) > 0 )
            stack.push( i ) ;
        else {
            stack.pop() ;
            --i ;
        }
    }
    
    printf("%lu\n", stack.size() );
    return 0 ;
}















