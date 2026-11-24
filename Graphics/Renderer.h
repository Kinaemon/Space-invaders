#pragma once

class Renderer{
public:
    Renderer();// Конструктор
    ~Renderer();// Деструктор

    Renderer(const Renderer& other) = delete;// Запрет на присваивание
    Renderer& operator=(const Renderer& other) = delete;

    int getWidth()const;
    int getHeight()const;
    void draw(int x, int y, char symbol);
    void clear();
    void display();
};