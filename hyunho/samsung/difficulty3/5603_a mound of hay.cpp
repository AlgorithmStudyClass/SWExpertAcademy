/*
5603. [Professional] 건초더미 D3
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXGEbd6cjMDFAUo&categoryId=AWXGEbd6cjMDFAUo&categoryType=CODE#
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std ;

int main() {

   int t, ans, line = 1, len, n, m, k, temp, sum, max, cnt, index;
   bool flag;
   vector<int> vec, temp_vec;
   string str, temp_str;
   vector<string> str_vec, ans_vec;

   cin >> t;

   while (t > 0) {
      //입력
      cin >> n;
      ans = 0;
      sum = 0;
      for (int i = 0; i < n; i++) {
         scanf("%d", &temp);
         vec.push_back(temp);
         sum += temp;
      }

      sort(vec.begin(), vec.end());
      
      int left = 0;
      int right = n - 1;
      int avg = sum / n;

      while (vec[left] != vec[right]) {
         temp = avg - vec[left];
         ans += temp;
         vec[left++] = avg;
         while (vec[right] - temp < avg) {
            temp -= vec[right] - avg;
            vec[right--] = avg;
         }
         vec[right] -= temp;
      }

      cout << "#" << line++ << " " << ans << endl;
      vec.clear();
      t--;
    }
   return 0;
}








