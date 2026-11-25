#pragma once

enum class Action{
    None,
    MoveLeft,
    MoveRight,
    Shoot,
    Quit
};

class Input{
public:
    static Action getAction();
};