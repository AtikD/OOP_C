#include <iostream>
#include "character.hpp"

class Warrior : public Character{
    bool _shield;
    int _weapon_damage;
    int _weapon_strength;
 public:
    Warrior(const Warrior& c): Character(c){};
    Warrior(std::string name = "", int health = 100, int power = 100, int armor = 20, bool shield = true, int weapon_damage = 40, int weapon_strength = 100) : Character(name, health, power, armor), _shield(shield), _weapon_damage(weapon_damage), _weapon_strength(weapon_strength) {}
    int attack(const Character& c);
    void protect(const Character& c, int damage);
};