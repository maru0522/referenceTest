#include <stdlib.h>
#include <cstdint>
#include <unordered_map>
#include <string>
#include <iostream>
#include <functional>
#include <memory>

// ptr�̎Q�Ɛ悪�����ȃA�h���X�����ʂ�����@

class A
{
public:
    int num;
    std::string id;
};

int main()
{
    A* insAPtr = nullptr;

    {
        std::unique_ptr<A> instanceA = std::make_unique<A>();
        instanceA->num = 10;
        instanceA->id = "im a";

        insAPtr = instanceA.get();
        instanceA.reset();
    }

    // insAPtr�̎Q�Ƃ���A�h���X�������ɂȂ��Ă��Ȃ��ꍇ
    if (insAPtr != nullptr) {
        std::cout << "alivePtr : " << insAPtr->num << std::endl;
    }
    // �����ɂȂ��Ă���ꍇ
    else {
        std::cout << "not alivePtr" << std::endl;
    }

    return 0;
}
