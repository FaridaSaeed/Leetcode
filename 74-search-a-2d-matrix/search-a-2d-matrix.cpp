class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0 , r = n*m-1, mid;
        while(l<=r)
        {
            mid = (r+l+1)/2;
            int elem = matrix[mid/m][mid%m];
            if(elem<target) l = mid+1;
            else if(elem>target)r = mid-1;
            else return true;
        }
        return false;
    }
};