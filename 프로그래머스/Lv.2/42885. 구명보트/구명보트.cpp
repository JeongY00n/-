#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int answer = 0;
    
    // 오름차순 정렬
    sort(people.begin(), people.end());
    
    int left=0, right=people.size()-1;
    
    while(left<=right)
    {
        if(left==right)
        {
            answer++; break;
        }
        
        if(people[left]+people[right]<=limit)// 두명을 태울 수 있는 경우
        {
            answer++;
            left++; right--;
        }
        else // 두명을 태울 수 없는 경우
        {
            answer++;
            right--;
        }
    }
    
    return answer;
}