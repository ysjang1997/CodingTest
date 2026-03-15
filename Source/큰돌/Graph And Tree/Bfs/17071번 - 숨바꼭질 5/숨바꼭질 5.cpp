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