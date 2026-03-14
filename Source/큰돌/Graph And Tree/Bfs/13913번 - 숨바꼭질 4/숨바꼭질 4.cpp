/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13913                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13913                          #+#        #+#      #+#    */
/*   Solved: 2026/03/15 03:41:17 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    최단거리 bfs , 경로저장 <- 이건 뭘로? stack?
    수행시간은 2초 깡으로 다돌면 시간초과

    Bfs 최단거리 찾기 + Previous 경로 저장 문제.

    복기
     - previous 활용해서 이전 경로 저장하기
        -> BFS 특성상 더 늦은 시간대의 경로의 값이 저장되는 일없음. prev배열로 직전값을 저장하면
           지금 까지 지나온 경로에 대해서 저장할 수 있음.

     - 출력을 while + stack으로 뒤집에서 저장하고 했는데
       for(int v = k; v != -1; v = previous[v]) 로 반복문으로 할 수 있음.
        -> 맨날 i++ 만쓰니까 이런 활용법에 대해서 까먹음.


*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, k;
int dist[100001] = {};
int previous[100001] = {};

queue<int> q;

int main()
{
    cin >> n >> k;

    q.push(n);
    dist[n] = 1;
    previous[n] = -1;
    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        if (num == k)
        {
            stack<int> results;
            results.push(num);
            int index = num;
            while (previous[index] != -1)
            {
                results.push(previous[index]);
                index = previous[index];           
            }

            cout << dist[num] - 1 << endl;
            while(!results.empty())
            {
                cout << results.top() << " ";
                results.pop();
            }
            return 0;
        }

        int arr[3] = {num + 1, num - 1, num * 2};
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] < 0 || arr[i] > 100'000)
                continue;

            if (!dist[arr[i]])
            {
                dist[arr[i]] = dist[num] + 1;
                previous[arr[i]] = num;
                q.push(arr[i]);
            }
        }
    }
}