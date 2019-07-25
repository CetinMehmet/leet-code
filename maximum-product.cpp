// Link to problem: https://leetcode.com/problems/maximum-product-of-three-numbers

// O(nlogn) solution

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int p1 = 1;
        int p2 = 1;
        
        // Sort array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // Assign 2 possibilities
        p1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        p2 = nums[n- 1] * nums[0] * nums[1];
        
        // Return max
        return max(p1, p2);
    }
};

// O(n) solution

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1001, max2 = -1001, max3 = -1001, min1 = 1001, min2 = 1001;
        for(int i = 0; i < nums.size(); i++) {
            
            // max2 max3 nums[i]
            if (nums[i] >= max3) {
                max1 = max2;
                max2 = max3;
                max3 = nums[i];
            }
            
            // max2 nums[i] max3
            else if (nums[i] >= max2) {
                max1 = max2;
                max2 = nums[i];
            }
            
            // nums[i] max2 max3
            else if (nums[i] >= max1) {
                max1 = nums[i];
            }
            
            // nums[i] min1
            if (nums[i] <= min1) {
                min2 = min1;
                min1 = nums[i];
            }
            
            // min1 nums[i] 
            else if (nums[i] <= min2) {
                min2 = nums[i];
            }
        }
        
        return max(min1 * min2 * max3, max1 * max2 * max3);
    }
};
