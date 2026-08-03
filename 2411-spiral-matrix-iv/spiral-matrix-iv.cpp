class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;

        while(head && top<= bottom && left<= right){
            for(int j=left;j<=right && head;j++){
                ans[top][j]=head->val;
                head=head->next;
            }
            top++;
            for(int i=top;i<=bottom && head;i++){
                ans[i][right]=head->val;
                head=head->next;
            }
            right--;
            if(top<=bottom){
            for(int j=right;j>=left && head;j--){
                ans[bottom][j]=head->val;
                head=head->next;
            }
            bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top && head;i--){
                    ans[i][left]=head->val;
                    head=head->next;
                }
                left++;
            }
        }
        return ans;
    }
};