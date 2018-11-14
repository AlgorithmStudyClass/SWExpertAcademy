/*
1928. Base64 Decoder
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PR4DKAG0DFAUq&categoryId=AV5PR4DKAG0DFAUq&categoryType=CODE

< input >
10
5
TGlmZSBpdHNlbGYgaXMgYSBxdW90YXRpb24u
U3VzcGljaW9uIGZvbGxvd3MgY2xvc2Ugb24gbWlzdHJ1c3Qu
VG8gZG91YnQgaXMgc2FmZXIgdGhhbiB0byBiZSBzZWN1cmUu
T25seSB0aGUganVzdCBtYW4gZW5qb3lzIHBlYWNlIG9mIG1pbmQu
1
QSBmdWxsIGJlbGx5IGlzIHRoZSBtb3RoZXIgb2YgYWxsIGV2aWwu
…

< output >
#1 Life itself is a quotation.
#2 Suspicion follows close on mistrust.
#3 To doubt is safer than to be secure.
#4 Only the just man enjoys peace of mind.
#5 A full belly is the mother of all evil.
...
 
*/

#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<sstream>
using namespace std ;

static std::string base64_encode(const std::string &in) {

    std::string out;

    int val=0, valb=-6;
    for (char c : in) {
        val = (val<<8) + c;
        valb += 8;
        while (valb>=0) {
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
            valb-=6;
        }
    }
    if (valb>-6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
    while (out.size()%4) out.push_back('=');
    return out;
}

static std::string base64_decode(const std::string &in) {

   std::string out;

   std::vector<int> T(256, -1);
   for (int i = 0; i<64; i++) {  // 문자열의 아스키코드 알아내서 거기 index 에 i 넣기
      T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
   }

   int val = 0, valb = -8;
   for (char c : in) {
      if (T[c] == -1)   // 코드에 없는것 제낌
         break;
      val = (val << 6) + T[c];
      valb += 6;
      if (valb >= 0) {

         cout << val << endl << valb << endl ;
         
         out.push_back(char( (val >> valb) ) );
         valb -= 8;
      }
   }
   return out;
}

int main() {

   int size = 0 ;
   scanf("%d", &size);

   int i = 0 ;
   while ( i < size ) {

      char inputText[100000] = "" ;
      scanf("%s" , inputText ) ;

      string inputString = string( inputText ) ;
      string ans = base64_decode(inputString);
      printf("#%d %s\n", ( i + 1 ) , ans.c_str());
      
      i++ ;
   }
}


