#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED



#include <stdint.h>
#include <stddef.h>
#include "../exheaders/raylib.h"



typedef enum ButtonState{
    BUTTON_NOT_INTERACTED,
    BUTTON_HOVER,
    BUTTON_CLICK_LEFT,
    BUTTON_CLICK_RIGHT,
    BUTTON_DOWN_LEFT,
    BUTTON_DOWN_RIGHT
} ButtonState;


ButtonState UiDrawButton(char* text, float x, float y, float sizeX, float sizeY, Color baseColor, Color textColor, Color hoverColor, int textSize);
void UiDrawTextBox(Rectangle box, char *text, int maxLength, bool *active, Color textColor) ;


#endif