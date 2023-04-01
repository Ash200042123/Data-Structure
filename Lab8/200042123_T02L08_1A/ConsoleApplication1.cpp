
#include <iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& P, string S) {
        sort(P.begin(), P.end());
        vector<vector<string>> ans;
        int left = 0;
        int right = P.size() - 1;

        for (int i = 0; i < S.length(); i++) {
            vector<string> res;
            char c = S[i];
            while (left <= right && (P[left].length() == i || P[left][i] < c)) {
                left++;
            }
            while (left <= right && (P[right].length() == i || P[right][i] > c)) {
                right--;
            }
            for (int j = 0; j < 3 && left + j <= right; j++) {
                res.push_back(P[left + j]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};


int main()
{
    vector<string> products;
    string searchWord,searchWordCopy;
    //products = ["mobile", "mouse", "moneypot", "monitor", "mousepad"]
    products.push_back("mobile");
    products.push_back("mouse");
    products.push_back("moneypot");
    products.push_back("monitor");
    products.push_back("mousepad");

    Solution s;

    cin >> searchWord;
    for (int i = 0;i < searchWord.length();i++) {
        char x = searchWord[i];
        searchWordCopy += x;
        vector<vector<string>> y = s.suggestedProducts(products, searchWordCopy);

        for (int j = i;j < y.size(); j++) {
            for (int k = 0;k < y[j].size(); k++)
            cout << y[j].at(k) << " ";
        }
        cout << "\n";
    }
	return 0;
}

