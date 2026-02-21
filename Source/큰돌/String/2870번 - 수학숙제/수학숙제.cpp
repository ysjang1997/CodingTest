/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2870                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2870                           #+#        #+#      #+#    */
/*   Solved: 2026/02/21 19:29:16 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<string> results;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        string str;
        for (int len = 0; len < input.size(); len++)
        {
            if (input[len] < '0' || input[len] > '9')
            {
                if (!str.empty())
                {
                    results.push_back(str);
                    str.clear();
                }
                continue;
            }

            if (str.empty())
            {
                str += input[len];
                continue;
            }

            if (str[0] == '0')
                str = input[len];
            else
                str += input[len];
        }

        if (!str.empty())
            results.push_back(str);
    }

    sort(results.begin(), results.end(), [](string a, string b)
    { 
        if(a.size() == b.size())
        {
            for(int i = 0; i < a.size(); i++)
            {
                if(a[i] == b[i])
                    continue;
               
                return a[i] < b[i];
            }
        }
        return a.size() < b.size(); 
    });

    for (auto &result : results)
    {
        cout << result << endl;
    }

    return 0;
}