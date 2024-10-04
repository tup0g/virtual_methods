#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>

using namespace std;

class Weapon {
    private:
        int damage;
        int ammo;
        string naming;
    public:
        Weapon(int d, int a, string n){
            damage = d;
            ammo = a;
            naming = n;
        }
        void print_info(){
            cout << damage << endl;
            cout << ammo << endl;
            cout << naming << endl;
        }
        void save_info(const string &filename){
            ofstream saveFile(filename);
            if (saveFile.is_open())
            {
                saveFile << damage << endl;
                saveFile << ammo << endl;
                saveFile << naming << endl;
                saveFile.close();
                cout << "Saved to: " << filename << endl;
            }
            else
            {
                cout << "error in saving" << endl;
            }
        }
        void open_info(const string &filename)
        {
            ifstream infoFile(filename);
            if (infoFile.is_open())
            {
                getline(infoFile, naming);
                infoFile >> damage;
                infoFile >> ammo;
                infoFile.close();
                cout << "Loaded from: " << filename << endl;
            }
            else
            {
                cout << "error in opening" << endl;
            }
        }     
};

int main()
{
    Weapon weapon(50, 31, "Ak-174");
    Weapon new_weapon(0,0,"");

    thread saveThread(&Weapon::save_info, &weapon, "weapon_info.txt");
    saveThread.join();

    thread loadThread(&Weapon::open_info, &new_weapon, "weapon_data.txt");
    loadThread.join();

    new_weapon.print_info();
}