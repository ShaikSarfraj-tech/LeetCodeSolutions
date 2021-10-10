#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contMap;
        for (auto &pStr : paths) {
            int i = 0;
            while (pStr[i] != ' ')
            	i++;
            string path = pStr.substr(0,i);
            for (int j = i + 1, k = 0; i < pStr.size(); i++) {
                if (pStr[i] == '(')
                	k = i+1;
                else if (pStr[i] == ')') {
                    string pathfile = path + '/' + pStr.substr(j, k-j-1),
                    cont = pStr.substr(k, i-k);
                    if (contMap.find(cont) == contMap.end())
                        contMap[cont] = vector<string>();
                    contMap[cont].push_back(pathfile);
                    j = i + 2;
                }
            }
        }
        vector<vector<string>> ans;
        for (auto &kv : contMap)
            if (kv.second.size() > 1)
            	ans.push_back(kv.second);
        return ans;
    }
};

int main() {
	Solution *obj = new Solution();
	vector<string> paths;
	int n; cin >> n;
	string s;
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		paths.push_back(s);
	}
	vector<vector<string>> res = obj->findDuplicate(paths);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}