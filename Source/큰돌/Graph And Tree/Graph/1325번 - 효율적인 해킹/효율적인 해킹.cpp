/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1325                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1325                           #+#        #+#      #+#    */
/*   Solved: 2026/03/01 00:22:28 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*

    이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, 
    A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.

    - B를 부모노드로 A를 자식노드로 생각할 수 있음 (역방향 그래프).

    복기
     - 인덱스의 범위를 잘 생각해야함 
        -> 문제에서 말하는 N은 배열의 index의 값임 그러니까 직접 접근할 필요가 있는 인덱스라
           tree배열의 범위를 인덱스보다 크게 잡아야함.

        -> tree배열 순회 돌때도 마찬가지 인덱스의 값까지 돌아야 하기 때문에 < 가 아닌 <= 또는 + 1

        -> A->B, B->A의 구조가 나올수 있기 때문에 visited 체크 안하면 무한루프

        -> SCC? 로 O(N+M)까지 줄일 수 있다고함. (중복된 순회를 하나로 합쳐두기)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int a, b;
int maxcnt = 0;
vector<int> v[10001];
vector<int> results;

int visited[10001] = {};

bool compare(int a, int b)
{
    return a < b;
}

int Dfs(int index)
{
    visited[index] = 1;

    int result = 1;
    for (int &node : v[index])
    {
        if (visited[node] == 1)
            continue;

        result += Dfs(node);
    }
    return result;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 0; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        int ret = Dfs(i);
        if (ret > maxcnt)
        {
            results.clear();
            results.push_back(i);
            maxcnt = ret;
        }
        else if (ret == maxcnt)
        {
            results.push_back(i);
        }
    }

    sort(results.begin(), results.end(), compare);

    for (int &result : results)
    {
        cout << result << " ";
    }

    return 0;
}