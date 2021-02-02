#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

/*
해설이랑 비슷하게 적은 것 같은데 효율성 못 통과하는 건 왜일까.

일단 근데 문제 자체가 어려워서.... 뭔가 싶다.
이진탐색도 일반적으로 구현하는 이진탐색이 아니라 upper_bound, lowr_bound 쓰고있네.
iterator 쓰는 것도 왜 저래야 하는지 아직 모른다.

replaceAll부분도 뭔가.. 복잡함.
... 그냥 총체적으로 ㅋㅋ 난국인 문제였다. 혼자 못푼다.
올려두는 것일 뿐.

답답.
*/

//길이에 맞는 걸 넣고 있습니다.
vector<string> vec[10001];
vector<string> cev[10001];

int countByRange(vector<string> v, string left, string right) {
    vector<string>::iterator rightIndex = upper_bound(v.begin(), v.end(), right);
    vector<string>::iterator leftIndex = lower_bound(v.begin(), v.end(), left);
    return rightIndex - leftIndex;
}

string replaceAll(string str, string from, string to) {
    string res = str;
    int pos = 0;
    while ((pos = res.find(from, pos)) != string::npos)
    {
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (int i = 0; i < words.size(); i++) {
        int len = words[i].length();
        vec[len].push_back(words[i]);

        reverse(words[i].begin(), words[i].end());
        /*string reverse = "";
        cout<<len<<endl;
        for (int j = 0; j < len; j++) {
            reverse += words[i][len - 1 - j];
        }
        cout<<reverse<<endl;*/
        cev[len].push_back(words[i]);
    }

    for (int i = 0; i < 10001; i++) {
        if (vec[i].size() == 0) continue;
        sort(vec[i].begin(), vec[i].end());
        sort(cev[i].begin(), cev[i].end());
    }

    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        int len = query.length();

        int cnt = 0;
        
        if (query[len-1] == '?') { //접미사에 있다.
            vec[len];//여기서 찾아본다.
            cnt = countByRange(vec[len], replaceAll(query, "?", "a"), replaceAll(query, "?", "z"));
        }
        else { //접두사에 있다.
            cev[len];

            reverse(query.begin(), query.end());
            cnt = countByRange(cev[len], replaceAll(query, "?", "a"), replaceAll(query, "?", "z"));

        }
        answer.push_back(cnt);
    }

    return answer;
}
