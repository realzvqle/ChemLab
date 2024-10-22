#include "ui.h"
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

ButtonState UiDrawButton(char* text, float x, float y, float sizeX, float sizeY, Color baseColor, Color textColor, Color hoverColor, int textSize) {
    if (!textSize) {
        textSize = sizeY / 2;
    }
    Rectangle recc =  { x, y, sizeX, sizeY };
    bool isMouseOver = CheckCollisionPointRec(GetMousePosition(),  recc);
    Color buttonColor = isMouseOver ? hoverColor : baseColor;
    DrawRectangle(x, y, sizeX, sizeY, buttonColor);
    int textWidth = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        textWidth += MeasureText(&text[i], textSize);
    }
    int textX = x + (sizeX - MeasureTextEx(GetFontDefault(), text, textSize, 4).x) / 2;
    int textY = y + (sizeY - textSize) / 2;
    DrawText(text, textX, textY, textSize, textColor);
    if (isMouseOver && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Rectangle rec =  { x, y, sizeX, sizeY };
        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_DOWN_LEFT;
    }
    if (isMouseOver && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        Rectangle rec =  { x, y, sizeX, sizeY };
        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_DOWN_RIGHT;
    }
    if (isMouseOver && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        Rectangle rec =  { x, y, sizeX, sizeY };

        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_CLICK_LEFT;
    }
    if (isMouseOver && IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) {
        Rectangle rec =  { x, y, sizeX, sizeY };
        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_CLICK_RIGHT;
    }
    if (isMouseOver) {
        Rectangle rec =  { x, y, sizeX, sizeY };
        DrawRectangleLinesEx(rec, 2, textColor);
        return BUTTON_HOVER;
    }
    return BUTTON_NOT_INTERACTED;
}

void UiDrawTextBox(Rectangle box, char *text, int maxLength, bool *active, Color textColor) {
    box.y = box.y - 90;
    DrawRectangle(box.x, box.y, box.width, box.height, *active ? WHITE : GRAY);
    DrawRectangleLines(box.x + 1, box.y + 1, box.width + 1, box.height + 1, *active ? BLACK : DARKGRAY);

    DrawText(text, box.x + 5, box.y + 8, 20, textColor);
    if (CheckCollisionPointRec(GetMousePosition(), box) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        *active = true;
    } else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        *active = false;
    }
    if (*active) {
        int key = GetKeyPressed();
        bool shift = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
        while (key > 0) {
            if ((key >= 32 && key <= 125) && (strlen(text) < (maxLength - 1))) {
                int len = strlen(text);
                if (shift && isalpha(key)) {
                    text[len] = toupper((char)key);
                } else {
                    text[len] = (char)key;
                }
                text[len + 1] = '\0';
            }

            key = GetKeyPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            int len = strlen(text);
            if (len > 0) {
                text[len - 1] = '\0';
            }
        }
        int textWidth = MeasureText(text, 20);
        if (textWidth < box.width - 10) {
            int cursorX = box.x + 5 + textWidth;
            int cursorY = box.y + 8;
            if ((GetTime() * 2.0f) - (int)(GetTime() * 2.0f) > 0.5f) {
                DrawText(" _", cursorX, cursorY, 20, BLACK);
            }
        }
    }
}