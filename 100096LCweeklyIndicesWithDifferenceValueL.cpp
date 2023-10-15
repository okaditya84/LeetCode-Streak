#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       int n =s.size();
       int left=0,right=0;
       int count=0;
       int min_length=INT_MAX;
       string res="";
       while(right<n){
        count=updateCount(s[right],count);
        while(count==k){
            tie(min_length,res)=updateRes(s,left,right,min_length,res);
            count=updateCount(s[left],count,false);
            left++;
        }
        right++;
       }
       return res;

    }
    private:
    int updateCount(char c,int count,bool increment=true){
        if(c=='1'){
            return increment ? count+1:count-1;
        }
        return count;
    }
    pair<int,string> updateRes(string s,int left,int right,int min_length,string res){
        if(right-left+1<min_length){
            min_length=right-left+1;
            res=s.substr(left,min_length);
        }
        else if(right-left+1==min_length){
            res=min(res,s.substr(left,min_length));
        }
        return {min_length,res};
    }

};