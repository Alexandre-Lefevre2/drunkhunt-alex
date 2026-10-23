#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "../include/my.h"

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfTexture* texture;

    window = sfRenderWindow_create(mode, "CSFML window", sfResize | sfClose, NULL);
    if (!window)
        return 84;

    texture = sfTexture_createFromFile("oiseau.png", NULL);
    if (!texture)
        return 84;

    while (sfRenderWindow_isOpen(window)) {
        if (drunkhunt(window, texture) == 84)
            return 84;
    }
}
