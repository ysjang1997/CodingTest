/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10709                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10709                          #+#        #+#      #+#    */
/*   Solved: 2026/02/21 22:27:23 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int h, w;
vector<string> v;

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }

    for (string &s : v)
    {
        bool cloud = false;
        int cnt = 0;
        for (char &_char : s)
        {
            if (_char == '.')
            {
                if (cloud)
                    cout << cnt++;
                else
                    cout << -1;
            }
            else
            {
                cloud = true;
                cnt = 0;
                cout << cnt++;
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}