/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2828                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2828                           #+#        #+#      #+#    */
/*   Solved: 2026/02/20 01:13:35 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

int n, m;
int applecnt;
int result;

int length;
int position = 1;

int main()
{
    scanf("%d %d", &n, &m);
    length = m - 1;

    scanf("%d", &applecnt);
    for (int i = 0; i < applecnt; i++)
    {
        int num;
        scanf("%d", &num);

        if (position > num)
        {
            int dist = position - num;
            result += dist;
            position -= dist;

            continue;
        }

        if (position + length < num)
        {
            int dist = num - (position + length);
            result += dist;
            position += dist;

            continue;
        }
    }

    cout << result;

    return 0;
}