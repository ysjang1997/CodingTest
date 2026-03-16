/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12851                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12851                          #+#        #+#      #+#    */
/*   Solved: 2026/03/09 22:33:46 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지
        -> 최단거리 Bfs
    가장 빠른 시간으로 찾는 방법이 몇 가지 인지
        -> 최단거리 layer의 갯수를 말하는듯

    한번 돌때 3개의 경우의 수를 가진 트리의 구조?

    Bfs니까 que로 시도

    복기
     - 무조건 다시 한번 풀어보기 깡으로

     - 최단경로의 갯수를 찾는 문제인데 천천히 길게 풀면 풀리긴했음 근데 더 깔끔하고 알고리즘
       의 성질을 이용해서 풀지 못했음.

     - 왜 첫방문만 검사하면 되는가?
        -> Bfs의 첫방문은 무조건 최단거리가 나온다. 계층별로 탐색을 진행하기에
    
     - 왜 같은 계층의 같은 경우의 수를 만나면 ++ 이 아니고 +=하는가? (이해필요)
        -> 나와 다른길로 와서 같은 계층 같은수로 만났다면 그것들 또한 방법의 수라서

     - Bfs할때 제발 que에 넣기전에 검사및 갱신하기 매번 이거때문에 꼬임
        -> 검사 -> 방문체크,각종 정보갱신 -> push

     - 해설을 보고도 이해 못한 문제 꼭 다시 풀어볼것. 2번써놨음 나중에 풀어볼 문제에도 추가했음.

*/
#include <iostream>
#include <queue>

using namespace std;

const int max_size = 100000;
int n, k;
queue<int> q;
int dist[100001] = {};
int cnt[100001] = {};

int main()
{
    cin >> n >> k;

    q.push(n);
    dist[n] = 1;
    cnt[n] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int arr[3] = {cur + 1, cur - 1, cur * 2};
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] < 0 || arr[i] > max_size)
                continue;

            if(!dist[arr[i]])
            {
                dist[arr[i]] = dist[cur] + 1;
                cnt[arr[i]] = cnt[cur];
                q.push(arr[i]);
            }
            else if(dist[arr[i]] == dist[cur] + 1)
            {
                 cnt[arr[i]] += cnt[cur];
            }
        }
    }

    cout << dist[k] - 1 << '\n' << cnt[k];

    return 0;
}