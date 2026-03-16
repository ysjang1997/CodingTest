/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16234                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16234                          #+#        #+#      #+#    */
/*   Solved: 2026/03/02 23:18:04 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    탐색, 저장, 갱신 -> 반복으로 카운팅
     - 갱신이 일어났다면 result++ 하고 반복

     Dfs + CC끼리 인접리스트로 저장 -> 데이터 갱신 -> result++

     복기
      - 전체적인 로직은 생각한대로 동작함.

      - 또 또 또 cin 입력 받을때 >> 가 아니라 ,찍고 삽질함 생각좀하자

      - visited가 이미 방문여부를 알고있으니 꼭 모든 순회를돌고 CC로 저장하고 있다가
        마지막에 변경하는 것이 아닌 이번 정점의 Dfs를 돌고 바로 갱신하고 날려고 문제가 없었음.

      - bool 체크가 필요한때 hasunion이 아닌 flag로 변수명 생각하기.

      - while 돌면서 flag를 false로 안돌려줘서 시간삽질함.

      - flag를 Dfs에서 인접한 arr인덱스로 이동이 가능한지 가능하면 true로 했는데
        이번 Dfs를 돌고 저장된 pairv의 size가 1보다 큰지를 체크하면 좀더 단축할수있음.
        
      - 위 문장에 추가로 pairv도 size가 1이면 굳이 나누기 연산을 통한 인구분배를 안해도 됐음.
      

      - 조금 손볼 부분이 있지만 생각했던 이상적인 동작구조에 근접했기에 나름 만족한 문제.




*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, l, r, num;
int arr[51][51] = {};
int visited[51][51] = {};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool hasunion = false;
int sum;
vector<pair<int, int>> pairv;

int result = 0;

void Dfs(int y, int x)
{
    visited[y][x] = 1;
    pairv.push_back({y, x});
    sum += arr[y][x];

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] == 1)
            continue;

        int diff = abs(arr[y][x] - arr[ny][nx]);
        if (l <= diff && r >= diff)
        {
            hasunion = true;
            Dfs(ny, nx);
        }
    }
}

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }

    while (true)
    {
        memset(visited, 0, sizeof(visited));
        hasunion = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 1)
                    continue;

                pairv.clear();
                sum = 0;
                Dfs(i, j);

                for (pair<int, int> &_pair : pairv)
                {
                    arr[_pair.first][_pair.second] = sum / pairv.size();
                }
            }
        }

        if (!hasunion)
            break;

        result++;
    }

    cout << result;

    return 0;
}
