/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4659                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: simba123 <boj.kr/u/simba123>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4659                           #+#        #+#      #+#    */
/*   Solved: 2026/02/21 17:51:33 by simba123      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
vector<bool> acceptables;

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char &_char)
{
    for (char &_vowel : vowel)
    {
        if (_char == _vowel)
            return true;
    }
    return false;
}

bool isAcceptable(string &str)
{
    bool hasvowel = false;
    int vowelcnt = 0;
    int consonantcnt = 0;

    for (int i = 0; i < str.size(); i++)
    {
        bool currnetchar = isVowel(str[i]);

        if (!hasvowel)
            hasvowel = currnetchar;

        if (currnetchar)
        {
            vowelcnt++;
            consonantcnt = 0;
        }
        else
        {
            consonantcnt++;
            vowelcnt = 0;
        }

        if (vowelcnt >= 3 || consonantcnt >= 3)
            return false;

        if (i > str.size() - 1)
            continue;

        char first = str[i];
        char second = str[i + 1];

        if (first == second && first != 'e' && first != 'o')
            return false;
    }
    return hasvowel;
}

int main()
{
    while (true)
    {
        string input;
        cin >> input;
        if (input == "end")
            break;

        v.push_back(input);
        acceptables.push_back(isAcceptable(input));
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << "<" << v[i] << "> is ";
        if (!acceptables[i])
        {
            cout << "not ";
        }
        cout << "acceptable." << endl;
    }

    return 0;
}