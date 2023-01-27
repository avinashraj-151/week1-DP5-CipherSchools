#include <bits/stdc++.h>
using namespace std;

void powerSet(vector<int>&vec, vector<vector<int>>& res, vector<int>& setSoFar, int len, int index) {
    if (index >= len) {
        res.push_back(setSoFar);
        return;
    }
    setSoFar.push_back(vec[index]);
    powerSet(vec, res, setSoFar, len, index + 1);
    setSoFar.pop_back();
    powerSet(vec, res, setSoFar, len, index + 1);
}

vector<vector<int>> powerSet(vector<int>& vec) {
    if (vec.empty()) return {};
    vector<vector<int>> result;
    vector<int> setSoFar;
    powerSet(vec, result, setSoFar, vec.size(), 0);
    return result;
}

int main() {
    vector<int> vec = {4,5,6};
    auto ans = powerSet(vec);
    for (auto &item : ans) {
        for (auto &num : item) cout << num <<  " " ;
        cout << endl;
    }
}