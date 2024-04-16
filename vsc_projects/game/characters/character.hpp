#include <iostream>

class Character {
 protected:
    std::string _name;
    int _health;
    int _power;
    int _armor;
 public:
    static int history_count;
    static int count;
    Character(const Character& c): _name(c._name), _health(c._health), _power(c._power), _armor(c._armor) {};
    Character(std::string name = "", int health = 100, int power = 10, int armor = 20): _name(name), _health(health), _power(power), _armor(armor){};
    virtual int attack(const Character& c);
    virtual void save(Character& c, int damage);
    ~Character(){count--;};
};