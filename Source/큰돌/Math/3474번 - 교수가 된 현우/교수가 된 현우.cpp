/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3474                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3474                           #+#        #+#      #+#    */
/*   Solved: 2026/02/21 23:22:49 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int t;
vector<int> v;

int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for(int i = 0; i < t; i++)
    {   
        int num;
        cin >> num;
           
        int result = 0;

        while(num > 0)
        {
            int devide = num / 5;
            result += devide;
            num = devide;
        }
        cout << result << '\n';
    }

    return 0;
}