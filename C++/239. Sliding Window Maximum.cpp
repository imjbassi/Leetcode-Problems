class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> window;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements out of the current window's range
            while (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }

            // Remove smaller elements as they will not be useful
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }

            window.push_back(i);

            // The front of the window deque contains the maximum element for the current window
            if (i >= k - 1) {
                result.push_back(nums[window.front()]);
            }
        }

        return result;
    }
};