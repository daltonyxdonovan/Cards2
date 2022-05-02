//using sfml for graphics
#include <SFML/Graphics.hpp>
//using atlstr for hiding the terminal easily
#include <atlstr.h>
//using iostream to write to the terminal
#include <iostream>
//vectorvectorvectorvectorvectorvectorvectorvectorvectorvector
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

//in the standard namespace
using namespace std;

//variables
const int WIDTH{ 960 };
const int HEIGHT{ 1000 };
int scrollbar{ 0 };
int scrollbar_state{ 0 };
int background_choice{ 7 };
int text_choice{ 8 };
int scroll_speed{ 60 };
int file_read_offset{ -1 };
int tickers{ 0 };
int time_offset{ 0 };
int mouse_lastx{ sf::Mouse::getPosition().x };
int mouse_lasty{ sf::Mouse::getPosition().y };

bool running = true; 
bool help = false;
bool terminal_disabled{ false };
bool help_clicked{ false };
bool checking{ false };

//vectors
vector<int> red;
vector<int> pink;
vector<int> purple;
vector<int> indigo;
vector<int> blue;
vector<int> cyan;
vector<int> teal;
vector<int> green;
vector<int> black;
vector<int> orange;
vector<int> orange_deep;
vector<int> brown;
vector<int> gray;
vector<int> gray_blue;
vector<vector<string>> content;
vector<string> row;
string line, word;
vector<int> background_color;
vector<int> text_color;
vector<int> card_position;

//states vectors 
vector<vector<string>> alabama;
vector<vector<string>> arizona;
vector<vector<string>> alaska;
vector<vector<string>> west_virginia;
vector<vector<string>> arkansas;
vector<vector<string>> california;
vector<vector<string>> colorado;
vector<vector<string>> connecticut;
vector<vector<string>> delaware;
vector<vector<string>> district_of_columbia;
vector<vector<string>> florida;
vector<vector<string>> georgia;
vector<vector<string>> hawaii;
vector<vector<string>> idaho;
vector<vector<string>> illinois;
vector<vector<string>> indiana;
vector<vector<string>> iowa;
vector<vector<string>> kansas;
vector<vector<string>> kentucky;
vector<vector<string>> louisiana;
vector<vector<string>> maine;
vector<vector<string>> maryland;
vector<vector<string>> massachusetts;
vector<vector<string>> michigan;
vector<vector<string>> minnesota;
vector<vector<string>> mississippi;
vector<vector<string>> missouri;
vector<vector<string>> montana;
vector<vector<string>> nebraska;
vector<vector<string>> nevada;
vector<vector<string>> new_hampshire;
vector<vector<string>> new_jersey;
vector<vector<string>> new_mexico;
vector<vector<string>> new_york;
vector<vector<string>> north_carolina;
vector<vector<string>> north_dakota;
vector<vector<string>> ohio;
vector<vector<string>> oklahoma;
vector<vector<string>> oregon;
vector<vector<string>> pennsylvania;
vector<vector<string>> rhode_island;
vector<vector<string>> south_carolina;
vector<vector<string>> south_dakota;
vector<vector<string>> tennessee;
vector<vector<string>> texas;
vector<vector<string>> utah;
vector<vector<string>> vermont;
vector<vector<string>> virginia;
vector<vector<string>> washington;
vector<vector<string>> wisconsin;
vector<vector<string>> wyoming;
vector<vector<string>> all_states;

vector<vector<string>> ca;
vector<vector<string>> co;
vector<vector<string>> hc;
vector<vector<string>> hf;
vector<vector<string>> ha;
vector<vector<string>> ac;
vector<vector<string>> it;
vector<vector<string>> hp;

vector<string> states_list;
vector<int> state_hovered;
vector<int> card_xpos;
vector<int> card_ypos;
vector<int> checked;
string fname;



int main()
{
	//images, texts (and one font)
	sf::Font cascadia;
	sf::Texture card_long;
	sf::Texture state_card;
	sf::Texture card_square;
	sf::Texture helping;
	sf::Texture up;
	sf::Texture down;
	sf::Texture left;
	sf::Texture right;
	sf::Texture checkbox_collider;
	
	sf::Sprite Card; //create sprite
	sf::RectangleShape Seperator;
	sf::RectangleShape Checkbox_top;
	sf::RectangleShape Checkbox_bottom;
	sf::RectangleShape Checkbox_left;
	sf::RectangleShape Checkbox_right;
	sf::Text Woid;
	sf::Text Req;
	sf::Text Status;
	sf::Text Address;
	sf::Text Opened;
	sf::Text Closed;
	Woid.setFont(cascadia);
	Status.setFont(cascadia);
	Req.setFont(cascadia);
	Address.setFont(cascadia);
	Opened.setFont(cascadia);
	Closed.setFont(cascadia);

	if (running)
	{
		wchar_t filename[MAX_PATH];
		OPENFILENAMEW ofn;
		ZeroMemory(&filename, sizeof(filename));
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
		ofn.lpstrFilter = L"TAB Files\0*.tab\0Any File\0*.*\0";
		ofn.lpstrFile = filename;
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrTitle = L"Select a .tab file";
		ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

		if (GetOpenFileNameW(&ofn))
		{
			fname = CW2A(filename);
		}
		else
		{
			// All this stuff below is to tell you exactly how you messed up above. 
			// Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
			switch (CommDlgExtendedError())
			{
			case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
			case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
			case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
			case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
			case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
			case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
			case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
			case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
			case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
			case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
			case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
			case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
			case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
			case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
			case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
			default: cout << "operation cancelled by user" << endl;
			}
		}

		fstream file(fname, ios::in);
		if (file.is_open())
		{
			if (running)
			{
				while (getline(file, line))
				{
					file_read_offset += 1;
					if (file_read_offset > 3)
					{
							row.clear();
						stringstream str(line);
						while (getline(str, word, '	'))
							row.push_back(word);
							if (row[1] == "CA")
								ca.push_back(row);
							else if (row[1] == "CO")
								co.push_back(row);
							else if (row[1] == "HC")
								hc.push_back(row);
							else if (row[1] == "HF")
								hf.push_back(row);
							else if (row[1] == "HA")
								ha.push_back(row);
							else if (row[1] == "AC")
								ac.push_back(row);
							else if (row[1] == "IT")
								it.push_back(row);
							else if (row[1] == "HP")
								hp.push_back(row);
						
						if (row[1] != "CO" && row[1] != "CL" && row[1] != "CA")
						{
							content.push_back(row);
							all_states.push_back(row);
							card_position.push_back(card_position.size());
							if (row[7] == "AL")
							{
								alabama.push_back(row);
								
							}
							
							if (row[7] == "AK")
							{
								alaska.push_back(row);
								
							}
							
							if (row[7] == "AZ")
							{
								arizona.push_back(row);
								
							}
							
							if (row[7] == "AR")
							{
								arkansas.push_back(row);
								
							}
							
							if (row[7] == "CA")
							{
								california.push_back(row);
								
							}
							
							if (row[7] == "CO")
							{
								colorado.push_back(row);
								
							}
							
							if (row[7] == "CT")
							{
								connecticut.push_back(row);
								
							}
							
							if (row[7] == "DE")
							{
								delaware.push_back(row);
								
							}
							
							if (row[7] == "DC")
							{
								district_of_columbia.push_back(row);
								
							}
							
							if (row[7] == "FL")
							{
								florida.push_back(row);
								
							}
							
							if (row[7] == "GA")
							{
								georgia.push_back(row);
								
							}
							
							if (row[7] == "HI")
							{
								hawaii.push_back(row);
								
							}
							
							if (row[7] == "ID")
							{
								idaho.push_back(row);
								
							}
							
							if (row[7] == "IL")
							{
								illinois.push_back(row);
								
							}
							
							if (row[7] == "IN")
							{
								indiana.push_back(row);
								
							}
							
							if (row[7] == "IA")
							{
								iowa.push_back(row);
								
							}
							
							if (row[7] == "KS")
							{
								kansas.push_back(row);
								
							}
							
							if (row[7] == "KY")
							{
								kentucky.push_back(row);
								
							}
							
							if (row[7] == "LA")
							{
								louisiana.push_back(row);
								
							}
							
							if (row[7] == "ME")
							{
								maine.push_back(row);
								
							}
							
							if (row[7] == "MD")
							{
								maryland.push_back(row);
								
							}
							
							if (row[7] == "MA")
							{
								massachusetts.push_back(row);
								
							}
							
							if (row[7] == "MI")
							{
								michigan.push_back(row);
								
							}
							
							if (row[7] == "MN")
							{
								minnesota.push_back(row);
								
							}
							
							if (row[7] == "MS")
							{
								mississippi.push_back(row);
								
							}
							
							if (row[7] == "MO")
							{
								missouri.push_back(row);
								
							}
							
							if (row[7] == "MT")
							{
								montana.push_back(row);
								
							}
							
							if (row[7] == "NE")
							{
								nebraska.push_back(row);
								
							}
							
							if (row[7] == "NV")
							{
								nevada.push_back(row);
								
							}
							
							if (row[7] == "NH")
							{
								new_hampshire.push_back(row);
								
							}
							
							if (row[7] == "NJ")
							{
								new_jersey.push_back(row);
								
							}
							
							if (row[7] == "NM")
							{
								new_mexico.push_back(row);
								
							}
							
							if (row[7] == "NY")
							{
								new_york.push_back(row);
								
							}
							
							if (row[7] == "NC")
							{
								north_carolina.push_back(row);
								
							}
							
							if (row[7] == "ND")
							{
								north_dakota.push_back(row);
								
							}
							
							if (row[7] == "OH")
							{
								ohio.push_back(row);
								
							}
							
							if (row[7] == "OK")
							{
								oklahoma.push_back(row);
								
							}
							
							if (row[7] == "OR")
							{
								oregon.push_back(row);
								
							}
							
							if (row[7] == "PA")
							{
								pennsylvania.push_back(row);
								
							}
							
							if (row[7] == "RI")
							{
								rhode_island.push_back(row);
								
							}
							if (row[7] == "SC")
							{
								south_carolina.push_back(row);
								
							}
							if (row[7] == "SD")
							{
								south_dakota.push_back(row);
								
							}
							if (row[7] == "TN")
							{
								tennessee.push_back(row);
								
							}
							if (row[7] == "TX")
							{
								texas.push_back(row);
								
							}
							if (row[7] == "UT")
							{
								utah.push_back(row);
								
							}
							if (row[7] == "VT")
							{
								vermont.push_back(row);
								
							}
							if (row[7] == "VA")
							{
								virginia.push_back(row);
								
							}
							if (row[7] == "WA")
							{
								washington.push_back(row);
								
							}
							if (row[7] == "WV")
							{
								west_virginia.push_back(row);
								
							}
							if (row[7] == "WI")
							{
								wisconsin.push_back(row);
								
							}
							if (row[7] == "WY")
							{
								wyoming.push_back(row);
								
							}
					}
					
							
							
					}
					else
						//delete row
						row.clear();
				}
				file.close();
			}
		}
		else
		{
			cout << "Could not open the file\n";
			running = false;
		}
		//set up window
		sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "~Cards 2: Electric Boogaloo~");
		sf::Event event;

		//populating the list with all the state values
		states_list.push_back("AL");
		states_list.push_back("AK");
		states_list.push_back("AZ");
		states_list.push_back("AR");
		states_list.push_back("CA");
		states_list.push_back("CO");
		states_list.push_back("CT");
		states_list.push_back("DC");
		states_list.push_back("DE");
		states_list.push_back("FL");
		states_list.push_back("GA");
		states_list.push_back("HI");
		states_list.push_back("ID");
		states_list.push_back("IL");
		states_list.push_back("IN");
		states_list.push_back("IA");
		states_list.push_back("KS");
		states_list.push_back("KY");
		states_list.push_back("LA");
		states_list.push_back("ME");
		states_list.push_back("MD");
		states_list.push_back("MA");
		states_list.push_back("MI");
		states_list.push_back("MN");
		states_list.push_back("MS");
		states_list.push_back("MO");
		states_list.push_back("MT");
		states_list.push_back("NE");
		states_list.push_back("NV");
		states_list.push_back("NH");
		states_list.push_back("NJ");
		states_list.push_back("NM");
		states_list.push_back("NY");
		states_list.push_back("NC");
		states_list.push_back("ND");
		states_list.push_back("OH");
		states_list.push_back("OK");
		states_list.push_back("OR");
		states_list.push_back("PA");
		states_list.push_back("RI");
		states_list.push_back("SC");
		states_list.push_back("SD");
		states_list.push_back("TN");
		states_list.push_back("TX");
		states_list.push_back("UT");
		states_list.push_back("VT");
		states_list.push_back("VA");
		states_list.push_back("WA");
		states_list.push_back("WV");
		states_list.push_back("WI");
		states_list.push_back("WY");
		states_list.push_back("ALL");
		
		for (int k{ 0 }; k < content.size(); k++)
		{
			card_xpos.push_back(20);
			card_ypos.push_back((k*210)+20);
			checked.push_back(0);
		}
		
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

		black.push_back(10);
		black.push_back(10);
		black.push_back(10);

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

		//image and font loading
		if (!card_long.loadFromFile("assets/card.png"))
		{
			cout << "Card.png has not been located. Are all the files in the correct location?" << endl;
		}
		if (!cascadia.loadFromFile("assets/Cascadia.ttf"))
		{
			cout << "Cascadia.ttf has not been located. Are all the files in the correct location?" << endl;
		}
		if (!state_card.loadFromFile("assets/card_state.png"))
		{
			cout << "Card_state.png has not been located. Are all the files in the correct location?" << endl;
		}
		if (!card_square.loadFromFile("assets/card_square.png"))
		{
			cout << "Card_square.png has not been located. Are all the files in the correct location?" << endl;
		}
		if (!helping.loadFromFile("assets/helping.png"))
		{
			cout << "helping.png has not been located. Are all the files in the correct location?" << endl;
		}
		if (!up.loadFromFile("assets/up.png"))
		{
			cout << "up.png has not been located. Are all the files in the correct location?" << endl;
		}
		if (!down.loadFromFile("assets/down.png"))
		{
			cout << "down.png has not been located. Are all the files in the correct location?" << endl;
		}
		if (!left.loadFromFile("assets/left.png"))
		{
			cout << "left.png has not been located. Are all the files in the correct location?" << endl;
		}
		if (!right.loadFromFile("assets/right.png"))
		{
			cout << "right.png has not been located. Are all the files in the correct location?" << endl;
		}
		if (!checkbox_collider.loadFromFile("assets/checkbox_collider.png"))
		{
			cout << "checkbox_collider.png has not been located. Are all the files in the correct location?" << endl;
		}
		
		//look for events while the window is open
		while (window.isOpen())
		{
			//get mouse position and save it to vector mouse_pos
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
			
			//hide terminal if needed
			if (terminal_disabled)
			{
				HWND hWnd = GetConsoleWindow();
				ShowWindow(hWnd, SW_HIDE);
			}
			
			//don't allow user to backscroll further than intended
			if (scrollbar > 0)
				scrollbar = 0;
			if (scrollbar_state > 0)
				scrollbar_state = 0;
			if (scrollbar_state < -1620)
				scrollbar_state = -1620;

	//much simpler theme styling than the other way (:
			//background styling
			if (background_choice == 0)
			{
				background_color.clear();
				background_color.push_back(red[0]);
				background_color.push_back(red[1]);
				background_color.push_back(red[2]);
			}
			if (background_choice == 1)
			{
				background_color.clear();
				background_color.push_back(pink[0]);
				background_color.push_back(pink[1]);
				background_color.push_back(pink[2]);
			}
			if (background_choice == 2)
			{
				background_color.clear();
				background_color.push_back(purple[0]);
				background_color.push_back(purple[1]);
				background_color.push_back(purple[2]);
			}
			if (background_choice == 3)
			{
				background_color.clear();
				background_color.push_back(indigo[0]);
				background_color.push_back(indigo[1]);
				background_color.push_back(indigo[2]);
			}
			if (background_choice == 4)
			{
				background_color.clear();
				background_color.push_back(blue[0]);
				background_color.push_back(blue[1]);
				background_color.push_back(blue[2]);
			}
			if (background_choice == 5)
			{
				background_color.clear();
				background_color.push_back(cyan[0]);
				background_color.push_back(cyan[1]);
				background_color.push_back(cyan[2]);
			}
			if (background_choice == 6)
			{
				background_color.clear();
				background_color.push_back(teal[0]);
				background_color.push_back(teal[1]);
				background_color.push_back(teal[2]);
			}
			if (background_choice == 7)
			{
				background_color.clear();
				background_color.push_back(green[0]);
				background_color.push_back(green[1]);
				background_color.push_back(green[2]);
			}
			if (background_choice == 8)
			{
				background_color.clear();
				background_color.push_back(black[0]);
				background_color.push_back(black[1]);
				background_color.push_back(black[2]);
			}
			if (background_choice == 9)
			{
				background_color.clear();
				background_color.push_back(orange[0]);
				background_color.push_back(orange[1]);
				background_color.push_back(orange[2]);
			}
			if (background_choice == 10)
			{
				background_color.clear();
				background_color.push_back(orange_deep[0]);
				background_color.push_back(orange_deep[1]);
				background_color.push_back(orange_deep[2]);
			}
			if (background_choice == 11)
			{
				background_color.clear();
				background_color.push_back(brown[0]);
				background_color.push_back(brown[1]);
				background_color.push_back(brown[2]);
			}
			if (background_choice == 12)
			{
				background_color.clear();
				background_color.push_back(gray[0]);
				background_color.push_back(gray[1]);
				background_color.push_back(gray[2]);
			}
			if (background_choice == 13)
			{
				background_color.clear();
				background_color.push_back(gray_blue[0]);
				background_color.push_back(gray_blue[1]);
				background_color.push_back(gray_blue[2]);
			}
			if (background_choice < 0)
				background_choice = 13;
			if (background_choice > 13)
				background_choice = 0;

			//now for text coloring
			if (text_choice == 0)
			{
				text_color.clear();
				text_color.push_back(red[0]);
				text_color.push_back(red[1]);
				text_color.push_back(red[2]);
			}
			if (text_choice == 1)
			{
				text_color.clear();
				text_color.push_back(pink[0]);
				text_color.push_back(pink[1]);
				text_color.push_back(pink[2]);
			}
			if (text_choice == 2)
			{
				text_color.clear();
				text_color.push_back(purple[0]);
				text_color.push_back(purple[1]);
				text_color.push_back(purple[2]);
			}
			if (text_choice == 3)
			{
				text_color.clear();
				text_color.push_back(indigo[0]);
				text_color.push_back(indigo[1]);
				text_color.push_back(indigo[2]);
			}
			if (text_choice == 4)
			{
				text_color.clear();
				text_color.push_back(blue[0]);
				text_color.push_back(blue[1]);
				text_color.push_back(blue[2]);
			}
			if (text_choice == 5)
			{
				text_color.clear();
				text_color.push_back(cyan[0]);
				text_color.push_back(cyan[1]);
				text_color.push_back(cyan[2]);
			}
			if (text_choice == 6)
			{
				text_color.clear();
				text_color.push_back(teal[0]);
				text_color.push_back(teal[1]);
				text_color.push_back(teal[2]);
			}
			if (text_choice == 7)
			{
				text_color.clear();
				text_color.push_back(green[0]);
				text_color.push_back(green[1]);
				text_color.push_back(green[2]);
			}
			if (text_choice == 8)
			{
				text_color.clear();
				text_color.push_back(black[0]);
				text_color.push_back(black[1]);
				text_color.push_back(black[2]);
			}
			if (text_choice == 9)
			{
				text_color.clear();
				text_color.push_back(orange[0]);
				text_color.push_back(orange[1]);
				text_color.push_back(orange[2]);
			}
			if (text_choice == 10)
			{
				text_color.clear();
				text_color.push_back(orange_deep[0]);
				text_color.push_back(orange_deep[1]);
				text_color.push_back(orange_deep[2]);
			}
			if (text_choice == 11)
			{
				text_color.clear();
				text_color.push_back(brown[0]);
				text_color.push_back(brown[1]);
				text_color.push_back(brown[2]);
			}
			if (text_choice == 12)
			{
				text_color.clear();
				text_color.push_back(gray[0]);
				text_color.push_back(gray[1]);
				text_color.push_back(gray[2]);
			}
			if (text_choice == 13)
			{
				text_color.clear();
				text_color.push_back(gray_blue[0]);
				text_color.push_back(gray_blue[1]);
				text_color.push_back(gray_blue[2]);
			}
			if (text_choice < 0)
				text_choice = 13;
			if (text_choice > 13)
				text_choice = 0;

			//clear the window with background color chosen
			window.clear(sf::Color(background_color[0], background_color[1], background_color[2]));

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
			//card loop begins
			for (int i{ 0 }; i < content.size(); i++)
			{
				Card.setTexture(card_long); //set texture to long card
				Card.setPosition(sf::Vector2f(card_xpos[i], scrollbar + card_ypos[i])); //set position on scrollbar dynamically
				window.draw(Card); //draw the card
				
				Seperator.setSize(sf::Vector2f(Card.getLocalBounds().width-24, 3));
				Seperator.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Seperator.setPosition(Card.getPosition().x+1, Card.getPosition().y + 35);
				window.draw(Seperator);
				
				Woid.setString(content[i][0]);
				Woid.setCharacterSize(25);
				Woid.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Woid.setPosition(Card.getPosition().x + (Card.getLocalBounds().width/2) - (Woid.getLocalBounds().width / 2), Card.getPosition().y + 3);
				window.draw(Woid);

				Status.setString(content[i][1]);
				Status.setCharacterSize(25);
				Status.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Status.setPosition(Card.getPosition().x + (Card.getLocalBounds().width) - (Status.getLocalBounds().width + 40), Card.getPosition().y + 3);
				window.draw(Status);

				Req.setString(content[i][2]);
				Req.setCharacterSize(60);
				Req.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Req.setPosition(Card.getPosition().x + 200, Card.getPosition().y + (Card.getLocalBounds().height / 2) - ((Req.getLocalBounds().height / 2)+30));
				window.draw(Req);
				
				Address.setString(content[i][5] + ", " + content[i][6] + ", " + content[i][7]);
				Address.setCharacterSize(25);
				Address.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Address.setPosition(Card.getPosition().x + (Card.getLocalBounds().width / 2) - ((Address.getLocalBounds().width / 2)+10), Card.getPosition().y + (Card.getLocalBounds().height / 2) - (Address.getLocalBounds().height / 2)+25);
				window.draw(Address);

				Opened.setString("Opened on: " + content[i][12]);
				Opened.setCharacterSize(15);
				Opened.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Opened.setPosition(Card.getPosition().x + 5, Card.getPosition().y + 165);
				window.draw(Opened);
				
				if (content[i][1] == "HF")
				{
					Closed.setString("Set for: " + content[i][13]);
					Closed.setCharacterSize(15);
					Closed.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
					Closed.setPosition(Card.getPosition().x + Card.getLocalBounds().width - (Closed.getLocalBounds().width+30), Card.getPosition().y + 165);
					window.draw(Closed);
				}
				
				Checkbox_top.setSize(sf::Vector2f(25, 3));
				Checkbox_top.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Checkbox_top.setPosition(Card.getPosition().x + 5, Card.getPosition().y + 5);
				window.draw(Checkbox_top);
				
				Checkbox_bottom.setSize(sf::Vector2f(25, 3));
				Checkbox_bottom.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Checkbox_bottom.setPosition(Card.getPosition().x + 5, Card.getPosition().y + 27);
				window.draw(Checkbox_bottom);
				
				Checkbox_left.setSize(sf::Vector2f(3, 25));
				Checkbox_left.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Checkbox_left.setPosition(Card.getPosition().x + 5, Card.getPosition().y + 5);
				window.draw(Checkbox_left);

				Checkbox_right.setSize(sf::Vector2f(3, 25));
				Checkbox_right.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				Checkbox_right.setPosition(Card.getPosition().x + 27, Card.getPosition().y + 5);
				window.draw(Checkbox_right);

				sf::Sprite checkbox_collide;
				checkbox_collide.setTexture(checkbox_collider);
				checkbox_collide.setPosition(Card.getPosition().x + 5, Card.getPosition().y + 5);
				window.draw(checkbox_collide);
				
				if (checked[i] == 1 && checking == true)
				{
					sf::RectangleShape checkmark_left;
					sf::RectangleShape checkmark_right;
					checkmark_left.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
					checkmark_right.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
					checkmark_left.setSize(sf::Vector2f(3, 10));
					checkmark_right.setSize(sf::Vector2f(3, 20));
					checkmark_left.setPosition(Card.getPosition().x + 9, Card.getPosition().y + 18);
					checkmark_left.setRotation(-30);
					checkmark_right.setPosition(Card.getPosition().x + 24, Card.getPosition().y + 8);
					checkmark_right.setRotation(30);
					window.draw(checkmark_left);
					window.draw(checkmark_right);
					int xpos_limit{ -820 };
					int ypos_limit{ card_ypos[i] - (i * 210 + 20) };
					
					time_offset += 1;
					if (time_offset > 40)
					{
						card_xpos[i] -= 10;
						if (card_xpos[i] < xpos_limit && card_xpos[i] > -1040)
						{
							tickers += 1;
							for (int j = i; j < card_ypos.size(); j++)
							{
								card_ypos[j] -= 10;
								if (card_ypos[j] < ypos_limit)
								{
									card_ypos[j] = ypos_limit;
								}
							}
							if (tickers == 21)
							{
								tickers = 0;
								time_offset = 0;
								checking = false;
							}
						}
					}
				}
				//if mouse intersects with checkbox_collide
				if (event.mouseButton.button == sf::Mouse::Left && checkbox_collide.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
				{
					checked[i] = 1;
				}
			}

			//state picker loop begins
			for (int j{ 0 }; j < states_list.size(); j++)
			{
				sf::Sprite State;
				State.setTexture(state_card);
				State.setPosition(sf::Vector2f(810,scrollbar_state + (j * 50) + 20));
				window.draw(State);
				
				sf::Text State_name;
				State_name.setFont(cascadia);
				State_name.setString(states_list[j]);
				State_name.setCharacterSize(25);
				State_name.setFillColor(sf::Color(text_color[0], text_color[1], text_color[2]));
				State_name.setPosition(State.getPosition().x + (State.getLocalBounds().width / 2) - (State_name.getLocalBounds().width / 2+5), State.getPosition().y + 3);
				window.draw(State_name);

				//if State intersects with mouse
				if (State.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
				{
					//if left mouse is clicked
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						
						if (j == 0)
						{
							content.clear();
							content = alabama;
						}
							
						else if (j == 1)
						{
							content.clear();
							content = alaska;
						}
							
						else if (j == 2)
						{
							content.clear();
							content = arizona;
						}
							
						else if (j == 3)
						{
							content.clear();
							content = arkansas;
						}
							
						else if (j == 4)
						{
							content.clear();
							content = california;
						}
							
						else if (j == 5)
						{
							content.clear();
							content = colorado;
						}
							
						else if (j == 6)
						{
							content.clear();
							content = connecticut;
						}
							
						else if (j == 7)
						{
							content.clear();
							content = district_of_columbia;
						}
							
						else if (j == 8)
						{
							content.clear();
							content = delaware;
						}
						
						else if (j == 9)
						{
							content.clear();
							content = florida;
						}
							
						else if (j == 10)
						{
							content.clear();
							content = georgia;
						}
							
						else if (j == 11)
						{
							content.clear();
							content = hawaii;
						}
							
						else if (j == 12)
						{
							content.clear();
							content = idaho;
						}
							
						else if (j == 13)
						{
							content.clear();
							content = illinois;
						}
							
						else if (j == 14)
						{
							content.clear();
							content = indiana;
						}
							
						else if (j == 15)
						{
							content.clear();
							content = iowa;
						}
							
						else if (j == 16)
						{
							content.clear();
							content = kansas;
						}
						
						else if (j == 17)
						{
							content.clear();
							content = kentucky;
						}
							
						else if (j == 18)
						{
							content.clear();
							content = louisiana;
						}
							
						else if (j == 19)
						{
							content.clear();
							content = maine;
						}
							
						else if (j == 20)
						{
							content.clear();
							content = maryland;
						}
							
						else if (j == 21)
						{
							content.clear();
							content = massachusetts;
						}
							
						else if (j == 22)
						{
							content.clear();
							content = michigan;
						}
							
						else if (j == 23)
						{
							content.clear();
							content = minnesota;
						}
							
						else if (j == 24)
						{
							content.clear();
							content = mississippi;
						}
						
						else if (j == 25)
						{
							content.clear();
							content = missouri;
						}
							
						else if (j == 26)
						{
							content.clear();
							content = montana;
						}
							
						else if (j == 27)
						{
							content.clear();
							content = nebraska;
						}
							
						else if (j == 28)
						{
							content.clear();
							content = nevada;
						}
							
						else if (j == 29)
						{
							content.clear();
							content = new_hampshire;
						}
							
						else if (j == 30)
						{
							content.clear();
							content = new_jersey;
						}
							
						else if (j == 31)
						{
							content.clear();
							content = new_mexico;
						}
							
						else if (j == 32)
						{
							content.clear();
							content = new_york;
						}
						
						else if (j == 33)
						{
							content.clear();
							content = north_carolina;
						}
							
						else if (j == 34)
						{
							content.clear();
							content = north_dakota;
						}
							
						else if (j == 35)
						{
							content.clear();
							content = ohio;
						}
							
						else if (j == 36)
						{
							content.clear();
							content = oklahoma;
						}
							
						else if (j == 37)
						{
							content.clear();
							content = oregon;
						}
							
						else if (j == 38)
						{
							content.clear();
							content = pennsylvania;
						}
							
						else if (j == 39)
						{
							content.clear();
							content = rhode_island;
						}
							
						else if (j == 40)
						{
							content.clear();
							content = south_carolina;
						}
						
						else if (j == 41)
						{
							content.clear();
							content = south_dakota;
						}
							
						else if (j == 42)
						{
							content.clear();
							content = tennessee;
						}
							
						else if (j == 43)
						{
							content.clear();
							content = texas;
						}
							
						else if (j == 44)
						{
							content.clear();
							content = utah;
						}
							
						else if (j == 45)
						{
							content.clear();
							content = vermont;
						}
							
						else if (j == 46)
						{
							content.clear();
							content = virginia;
						}
							
						else if (j == 47)
						{
							content.clear();
							content = washington;
						}
							
						else if (j == 48)
						{
							content.clear();
							content = west_virginia;
						}
						
						else if (j == 49)
						{
							content.clear();
							content = wisconsin;
						}
							
						else if (j == 50)
						{
							content.clear();
							content = wyoming;
						}
							
						else if (j == 51)
						{
							content.clear();
							content = all_states;
						}
						
							
						
						
						
						scrollbar = 0;
					}
				}
			}
				
			sf::Sprite Help;
			Help.setTexture(card_square);
			Help.setPosition(sf::Vector2f(888, 20));
			window.draw(Help);
			sf::Text Help_mark;
			Help_mark.setFont(cascadia);
			Help_mark.setString("?");
			Help_mark.setCharacterSize(40);
			Help_mark.setFillColor(sf::Color(text_color[0],text_color[1],text_color[2]));
			//center Help_mark in Help
			Help_mark.setPosition(sf::Vector2f(878 + (card_square.getSize().x - Help_mark.getLocalBounds().width)/2, (card_square.getSize().y - Help_mark.getLocalBounds().height)/2));
			window.draw(Help_mark);
			
			for (int l{ 1 }; l < 7; l++)
			{
				sf::Sprite Status_filter;
				Status_filter.setTexture(card_square);
				Status_filter.setPosition(sf::Vector2f(888, 20 + (card_square.getSize().y + 10)*l));
				window.draw(Status_filter);
				
				sf::Text hc_text;
				hc_text.setFont(cascadia);
				hc_text.setString("HC");
				hc_text.setCharacterSize(40);
				hc_text.setFillColor(sf::Color(text_color[0],text_color[1],text_color[2]));
				//center hc_text in Status_filter
				hc_text.setPosition(sf::Vector2f(880 + (card_square.getSize().x - hc_text.getLocalBounds().width)/2, 115));
				window.draw(hc_text);
					
				sf::Text hf_text;
				hf_text.setFont(cascadia);
				hf_text.setString("HF");
				hf_text.setCharacterSize(40);
				hf_text.setFillColor(sf::Color(text_color[0],text_color[1],text_color[2]));
				//center hf_text in Status_filter
				hf_text.setPosition(sf::Vector2f(880 + (card_square.getSize().x - hf_text.getLocalBounds().width)/2, 205));
				window.draw(hf_text);
				
				sf::Text ha_text;
				ha_text.setFont(cascadia);
				ha_text.setString("HA");
				ha_text.setCharacterSize(40);
				ha_text.setFillColor(sf::Color(text_color[0],text_color[1],text_color[2]));
				//center ha_text in Status_filter
				ha_text.setPosition(sf::Vector2f(880 + (card_square.getSize().x - ha_text.getLocalBounds().width)/2, 295));
				window.draw(ha_text);
			/////////////////////////////////////////////////
				sf::Text ac_text;
				ac_text.setFont(cascadia);
				ac_text.setString("AC");
				ac_text.setCharacterSize(40);
				ac_text.setFillColor(sf::Color(text_color[0],text_color[1],text_color[2]));
				//center ca_text in Status_filter
				ac_text.setPosition(sf::Vector2f(880 + (card_square.getSize().x - ac_text.getLocalBounds().width)/2, 385));
				window.draw(ac_text);
				
				sf::Text it_text;
				it_text.setFont(cascadia);
				it_text.setString("IT");
				it_text.setCharacterSize(40);
				it_text.setFillColor(sf::Color(text_color[0],text_color[1],text_color[2]));
				//center co_text in Status_filter
				it_text.setPosition(sf::Vector2f(880 + (card_square.getSize().x - it_text.getLocalBounds().width)/2, 475));
				window.draw(it_text);

				sf::Text hp_text;
				hp_text.setFont(cascadia);
				hp_text.setString("HP");
				hp_text.setCharacterSize(40);
				hp_text.setFillColor(sf::Color(text_color[0],text_color[1],text_color[2]));
				//center hp_text in Status_filter
				hp_text.setPosition(sf::Vector2f(880 + (card_square.getSize().x - hp_text.getLocalBounds().width)/2, 565));
				window.draw(hp_text);
				
				//if left mouse button is pressed
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//if mouse collides with hc_text
					if (hc_text.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						content.clear();
						content = hc;
					}
					//if mouse collides with hf_text
					else if (hf_text.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						content.clear();
						content = hf;
					}
					//if mouse collides with ha_text
					else if (ha_text.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						content.clear();
						content = ha;
					}
					
					//if mouse collides with ac_text
					else if (ac_text.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						content.clear();
						content = ac;
					}
					//if mouse collides with it_text
					else if (it_text.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						content.clear();
						content = it;
					}
					//if mouse collides with hp_text
					else if (hp_text.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
					{
						content.clear();
						content = hp;
					}
					
				}
				
			}
			
			//event polling
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				//keypresses
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
						window.close();
					else if (event.key.code == sf::Keyboard::Delete)
						terminal_disabled = !terminal_disabled;
					else if (event.key.code == sf::Keyboard::Return)
					{
						cout << scrollbar_state << endl;
					}
					else if (event.key.code == sf::Keyboard::Up)
						background_choice += 1;
					else if (event.key.code == sf::Keyboard::Down)
						background_choice -= 1;
					else if (event.key.code == sf::Keyboard::Left)
						text_choice -= 1;
					else if (event.key.code == sf::Keyboard::Right)
						text_choice += 1;
				}
				//if mouse is scrolled
				if (event.type == sf::Event::MouseWheelScrolled)
				{
					if (event.mouseWheelScroll.delta > 0)
						// if mouse x position is less than 750:
						if (mouse_pos.x < 800)
							scrollbar += scroll_speed * event.mouseWheelScroll.delta;
						else if (mouse_pos.x > 800)
						{
							scrollbar_state += (scroll_speed * 3) * event.mouseWheelScroll.delta;
						}
					if (event.mouseWheelScroll.delta < 0)
						if (mouse_pos.x < 800)
							scrollbar += scroll_speed * event.mouseWheelScroll.delta;
						else if (mouse_pos.x > 800)
						{
							scrollbar_state += (scroll_speed * 3) * event.mouseWheelScroll.delta;
						}
				}
				// if left mouse button is pressed
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						for (int i{ 0 }; i < content.size(); i++)
						{
							if (checked[i] == 1)
								checking = true;
						}
						if (Help.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							help_clicked = true;
							if (help_clicked = true);
							{
								if (help == true)
									help = false;
								else if (help == false)
									help = true;
								help_clicked = false;
							}
						}
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			if (help)
			{
				sf::Sprite help_box;
				help_box.setTexture(helping);
				help_box.setPosition(sf::Vector2f(0, 500));
				window.draw(help_box);

				sf::Sprite up_key;
				up_key.setTexture(up);
				up_key.setPosition(sf::Vector2f(100, 600));
				window.draw(up_key);

				sf::Sprite down_key;
				down_key.setTexture(down);
				down_key.setPosition(sf::Vector2f(100, 660));
				window.draw(down_key);
				
				sf::Sprite left_key;
				left_key.setTexture(left);
				left_key.setPosition(sf::Vector2f(70, 750));
				window.draw(left_key);

				sf::Sprite right_key;
				right_key.setTexture(right);
				right_key.setPosition(sf::Vector2f(130, 750));
				window.draw(right_key);

				sf::Text updown;
				updown.setFont(cascadia);
				updown.setString("Up and Down change the background color.");
				updown.setCharacterSize(30);
				updown.setFillColor(sf::Color(10,10,10));
				updown.setPosition(sf::Vector2f(180, 640));
				window.draw(updown);
				
				sf::Text leftright;
				leftright.setFont(cascadia);
				leftright.setString("Left and Right change the text color.");
				leftright.setCharacterSize(30);
				leftright.setFillColor(sf::Color(10,10,10));
				leftright.setPosition(sf::Vector2f(210, 755));
				window.draw(leftright);
			}
			//draw the window
			window.display();
		}
		//return okay if the program exits properly
		return 0;
	}
}