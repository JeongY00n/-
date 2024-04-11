#include <string>
#include <vector>
#include<queue>
#include <unordered_map>
#include<iostream>

using namespace std;

/*
    begin의 문자열 길이에 대한 반복문
    하나를 제외한 나머지 문자열에 대해 다른 문자열이 일치하는지 확인 일치하면 push, 몇번째 단계인지 cnt
*/
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int flag=0;
    for(int i = 0; i<words.size(); i++)
    {
        if(target==words[i])
        {
            flag=1;
            break;
        }            
    }
    // 변환할 수 없는 경우 0 return
    if(!flag)
        return 0;
    
    
    int visited[50]={0};
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    int end_flag=0;
    while(!q.empty()){
        pair<string, int> now = q.front(); q.pop();
        
        string str=now.first;
        int cnt=now.second;
        
        for(int i = 0; i<str.size(); i++)
        {
            // 문자 하나만 바꾼 hash 생성
            unordered_map<string,int> hash;
            for(char c='a'; c<='z'; c++)
            {
                string nstr=str;
                nstr[i]=c;
                hash[nstr]=1;
                
                // target에 도달
                if(nstr==target)
                {
                    answer=cnt+1;
                    end_flag=1;
                    break;
                }
                    
            }
            if(end_flag)break;
            
            for(int j = 0; j<words.size(); j++)
            {
                if(str==words[j])continue;
                if(visited[j])continue; //이미 변환한 문자열에 대해서는 넘어가기
                if(hash.find(words[j])==hash.end())continue;//words가 hash에 없는 경우 넘어감 
                
                
                visited[j]=1;
                q.push({words[j],cnt+1});
            }
        }
    }
    return answer;
}