/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12869                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12869                          #+#        #+#      #+#    */
/*   Solved: 2026/03/03 06:18:46 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
    뮤탈의 공격 경우의 수 = 순열
    scv를 모두 파괴하는 경우의 수 중 가장 짧은 공격 횟수 = 탐색 + Bfs(최단거리)
    
    복기
     - 뮤탈 공격 경우의 수가 3! 이라서 배열에 수작업 범위가 크면 백트래킹을 통해 찾아야함.
        -> 무식하게 할 수 있다면 무식하게 하라는 이유 알거같음. 처음에 백트래킹으로 순열을
           찾으려 했는데 실제 코테가서 그러면 순열 구한다고 시간 다쓸거같음.

     - 매 번 dy dx 문제만 풀다가 순열의 경우의 수를 만나니 생각을 못했음. 같은 결이라는걸 깨달아야함.
     
     - 방문 체크또한 마찬가지 na nb nc 만들어서 집어넣기만 하면 될줄 알았지만
       이번 while에서 만들어진 중복이 생길수도 있었음 A 루트 B루트 C루트 타고 가면서 
       서로 다른 경우의 수 만들어 내지만 그 과정에서 중복되는 경우의 수가 발생 할 수 있고
       이 문제로 인해서 중복된 값이 que에 들어가고 메모리 초과 발생.

     - 알고리즘은 같지만 데이터의 구조가 달라진 경우를 처음 마주한 문제. 좀더 열린 사고방식이 필요할듯.

     - Bfs 면 방문 거리를 visited에 저장하는 습관도 제발 들이자 또 까먹음.

*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
    int a;
    int b;
    int c;
    int layer;
};

int n, input;
int scv[3] = {0, 0, 0};
int permutation[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};
int visited[61][61][61] = {};

Node node;
queue<Node> q;
int result = 99999999;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> scv[i];
    }
    node.a = scv[0];
    node.b = scv[1];
    node.c = scv[2];
    node.layer = 0;

    q.push(node);
    visited[node.a][node.b][node.c] = 1;

    while (!q.empty())
    {
        Node curnode = q.front();
        q.pop();

        if (curnode.a == 0 && curnode.b == 0 && curnode.c == 0)
        {
            cout << curnode.layer;
            return 0;
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                Node _node;
                _node.a = max(0, curnode.a - permutation[i][0]);
                _node.b = max(0, curnode.b - permutation[i][1]);
                _node.c = max(0, curnode.c - permutation[i][2]);
                _node.layer = curnode.layer + 1;

                if (visited[_node.a][_node.b][_node.c] == 1)
                    continue;

                q.push(_node);
                visited[_node.a][_node.b][_node.c] = 1;
            }
        }
    }
}