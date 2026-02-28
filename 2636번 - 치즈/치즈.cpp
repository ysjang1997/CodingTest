/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2636                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2636                           #+#        #+#      #+#    */
/*   Solved: 2026/02/28 00:12:28 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
    1. 입력 받으면서 외곽을 바깥공기 세팅 (-1)

    2. Air순회 - 바깥 공기와 닿아있다면 -1 (Dfs) 

    3. arr순회 - cheese 카운팅, 녹게 될 치즈 melts에 추가

    4. 치즈가 남았는지?
        -> 없으면 turn 과 cheesecnt 출력
        -> 있으면 반복 turn++, cheesecnt 캐싱, melts순회로 치즈 녹이기 이후 2번으로

    복기
    - Dfs의 주체가 될 객체에 대해서 고민해보기 (꼭 0인 객체를 기준으로 돌았어여 하는가)
        -> 0부터 돌면 -1을 찾고 나를 바뀌야함
        -> 1부터 돌면 0을찾고 0을 -1로 바꾸고 계속 진행가능
    - visited는 탐색을 돌면서 이미 탐색한 객체를 체크하기 위해서 필요함
    - for문 작성시 오타좀 내지마 제발
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int h, w;
int arr[100][100] = {};
int visited[100][100] = {};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int cheeseresult = 0;
int turnresult = 0;

void AirDfs(int y, int x)
{
    visited[y][x] = 1;
    arr[y][x] = -1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w)
            continue;

        if (visited[ny][nx] == 1)
            continue;

        if (arr[ny][nx] == 0)
            AirDfs(ny, nx);
    }
}

bool isMelt(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w)
            continue;

        if (arr[ny][nx] == -1)
            return true;
    }

    return false;
}

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> arr[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
                arr[i][j] = -1;
        }
    }

    while (true)
    {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (arr[i][j] == -1 && visited[i][j] == 0)
                    AirDfs(i, j);
            }
        }

        vector<pair<int, int>> melts;
        int _cheesecnt = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (arr[i][j] == 1)
                {
                    if (isMelt(i, j))
                        melts.push_back({i, j});

                    _cheesecnt++;
                }
            }
        }

        if (_cheesecnt == 0)
            break;

        cheeseresult = _cheesecnt;
        turnresult++;

        for (auto &melt : melts)
        {
            arr[melt.first][melt.second] = -1;
        }
    }

    cout << turnresult << endl;
    cout << cheeseresult;

    return 0;
}