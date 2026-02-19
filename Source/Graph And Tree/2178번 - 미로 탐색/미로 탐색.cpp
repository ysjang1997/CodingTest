/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2178                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2178                           #+#        #+#      #+#    */
/*   Solved: 2026/02/19 14:43:52 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

using namespace std;

const int maxsize = 104;

int n, m;

int arr[maxsize][maxsize] = {};
int visited[maxsize][maxsize] = {};
queue<pair<int, int>> q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Bfs()
{
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] == 0)
            continue;

        if (visited[ny][nx] != 0)
            continue;

        q.push({ny, nx});
        visited[ny][nx] = visited[y][x] + 1;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            scanf("%1d", &num);
            arr[i][j] = num;
        }
    }

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty())
    {
        Bfs();
    }

    cout << visited[n-1][m-1];

    return 0;
}