#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
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
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
}
