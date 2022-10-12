//largest rectangle in histogram using stack
//https://www.leetcode.com/debayankumar
//my leetcode account

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans=0;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
               
                int top=heights[st.top()];
                st.pop();
                int ran=st.empty()?-1:st.top();
                ans=max(ans,top*(i-ran-1));
                
            }
            st.push(i);
      
        }
        return ans;
       
    }
};