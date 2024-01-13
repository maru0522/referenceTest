#include <iostream>
#include <DirectXMath.h>
#include <vector>
#include <algorithm>
#include <string>

// stdmoveの仕様について知る

struct A
{
    A() {}

    // 左辺値からコピー
    A(const A&)
    {
        std::cout << "copy" << std::endl;
    }

    // 右辺値からムーブ
    A(A&&)
    {
        std::cout << "move" << std::endl;
    }
};

int main()
{
    std::unique_ptr<A> a1 = nullptr;
    if (a1.get() == nullptr) { std::cout << "a1.get() == nullptr"; }
    if (a1 == nullptr) { std::cout << "a1 == nullptr"; }

    return 0;
}
