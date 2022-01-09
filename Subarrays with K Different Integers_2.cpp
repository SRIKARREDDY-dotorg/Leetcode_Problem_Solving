/**
 * @file Subarrays with K Different Integers.cpp
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
     int subarraysWithAtMostKDistinct(vector<int> nums, int k)
{
	unordered_map<int, int> freq;
	int size = nums.size();
	int start = 0, end = 0;
	int total = 0;

	while(end < size)
	{
		if(freq[nums[end]] == 0) // distinct
		{
			k--;
		}

		if(k >= 0)
		{
			freq[nums[end++]]++;
		}

		else
		{
			freq[nums[end++]]++;
			while(k < 0)
			{
				if(freq[nums[start]] == 1)
				{
					k++;
				}
				freq[nums[start]]--;
                //if(!freq[nums[start]])freq.erase(nums[start]);
				start++;
			}
		}
		
		total += end-start;
	}

	return total;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
	int atMostKdistinct = subarraysWithAtMostKDistinct(nums, k);
    //cout<<atMostKdistinct<<" ";
	int atMostK_1distinct = subarraysWithAtMostKDistinct(nums, k-1);
    //cout<<atMostK_1distinct<<" ";
	return atMostKdistinct - atMostK_1distinct;
}
};