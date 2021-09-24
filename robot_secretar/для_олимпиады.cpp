// для_олимпиады.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <numeric>
#include <array>
//#include <algorithm>
#include <vector>
#include <string>

int main()
{
    setlocale(LC_ALL, "rus");
    std::string sent;
    std::getline(std::cin,sent);
    int len = sent.length();
    int sum = 0;
    std::array<std::vector <int>, 2>sentense;
    sentense[0].assign(len+1,0);
    sentense[1].assign(len+1,0);
    sentense[1][0] = 2 * len + 2;
    for (int i = 0; i < len; i++)
    {
        char s = sent[i];
        if (s>='A' && s<='Z')
        {
           sentense[0][i + 1] = sentense[0][i] + 1;
           sentense[1][i + 1] = std::min(sentense[1][i], sentense[0][i] + 2);
        }
        else if(s>='a' && s<='z')
        {
            sentense[1][i + 1] = sentense[1][i] + 1;
            sentense[0][i + 1] = std::min(sentense[0][i], sentense[1][i] + 2);
        }
        else
        {
            sentense[0][i + 1] = sentense[0][i];
            sentense[1][i + 1] = sentense[1][i];
        }
    }
    sum = std::min(sentense[0][len], sentense[1][len]) + len;
    std::cout << sum;

    return 0;
}

