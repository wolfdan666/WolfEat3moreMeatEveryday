/* 
2021年06月20日14:33:35 开始看题
2021年06月20日15:01:27 觉得自己的父亲孩子兄弟树实现不够优美，还是看答案吧


作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/throne-inheritance/solution/huang-wei-ji-cheng-shun-xu-by-leetcode-s-p6lk/

2021年06月20日15:05:16 发现原来完全无需存父亲的边...尴尬
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// class ThroneInheritance {
// public:
//     ThroneInheritance(string kingName) {
//         vector<string> tmp();
//         tmp.push_back(nullptr);
//         father_children_v.push_back(tmp);
//     }
    
//     void birth(string parentName, string childName) {
//         if (father_children_v)
//     }
    
//     void death(string name) {

//     }
    
//     vector<string> getInheritanceOrder() {

//     }
// private:
//     vector<string> curOrder();
//     // 第一维是自己，然后第二维中第一个是自己的父亲，然后后面的是自己的孩子
//     vector<<vector<string> > father_children_v();
// };

class ThroneInheritance {
private:
    unordered_map<string, vector<string>> edges;
    unordered_set<string> dead;
    string king;

public:
    ThroneInheritance(string kingName): king{move(kingName)} {}
    
    void birth(string parentName, string childName) {
        edges[move(parentName)].push_back(move(childName));
    }
    
    void death(string name) {
        dead.insert(move(name));
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;

        function<void(const string&)> preorder = [&](const string& name) {
            if (!dead.count(name)) {
                ans.push_back(name);
            }
            if (edges.count(name)) {
                for (const string& childName: edges[name]) {
                    preorder(childName);
                }
            }
        };

        preorder(king);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main(){
    
    
    return 0;
}