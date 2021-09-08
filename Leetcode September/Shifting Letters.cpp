class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum = 0, n = shifts.size();
        for(int i=n-1; i>=0; i--) {
            sum += (shifts[i])%26;
            shifts[i] = sum;
        } 
        for(int i=0; i<n; i++) {
            s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        return s;
    }
};
