#include <iostream>
using namespace std;

class Enemy {
public:
	virtual void attack() {
	}
};

class Ninja: public Enemy {
public:
	void attack() {
		cout << "i am ninja" << endl;
	}
};

class Monster: public Enemy {
public:
	void attack() {
		cout << "i am monster" << endl;
	}
};

int main() {

	Ninja n;
	Monster m;
	Enemy *enemy1 = &n;
	Enemy *enemy2 = &m;
	enemy1->attack();
	enemy2->attack();
	return 0;
}