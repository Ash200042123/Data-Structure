
#include <iostream>
#include<vector>
#include<map>
#include <regex>

using namespace std;


class Trie {
public:
    int trie[300005][50];
    int id = 1;
    int endmark[300005];
    int pre[300005];
    Trie() {
        memset(trie, 0, sizeof(trie));
        memset(endmark, 0, sizeof(endmark));
        memset(pre, 0, sizeof(pre));
    }

    void insert(string word) {
        int row = 1;
        for (int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if (trie[row][ch] == 0)
            {
                trie[row][ch] = ++id;
            }
            row = trie[row][ch];
            pre[row]++;
        }
        endmark[row] = 1;

    }
    bool search(string word) {
        int row = 1;
        for (int i = 0; i < word.size();i++)
        {
            int ch = word[i] - 'a';
            if (trie[row][ch] == 0) return false;
            row = trie[row][ch];

        }
        return (endmark[row] == 1);
    }

    bool startsWith(string prefix) {
        int row = 1;
        for (int i = 0; i < prefix.size();i++)
        {
            int ch = prefix[i] - 'a';
            if (trie[row][ch] == 0) return false;
            row = trie[row][ch];

        }
        return (pre[row] >= 1);
    }
};


class WordDictionary {
    vector <string> arr;

public:
    WordDictionary() {
        //arr = new vector<string>;
    }

    void addWord(string x) {

        regex b(x);
        for (int i = 0; i < arr.size(); i++) {
            if (regex_match(arr[i], b)) {
                return;
            }
        }

        int index = arr.size();
        arr.push_back(x);
    }


    void search(string x) {
         
            regex b(x);
            for (int i = 0; i < arr.size(); i++) {
                if (regex_match(arr[i], b)) {
                    cout << "Word Found" << endl;
                    return;
                }
            }
        
        cout << "Word Not Found" << endl;
    }
};



int main()
{
    WordDictionary w = WordDictionary();
    w.addWord("bad");
    w.addWord("dad");
    w.addWord("mad");
    w.search("pad");
    w.search("bad");
    w.search(".ad");
    w.search("b..");

	return 0;
}

