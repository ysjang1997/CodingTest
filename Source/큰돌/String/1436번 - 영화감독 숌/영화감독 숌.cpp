/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1436                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1436                           #+#        #+#      #+#    */
/*   Solved: 2026/02/27 02:42:13 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int num = 666;
int n;

using namespace std;

int main()
{
    cin >> n;

    for (int i = 0;; i++)
    {
        if (to_string(i).find("666") != string::npos)
            n--;

        if (n <= 0)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}