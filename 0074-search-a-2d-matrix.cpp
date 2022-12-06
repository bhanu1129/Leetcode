/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();

        int s=0;
        int e=(row*col)-1;
        int mid=s+(e-s)/2;

        while(s<=e){
            int element=matrix[mid/col][mid%col];

            if(element==target){
                return 1;
            }

            if(element<target){
                s=mid+1;
            }else{
                e=mid-1;
            }

            mid=s+(e-s)/2;            
        }

        return 0;
    }
};