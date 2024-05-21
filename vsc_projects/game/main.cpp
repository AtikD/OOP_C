#include <iostream>
#include "virtual/Position.hpp"
#include "characters/Character.hpp"
#include "characters/Target.hpp"


int Character::count = 0;
int Character::history_count = 0;

int main(){

    Target test(Position(0,0), 0);
    std::cout << test.name() << "\n";
    return 0;
}