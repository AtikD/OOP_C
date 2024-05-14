#include <iostream>
#include "item.hpp"

class Shield: public Item{
    bool _ready;
    int _reload;
 public:
    Shield(std::string name, int lvl){
        _name = name;
        _lvl = lvl < 5 ? 5 : lvl;
        _duration = 10 * lvl;
        _damage = 0;
        _ready = true;
        _reload = 10 - (int)(lvl * 1.5);          
    }

    bool use(){
        if (_ready){
            _ready = false;
            return true;
        } else return false;
    }

    void step(){
        if (!_ready && _reload != 0)
            _reload--;
        else if(!_ready && _reload == 0){
            _ready = true;
            _reload = 10 - (int)(_lvl * 1.5);
        }
    }

};
