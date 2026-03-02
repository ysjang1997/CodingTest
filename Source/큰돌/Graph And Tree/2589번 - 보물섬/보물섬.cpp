/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2589                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2589                           #+#        #+#      #+#    */
/*   Solved: 2026/03/02 20:37:22 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    이 지도에서 이동은 상하좌우로 이웃한 육지로만 가능하며, 한 칸 이동하는데 한 시간이 걸린다.
    보물이 묻혀 있는 두 곳 간의 최단 거리로 이동하는 시간을 구하는 프로그램을 작성하시오.
        -> 같은 가중치 + 최단거리 = BFS

    보물이 어디 묻혀있다는거지?
     - 보물은 서로 간에 최단 거리로 이동하는데 있어
       가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다.

    복기
     - Bfs는 que를 사용해서 구현하는데 구현 로직이 기억이 안나서 한번 참고함
     - visited를 단순 방문이 아닌 방문 + 거리를 측정하는 용도로 사용
     - L만 방문해야하는데 맵순회 시작때 W필터를 안해서 한번 틀림 (기저사항 확인) 
     - 문제를 잘 읽어야함 처음에 보물이 어디에서 시작하는지를 찾느라 시간소요.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int h, w;
char c;

int arr[51][51];
int visited[51][51];
queue<pair<int, int>> q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int result = 0;

void Bfs()
{
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    result = max(result, visited[y][x]);

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w || visited[ny][nx] != -1)
            continue;

        if (arr[ny][nx] == 1)
        {
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
}

int main()
{
    memset(arr, -1, sizeof(arr));

    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> c;
            if (c == 'L')
                arr[i][j] = 1;
            if (c == 'W')
                arr[i][j] = 0;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] == 0)
                continue;

            memset(visited, -1, sizeof(visited));

            q.push({i, j});
            visited[i][j] = 0;
            while (!q.empty())
            {
                Bfs();
            }
        }
    }
    cout << result;

    return 0;
}