#include "GameObject.h"

GameObject::GameObject(int pos_x, int pos_y, char symbol): 
    pos_x(pos_x), pos_y(pos_y), symbol(symbol){}

GameObject::~GameObject() = default;

int GameObject::getX() const{
    return pos_x;
}

int GameObject::getY() const{
    return pos_y;
}

char GameObject::getSymbol() const{
    return symbol;
}

bool GameObject::isAlive() const{
    return alive;
}

void GameObject::destroy() {
    alive = false;
}

void GameObject::move(int dx, int dy){
    pos_x += dx;
    pos_y += dy;
}

int Player::get_hp() const{
    return health;
}

int Enemy::get_hp() const{
    return health;
}

void Enemy::update(){}

void Bullet::update(){
    move(0,-1);
}