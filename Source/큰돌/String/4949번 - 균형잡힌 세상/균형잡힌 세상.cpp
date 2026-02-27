/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4949                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4949                           #+#        #+#      #+#    */
/*   Solved: 2026/02/27 21:23:15 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

/*
    직전 문제를 9012번: 괄호 를 풀었는데 바로 복기한 내용이나옴
     - (짝 맞추기 문제 = Stack을 이용한 해결)
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBalance(string &_str)
{
    stack<char> charstack;

    for (char &c : _str)
    {
        if (c == '(' || c == '[')
        {
            charstack.push(c);
            continue;
        }

        if (c == ')')
        {
            if (charstack.empty() || charstack.top() != '(')
                return false;

            charstack.pop();
            continue;
        }

        if (c == ']')
        {
            if (charstack.empty() || charstack.top() != '[')
                return false;

            charstack.pop();
            continue;
        }
    }

    if (charstack.empty())
        return true;

    return false;
}

int main()
{

    while (true)
    {
        string str;
        getline(cin, str);

        if (str == ".")
            break;

        cout << (isBalance(str) ? "yes" : "no") << endl;
    }

    return 0;
}