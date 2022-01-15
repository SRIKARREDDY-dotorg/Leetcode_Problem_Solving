/**
 * @file Maximal_Rectangle.cpp
 * @brief Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 * @version 0.1
 * @date 2022-01-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

class Solution {
public:
    int getMaxArea(vector<int>arr, int n){
        stack<int>st;
        int tp,i=0;
        int areawithtop;
        int max_area=0;
        while(i<n){
            if(st.empty() || arr[st.top()]<=arr[i]){
                st.push(i++);
            }else{
                tp = st.top();
                st.pop();
                areawithtop = arr[tp]*(st.empty()? i: i-st.top()-1);
                if(areawithtop>max_area){
                    max_area = areawithtop;
                }
            }
        }
        while(st.empty()==false){
            tp = st.top();
                st.pop();
                areawithtop = arr[tp]*(st.empty()? i: i-st.top()-1);
                if(areawithtop>max_area){
                    max_area = areawithtop;
                }
        }
        
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int>dp(c);
        int ans=0;
        for(int j=0;j<c;j++){
            dp[j]=matrix[0][j]-'0';
        }
        ans=getMaxArea(dp,c);
        //cout<<ans<<endl;
        for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
                dp[j] = matrix[i][j]=='0' ? 0:dp[j]+1;
            }
            ans=max(ans,getMaxArea(dp,c));
            //cout<<ans<<endl;
        }
        return ans;
    }
};