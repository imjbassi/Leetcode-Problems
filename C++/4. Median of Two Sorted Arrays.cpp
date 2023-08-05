class Solution {
  public: double findMedianSortedArrays(vector < int > & nums1, vector < int > & nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is smaller to optimize partitioning
    }

    int m = nums1.size();
    int n = nums2.size();
    int low = 0;
    int high = m;

    while (low <= high) {
      int partitionX = (low + high) / 2;
      int partitionY = (m + n + 1) / 2 - partitionX;

      int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
      int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];

      int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
      int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

      if (maxX <= minY && maxY <= minX) {
        // Correct partition found
        if ((m + n) % 2 == 0) {
          return (max(maxX, maxY) + min(minX, minY)) / 2.0;
        } else {
          return max(maxX, maxY);
        }
      } else if (maxX > minY) {
        // Move partitionX to the left
        high = partitionX - 1;
      } else {
        // Move partitionX to the right
        low = partitionX + 1;
      }
    }

    throw std::invalid_argument("Input arrays are not sorted or invalid.");
  }
};