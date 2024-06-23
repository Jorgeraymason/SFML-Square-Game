#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

void Update(int &keyTime, RectangleShape &square, RenderWindow &window);

void Draw(RenderWindow &window, RectangleShape &square);

int main()
{
	int keyTime = 8;

	RenderWindow window(VideoMode(640, 480), "JORGERAYMASON GAMEZ");
	window.setFramerateLimit(60);


	RectangleShape square(Vector2f(100.f, 100.f));
	square.setFillColor(Color::Blue);
	square.setPosition(window.getSize().x / 2, window.getSize().y / 2);


	CircleShape circle(50.f);
	circle.setPosition(window.getPosition().x / 3.4, window.getPosition().y / 7.1);
	circle.setFillColor(Color::White);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}	

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}
		Update(keyTime, square, window);
		Draw(window, square );
	}

	return 0;
}

void Update(int &keyTime, RectangleShape &square, RenderWindow &window) {
	if (keyTime < 8)
	{
		keyTime++;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) && square.getPosition().y > 0)
	{
		keyTime = 0;
		square.move(0.f, -9.f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) && square.getPosition().y + square.getSize().y < window.getSize().y)
	{
		keyTime = 0;
		square.move(0.f, 9.f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) && square.getPosition().x > 0)
	{
		keyTime = 0;
		square.move(-9.f, 0.f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Right) && square.getPosition().x + square.getSize().x < window.getSize().x)
	{
		keyTime = 0;
		square.move(9.f, 0.f);
	}

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		keyTime = 0;
		square.setFillColor(Color::Green);
	}
	else
	{
		square.setFillColor(Color::Blue);
	}
}

void Draw(RenderWindow &window, RectangleShape &square) {
	window.clear(Color::White);

	window.draw(square);

	window.display();
}