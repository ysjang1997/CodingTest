/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15686                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15686                          #+#        #+#      #+#    */
/*   Solved: 2026/03/02 01:10:56 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
    복기
     - 문제에서 최대 M개의 치킨집이라고 했는데 무조건 M개의 치킨집인가? 아니면 1~최대M개의 치킨집인가?
       내가 이해를 못하는건지 헷갈리게 써놔서 그냥 1~최대M개를 기준으로 품

     - 경우의 수를 모두 돌아봐야 하기 때문에 완전 탐색이고 치킨집탐색시 순서가 상관없기 때문에 재귀로 품

     - vector를 인자로 복사해서 넘기는방식으로 이전 계산을 넘겨 받을 수 있도록 함.

     다른 해결
     - 이번 문제를 전체적으로 이해를 못해서 헤딩하면서 풀었고 일단 푼다음 해설을 보고 알았음.

     - m개의 조합을 담는 구조로 재귀를 만들고 m개의 조합이 만들어지면 최소값을 뽑는 방식으로 할수 있음.
        -> 2중 for M : vector +  i < home.size() 형태로 만듬
        -> M개의 치킨집과 home을 비교하는거임

        -> 근데 또 순서가 중요한게 치킨집을 먼저하면 현재 치킨집과 비교된 모든 home을 저장하고
           다음 home 배열과 min검사를 해야함

           home을 먼저하고 치킨집들을 비교하면 현재 집에서 가장 가까운 치킨집을 찾고
           sum에 추가하며 이번 계산을 끝내버릴수 있음.

        -> 이 구조로 만들면 배열 복사도 안하고 함수 하나 호출로 끝내버릴수 있음.

        ## 다만 확실하게 M개의 조합을 기준으로 로직을 실행함 애매하게 1~M개 하면 또 다른 방법 생각해봐야함
           -> 생각해 봤는데 vector.size() > m 이면 return 하도록하고 매 함수 실행시 계산하도록 하면 될것같은데?


     이 밑은 GPT가 보여준 예시이고 강의랑 비슷한 구조를 가지고 있음
            -> push_back -> 함수 -> pop_back
        /========================================================================================/

        int result = 1e9;

        vector<pair<int, int>> home;
        vector<pair<int, int>> chome;
        vector<int> selected;

        void dfs(int start)
        {
            // 정확히 m개 선택했을 때만 계산
            if (selected.size() == m)
            {
                int sum = 0;

                for (int i = 0; i < home.size(); i++)
                {
                    int mindist = 1e9;

                    for (int idx : selected)
                    {
                        int dist = abs(home[i].first - chome[idx].first)
                                + abs(home[i].second - chome[idx].second);

                        mindist = min(mindist, dist);
                    }

                    sum += mindist;
                }

                result = min(result, sum);
                return;
            }

            // 조합 생성
            for (int i = start; i < chome.size(); i++)
            {
                selected.push_back(i);
                dfs(i + 1);
                selected.pop_back();
            }
        }
        
        int main()
        {
            cin >> n >> m;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int num;
                    cin >> num;

                    if (num == 1)
                        home.push_back({i, j});
                    else if (num == 2)
                        chome.push_back({i, j});
                }
            }

            dfs(0);

            cout << result;
            return 0;
        }
        /========================================================================================/
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, num;

vector<pair<int, int>> home;
vector<pair<int, int>> chome;

int minarr[51];
int result = 10001;

void solve(int index, int mcnt, vector<int> _v)
{
    int _result = 0;
    if (mcnt == 1)
    {
        for (int j = 0; j < home.size(); j++)
        {
            int sum = abs(chome[index].first - home[j].first) + abs(chome[index].second - home[j].second);
            _v.push_back(sum);
            _result += sum;
        }
    }
    else
    {
        for (int j = 0; j < _v.size(); j++)
        {
            int sum = abs(chome[index].first - home[j].first) + abs(chome[index].second - home[j].second);
            _v[j] = min(_v[j], sum);
            _result += _v[j];
        }
    }
    result = min(result, _result);

    if (mcnt == m)
        return;

    for (int i = index + 1; i < chome.size(); i++)
    {
        solve(i, mcnt + 1, _v);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            if (num == 1)
            {
                home.push_back({i, j});
                continue;
            }
            if (num == 2)
            {
                chome.push_back({i, j});
                continue;
            }
        }
    }

    for (int i = 0; i < chome.size(); i++)
    {
        vector<int> v;
        solve(i, 1, v);
    }

    cout << result;

    return 0;
}