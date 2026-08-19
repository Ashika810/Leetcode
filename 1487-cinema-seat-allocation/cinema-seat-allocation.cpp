class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,int>rows;

        for(auto &seat:reservedSeats){
            int row=seat[0];
            int s=seat[1];

            if(s>=2 && s<=9)
                rows[row] |= (1<<s);
            }
            int answer= (n-rows.size()) *2;

            for(auto &[row,mask]: rows){
                bool left= true;
                bool middle = true;
                bool right = true;

                for(int s=2;s<=5;s++)
                    if(mask &(1<<s))
                left=false;

                for(int s=4; s<=7;s++)
                if(mask &(1<<s))
                middle=false;

                for(int s=6;s<=9;s++)
                if(mask &(1<<s))
                right=false;

                if(left && right)
                answer +=2;
                else if(left || right || middle)
                answer +=1;
            }
            return answer;
        }
};