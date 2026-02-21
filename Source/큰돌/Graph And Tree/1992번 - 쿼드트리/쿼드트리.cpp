/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1992                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1992                           #+#        #+#      #+#    */
/*   Solved: 2026/02/19 21:38:34 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

using namespace std;

int n;

int arr[64][64] = {};

string Quad(int y, int x, int num)
{
    if (num <= 1)
        return to_string(arr[y][x]);

    string result = "";
    int half = num / 2;
   
    result += Quad(y, x, half);
    result += Quad(y, x + half, half);
    result += Quad(y + half, x, half);
    result += Quad(y + half, x + half, half);

    for(int i = 1; i <result.size(); i++)
    {
        if(result[0] != result[i])
            return "(" + result + ")";
    }
    return string(1,result[0]);

}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            scanf("%1d", &num);
            arr[i][j] = num;

        }      
    }

    string result = Quad(0,0,n);

    cout << result;

    return 0;
}