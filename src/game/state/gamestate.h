#pragma once

class GameState {
public:
    virtual ~GameState() = default;

    virtual void update(float frameTime) = 0;
    virtual void render() = 0;
    virtual bool shouldQuit() const { return false; }
};
