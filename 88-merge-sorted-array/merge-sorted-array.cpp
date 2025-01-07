class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idxn = n-1 ,idxm = m-1,r = m+n-1;
        while(idxn>=0)
        {
            if(idxm>=0 && nums1[idxm] > nums2[idxn])
            {
                nums1[r] = nums1[idxm];
                idxm--;
            }
            else
            {
                nums1[r] = nums2[idxn];
                idxn--;
            }
            r--;
        } 
    }
};