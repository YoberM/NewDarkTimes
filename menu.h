#ifndef MENU_H
#define MENU_H
#include"Headers.h"
using namespace std;
using namespace sf;
#define MAX_NUMERO 3
class Menu
{
private:
    int tam=25;
    int seleccionar;
    Texture text_menu;
    Sprite sprite_menu;
    Font font;
	Text menu[MAX_NUMERO];
    bool abierto=1;
public:
    Menu(float ancho, float alto,RenderWindow &Window);
    bool Interaccion(sf::RenderWindow&);
    void drawfondo(RenderWindow &window);
    void draw(RenderWindow &window);
    void Mover_arriba();
	void Mover_abajo();
	int get_presionado() { return seleccionar; }
};

#endif 