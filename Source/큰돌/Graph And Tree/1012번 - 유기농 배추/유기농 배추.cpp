/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1012                           #+#        #+#      #+#    */
/*   Solved: 2026/02/19 15:56:28 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int t;

int arr[50][50] = {};
vector<int> results;
int visited[50][50] = {};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, indexcnt;

void Dfs(int height, int width)
{
    visited[height][width] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = height + dy[i];
        int nx = width + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n || arr[ny][nx] == 0)
            continue;

        if (visited[ny][nx] == 1)
            continue;

        Dfs(ny, nx);
    }
}

int main()
{

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        n = m = indexcnt = 0;

        scanf("%d %d %d", &m, &n, &indexcnt);
        for (int j = 0; j < indexcnt; j++)
        {
            int y, x;
            scanf("%d %d", &y, &x);
            arr[y][x] = 1;
        }

        int count = 0;
        for (int h = 0; h < m; h++)
        {
            for (int w = 0; w < n; w++)
            {
                if (arr[h][w] == 0)
                    continue;

                if (visited[h][w] == 1)
                    continue;

                Dfs(h, w);
                count++;
            }
        }

        results.push_back(count);
    }

    for (int &result : results)
    {
        cout << result << endl;
    }

    return 0;
}
