#include <iostream>
#include <DirectXMath.h>
#include <vector>
#include <algorithm>
#include <string>

// stdmove�̎d�l�ɂ��Ēm��

struct A
{
    A() {}

    // ���Ӓl����R�s�[
    A(const A&)
    {
        std::cout << "copy" << std::endl;
    }

    // �E�Ӓl���烀�[�u
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
