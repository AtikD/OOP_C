class Character{
 protected:
    Position _pos;
    std::string _name;
    int _hp;
    int _dmg;
    int _arm;
 public:
    static int count;
    static int history_count;
    Character(Position pos, std::string n, int hp, int damage, int arm):
    _pos(pos), _name(n), _hp(hp), _dmg(damage), _arm(arm){}

    ~Character(){
        count--;
    }
    Position pos() const noexcept{
        return _pos;
    }
    std::string name() const noexcept{
        return _name;
    }
    int hp() const noexcept{
        return _hp;
    }
    int dmg() const noexcept{
        return _dmg;
    }
    int armor() const noexcept{
        return _arm;
    }
    virtual int attack() = 0;
    virtual int defence(int dmg) = 0;
};