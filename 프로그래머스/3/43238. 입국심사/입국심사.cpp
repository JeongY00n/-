#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

/*
    주어진 입력값에 의한 시간의 최대는 times의 개수로 사람 수를 나눈값에 가장 큰 시간 값을 곱하는 것
    => n/times.size() * times[times.size()-1];
    mid / time[1] + mid / time[2] + ... > n이라면 right=mid-1;
    mid / time[1] + mid / time[2] + ... < n이라면 left=mid+1;
    
*/
long long solution(int n, vector<int> times) {
    
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long right = n/times.size()*times[times.size()-1]+times[times.size()-1];
    long long left = 0;
    
    while(left<=right){
        long long mid = (right+left)/2;
        long long sum=0;
        
        for(int i = 0; i<times.size(); i++)
            sum+=mid/times[i];
        
        cout<<left<<","<<right<<","<<mid<<","<<sum<<"\n";
        

        answer=mid;

        
        if(sum>n)
        {
            right=mid-1;
        }
            
        else if(sum<n)
        {
            left=mid+1;
        }
            
        else
        {
            long long mini=2e9;
            for(int i = 0; i<times.size(); i++)
                mini=min(mini, mid%times[i]);
            
            answer=mid-mini;
            break;
        }
        
    }
    
    
    return answer;
}