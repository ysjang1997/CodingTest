/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2468                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2468                           #+#        #+#      #+#    */
/*   Solved: 2026/02/19 18:49:42 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[100][100] = {};
int visited[100][100] = {};
int result = 0;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int loopmin, loopmax = 1;

void Dfs(int y, int x, int condition)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;

        if (visited[ny][nx] == 1)
            continue;

        if (arr[ny][nx] <= condition)
            continue;

        Dfs(ny, nx, condition);
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            scanf("%d", &num);
            arr[i][j] = num;
            loopmax = max(loopmax, num);
        }
    }

    for (int k = loopmin; k < loopmax; k++)
    {
        int count = 0;
        memset(visited, 0, sizeof(visited));

        for (int h = 0; h < n; h++)
        {
            for (int w = 0; w < n; w++)
            {
                if (visited[h][w] == 1)
                    continue;

                if (arr[h][w] <= k)
                    continue;

                Dfs(h, w, k);
                count++;
            }
        }

        result = max(result, count);
    }

    cout << result;

    return 0;
}