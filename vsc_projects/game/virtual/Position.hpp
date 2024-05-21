class Position {
  private:
    int _x;
    int _y;
  public:

    Position(int __x, int __y){
      _x=__x;
      _y=__y;
    }
    int x(){
        return _x;
    }
    int y(){
        return _y;
    }
};

