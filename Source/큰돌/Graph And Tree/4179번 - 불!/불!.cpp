/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4179                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4179                           #+#        #+#      #+#    */
/*   Solved: 2026/03/03 02:21:23 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
    불을 확산시키고 확산된 위치를 저장하고 아직 확산이 일어나지 않은 애들만 다시하는방식?

    탈출시도 -> 불확산 반복
    queue로 이번 턴의 탈출 경우의 수 저장 + 턴카운트

    모든 경우의 수가 탈출 불가능 = impossible;
    탈출한 경우의 수가 있으면 = result;

    복기
     - 사람 1턴 불1턴의 턴 개념이 있는 문제였고, 매 턴 서로의 경우의 수를 비교해가면서 풀어야 했음.

     - 초기 경우의 수를 미리 저장하고, 턴을 진행 -> 다음 턴에 진행할수 있는 경우의 수를 저장.
        -> 경우의 수는 vector로 저장하고 (순회가 빨라서) 이 vector를 que에 저장
           매턴 que에 들어있는 vector를 꺼내고 새로운 vector를 넣어주고
           꺼낸 vector를 순회 (이번 턴의 경우의 수 진행)

     - 사람이 이미 지나간 자리거나 불이 이미 번진 자리는 중복으로 검사를 할 필요가 없으므로 위 방식으로 구현
       -> 내 주변 상호작용 (움직이거나, 불번짐) 후 우효하면 다음 턴 행동목록에 추가 반복

     - 사람이 이번에 수행할 행동 목록이 없거나, 이미 외곽에 도착을 했으면 종료.
     
     - 턴 개념 문제는 처음 풀어봤는데 이런 구조가 처음에 이해가 안되서 일단 불번짐 함수 먼저 만들었는데
       만들다가 갑자기 깨달음.. 이미 진행한 자리는 또 할 필요없지않나? 그럼 매번 모든 배열을 검사할
       필요도 없고 그럼 진행 상황을 저장하고 다음 턴에 이 부분에 대해서만 수행하고 이걸 반복하면
       될거 같은데? -> 해결

     - 다른 사람들 문제 풀이가 궁금해서 찾아보니 대부분 구조는 비슷했음 다만 수행시간 차이가 있었는데

       BFS로 불의 도착 시간을 먼저 계산하고 사람을 계산해서 그 도착시간과 비교해서 갈수 있는지 없는지
       판단하는 방법.

       또는 상태저장을 하는 구조체를 만들어서(위치, 속성) 하나의 que로 반복하는방법.

       나는 vector를 만들고 그걸 que에 넣고 복사도하고 함수 호출도하고 해서 오래걸림 만약 다음에 다시
       한다면 2번 방법으로 할 것 같음.

     - 함수 호출도 비용이기 때문에 main에서 if분기로 처리하는게 더빠른듯? 다른 사람들도 최대한 함수를
       사용 안하는거같음 다들 if처리 많이함
         




*/
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int r, c;
char arr[1001][1001] = {};
int visited[1001][1001] = {};
int firevisited[1001][1001] = {};

queue<vector<pair<int, int>>> fireqv;
queue<vector<pair<int, int>>> moveqv;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool flag = false;

int result = 0;
string impossible = "IMPOSSIBLE";

void Fire(int y, int x)
{
    firevisited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c || firevisited[ny][nx] == 1)
            continue;

        if (arr[ny][nx] == '.' || arr[ny][nx] == 'J')
        {
            arr[ny][nx] = 'F';
            fireqv.front().push_back({ny, nx});
        }
    }
}

void Move(int y, int x)
{
    if (arr[y][x] == 'F')
        return;

    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
        {
            flag = true;
            return;
        }

        if (arr[ny][nx] == '.')
        {
            moveqv.front().push_back({ny, nx});
        }
    }
}

int main()
{

    vector<pair<int, int>> startfirev;
    vector<pair<int, int>> startmovev;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'F')
                startfirev.push_back({i, j});

            if (arr[i][j] == 'J')
                startmovev.push_back({i, j});
        }
    }
    fireqv.push(startfirev);
    moveqv.push(startmovev);

    while (true)
    {

        result++;
        if (!moveqv.empty())
        {
            auto turnmovev = moveqv.front();
            moveqv.pop();

            vector<pair<int, int>> _movev;
            moveqv.push(_movev);

            for (auto &_pair : turnmovev)
            {
                if (visited[_pair.first][_pair.second] == 0)
                    Move(_pair.first, _pair.second);
            }
        }

        if (flag || moveqv.front().empty())
            break;

        if (!fireqv.empty())
        {
            auto turnfirev = fireqv.front();
            fireqv.pop();

            vector<pair<int, int>> _firev;
            fireqv.push(_firev);

            for (auto &_pair : turnfirev)
            {
                Fire(_pair.first, _pair.second);
            }
        }
    }

    if (flag)
        cout << result;
    else
        cout << impossible;

    return 0;
}