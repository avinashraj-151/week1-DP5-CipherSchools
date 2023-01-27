#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(string &combinationSoFar, int open, int close, vector<string> &result)
    {
        if (open < 0 || close < 0)
        {
            return;
        }
        else if (open == 0 && close == 0)
        {
            string temp = combinationSoFar;
            result.push_back(temp);
        }
        else if (open <= close)
        {
            combinationSoFar += "(";
            generateParenthesis(combinationSoFar, open - 1, close, result);
            combinationSoFar = combinationSoFar.substr(0, combinationSoFar.size() - 1);

            combinationSoFar += ")";
            generateParenthesis(combinationSoFar, open, close - 1, result);
            combinationSoFar = combinationSoFar.substr(0, combinationSoFar.size() - 1);
        }
    }
    vector<string> generateParenthesis(const int n)
    {
        vector<string> result = {};
        string combinationSoFar = "";
        generateParenthesis(combinationSoFar, n, n, result);
        return result;
    }
int main()
{
    int n;
    cin>>n;
    vector<string> result = generateParenthesis(n);
    for(auto value : result){
        cout<<value<<endl;
    }
}