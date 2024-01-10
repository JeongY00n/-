#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int arr[360000];
string solution(string play_time, string adv_time, vector<string> logs) {

    for (auto x : logs)
    {
        int from = stoi(x.substr(0, 2)) * 3600 + stoi(x.substr(3, 2)) * 60 + stoi(x.substr(6, 2));
        int to = stoi(x.substr(9, 2)) * 3600 + stoi(x.substr(12, 2)) * 60 + stoi(x.substr(15, 2));

        for (int i = from + 1; i <= to; i++)
            arr[i]++;
    }

    int length = stoi(adv_time.substr(0, 2)) * 3600 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));
    int playtime = stoi(play_time.substr(0, 2)) * 3600 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));

    long long int sum = 0;
    long long int maximum = -1;
    int index = 1;

    for (int i = 1; i <= length; i++)
        sum += arr[i];
    maximum = sum;

    for (int i = 2; i <= (playtime - length + 1); i++)
    {
        sum += (long long int)(arr[i + length - 1] - arr[i - 1]);

        if (sum > maximum)
        {
            maximum = sum;
            index = i;
        }
    }




    index--;
    string answer;
    int hour, minute, second;

    hour = index / 3600;
    index -= hour * 3600;
    minute = index / 60;
    second = index % 60;

    if (hour <= 9)
        answer.push_back('0');
    answer += (to_string(hour));
    answer.push_back(':');

    if (minute <= 9)
        answer.push_back('0');
    answer += (to_string(minute));
    answer.push_back(':');
    if (second <= 9)
        answer.push_back('0');
    answer += (to_string(second));


    if(answer.size() != 8)
        while(1);

    return answer;
}