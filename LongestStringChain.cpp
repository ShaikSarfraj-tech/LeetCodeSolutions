#include <bits/stdc++.h>
using namespace std;

struct compare {
	inline bool operator()(const string& first, const string& second) {
		return first.size() < second.size();
	}
};

class Solution {
public:
    	int longestStrChain(vector<string>& words) {
    	int res = 0;
    	//Sorting based on length
    	sort(words.begin(), words.end(), []
		    (const string& first, const string& second){
		        return first.size() < second.size();
		    });

    	map<string, int> map;
    	for(int i = 0; i < words.size(); i++) {
    		int maxAns = 0;
    		for(int j = 0; j < words[i].length(); j++) {
    			string prev = words[i].substr(0, j) + words[i].substr(j+1);
    			maxAns = max(maxAns, map[prev]+1);
    		}
    		map[words[i]] = maxAns;
    		res = max(res, maxAns);
    	}
    	return res;
    }
};

int main() {
	Solution *obj = new Solution();
	vector<string> words;
	int n; cin >> n;
	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		words.push_back(s);
	}
	int res = obj->longestStrChain(words);
	cout << res << "\n";
}