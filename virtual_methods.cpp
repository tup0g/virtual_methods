#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
    virtual void hit_damage() = 0;
};

class Bazuka : public Weapon {
public:
    void hit_damage() override{
        cout << "BAM-BAM" << endl;
    }
};

class Rifle : public Weapon {
public:
    void hit_damage() override {
        cout << "ratatatatatatata" << endl;
    }
};

class Pistol : public Weapon {
    void hit_damage() override {
        cout << "piw piw paw" << endl;
    }
};

class Sniper_rifle : public Weapon {
    void hit_damage() override {
        cout << "BUH" << endl;
    }
};



class Player {
public: 
    void Shoot(Weapon *weapon) {
        weapon->hit_damage();
    }
};

int main()
{
    Bazuka bazuka;
    Rifle rifle;
    Pistol pistol;
    Sniper_rifle s_rifle;

    Player player1;
    player1.Shoot(&bazuka);
    player1.Shoot(&rifle);
    player1.Shoot(&s_rifle);
    player1.Shoot(&pistol);
    
}
