/* Abhishek Vaishnav */
#include <bits/stdc++.h>
using namespace std;

// Problem Link
//https://leetcode.com/problems/largest-rectangle-in-histogram/

int largestRectangleArea(vector<int>& heights) {
   int n = heights.size();
   //nsl=next smaller in left
   //nsr=next smaller in right
   vector<int> nsl(n, 0), nsr(n, 0); //stores index
   stack<int> st;
   for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.top()] >= heights[i])st.pop();
      if (st.empty())nsl[i] = -1;
      else nsl[i] = st.top();
      st.push(i);
   }
   while (!st.empty())st.pop();
   for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && heights[st.top()] >= heights[i])st.pop();
      if (st.empty())nsr[i] = n;
      else nsr[i] = st.top();
      st.push(i);
   }
   int ans = 0;
   for (int i = 0; i < n; i++) {
      ans = max(ans, (nsr[i] - nsl[i] - 1) * heights[i]);
   }
   return ans;

}
void solve()
{
   // size of vector
   int n;
   cin >> n;
   vector<int> heights(n);
   for (int i = 0; i < n; i++)cin >> heights[i];
   cout << largestRectangleArea(heights) << endl;
}
signed main() {
   int t = 1;
   cin >> t;
   while (t--)solve();

   return 0;
}