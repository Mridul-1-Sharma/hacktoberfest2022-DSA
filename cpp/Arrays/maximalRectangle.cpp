/* Abhishek Vaishnav */
#include <bits/stdc++.h>
using namespace std;

// Problem link
//https://leetcode.com/problems/maximal-rectangle/
int max_area_histogram(vector<int> &v) {
   int n = v.size();
   stack<pair<int, int>> st;
   vector<int> nsl(n, -1), nsr(n, n);
   for (int i = 0; i < n; i++) {
      while (!st.empty() && st.top().first >= v[i])st.pop();
      if (!st.empty())nsl[i] = st.top().second;
      st.push({v[i], i});
   }
   while (!st.empty())st.pop();
   for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && st.top().first >= v[i])st.pop();
      if (!st.empty())nsr[i] = st.top().second;
      st.push({v[i], i});
   }
   int ans = 0;
   for (int i = 0; i < n; i++) {
      ans = max(ans, (nsr[i] - nsl[i] - 1) * v[i]);
   }
   return ans;
}
int maximalRectangle(vector<vector<char>>& matrix) {
   int n = matrix.size(), m = matrix[0].size();
   vector<vector<int>> v(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         v[i][j] = (matrix[i][j] == '1' ? 1 : 0);
         if (i > 0 && v[i - 1][j] > 0 && v[i][j] == 1)v[i][j] += v[i - 1][j];
      }
   }
   int ans = 0;
   for (int i = 0; i < n; i++) {

      ans = max(ans, max_area_histogram(v[i]));
   }
   return ans;
}
void solve()
{
   // size of matrix nxm
   int n, m;
   cin >> n, m;
   vector<vector<char>> matrix(n, vector<char>(m));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)cin >> matrix[i][j];
   }
   cout << maximalRectangle(matrix) << endl;
}
signed main() {
   int t = 1;
   cin >> t;
   while (t--)solve();

   return 0;
}