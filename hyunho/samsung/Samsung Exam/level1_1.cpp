#include<iostream>
#include <vector>
#include <queue>
#include<string>
#include<algorithm>

using namespace std;

vector<string> ans;
string str;
int len;

void dfs(int i, string temp) {
   if (i == len) {
      ans.push_back(temp);
      return;
   }
   if (temp[0] > str[i])
      dfs(i + 1, temp + str[i]);
   if (temp[0] <= str[i])
      dfs(i + 1, str[i] + temp);
}

int main(void) {
   int n,t,line=1;
   char temp;

   scanf("%d", &t);
   while (t > 0) {
      scanf("%d", &n);
      
      for (int i = 0; i < n; i++) {
         scanf(" %c", &temp);
         str+=temp;
      }

      len = str.length();
      dfs(0, "");
      sort(ans.rbegin(), ans.rend());

      printf("#%d %s\n", line++,ans[0].c_str());
      str.clear();
      ans.clear();
      t--;
   }
   

   return 0;
}