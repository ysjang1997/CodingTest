/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14497                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14497                          #+#        #+#      #+#    */
/*   Solved: 2026/03/16 04:50:07 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    n * m
    4방향
    한 번의 점프는 한 겹의 친구들을 쓰러뜨린다. 다음의 예를 보자.
     -> 장애물에 막힘없이 주난에게 도달이 가능한가?

     1. 재귀
     - 주난입장에서의 경로탐색
        -> Dfs로 1만나면 캐싱하고 넘기기 파동이 퍼저나가면서 만날수있는 모든 1을 검사?

     - 각각 요소들 입장에서의 경로 탐색
       -> 각 요소별로 주난에게 도달할수 있는가?
       -> XXX 매 요소마다 중복연산 너무많이 함 비효율적

     2. que
        -> 1과 도둑놈을 q에 저장하고 매 요소마다 경로탐색
        -> XXX 매 요소마다 중복연산 너무많이 함 비효율적

    1번 주난 입장에서의 탐색이 맞는거같음

    복기
     - 오랜만에 쉬운문제 생각한대로 금방 풀었음.

     - visited랑 del이라는 이번 턴의 삭제등록을 했는지를 체크하는 배열을 따로 했었는데
       생각해보니 이미 visited에서 방문을 체크했으니 추가로 삭제 등록은 안 할거라 del 제거

     - 다른 사람이랑 코드 비교를 해봤는데 함수로 재귀를 도느냐 que로 반복을 하느냐의 차이
       물론 함수 재귀는 함수호출도 비용이기 때문에 실행시간이 좀더 늦게 나옴. 다만 문제를
       해결하는데 있어서는 크게 차이나지 않았음


*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
pair<int, int> start, target;

char arr[301][301] = {};
int visited[301][301] = {};
vector<pair<int, int>> delv;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int result = 0;

void Dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == 1)
            continue;

        if (arr[ny][nx] == '1' || arr[ny][nx] == '#')
        {
            delv.push_back({ny, nx});
            continue;
        }
        if (arr[ny][nx] == '0')
            Dfs(ny, nx);
    }
}

int main()
{
    cin >> n >> m;
    cin >> start.first >> start.second >> target.first >> target.second;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (arr[target.first - 1][target.second - 1] != '0')
    {
        memset(visited, 0, sizeof(visited));
        Dfs(start.first - 1, start.second - 1);

        for (pair<int, int> &_pair : delv)
        {
            arr[_pair.first][_pair.second] = '0';
        }
        delv.clear();
        result++;
    }

    cout << result;

    return 0;
}