#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;

unordered_map<string, char> number;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i = 0; i<phone_book.size(); i++)
    {
        number.insert({phone_book[i],1});
    }
    for(int i = 0; i<phone_book.size(); i++)
    {
        int endflag=0;
        for(int j = 0; j<phone_book[i].size(); j++)
        {
            string sub = phone_book[i].substr(0,j);
            // cout<<sub<<"\n";
            if(number[sub]==1)
            {
                answer=false;
                endflag=1;
                break;
            }
        }
        if(endflag) break;
    }
    
    return answer;
}