/**
 * @file Subarrays with K Different Integers.cpp
 * @author your name (you@domain.com)
 * @brief Given an integer array nums and an integer k, return the number of good subarrays of nums.
 * A good array is an array where the number of different integers in that array is exactly k.
 * For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
 * A subarray is a contiguous part of an array.
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>Map;
        int good_subarray=0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                Map[nums[j]]++;
                if(Map.size()==k) good_subarray++;            
            }
            //if(Map.size()==k) good_subarray++;
            Map.clear();
        }
        return good_subarray;
    }
};