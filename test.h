#pragma once
#include <array>
#include <iostream>

class test
{
public:
    test(int a,int b) {
        n_ = a;
        pr_ = b;
    }
    ~test() {
        std::cout << "�f�X�g���N�^" << std::endl;
    }
    //test(const test& obj) {
    //    std::cout << "copy" << std::endl;
    //    n_ = obj.n_;
    //    pr_ = obj.pr_;
    //}

public:
    int n_{};
private:
    int pr_{};
};