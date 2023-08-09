class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[nums.size() - 1] - nums[0];
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            int i = 0;
            
            while (i < nums.size() - 1) {
                if (nums[i + 1] - nums[i] <= mid) {
                    count++;
                    i++;
                }
                i++;
            }
            
            if (count >= p) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};
