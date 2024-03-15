#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin>>s;
    deque<char> Left(s.begin(), s.end()), Right; // 커서 왼쪽 값과 커서값 포함, 커서의 오른쪽 값

    int N; cin>>N;
    int point = s.size();

    for(int i = 0; i<N; i++)
    {
        char op; cin>>op;
        
        if(op=='L')
        {
            if(!Left.empty())
            {
                char a = Left.back();
                Left.pop_back();
                Right.push_front(a);
            }
        }
        else if(op=='D')
        {
            if(!Right.empty())
            {
                char a = Right.front();
                Right.pop_front();
                Left.push_back(a);
            }
        }
        else if(op=='B')
        {
            if(!Left.empty())
                Left.pop_back();
        }
        else if(op=='P')
        {
            char a; cin>>a;
            Left.push_back(a);
        }
    }

    while(!Left.empty())
    {
        cout<<Left.front();
        Left.pop_front();
    }
    while(!Right.empty())
    {
        cout<<Right.front();
        Right.pop_front();
    }

    return 0;
}