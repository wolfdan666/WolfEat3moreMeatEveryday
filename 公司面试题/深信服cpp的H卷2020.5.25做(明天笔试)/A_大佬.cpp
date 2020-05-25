/*
妙用find_last_of,太强了

*/

#include <map>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n;
    vector<string> check;
    string prior, path;
    cin >> m;
    string temp;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        check.push_back(temp);
    }

    cin >> n;
    map<string, string> priorMap;
    for(int i = 0 ; i < n; i++) {
        cin >> prior;
        cin >> path;
        if(priorMap[path] == "") {
            priorMap[path] = prior;
        }
    }
    if(priorMap["/"] == "") {
         priorMap["/"] = "N";
    }

    for(int i = 0; i < m; i++) {
        string temp_path = check[i];
        while((temp_path != "") && (priorMap[temp_path] == "")) {

            temp_path = temp_path.substr(0, temp_path.find_last_of('/'));


        }
        if(temp_path == "") {
            cout << priorMap["/"] << endl;
        }
        else {
            cout << priorMap[temp_path] << endl;
        }
    }

}