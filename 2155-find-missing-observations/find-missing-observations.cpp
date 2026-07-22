class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        int knownSum=0;

        for(int x: rolls)
        knownSum+= x;

        int totalSum = mean * (n+m);
        int missingSum = totalSum - knownSum;

        if(missingSum< n || missingSum > 6*n)
        return {};

        vector<int> ans(n,1);

        int extra = missingSum - n;

        for(int i =0;i<n && extra> 0;i++){
            int add = min(5,extra);
            ans[i] +=add;
            extra -= add;
        }
        return ans;
    }
};