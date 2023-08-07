
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty())
            return 0;

        int j = 0; // Pointer to track the last position of a unique element

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[j]) {
                nums[++j] = nums[i];
            }
        }

        return j + 1;
    }
};