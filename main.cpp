#include <DirectXMath.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// std::ifstreamでテスト

int main()
{
    //std::ifstream ifs(str);
    std::istringstream strs("AAABBBCCCDDDEEE"); // istringstreamをifstreamに見立ててる。
    std::istringstream strs2("AAA,BBB,CCC,DDD,EEE"); // istringstreamをifstreamに見立ててる。

    //ifs.seekg(0, std::ios_base::beg);
    strs.seekg(3, std::ios_base::beg);

    std::string out;
    strs >> out;
    std::cout << out << std::endl;


    // ,は含まれるのか？
    std::string str;
    while (std::getline(strs2, str))
    {
        std::string word;
        std::istringstream iss(str);
        while (std::getline(iss, word, ','))
        {
            std::cout << word << std::endl;
        }
    }

    std::string a = { "12345" };
    std::cout << a.size() << std::endl;
    std::cout << a[a.size()];

    return 0;
}
