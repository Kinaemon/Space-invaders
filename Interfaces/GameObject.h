#pragma once 


class GameObject{
private:
    int health;
    int pos_x;
    int pos_y;

public:
    int get_hp() const;
    int get_pos() const;
};

class Player : public GameObject{
private:
    int health;
    int pos_x;
    int pos_y;

public:
    Player();
    Player(int health, int pos_x, int pos_y);
    ~Player();
    int get_hp() const;
    int get_pos() const;
};

class Enemy : public GameObject{
private:
    int health;
    int pos_x;
    int pos_y;

public:
    Enemy();
    Enemy(int health, int pos_x, int pos_y);
    ~Enemy();
    int get_hp() const;
    int get_pos() const;
};