#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "../include/my.h"

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;

    window = sfRenderWindow_create(mode, "CSFML window", sfResize | sfClose, NULL);
    if (!window)
        return 84;

    texture = sfTexture_createFromFile("oiseau.png", NULL);
    if (!texture)
        return 84;

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        if (drunkhunt(window, texture, sprite, event) == 84)
            return 84;
    }

    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}
