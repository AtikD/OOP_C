#include <iostream>
#include <game.hpp>




int main() {
    Character p1, p2("Bob", 120, 10, 30), p3("Piter");
    std::cout << p1.count << " " << Character::count << "\n";
    
    p1.save(p2, p2.attack(p1));
 
    return 0;
}