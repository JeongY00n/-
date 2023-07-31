#include<iostream>
#include<cstring>
using namespace std;


/*
    anta tica
    a b c d e f g h i j k l m n o p q r s t u v w x y z
    -   -           -         -           -
    각 단어 당 알아야하는 글자의 수(기본적으로 5개)
    
    알아야하는 글자가 한 개인 경우(중복된 글자로)

    다른 단어에는 겹치지 않는 글자들로만 구성된 단어

    우선순위를 두기?
    

*/
int n, k, answer;
char str[50][16];
int used[26]; // 모든 단어에서 사용되는 글자
int total;
void init(){
    cin>>n>>k;
    for(int i = 0; i<n; i++)
    {
        cin>>str[i];
        for(int j = 4; j<strlen(str[i])-3; j++)
        {
            // 기본적으로 알아야하는 단어는 제외
            if(str[i][j]=='a'||str[i][j]=='c'||str[i][j]=='i'||str[i][j]=='n'||str[i][j]=='t')continue;
            if(used[str[i][j]-'a']==0)
            {    
                total++;
                used[str[i][j]-'a']=1;
            }
        }
    }
}

int pick[26];
int reading(){
    int cnt=0;
    for(int i = 0; i<n; i++)
    {
        int read=1;
        for(int j = 4; j<strlen(str[i])-3; j++){
            if(str[i][j]=='a'||str[i][j]=='c'||str[i][j]=='i'||str[i][j]=='n'||str[i][j]=='t')continue;
            else if(pick[str[i][j]-'a']==0){
                read=0;
                break;
            }
        }
        if(read) cnt++;
    }
    
    return cnt;
}

void learn(int cnt, int idx){
    if(cnt >= k - 5)
    {   
        answer = max(answer, reading());
        return;
    }

    for(int i = idx; i<26; i++)
    {
        if(used[i]==1)
        {
            pick[i]=1;
            learn(cnt+1, i+1);
            pick[i]=0;
        }
    }
}

void solution(){
    if(k<5){
        answer = 0;
    }
    else if(total<=k-5){
        answer = n;
    }
    else if(k==5){
       for(int i = 0; i<n; i++)
       {
            int read = 1;
            for(int j = 4; j<strlen(str[i])-3; j++)
            {
                if(str[i][j]=='a'||str[i][j]=='c'||str[i][j]=='i'||str[i][j]=='n'||str[i][j]=='t')continue;
                else
                {
                    read=0;
                    break;
                }
            }
            if(read)   answer++;
       } 
    }
    else{
        learn(0,0);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    cout<<answer;

    return 0;
}