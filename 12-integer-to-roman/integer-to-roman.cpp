class Solution {
public:
    string intToRoman(int num) {
    int nums[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string s[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int i=0;
    string ret="";
    while(num!=0){
       if(num>=nums[i]){
            num=num-nums[i];
            ret+=s[i];
       }
       else{
        i++;
       }
    }
    return ret;
    }
}; 