/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17298                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17298                          #+#        #+#      #+#    */
/*   Solved: 2026/03/01 02:19:35 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
    오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수
      -> 나와 대응대는 무언가 찾기 = 짝 맞추기 stack

    값을 입력받음

    기본배열에 값을 저장

    스택이 비어있으면 루프넘기고 스택에 추가

    스택이 있으면 탑을 조건검사
        -> 크면 꺼내고 탑인덱스에 지금 값을 추가 및 fasle까지 반복
        -> 작으면 스택에 루프넘기고 스택에 추가


    복기
     - 보자마자 짝 맞추기인줄 몰랐음.

     - 나와 대응대는 무언가를 찾아야 한다면 짝맞추기를 떠올려봐야 할듯?

     - 스택에 값이 아닌 인덱스를 저장한다는 생각도 못해봤음 이거 좋은듯

     - 코테에서 while을 사용하는 경우가 많은데 단순 true가 아닌
       조건을을 넣어서 코드를 깔끔하게 하는 연습도 하자

*/

#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int n, num;
int arr[100'0001] = {};
int results[100'0001] = {};

stack<int> _stack;

int main()
{
    memset(results, -1, sizeof(results));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[i] = num;

        while (!_stack.empty() && arr[_stack.top()] < arr[i])
        {
            results[_stack.top()] = arr[i];
            _stack.pop();
        }
        _stack.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << results[i] << " ";
    }

    return 0;
}
