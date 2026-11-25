#pragma once 


class GameObject{
private:
    int pos_x;
    int pos_y;
    bool alive = true;
    char symbol;

public:
    virtual ~GameObject() = 0;
    GameObject(int pos_x, int pos_y, char symbol);

    int getX() const;
    int getY() const;
    char getSymbol() const;
    bool isAlive() const;

    void destroy();
    void move(int dx, int dy);
    bool isColliding(const GameObject& other) const;

    virtual void update(){};
};

class Player : public GameObject{
private:
    int health = 100;

public:
    Player(int pos_x, int pos_y) : GameObject(pos_x, pos_y, 'A'){};
    int get_hp() const;
};

class Enemy : public GameObject{
private:
    int health = 10;

public:
    Enemy(int pos_x, int pos_y) : GameObject(pos_x, pos_y, 'W'){};
    int get_hp() const;
    
    void update() override;
};

class Bullet : public GameObject{
public:
    Bullet(int pos_x, int pos_y) : GameObject(pos_x, pos_y, '\|'){};

    void update() override;
};