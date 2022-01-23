/**
 * @file Sequential_Digits.cpp
 * @brief An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
 */

#include <cmath>
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>result;
        
        int nlow = (int)(log10(low)+1);
        int nhigh = (int)(log10(high)+1);
        
        int h, k, num;
        //int startLow = (int)(low/(int)pow(10,nlow-1));
        //int starthigh = (int)(high/(int)pow(10,nhigh-1));
        
        for(int i = nlow; i <= nhigh; i++) {
            int n = 9-i+1;
            for(int j = 1; j <= n; j++) {
                h = j;
                k = i;
                num = 0;
                while(k) {
                    num = num*10+h;
                    h++;
                    k--;
                }
                //cout<<num<<" ";
                if((low <= num) && (num <= high)) {
                    result.push_back(num);
                }
                if(num > high) return result;
            }
            //cout<<endl;
        }
        
        return result;
    }
};