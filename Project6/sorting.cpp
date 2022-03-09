#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

/* 프로그래머스 고득점 kit - 정렬 - k번째 수 */
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> original = array;
    for (int i = 0; i < commands.size(); i++) {
        sort(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        answer.push_back(array[commands[i][2] + commands[i][0] - 2]);
        array = original;
    }
    return answer;
}

/* 프로그래머스 고득점 kit - 정렬 - 가장 큰 수 */
bool compare(int a, int b) {
    string str_a = to_string(a) + to_string(b);
    string str_b = to_string(b) + to_string(a);
    return str_a > str_b;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    if (numbers[0] == 0) {
        return "0";
    }
    for (int i = 0; i < numbers.size(); i++) {
        answer = answer + to_string(numbers[i]);
    }
    return answer;
}


/* 프로그래머스 고득점 kit - 정렬 - h index */
int solution1(vector<int> citations) {
    int answer = 0;
    int count = 0;
    sort(citations.begin(), citations.end());
    int size = citations.size();
    if (citations[size - 1] == 0)
        return 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (citations[j] >= answer) {
                count++;
            }
        }
        if (count > answer) {
            answer++;
            count = 0;
        }
        else {
            if (answer == count + 1)
                return answer - 1;
            return answer;
        }
    }
}

