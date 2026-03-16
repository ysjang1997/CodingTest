/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3197                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3197                           #+#        #+#      #+#    */
/*   Solved: 2026/03/17 01:22:05 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    2차원 배열
    두 백조가 만날수 있는가?
    매턴 물에 닿아있는 얼음이 녹는다.

    1. 백조 만날수 있는가?
    2. 얼음을 녹인다.
    3. 다음턴으로

    1초에 1500 1500 크기면 2250000 한번 순회는 크기 않음 단 매번 반복을 한다면 클거같음
    que에 얼음 담아서 검사
        -> 녹일수 있으면 녹임
        -> 녹일수 없으면 다시 q에 넣음
    턴동기화를 해야하는데 언제 녹은 얼음인지를 따로 체크해서 이번턴에 얼음에 닿았는지 같은걸 검사해야할듯?
    이유는 que의 자료구조를 택했는데 지금 이걸녹이면 다음 녹일 같은턴의 얼음에 영향이 가기 때문에
    ㄱㄱ

    복기
     - 시간초과 2번남
        -> 백조를 매번 새로 경로탐색 -> 중복 경로 탐색
        -> 모든얼음을 q에 녹으면 제거 아니면 다시 q에넣음 -> 이것 역시 중복탐색

     - 그래서 현재 유효한 동작을 할수 있는 대상들만 q로 넣음
        -> 백조는 경로탐색하다 얼음에 막히면 그때 q에 넣고 다음턴에 이어서 동작
        -> 얼음도 현재 녹을 수 있는 얼음만 q에 집어넣고 동작

     - 시간 문제는 해결했지만 자꾸 틀렸다고나옴
        -> 처음 값을 받을때 하나 받을때마다 얼음이면 dydx검사 녹을 수있는가?
        -> 근데 이게 문제였음 아직 맵이 완성이 안되었는데 물이있는지를 검사해서 물값이 들어오기 전에
           검사를 해버리니 물이 없다고 나오는거임 여기서 얼음que가 잘못만들어져서 틀림.

     - 다른 사람과 비교를 해보니 나는 얼음과 백조를 관리했고 다른사람은 물과 백조를 관리했음.
       동작 시간은 크게 차이가 없었지만 메모리 크기가 2배가 차이남.

     - 애초에 얼음을 넣으려니 배열이 완성되고 얼음 체크를 한번더 했었는데 물을 기준으로 얼음을 녹이면 한번에 가능

     - 또 결국은 얼음을 초기세팅에 넣었지만 이후 while에서의 로직을 보면 물처럼 동작한다는걸 알수있음
        -> 얼음을 물로 바꾸고 - 내 주변 dydx검사 - 얼음? - 다음턴 녹을q에 추가

    - 또 다른사람은 동작속도가 2배정도 빠른데 재귀를 타지않고 오늘과 내일이라는 que 2개로 관리해서 Bfs함.
      -> 이것도 좀 익숙해 져야할듯

     - 동작이 될 대상에 대해서 잘 생각해보고 설계하는 능력이 필요할듯.

     - 그래도 문제의 흐름은 잘 잡고 해결함. 삽질로 시간을 좀 박음;;;

*/
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int row, cul;

char arr[1501][1501] = {};

queue<pair<int, int>> iceq;
queue<pair<int, int>> q;

int visited[1501][1501] = {};
int visitedice[1501][1501] = {};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

pair<int, int> start;
int result = 0;
bool flag = false;

void Dfs(int y, int x)
{
    for (int j = 0; j < 4; j++)
    {
        if (flag)
            return;

        int ny = y + dy[j];
        int nx = x + dx[j];

        if (ny < 0 || ny >= row || nx < 0 || nx >= cul || visited[ny][nx] == 1)
            continue;

        visited[ny][nx] = 1;
        if (arr[ny][nx] == 'L')
        {
            flag = true;
            return;
        }

        if (arr[ny][nx] == 'X')
        {
            q.push({ny, nx});
            continue;
        }

        if (arr[ny][nx] == '.')
        {
            Dfs(ny, nx);
        }
    }
}

void MeltCheck(int y, int x)
{
    for (int j = 0; j < 4; j++)
    {
        int ny = y + dy[j];
        int nx = x + dx[j];

        if (ny < 0 || ny >= row || nx < 0 || nx >= cul)
            continue;

        if (arr[ny][nx] == '.' || arr[ny][nx] == 'L')
        {
            visitedice[y][x] = 1;
            iceq.push({y, x});
            break;
        }
    }
}
int main()
{
    cin >> row >> cul;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cul; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'X')
                iceq.push({i, j});

            if (arr[i][j] == 'L')
                start = {i, j};
        }
    }

    int initsize = iceq.size();
    for (int i = 0; i < initsize; i++)
    {
        pair<int, int> icepair = iceq.front();
        iceq.pop();
        MeltCheck(icepair.first, icepair.second);
    }

    q.push(start);
    visited[start.first][start.second] = 1;

    while (true)
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            pair<int, int> _pair = q.front();
            q.pop();

            Dfs(_pair.first, _pair.second);
            if (flag)
            {
                cout << result;
                return 0;
            }
        }

        result++;
        int iceqsize = iceq.size();
        for (int i = 0; i < iceqsize; i++)
        {
            pair<int, int> _ice = iceq.front();
            iceq.pop();
            arr[_ice.first][_ice.second] = '.';

            for (int j = 0; j < 4; j++)
            {
                int ny = _ice.first + dy[j];
                int nx = _ice.second + dx[j];

                if (ny < 0 || ny >= row || nx < 0 || nx >= cul)
                    continue;

                if (arr[ny][nx] == 'X' && visitedice[ny][nx] == 0)
                {
                    visitedice[ny][nx] = 1;
                    iceq.push({ny, nx});
                }
            }
        }
    }
}