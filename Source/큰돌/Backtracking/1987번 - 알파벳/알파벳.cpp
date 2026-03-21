/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1987                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1987                           #+#        #+#      #+#    */
/*   Solved: 2026/03/17 09:41:45 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    2차원 배열의 맵
    한번 만났던 알파뱃으로는 다시 진행 불가
    최대한 많이 나아갔던 진행도 출력

    Dfs + 백트래킹

    visited는 A - A = 0 이라는 점을 이용해서 알파뱃 자체를 인덱스화 시킬수있음.
    dydx도 이미 이전에 지나온 알파뱃을 저장하고 있기때문에 중복 방문할 일이 없음.

    복기
     - 너무 깔끔하게 생각했던 방법으로 해결됨.

     - 자만하면 안돼는데 알파뱃을 -'A'를 이용해 인덱스화 시킨다는 발상을 했다는게 성장한느낌이듬


*/
#include <iostream>

using namespace std;

int row, cul;
char arr[21][21] = {};
int visited[26] = {};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int result = 0;
int cnt = 0;

void solve(int y, int x)
{
    visited[arr[y][x] - 'A'] = 1;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= row || nx < 0 || nx >= cul || visited[arr[ny][nx] - 'A'] == 1)
            continue;

        solve(ny, nx);
    }
    result = max(result, cnt);
    visited[arr[y][x] - 'A'] = 0;
    cnt--;
}

int main()
{
    cin >> row >> cul;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cul; j++)
        {
            cin >> arr[i][j];
        }
    }
    solve(0, 0);
    cout << result;

    return 0;
}