#include <iostream>
#include <future>
#include <thread>

// std::async�̎g������T��
// https://cpprefjp.github.io/reference/future/async.html

int foo() { std::cout << "executes foo()\n"; return 3; }

int main()
{
    // �V���ȃX���b�h�Ŋ֐�foo()��񓯊����s
    {
        std::cout << "invokes std::async(std::launch::async, foo)" << std::endl;
        std::future<int> f = std::async(std::launch::async, foo);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "main thread: slept for 10 msec\n";
        // �񓯊����s�̌��ʂ��擾
        int result = f.get();
        std::cout << "foo() = " << result << std::endl;
    }

    std::cout << std::endl;

    // �֐�f��x����ԂŔ񓯊����s
    {
        // ���̒i�K�ł͊֐�foo()�����s���Ȃ�
        std::cout << "invokes std::async(std::launch::deferred, foo)" << std::endl;
        std::future<int> f = std::async(std::launch::deferred, foo);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "main thread: slept for 10 msec\n";

        // �񓯊����s�̌��ʂ��擾
        // ���̒i�K�Ŋ֐�foo()�����s
        int result = f.get();
        std::cout << "foo() = " << result << std::endl;
    }

    return 0;
}
