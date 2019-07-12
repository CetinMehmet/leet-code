// Link to problem: https://leetcode.com/problems/max-consecutive-ones/

// O(n ^ 2) solution
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        // Good practice to init maxLength to -1e9
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                int currLength = 1;
                int j = i + 1;
                
                while(j < nums.size() && nums[j] == 1) {
                    currLength++;
                    j++;
                }
                maxLength = max(maxLength, currLength);
            }
        }
        return maxLength;
    }
};


// O(n) solution
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int i = 0;
        while(i < nums.size()) {
            if (nums[i] == 1) {
                int curr_len = 1;
                int j = i + 1;
                while(j < nums.size() && nums[j] == 1) {
                    curr_len++;
                    j++;
                }
                
                // Very important line
                // Prevents us from checking the array again after finding the longest 1s
                i = j;
                
                maxLen = max(maxLen, curr_len);
            }
            else {
                i++;
            }
        }
        return maxLen;
    }
};
