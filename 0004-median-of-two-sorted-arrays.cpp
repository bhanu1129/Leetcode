/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size();
        int m = nums2.size();

        int low=0, high=n;
        while(low <= high){
            int mid1 = (low + high) / 2;
            int mid2 = (n + m + 1)/2 - mid1;

            int l1 = mid1 == 0 ? INT_MIN : nums1[mid1-1];
            int l2 = mid2 == 0 ? INT_MIN : nums2[mid2-1];
            int r1 = mid1 == n ? INT_MAX : nums1[mid1];
            int r2 = mid2 == m ? INT_MAX : nums2[mid2];

            if(l1 <= r2 && l2 <= r1){
                if((n + m)%2 == 0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return (max(l1,l2));
            }
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }

        return 0.0;
    }
};