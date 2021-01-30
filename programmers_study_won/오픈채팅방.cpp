#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
string s[100000][3];
int len;
string findName(string id, int idx)
{
    for (int i = 0; i < idx; i++)
    {
        if (s[i][1] == id)
        {
            return s[i][2];
        }
    }
}
void changeName(string id, string name, int idx)
{
    for (int i = 0; i < idx; i++)
    {
        if (s[i][1] == id)
        {
            s[i][2] = name;
        }
    }
}
void checkName(string id, string name, int idx)
{
    for (int i = 0; i < idx; i++)
    {
        if (s[i][1] == id && s[i][2] != name)
        {
            s[i][2] = name;
        }
    }
}
vector<string> solution(vector<string> record)
{
    vector<string> answer;
    unordered_map<string, string> name;
    len = record.size();

    for (int i = 0; i < record.size(); i++)
    {
        string state = "";
        int k = 0;
        for (int j = 0; j < record[i].length(); j++)
        {
            if (record[i][j] == ' ')
            { 
                s[i][k] = state;
                state = "";
                ++k;
            }
            else
                state += record[i][j];

            if (j == record[i].length() - 1)
            {
                s[i][k] = state;
            }
        }
        if (s[i][0] == "Change")
        {
            name[s[i][1]] = s[i][2];
        }
        if (s[i][0] == "Enter")
        {
            name[s[i][1]] = s[i][2];
        }
    }

    for (int i = 0; i < len; i++)
    {
        string status = s[i][0];
        string id = s[i][1];

        if (status == "Enter")
            status = "들어왔습니다.";
        if (status == "Leave")
            status = "나갔습니다.";
        if (status != "Change")
            answer.push_back(name[id] + "님이 " + status);
    }
    return answer;
}