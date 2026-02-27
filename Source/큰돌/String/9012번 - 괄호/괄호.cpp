/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9012                           #+#        #+#      #+#    */
/*   Solved: 2026/02/27 19:55:34 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/* 
    -복기-

    ()가 만나면 지우고 다시 처음부터 배열을 순회하는 식의 재귀로 구현했는데
    Stack의 구조로 만들면 한번의 순회로 하나의 string을 처리 할 수 있음.

    예를들어 '(' 를 push하고, ')'가 들어왔을 때 pop을 하며 조건검사를 진행하거나
    또는 int 변수로 카운팅하여 '('는 ++, ')'는--를 해서 변수가 음수인지 매번 검사를 진행

*/

#include <iostream>
#include <string>

using namespace std;

int t;

bool isVPS(string& _str)
{
    if (_str.empty())
        return true;

    int erasenum = -1;
    for (int i = 0; i < _str.size() - 1; i++)
    {
        if (_str[i] == '(' && _str[i + 1] == ')')
        {
            erasenum = i;
            break;
        }
    }

    if(erasenum == -1)
        return false;

    return isVPS(_str.erase(erasenum, 2));
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;

        cout << (isVPS(s) ? "YES" : "NO");
        cout << '\n';
    }

    return 0;
}