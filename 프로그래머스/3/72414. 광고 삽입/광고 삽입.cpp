#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
    play_time : 동영상이 끝나는 시각
    adv_time : 광고 시간 길이
    
    * 시간을 모두 초로 바꾸고 해당 초에 시청하는 시청자 cnt
    * 시청자가 있으면 시청자 수 cnt
    * 만약 cnt를 시작했던 시각부터 adv_time 시간이 지나면,
      cnt를 시작했던 시각에 +1하고 시청자 수를 빼준다
    * 그러면서 max cnt에 대한 시간을 저장
    
*/
int ptime[3], atime[3];
int ptotal, atotal;
long long check[10000000];
string answer = "";
void findanswer()
{
    int left=0, right=0;
    int start_time=0;
    long long maxi=0, cnt=0;
    while(right<=ptotal){
        if(right-left==atotal)
        {
            // 종료시각 이전까지 계산한 cnt에 대해 조건 확인 해주기
            if(maxi < cnt){
                maxi = cnt;
                start_time = left;
            }
            // 조건 확인이 끝나면 종료시각의 cnt 더해주기
            cnt-=check[left];
            cnt+=check[right];
            left++;
            right++;
            
        }
        else
        {
            cnt+=check[right];
            right++;
        }
    }

    int h = start_time/(60*60);
    int m = start_time%(60*60)/60;
    int s = start_time%(60*60)%60;

    if(h<10)
        answer=answer+'0'+(char)(h+'0')+':';
    else
        answer=answer+(char)(h/10+'0')+(char)(h%10+'0')+':';
    if(m<10)
        answer=answer+'0'+(char)(m+'0')+':';
    else
        answer=answer+(char)(m/10+'0')+(char)(m%10+'0')+':';
    if(s<10)
        answer=answer+'0'+(char)(s+'0');
    else
        answer=answer+(char)(s/10+'0')+(char)(s%10+'0');
    
}
string solution(string play_time, string adv_time, vector<string> logs) {
    
    // 동영상 재생시간
    int j=0;
    for(int i = 0; i<play_time.size(); i++)
    {
        if(play_time[i]=='"')
            continue;
        else if(play_time[i]==':')
            j++;
        else
            ptime[j]=ptime[j]*10+(play_time[i]-'0');
    }
    ptotal = ptime[0]*60*60+ptime[1]*60+ptime[2];
    
    // 광고 재생시간
    j=0;
    for(int i = 0; i<adv_time.size(); i++)
    {
        if(adv_time[i]=='"')
            continue;
        else if(adv_time[i]==':')
            j++;
        else  
            atime[j]=atime[j]*10+(adv_time[i]-'0');
    }
    
    atotal = atime[0]*60*60+atime[1]*60+atime[2];
    
    for(int i = 0; i<logs.size(); i++)
    {
        int start=0,end=0;
        int ltime[2][3]={}, n=0, m=0;
        for(int j = 0; j<logs[i].size(); j++)
        {
            if(logs[i][j]=='"')
                continue;
            else if(logs[i][j]==':')
                m++; 
            else if(logs[i][j]=='-')
            {
                n++;
                m=0; 
            }
            else
                ltime[n][m]=ltime[n][m]*10+(logs[i][j]-'0');
        }
        
        start = ltime[0][0]*60*60+ltime[0][1]*60+ltime[0][2];
        end = ltime[1][0]*60*60+ltime[1][1]*60+ltime[1][2];
        
        for(int j = start; j<end; j++)
            check[j]++;
        
    }
    
    findanswer();
    
    return answer;
}