#include<iostream>

using namespace std;


int N,M,K;
long long num[1000001];
long long tree[4000004];

long long make_tree(int start, int end, int idx){
    // 가장 끝(리프노드)에 도달했으면, 숫자 삽입
    if(start == end) return tree[idx]=num[start];

    int mid = (start+end)/2;
    return tree[idx] = make_tree(start, mid, idx*2)+make_tree(mid+1, end, idx*2+1);
}
long long subSum(int start, int end, int idx, int left, int right){
    // 범위 밖에 있는 경우
    if(left>end || right<start)
        return 0;
    // 범위 안에 있는 경우
    if(left<=start && end<=right)
        return tree[idx];
    // 그렇지 않은 경우
    int mid = (start+end)/2;
    return subSum(start, mid, idx*2, left, right) + subSum(mid+1, end, idx*2+1, left, right);
}
// what : 구간 합을 수정하고자 하는 노드
// value : 수정할 값
void update(int start, int end, int idx, int what, long long value){
    // 범위 밖에 있는 경우
    if(what<start || end<what)
        return;
    // 범위 안에 있으면 내려가면서 다른 원소도 갱신
    tree[idx]+=value;
    if(start==end)
        return;
    int mid = (start+end)/2;
    update(start, mid, idx*2, what, value);
    update(mid+1, end, idx*2+1, what, value);
}
void init(){
    cin>>N>>M>>K;
    for(int i = 0; i<N; i++)
        cin>>num[i];
    
    make_tree(0, N-1,1);
}
void solution(){
    long long a,b,c;
    for(int i = 0; i<M+K; i++)
    {
        cin>>a>>b>>c;
        if(a==1)// 변경
        {
            update(0,N-1,1,b-1,c-num[b-1]);
            num[b-1]=c;
        }
        else//구간합
            cout<<subSum(0,N-1,1,b-1,c-1)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();

    return 0;
}