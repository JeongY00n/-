#include <string>
#include <vector>

using namespace std;
int answer;
void dfs(vector<int> numbers, int target, int idx, int calc){
    // 한 바퀴 다 돈 경우
    if(numbers.size()-1 == idx)
    {   
        if (calc == target)
            answer++;
        return;
    }
    dfs(numbers, target, idx+1, calc+numbers[idx+1]);
    //cout<<idx+1<<": "<<calc+numbers[idx+1]<<"\n";
    dfs(numbers, target, idx+1, calc-numbers[idx+1]);
    //cout<<idx+1<<": "<<calc-numbers[idx+1]<<"\n";
}
int solution(vector<int> numbers, int target) {
    dfs(numbers, target, -1, 0);
    return answer;
}