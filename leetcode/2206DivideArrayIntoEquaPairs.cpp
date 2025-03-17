class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(const auto& num : nums) {
            freq[num]++;
        }

        for(const auto& [firts, second] : freq) {
            if(second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};
