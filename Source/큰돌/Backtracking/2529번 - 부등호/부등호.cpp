/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2529                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2529                           #+#        #+#      #+#    */
/*   Solved: 2026/03/18 22:19:24 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
/*
     2 ~ 9 에서 부등호를 만족하는 경우의수 중복X
    완성된 배열을 저장
    배열 정렬
    최소값 최대값 출력

    복기
     - 0 ~ 9까지의 경우의수 를돌면서 다음 인덱스르 0~9까지 돌고 부등호 조건에 만족하는
       숫자 배열을 만들어서 저장

     - 0 ~ 9 까지 순차적으로 돌기때문에 따로 정렬할 필요는 없음

     - 다만 인덱스에 들어갈수 있는 경우의 수 0 ~ 9 가있고
       부등호를 저장하는 배열이 따로 있어서 인덱스 0~9 부등호 0 인덱스 0~9 부등호1
       이런식이라 부등호와 경우의 수에 대한 진행도를 저장하는 인덱스 따로 관리 필요했음.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
char inequality[10] = {};

vector<int> cache;
vector<vector<int>> q;

int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int visited[10] = {};

bool Check(int a, int b, char ineq)
{
    if (ineq == '>')
        return a > b;

    if (ineq == '<')
        return a < b;

    return false;
}

void solve(int num, int count)
{
    visited[num] = 1;
    cache.push_back(num);

    if (cache.size() == k + 1)
        q.push_back(cache);
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (visited[arr[i]] == 1)
                continue;

            if (Check(num, arr[i], inequality[count]))
                solve(arr[i], count + 1);
        }
    }

    cache.pop_back();
    visited[num] = 0;
}

int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> inequality[i];
    }

    for (int i = 0; i < 10; i++)
    {
        solve(i, 0);
    }

    for (int &num : q.back())
        cout << num;

    cout << endl;

    for (int &num : q.front())
        cout << num;

    return 0;
}