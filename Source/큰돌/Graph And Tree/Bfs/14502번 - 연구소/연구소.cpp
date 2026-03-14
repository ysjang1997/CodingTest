/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14502                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14502                          #+#        #+#      #+#    */
/*   Solved: 2026/02/27 22:06:03 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
    1. 벽을 3개 세우기
    2. 바이러스 퍼트리기
    3. 안전범위 리턴 + max()로 필터링

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int wall = 3;
int arr[8][8] = {};
int copyarr[8][8] = {};

int visited[8][8] = {};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<pair<int, int>> canwall;
int result = 0;

void Dfs(int y, int x)
{

    visited[y][x] = 1;
    copyarr[y][x] = 2;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (visited[ny][nx] == 1)
            continue;

        if (copyarr[ny][nx] == 0)
            Dfs(ny, nx);
    }
}

int check()
{
    copy(&arr[0][0], &arr[0][0] + (sizeof(arr) / sizeof(arr[0][0])), &copyarr[0][0]);
    memset(visited, 0, sizeof(visited));
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && copyarr[i][j] == 2)
                Dfs(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (copyarr[i][j] == 0)
                result++;
        }
    }

    return result;
}

int main()
{
    memset(arr, -1, sizeof(arr));

    cin >> n >> m;
    for (int height = 0; height < n; height++)
    {
        for (int width = 0; width < m; width++)
        {
            cin >> arr[height][width];

            if (arr[height][width] == 0)
                canwall.push_back({height, width});
        }
    }

    for (int i = 0; i < (int)canwall.size() - 2; i++)
    {
        for (int j = i + 1; j < (int)canwall.size() - 1; j++)
        {
            for (int k = j + 1; k < (int)canwall.size(); k++)
            {
                arr[canwall[i].first][canwall[i].second] = 1;
                arr[canwall[j].first][canwall[j].second] = 1;
                arr[canwall[k].first][canwall[k].second] = 1;
                result = max(result, check());
                arr[canwall[i].first][canwall[i].second] = 0;
                arr[canwall[j].first][canwall[j].second] = 0;
                arr[canwall[k].first][canwall[k].second] = 0;
            }
        }
    }

    cout << result;

    return 0;
}