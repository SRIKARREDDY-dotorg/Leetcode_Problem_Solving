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