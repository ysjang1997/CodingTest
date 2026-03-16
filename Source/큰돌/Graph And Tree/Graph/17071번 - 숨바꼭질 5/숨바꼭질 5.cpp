/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17071                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17071                          #+#        #+#      #+#    */
/*   Solved: 2026/03/15 07:59:43 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    수빈 n 동생 k
    수빈 -> 매턴 n + 1, n - 1, n * 2 이동
    동생 -> 매턴 t(t + 1)/2 만큼 이동  // 1, 2, 3, 4, 5

    Parity BFS, 시간 의존 BFS 문제 유형

    복기
     - 숨바꼭질 시리즈 벌써 3개째라 큰 흐름은 똑같아서 금방 이해함

     - 시간제한 0.25초에 동생이 계속 움직이는 점에서 이해를 못하고 해답을 봄

     - 동생은 계속 n(n + 1)/ 2 의 위치로 매턴 이동을 하는데 그러니까 이번 layer에서 찾아야 하는 값이
       계속 갱신되는데 시간제한 떄문에 매턴 새로 Bfs를 돌수도 없고 어떻게 하지..

     - 해답은 수빈이의 이동 n +1 n -1 를 이용해서 2턴에 한번씩 내가 방문했던 위치로 복귀가
       가능한 점을 이용해서 visited배열을 2개 만들어서 짝수턴 홀수턴의 방문을 기록해 두었다가
       동생의 위치 계산때 수빈이가 방문한 적이 있는지를 검사 물론 짝수턴 홀수턴에 맞춰서 검사
     
     - 이렇게 되면 visited 등록 만으로 수빈이의 과거 움직임의 저장을 할 수 있고 동생위치 갱신때
       방문 짝/홀수 턴에 맞는 visited 배열에서 방문여부를 확인 하는것으로 둘이 만날수 있다는 것을
       찾아낼 수 있음

     - 외 배열을 2개만드는 거지? 왜 짝수 홀수를 나누는 거지? 고민만하다가 일단 코드를 짯는데 짜면서 이해가 되었음.

     - 이게 문제를 처음 보자마자 해결 구조가 빡하고 떠오를 수가 있나? 솔직히 너무 어려움.

     - 그래도 실버나 골드 5급 정도 문제는 머리 박치기로 어느정도 해결이 되었는데 확실히 플레급 부터는
       문제 풀어본 경험이 좀 많이 필요한듯.


*/
#include <iostream>
#include <queue>

using namespace std;

int n, k;
int visited[2][500'001] = {};
const int max_size = 500000;

queue<int> q;
int turn;

int main()
{
    cin >> n >> k;

    q.push(n);
    visited[0][n] = 1;
    turn = 0;
    while (!q.empty())
    {
        int current_k = k + (turn * (turn + 1)) / 2;

        if (current_k > max_size)
        {
            cout << -1;
            return 0;
        }

        if (visited[turn % 2][current_k])
        {
            cout << turn;
            return 0;
        }

        turn++;
        int qsize = q.size();
        for (int i = 0; i < qsize; i++)
        {
            int current_n = q.front();
            q.pop();

            int arr[3] = {current_n + 1, current_n - 1, current_n * 2};
            for (int j = 0; j < 3; j++)
            {
                if (arr[j] < 0 || arr[j] > max_size)
                    continue;

                if (visited[turn % 2][arr[j]] == 1)
                    continue;

                visited[turn % 2][arr[j]] = 1;
                q.push(arr[j]);
            }
        }

        
    }

    return 0;
}