class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> keytoRow;
        vector<string> keyboardRows={"qwertyuiop","asdfghjkl","zxcvbnm"};
        for(int i=0;i<keyboardRows.size();i++){
            for(auto &ch:keyboardRows[i]){
                keytoRow.insert(make_pair(ch,i));
                keytoRow.insert(make_pair(ch-'a'+'A',i));
            }
        }
        vector<string> res;
        for(auto &word:words){
            int row=keytoRow[word[0]];
            bool flag=true;
            for(auto &ch:word){
                if(keytoRow[ch]!=row){
                    flag=false;
                    break;
                }
            }
            if(flag) res.push_back(word);
        }
        return res;
    }
};