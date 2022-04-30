//using sfml for graphics
#include <SFML/Graphics.hpp>
//using atlstr for hiding the terminal easily
#include <atlstr.h>
//using iostream to write to the terminal
#include <iostream>
//vectorvectorvectorvectorvectorvectorvectorvectorvectorvector
#include <vector>

//in the standard namespace
using namespace std;

//variables
const int WIDTH{ 960 };
const int HEIGHT{ 1000 };

//vectors

vector<int> red;
vector<int> pink;
vector<int> purple;
vector<int> indigo;
vector<int> blue;
vector<int> cyan;
vector<int> teal;
vector<int> green;
vector<int> yellow;
vector<int> orange;
vector<int> orange_deep;
vector<int> brown;
vector<int> gray;
vector<int> gray_blue;

vector<int> background_color;
vector<int> word_color;

//images (and one font)
sf::Font cascadia;
sf::Texture card_long;


bool terminal_disabled{ false };

int main()
{
	//set up window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "~Cards 2: Electric Boogaloo~");
	sf::Event event;

	//colors to use easily in a [0], [1], [2] fashion
	
	red.push_back(244);
	red.push_back(67);
	red.push_back(54);

	pink.push_back(232);
	pink.push_back(30);
	pink.push_back(99);

	purple.push_back(156);
	purple.push_back(39);
	purple.push_back(176);

	indigo.push_back(50);
	indigo.push_back(86);
	indigo.push_back(168);

	blue.push_back(33);
	blue.push_back(150);
	blue.push_back(243);

	cyan.push_back(0);
	cyan.push_back(188);
	cyan.push_back(212);

	teal.push_back(0);
	teal.push_back(150);
	teal.push_back(136);

	green.push_back(76);
	green.push_back(175);
	green.push_back(80);

	yellow.push_back(255);
	yellow.push_back(235);
	yellow.push_back(59);

	orange.push_back(255);
	orange.push_back(152);
	orange.push_back(0);

	orange_deep.push_back(255);
	orange.push_back(87);
	orange.push_back(34);

	brown.push_back(121);
	brown.push_back(85);
	brown.push_back(72);

	gray.push_back(158);
	gray.push_back(158);
	gray.push_back(158);

	gray_blue.push_back(96);
	gray_blue.push_back(125);
	gray_blue.push_back(139);

	//image loading
	if (!card_long.loadFromFile("assets/card.png"))
	{
		cout << "Card.png has not been located. Are all the files in the correct location?" << endl;
	}
	if (!cascadia.loadFromFile("assets/Cascadia.ttf"))
	{
		cout << "Cascadia.ttf has not been located. Are all the files in the correct location?" << endl;
	}

	//hide terminal if needed
	if (terminal_disabled)
	{
		HWND hWnd = GetConsoleWindow();
		ShowWindow(hWnd, SW_HIDE);
	}
	
	//look for events while the window is open
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				else if (event.key.code == sf::Keyboard::F1)
					terminal_disabled = !terminal_disabled;
			}
		}
		//clear the window
		window.clear(sf::Color(indigo[0],indigo[1],indigo[2]));
		









		
		//draw the window
		window.display();
	}

	
	

	//return okay if the program exits properly
    return 0;
}