#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

class Button {
public:
    Button(Texture2D tex, Rectangle rec, Rectangle dest);
    void setBtnState(int state) { btnState = state; }
    int getBtnState() { return btnState; }
    void setBtnAction(bool action) { btnAction = action; }
    bool getBtnAction() { return btnAction; }
    void click(Vector2 mousePoint);
    void draw();
protected:
    Texture2D btnTex{};
    Rectangle btnSourceRec{};
    Rectangle btnDestRec{};
    int btnState{ 0 };
    bool btnAction{ false };
};

#endif // !BUTTON_H