# include <string>
# include <iostream>
# include<algorithm>
using namespace std;

// 哈希表
bool isAnagram(string s, string t) {
    if (s.length() != t.length()){
        return 0;
    }
    int alphabet[26] = {0};
    for (int i = 0; s[i]!='\0' && t[i]!='\0'; i++){
        alphabet[s[i] - 'a'] += 1;
        alphabet[t[i] - 'a'] -= 1;
    }

    for (int j = 0; j<26; j++){
        if (alphabet[j] != 0){
            return 0;
        }
    }
    return 1;
}


// 代码瘦身版
bool isAnagram_thinner(string s, string t) {
    int freq[26] {};
    for (char ch : s) ++freq[ch - 'a'];
    for (char ch : t) --freq[ch - 'a'];
    return all_of(begin(freq), end(freq), [](int x) { return x == 0; });
}

// 排序法
bool isAnagram1(string s, string t) {
        if (s.length()!=t.length()){
            return 0;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }


int main(){
    bool res = isAnagram("anagram", "nagaram");
    cout << res << endl;
    return 0;
}