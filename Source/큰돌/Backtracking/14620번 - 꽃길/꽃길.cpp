/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14620                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14620                          #+#        #+#      #+#    */
/*   Solved: 2026/03/21 13:38:00 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    2차원 맵 + 각 위치에는 가격이 있음
    dydx검사 필요
    순회하며 최소치를 묻는 문제
    꽃을 심을수 있는건 1,1 ~ 10,10 배열은 0~10이 필요 (화단 밖으로 나가는 거 검사)
    0~9 까지로 하고 밖으로 나가는건 로직으로 처리

    - 현재 위치에 꽃잎을 심을수 있는가? 가로세로 검사
    - 3개의 꽃을 심을때까지 반복 + 완료시 값을 내는 로직
    - 전체 구조는 백트래킹의 형식

    ㄱㄱ

    복기
     - 몇번 풀어본 유형의 문제 쉬웠음. 전체 로직도 생각한 대로 동작함

     - 다만 인덱스 매핑해놓고 범위 생각을 잘못함. 꽃을 심을수 있는 위치는 1 ~ n-1인데
       매핑된 범위를 n-1 * n-1 로 함

       만약 n = 10 라면 1,1 ~ 최대 9,9 까지 심을수 있는건데 저 범위대로면
       81까지밖에 동작안함 9,9는 매핑하면 88이 나옴 (0~9일때)

     - 이전 문제인 사다리 구조를 풀면서 해딩했던게 도움이 컸음.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10][10] = {};
int visited[10][10] = {};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int curmoney;
int result = 9999'9999;

bool check(int y, int x)
{
    if (y < 1 || y > n - 1 || x < 1 || x > n - 1 || visited[y][x] == 1)
        return false;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] == 1)
            return false;
    }

    return true;
}

void solve(int index, int depth)
{
    int y = index / (n - 1);
    int x = index % (n - 1);
    if (!check(y, x))
        return;

    visited[y][x] = 1;
    curmoney += arr[y][x];
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        visited[ny][nx] = 1;
        curmoney += arr[ny][nx];
    }

    if (depth == 3)
    {
        result = min(curmoney, result);
    }
    else
    {
        for (int i = index + 1; i <= n * n; i++)
        {
            solve(i, depth + 1);
        }
    }

    visited[y][x] = 0;
    curmoney -= arr[y][x];
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        visited[ny][nx] = 0;
        curmoney -= arr[ny][nx];
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = (n - 1) + 1; i < n * n; i++)
        solve(i, 1);

    cout << result;

    return 0;
}