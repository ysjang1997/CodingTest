/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2910                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2910                           #+#        #+#      #+#    */
/*   Solved: 2026/02/20 11:07:35 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n,c;
map<int,vector<int>> mp;
vector<pair<int,int>> v;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(mp[a.second].size() == mp[b.second].size())
        return mp[a.second].front() < mp[b.second].front();
        
    return mp[a.second].size() > mp[b.second].size();
}

int main()
{
    scanf("%d %d", &n ,&c);
   
    for(int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);

        v.push_back({i,num});
        mp[num].push_back(i);
    }

    sort(v.begin(),v.end(),compare);

    for(pair<int,int>& result : v)
    {
        cout << result.second << " ";
    }

    return 0;
}

