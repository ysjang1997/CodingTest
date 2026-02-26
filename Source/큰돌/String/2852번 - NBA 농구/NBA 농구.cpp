/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2852                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2852                           #+#        #+#      #+#    */
/*   Solved: 2026/02/26 23:47:22 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

using namespace std;

int n;
int A, B, Asum, Bsum;
string cache;
string RegulationTime = "48:00";

string intToTime(int _num)
{
    string m = "00" + to_string(_num / 60);
    string s = "00" + to_string(_num % 60);

    return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
}

int TimeToint(string _time)
{
    return atoi(_time.substr(0, 2).c_str()) * 60 + atoi(_time.substr(3, 2).c_str());
}

void AddTime(int &_sum, string _time)
{
    _sum += TimeToint(_time) - TimeToint(cache);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int team;
        string time;

        cin >> team >> time;

        if (A > B)
            AddTime(Asum, time);
        else if (B > A)
            AddTime(Bsum, time);

        team == 1 ? A++ : B++;
        cache = time;
    }

    if (A > B)
        AddTime(Asum, RegulationTime);
    else if (B > A)
        AddTime(Bsum, RegulationTime);

    cout << intToTime(Asum) << endl;
    cout << intToTime(Bsum) << endl;

    return 0;
}