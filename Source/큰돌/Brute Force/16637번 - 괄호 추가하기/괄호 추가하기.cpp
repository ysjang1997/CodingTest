/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16637                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16637                          #+#        #+#      #+#    */
/*   Solved: 2026/03/09 04:18:27 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
    왼쪽에서부터 순서대로 계산해야 한다.
    수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다.
    수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램
    추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.

    최댓값 / 모든 경우의수 / 괄호 먼저

    괄호가 될수도 안될수도 있는 모든 경우의 수에서 최대값

    탐색 / 제한시간 0.5초 / 값을 저장하면서 최소한의 동작시간으로 가야함


    복기
     - 문제 설명을 제대로 안읽어서 이해를 못하고 해설을 보고옴
        -> 괄호가 있을수도 없을수도 어디에 괄호를 치든 상관없이 최댓값을 구하는 문제였음
        -> 근데 *일때만 찾아서 괄호를 치는줄알고 삽질

     - a oper b 또는 a oper (b oper c) 두가지의 경우의 수가 있음 이게 인덱스 끝까지 가서 최댓값을 만드는 문제
        -> 트리의 구조처럼 타고가다가 끝에 닿으면 return. 

     - 문제 구현자체는 안어려웠는데 문제를 보고 어떻게 구현할지에 대해서 생각하는게 오래걸림.

     
*/
#include <iostream>
#include <vector>

using namespace std;

int n;
char input;

vector<int> numv;
vector<char> operv;

int result = -9999'9999;

int oper(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    return 0;
}

void solve(int index, int ret)
{
    if (index >= numv.size() - 1)
    {
        result = max(result, ret);
        return;
    }
    solve(index + 1, oper(ret, numv[index + 1], operv[index]));
    if (index + 2 < numv.size())
        solve(index + 2, oper(ret, oper(numv[index + 1], numv[index + 2], operv[index + 1]), operv[index]));
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input >= '0' && input <= '9')
            numv.push_back(input - '0');
        else
            operv.push_back(input);
    }

    solve(0, numv[0]);

    cout << result;
    return 0;
}