/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2583                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2583                           #+#        #+#      #+#    */
/*   Solved: 2026/02/19 20:01:33 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100][100] = {};
int visited[100][100] = {};
vector<int> results;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int m, n, k;

bool compare(int a, int b)
{
    return a < b;
}

int Dfs(int y, int x)
{
    visited[y][x] = 1;
    int sum = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n)
            continue;

        if (arr[ny][nx] != 0)
            continue;

        if (visited[ny][nx] == 1)
            continue;

        sum += Dfs(ny, nx);
    }

    return sum;
}

int main()
{
    scanf("%d %d %d", &m, &n, &k);
    for (int num = 0; num < k; num++)
    {
        pair<int, int> start, end;
        scanf("%d %d %d %d", &start.first, &start.second, &end.first, &end.second);

        for (int i = start.second; i < end.second; i++)
        {
            for (int j = start.first; j < end.first; j++)
            {
                arr[i][j]++;
            }
        }
    }

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (arr[y][x] != 0)
                continue;

            if (visited[y][x] == 1)
                continue;

            results.push_back(Dfs(y, x));
        }
    }

    sort(results.begin(), results.end(), compare);

    cout << results.size() << endl;
    for (int &result : results)
    {
        cout << result << " ";
    }

    return 0;
}