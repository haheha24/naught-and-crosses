#include "Button.h"

Button::Button(Texture2D tex, Rectangle rec, Rectangle dest) :
    btnTex(tex),
    btnSourceRec(rec),
    btnDestRec(dest)
{};

void Button::click(Vector2 mousePoint) {

    if (CheckCollisionPointRec(mousePoint, btnDestRec))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
    }
    else btnState = 0;
}

void Button::draw() {
    DrawTexturePro(btnTex, btnSourceRec, btnDestRec, {}, 0.f, WHITE);
}