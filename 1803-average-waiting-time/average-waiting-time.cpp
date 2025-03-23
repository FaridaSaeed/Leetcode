class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = 1,n = customers.size();
        double count=0;
        for(auto i:customers)
        {
            if(time<=i[0]){
                count+=i[1];
                time = i[0]+i[1];
            }
            else {
                count+=time-i[0] + i[1];
                time+=i[1];
            }
        }

        return count/n;
    }
};