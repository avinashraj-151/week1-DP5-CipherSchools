#include <bits/stdc++.h>
using namespace std;

bool isMatching(char open, char close){
    return ((open == '(' && close == ')') ||
    (open == '{' && close == '}')   ||
    (open == '[' && close == ']'));
}
bool isOpen(char ch){
    return (ch == '(' || ch == '{' || ch == '[');
}
bool isvalid(string &str){
    if(str.size() == 0){
     return true;
    }else if(str.size() &1){
        return false;
    }else{
        stack<char> s;
        for(int i = 0; i < str.size();i++){
            if(isOpen(str[i])){
                s.push(str[i]);
            }else{
                if (s.empty()){
                    return false;
                }
                if(!isMatching(s.top(), str[i])){
                    return false;
                }
                s.pop();    
            }
        }
    }
}
int main()
{
    return 0;
}