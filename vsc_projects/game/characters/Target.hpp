class Target : public Character{
    public:
    Target(Position pos, int armor = 0):Character(pos, "Punch Me!", 10000, 0, armor){}

    int attack(){
        return 0;
    }
    int defence(int dmg){
        int finallydmg;
        if(0.3 * dmg > _arm) {
            finallydmg = _arm;
            _arm = 0;
        }else {
            finallydmg = (int)(0.3 * dmg);
            _arm -= (int)(0.3 * dmg);
        }
        return finallydmg;
    }
};