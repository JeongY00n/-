#include<iostream>
#include<vector>

using namespace std;


struct Info{
    long long t,a,h;
};
int N;
long long Hatk, Hmax;
vector<Info> room;
void init(){
    cin>>N>>Hatk;
    for(int i = 0; i<N; i++)
    {
        long long t,a,h; cin>>t>>a>>h;
        room.push_back({t,a,h});
    }
}
long long playing(long long maxi){
    long long cur=maxi, atk=Hatk;
    for(int i = 0; i<N; i++)
    {   
        //몬스터
        if(room[i].t==1)
        {
            //반복문으로 돌리지 말고, 
            //나머지 계산으로 몬스터를 죽일 수 있는지에 대한 여부 파악
            long long hp=room[i].h;
            hp%=atk;
            cur-=(room[i].a*(room[i].h/atk));
            if(hp==0)
                cur+=room[i].a;

            //용사 사망
            if(cur<=0)
                return 2;
        }
        //포션
        if(room[i].t==2)
        {
            atk+=room[i].a;
            cur+=room[i].h;
            if(cur>maxi) cur=maxi;
        }
    }
    return 1;
}
void solution(){
    long long left=1, right=9e18;
    long long answer;

    while(left<right)
    {
        long long mid = (left+right)/2;
        long long result = playing(mid);
        
        if(result==1)
        {
            // cout<<answer<<" ";
            //answer=mid;
            right=mid;
        }
        //작은 경우
        else
            left=mid+1;
        
    }
    cout<<right;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}