#include "Day8.h"
#include <iostream>
#include <memory>
#include "Car.h"
#include "Console.h"
#include "Input.h"
#include <GameTextures.h>


const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 550;
void Day8::PartB_1()
{
	std::string hello = "Hello Day 8!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		GameTextures::Initialize(engine.Renderer());

		std::vector<std::string> menuOptions{
			"1. Create a Stack BlackjackCard",
			"2. Create a Heap BlackjackCard",
			"3. Upcasting Blackjack Card pointers",
			"0. Exit" };
		ShowMenu("Day 8", menuOptions);



		engine.ClearScreen(50, 150, 50, 255);
		engine.Present();
		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
				{
					quit = true;
				}
				else if (e.type == SDL_KEYUP && e.key.repeat == 0)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_KP_1:
					case SDLK_1:
					{
						float scale = 1.0F;
						engine.ClearScreen(50, 150, 50, 255);

						//
						// TODO: Part B-1.2 Create a BlackjackCard object on the stack
						//

						pos cardSize = GameTextures::CardSize(scale);
						int x = 5;
						int y = 5;

						//
						// TODO: Part B-1.3  call GameTextures::RenderImage with the BlackjackCard object
						//


						//
						// TODO: Part B-1.4 
						// call the Print method
						// call the Value method and print the value
						//

						//Update screen
						engine.Present();
						break;
					}
					case SDLK_KP_2:
					case SDLK_2:
					{
						float scale = 1.0F;
						engine.ClearScreen(50, 150, 50, 255);

						//
						// TODO: Part B-2.1 Create a BlackjackCard object on the HEAP
						//

						pos cardSize = GameTextures::CardSize(scale);
						int x = 5;
						int y = 5;

						//
						// TODO: Part B-2.2  call GameTextures::RenderImage with the BlackjackCard Heap object
						//

						//
						// TODO: Part B-2.3 
						// call the Print method
						// call the Value method and print the value
						//

						//Update screen
						engine.Present();
						break;
					}
					case SDLK_KP_3:
					case SDLK_3:
					{
						float scale = 1.0F;
						engine.ClearScreen(50, 150, 50, 255);

						//
						// TODO: Part B-3.1 create a vector to store pointers to Card objects
						//

						pos cardSize = GameTextures::CardSize(scale);
						int x = 5;
						int y = 5;

						//
						// TODO: Part B-3.2 call the Value function
						//


						//
						// TODO: Part B-3.4  delete the objects
						//

						//Update screen
						engine.Present();
						break;
					}
					case SDLK_KP_0:
					case SDLK_0:
					{
						quit = true;
						break;
					}

					}
				}
			}

		}
		GameTextures::Cleanup();
	}
	engine.Close();

}