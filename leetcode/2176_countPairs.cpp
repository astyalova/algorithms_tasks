class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < nums.size(); ++i) {
            valueToIndices[nums[i]].push_back(i);
        }

        int counter = 0;
        for (const auto& [num, indices] : valueToIndices) {
            for (int i = 0; i < indices.size(); ++i) {
                for (int j = i + 1; j < indices.size(); ++j) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        ++counter;
                    }
                }
            }
        }
        return counter;
    }
};