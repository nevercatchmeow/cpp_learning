#pragma once

#include "Gun.hpp"

#include <string>

class Solider
{
private:
    std::string _name;
    Gun *_ptr_gun;

public:
    Solider(std::string name);
    ~Solider();
    void addGun(Gun *ptr_gun);
    void addBulletToGun(int bullet_num);
    bool fire();
};
