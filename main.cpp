#include <stdlib.h>
#include <cstdint>
#include <unordered_map>
#include <string>
#include <iostream>
#include <functional>
#include <memory>

// ptrの参照先が無効なアドレスか識別する方法

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

    // insAPtrの参照するアドレスが無効になっていない場合
    if (insAPtr != nullptr) {
        std::cout << "alivePtr : " << insAPtr->num << std::endl;
    }
    // 無効になっている場合
    else {
        std::cout << "not alivePtr" << std::endl;
    }

    return 0;
}
