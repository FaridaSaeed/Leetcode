class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shifted = 0;

        while(left != right){
            
            shifted++;
            left = left>>1;
            right = right>>1;
        }
       
        

        return left<<shifted;
    }
};