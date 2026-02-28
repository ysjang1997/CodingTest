/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1068                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1068                           #+#        #+#      #+#    */
/*   Solved: 2026/02/28 23:26:13 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
    n 입력

    for n
    -1 = root 저장

    vecotr[부모] 에 자식을 추가

    root부터 dfs

    복기
     - 트리는 좀더 많이 해봐야 할듯 해결방법이 생각이 안나서 해설 보고함

     - 이 문제는 입력에서 이미 정렬된 값이 들어와서 for를 돌면서 바로바로 노드 삽입이 가능했지만
       정렬되지 않은 입력이 들어오는 상황에 대한 생각을 해봐야할듯?
     
     - 처음에는 Node 구조체를 만들어서 할까 했는데 vector<int> 자료형을 가지는 배열을 만들어서
       인접 리스트를 만들면 부모 노드와 연결된 자식을 저장하여 트리구조를 만들 수 있음.

*/
#include <iostream>
#include <vector>

using namespace std;

int n, root, del;
vector<int> v[50];
int num = 0;

int Dfs(int node)
{
    int childcnt = 0;
    int leafcnt = 0;
    for (int &child : v[node])
    {
        if (child == del)
            continue;

        leafcnt += Dfs(child);
        childcnt++;
    }
    if (childcnt == 0)
        return 1;

    return leafcnt;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == -1)
        {
            root = i;
            continue;
        }
        v[num].push_back(i);
    }

    cin >> num;
    if (num == root)
    {
        cout << 0;
        return 0;
    }

    del = num;
    cout << Dfs(root);

    return 0;
}