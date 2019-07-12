// Link to problem: https://leetcode.com/problems/two-sum/submissions/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector < pair<int, int> > nums2;
        vector <int> ret;
        for (int k = 0; k < nums.size(); k++) {
            pair<int, int> temp(nums[k], k);
            nums2.push_back(temp);
        }
        
        sort(nums2.begin(), nums2.end());
        
        int i = 0;
        int j = nums2.size() - 1;
        
        while (nums2[i].first + nums2[j].first != target) {

            if (nums2[i].first + nums2[j].first > target) {
                j--;
            }

            if (nums2[i].first + nums2[j].first < target) {
                i++;
            }
        }
        ret.push_back(nums2[i].second);
        ret.push_back(nums2[j].second);
        return ret;
    } 
};
 
