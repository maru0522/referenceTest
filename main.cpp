#include <iostream>
#include <DirectXMath.h>
#include <vector>
#include <algorithm>
#include <string>

// stdfind‚ÌŽd—l‚É‚Â‚¢‚Ä’m‚é

struct TestA
{
    std::string id_;
};

int main()
{
    std::vector<TestA> vec1;
    vec1.emplace_back();
    vec1.back().id_ = "AAAAA";
    std::cout << vec1.back().id_ << std::endl;
    //auto itr1 = std::find(vec1.begin(), vec1.end(), "AAAAA");
    //std::cout << itr1->id_ << std::endl;


    std::vector<int> vec2 = { 1,2,3,4,5 };
    auto itr2 = std::find(vec2.begin(), vec2.end(), 5);
    std::cout << *itr2 << std::endl;


    return 0;
}
