class Solution {
public:
// void solve(int i, string &current, string &s, string &t, int& cnt){
    
//     if(current.size() == t.size() && current == t) {
//         cnt++;
//         return;
//     }
//     if(i == s.size()) return;

//     current.push_back(s[i]);

//     int len = current.size();
//     if(current[len - 1] == t[len - 1]){
//         solve(i + 1, current, s, t, cnt);
//     }
//         current.pop_back();
    
//     solve(i + 1, current, s, t, cnt);
// }
    int solve(int i, int j, string& s, string &t, vector<vector<int>>&dp ){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int way = solve(i + 1, j, s, t, dp);
        if(s[i] == t[j]){
            way += solve(i + 1, j + 1, s, t, dp);
        }
        return dp[i][j] = way;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, s, t, dp);
        
    }
};