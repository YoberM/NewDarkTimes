#include "Headers.h"
#include "menu.h"
using namespace std;

Menu::Menu(float ancho, float alto,RenderWindow &Window)
{
	text_menu.loadFromFile("pistola.png");
	sprite_menu.setTexture(text_menu);
	//sprite_menu.setOrigin(sprite_menu.getTexture()->getSize().x/2.f, sprite_menu.getTexture()->getSize().y/2.f);
	sprite_menu.setScale(((float)Window.getSize().x/sprite_menu.getTexture()->getSize().x),((float)Window.getSize().y/sprite_menu.getTexture()->getSize().y));
	int tam=25;
    font.loadFromFile("arial.ttf");
    menu[0].setFont(font);
	menu[0].setColor(Color::Red);
	menu[0].setString("Jugar");
	menu[0].setPosition(Vector2f( ancho/ 2, alto / (MAX_NUMERO + 1) * 1));
	menu[0].setCharacterSize(tam);

    menu[1].setFont(font);
	menu[1].setColor(Color::Black);
	menu[1].setString("Opciones");
	menu[1].setPosition(Vector2f(ancho / 2, alto / (MAX_NUMERO + 1) * 2));
	menu[1].setCharacterSize(tam);

    menu[2].setFont(font);
	menu[2].setColor(Color::Black);
	menu[2].setString("Salir");
	menu[2].setPosition(Vector2f(ancho / 2, alto / (MAX_NUMERO + 1) * 3));
	menu[2].setCharacterSize(tam);

	seleccionar = 0;
}

bool Menu::Interaccion(sf::RenderWindow& window){//Si es 1 , el menu seguira
												 //si es 0 sale del menu
												//y pasa al juego
	sf::Event event1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		Mover_arriba();
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		Mover_abajo();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		return 0;
	}
		return 1;
}

void Menu::drawfondo(RenderWindow &window)
{
	window.draw(sprite_menu);
}

void Menu::draw(RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMERO; i++)
	{
		
		window.draw(menu[i]);
	}
}
void Menu::Mover_arriba()
{
    if (seleccionar - 1 >= 0)
	{
		menu[seleccionar].setColor(Color(30,30,30));
		menu[seleccionar].setCharacterSize(tam);
		seleccionar--;
		menu[seleccionar].setColor(Color(230,0,0));
		menu[seleccionar].setCharacterSize(40);
	}
}

void Menu::Mover_abajo()
{
    if (seleccionar + 1 <= 2)
	{
		menu[seleccionar].setColor(Color(230,230,230));
		menu[seleccionar].setCharacterSize(tam);
		seleccionar++;
		menu[seleccionar].setColor(Color(230,0,0));
		menu[seleccionar].setCharacterSize(40);
	}
}