//
// Created by bas on 9/29/21.
//

#ifndef ALGRITHOM_20ISVALID_H
#define ALGRITHOM_20ISVALID_H

//Method1 stack
//stack的经典用法
class Solution {
public:
    bool isValid(string s) {
        if( s.size() % 2 ) return false;
        stack<char> stk;
        for(auto& c : s) {
            if(c == '(') stk.push(')');
            else if(c == '{') stk.push('}');
            else if(c == '[') stk.push(']');
            else if(stk.empty() || stk.top() != c) return false;
            else stk.pop();
        }
        return stk.empty();//配对的陪完了，剩下的字符如果为空，则为1 true；若不为空，则empty显示false。
    }
};


//Method 2 hashmap stack
class Solution {
public:
    bool isValid(string s) {
        if( (s.size() & 1) == 1 ) return false;
        //s.size() % 2
        stack<char> stk;

        //因为hashmap是查key得到value，通过value和stack pop的值来配对，所以为}{ )(
        unordered_map<char, char> map {
                {')', '('},
                {'}', '{'},
                {']', '['}
        };
        for(auto& c : s) {
            if(map.count(c)){//c为map 的 key，返回true 否则 false
                if(stk.empty() || stk.top() != map[c]){
                    return false;
                }
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();//配对的陪完了，剩下的字符如果为空，则为1 true；若不为空，则empty显示false。
    }
};
#endif //ALGRITHOM_20ISVALID_H
