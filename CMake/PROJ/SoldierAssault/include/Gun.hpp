#pragma once

#include <string>

class Gun
{
private:
    int _bullet_count;
    std::string _type;

public:
    Gun(std::string type) : _bullet_count(0), _type(type) {}

    void addBullet(int bullet_num);
    bool shoot();
};
