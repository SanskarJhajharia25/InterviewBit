/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
       int solve1(vector<int> &nums,int target){
        int low=0;
        int high=nums.size()-1;      //Setting bounds for Binary search
		
        while(low<=high){                     //low<=high since we need to consider single element array even
            int mid=(low+high)/2;     
            if(nums[mid]==target){            //Once target is found at mid,
                if(mid-1>=0){
                    if(nums[mid-1]==target)     //Check if there's another target to the left.
                        high=mid-1;                    //if found, reduce the area of operation
                    else
                        return mid;                 //if not found return currentIndex.
                }else
                    return mid;                     
            }else if(nums[mid]>target){     //if the target is less than current element move left since the array is sorted.
                high=mid-1;
            }
            else 
                low=mid+1;    //else move right.
        }
        return -1;                  //if this did not match any above, return -1
        
    }
    int solve2(vector<int> &nums,int target){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                if(mid+1<=nums.size()-1){
                    if(nums[mid+1]==target)
                        low=mid+1;
                    else
                        return mid;
                }else
                    return mid;
            }
            else if(nums[mid]>target){
                high--;
            }
            else 
                low++;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
			// A naive Approach using one for Loop. 
//         vector<int> arr(2,-1);
//         for(int i=0;i<nums.size();i++){
            
//             if(target==nums[i] && arr[0]==-1){
//                 arr[0]=i;
//                 arr[1]=i;
//             }else if(target==nums[i]){
//                 arr[1]=i;
//             }
//         }
//         return arr;
        
        vector<int> arr;
		//solve1 function for first occurence
		//solve2 function for last occurence
        arr.push_back(solve1(nums,target));
        arr.push_back(solve2(nums,target));
        return arr;
        
    }
};
