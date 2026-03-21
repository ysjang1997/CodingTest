/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9934                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9934                           #+#        #+#      #+#    */
/*   Solved: 2026/03/20 09:13:04 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
    깊이 k 완전이진트리

    주어진 트리배열의 계층을 출력

    반으로 나누고 나누고 나누고 계층구조를 가진 결과출력

    0 ~ 6
    0 ~ 2 4 ~ 6
      1
    0   2

    복기
     - 트리 문제는 처음이라 해설 참고했음.
       문제보고 예제보고 절반씩 타고 들어가면서 구하나? 생각했고 출력하려면 구조상
       계층별 값에 대해서 저장을 해야하나? 결과적으로는 맞는 접근방식 이었음.

     - 처음에 문제보고 상근이가 어떻게 순회를 했길래 노드의 숫자들이 이따구인거지?
        -> 근데 그걸 물어보는 문제가 아니었음.

     -  완전 이진 트리 구조의 1 6 4 3 5 2 7 처럼 inOrder의 트리 배열이 주어지고
       이 배열을 계층 구조로 출력하는 문제

     - pow(제곱근)으로 트리 노드의 총 개수를 구하고 pow(0,k) - 1
       배열의 절반씩 나눠가며 타고 들어가 계층별로 배열에 저장하고 출력

     - 완전 이진트리의 노드개수는 2K제곱 - 1
       근데 입력 첫째줄에 k (1 <= 10)가 주어진다고 했고 그걸 잘못생각해서 최대 노드의 개수로
       착각함.
       k는 따지고보면 완전이진트리의 layer와 같은 값을 가지게 될것이고 그럼 계층 배열의 크기도
       10으로 만들어 두었으면 되는 것인데 그 부분에 대한 처리를 제대로 하지 않아서
       Out of Bounce 당함.



*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int k, input;
int arr[1025] = {};
vector<int> layerv[10] = {};

void solve(int low, int high, int layer)
{
    int mid = (low + high) / 2;
    layerv[layer].push_back(arr[mid]);

    if (low == high)
        return;

    solve(low, mid - 1, layer + 1);
    solve(mid + 1, high, layer + 1);
}

int main()
{
    cin >> k;
    int len = pow(2, k) - 1;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    solve(0, len - 1, 0);

    for (int i = 0; i < 10; i++)
    {
        for (int &output : layerv[i])
        {
            cout << output << " ";
        }
        cout << endl;
    }

    return 0;
}