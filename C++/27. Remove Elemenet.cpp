class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int j = 0; // Pointer to track the position to place the non-val elements

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};