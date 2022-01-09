/**
 * @brief There is an integer array nums sorted in ascending order (with distinct values).
 * Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
 * such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 * Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
 *  or -1 if it is not in nums.You must write an algorithm with O(log n) runtime complexity.
 */

class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        int n=arr.size();
        int left = 0;
        int right = n-1;
        int mid;
        
        while(left+1 < right){
            
            mid = (left + right) / 2;
            
            if(target == arr[mid]) {
                return mid;
            }
            
            else if(target > arr[mid]) {
                if(arr[mid] > arr[left]) {
                    left = mid;
                }        
                else if(arr[mid] < arr[right]) {
                    if(target > arr[right]) {
                        right = mid;
                    }else {
                        left = mid;
                    }
                }
            }else {
                if(arr[mid] > arr[left]) {
                    if(target >= arr[left]) {
                        right = mid;
                    }else{
                        left = mid;
                    }
                }else if(arr[mid] < arr[right]) {
                    right = mid;
                }
            }
            
        }
        if(arr[left] == target) return left;
        if(arr[right] == target) return right;
        return -1;
    }
};