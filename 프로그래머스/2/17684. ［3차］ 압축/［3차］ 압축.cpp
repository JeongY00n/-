#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string, int> hash;
    for(char c='A'; c<='Z'; c++)
    {
        string str(1,c);
        hash[str]=c-'A'+1;
    }
    int idx=26;
    
    for(int i = 0; i<msg.size(); i++)
    {
        string str="";
        for(int j=i; j<msg.size(); j++)
        {
            if(hash.find(str+msg[j])==hash.end())// 값이 없는 경우
            {
                answer.push_back(hash[str]);
                idx++;
                hash[str+msg[j]]=idx;
                i=j-1;
                break;
            }
            else // 값이 있는 경우
            {
                str+=msg[j];
                if(j==msg.size()-1)
                {
                    answer.push_back(hash[str]);
                    idx++;
                    hash[str+msg[j]]=idx;
                    i=j;
                }
            }
            
        }
    }
    return answer;
}