class Solution {
public:
    char slowestKey(vector<int>& releaseTime, string keysPressed) {
        int res_time = releaseTime[0];
        char ch = keysPressed[0];
        int n = keysPressed.size();
        
        for(int i=1; i<n; i++) {
            int time = releaseTime[i] - releaseTime[i-1];
            if(res_time == time && (ch - 'a' < keysPressed[i] - 'a')) {
                ch = keysPressed[i];
            }
            else if(res_time < time) {
                ch = keysPressed[i];
                res_time = time;
            }
        }
        return ch;
    }
};
