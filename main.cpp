#include <stdlib.h>
#include <cstdint>
#include <unordered_map>
#include <string>
#include <iostream>
#include <functional>
#include <memory>

struct Person
{
    int age;
    std::string name;
};

int main(void)
{
    std::vector<std::unique_ptr<Person>> vector_persons_;
    vector_persons_.emplace_back(std::make_unique<Person>());
    vector_persons_.emplace_back(std::make_unique<Person>());
    vector_persons_.emplace_back(std::make_unique<Person>());
    vector_persons_.back()->age = 10;

    for (auto& a : vector_persons_)
    {
        std::cout << a->age << std::endl;
    }

    std::function<bool(const std::unique_ptr<Person>&)> f = [&](const std::unique_ptr<Person>& arg_up_p) {return arg_up_p->age == 10; };
    //std::erase_if(vector_persons_, f);
    vector_persons_.erase(std::remove_if(vector_persons_.begin(), vector_persons_.end(), f), vector_persons_.end());

    std::cout << "deleted" << std::endl;

    for (auto& a : vector_persons_)
    {
        std::cout << a->age << std::endl;
    }

    return 0;
}
