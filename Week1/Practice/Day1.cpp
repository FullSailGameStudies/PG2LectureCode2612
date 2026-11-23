#include "Day1.h"
#include <string>
#include <vector>
#include <Console.h>
#include <Input.h>
#include "Player.h"
#include "Map.h"
#include "Target.h"

void Day1::PartA_2()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 750;
	const int SCREEN_HEIGHT = 750;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part A-1.3"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::Write("Part A-2 Goal: ", ConsoleColor::Green);
		Console::WriteLine("Before the while loop, move the player to the target.");
		Console::WriteLine("HINT: explore the Player.h file to see what methods could be used.");

		float scale = 0.25f;
		Player steev(&engine, scale, 1, 1);
		if (!steev.IsValid())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Map map(engine.Renderer(), steev.Size());
			map.mapData =
			{
				1,1,1,1,1,1,1,1,1,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1
			};

			Target target{ 7, 6, 0xD9, 0xD6, 0x02 };
			PG2Texture oreTexture(engine.Renderer());
			if (!oreTexture.LoadFromFile("diamonds.png"))
			{
				Console::WriteLine("\n\nFAILED to load diamonds.png", ConsoleColor::Red);
			}
			oreTexture.BlendMode(SDL_BLENDMODE_NONE);

			steev.SetMap(map.mapData, 10, 10);

			bool quit = false;
			SDL_Event e;


			//
			//Part A-2: move player to a predefined Target spot 
			//
			for (int i = 0; i < 5; i++)
			{
				steev.MoveDown();
				steev.MoveRight();
			}
			steev.MoveRight();

			bool canMoveInDirection = steev.CanMove(Direction::Up);
			if (canMoveInDirection)
			{

			}


			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE && e.type == SDL_KEYUP))
					{
						quit = true;
					}
				}

				engine.ClearScreen(0, 0, 0, 0xFF); 

				map.DrawMap2D();
				//map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
				map.DrawCell(target.col, target.row, &oreTexture, 1);

				steev.Render();

				//Update screen
				engine.Present();
			}
		}
	}
	engine.Close();
}


//
// Part A-4.2: create the DEFINITION for CreateTargets
//
//  % N results in 0 - (N-1)
//rand() % mapSize - range is 0 to mapSize-1
std::vector<Target> Day1::CreateTargets(int mapSize)
{
	std::vector<Target> targets;

	for (int i = 0; i < 10; i++)
	{
		Target t1000;
		t1000.row = rand() % mapSize;
		t1000.col = rand() % mapSize;

		targets.push_back(t1000);
	}

	return targets;
}

void Day1::PartA_4()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 750;
	const int SCREEN_HEIGHT = 750;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part A-2"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::Write("Part A-4 Goal: ", ConsoleColor::Green);
		Console::WriteLine("Add a method called CreateTargets");

		int mapSize = 10;
		//use rand() % mapSize to generate the col and row.
		Target example;
		example.col = rand() % mapSize;
		example.row = rand() % mapSize;

		//use rand() % colorRange to generate each color component (red, green, and blue)
		int colorRange = 255;
		example.red = rand() % colorRange;
		example.green = rand() % colorRange;
		example.blue = rand() % colorRange;

		//
		// Part A-4.3: Call CreateTargets and store the returned vector into the "targets" variable.
		//
		std::vector<Target> targets;
		targets = CreateTargets(mapSize);

		float scale = 0.25f;
		Player player(&engine, scale, 1, 1);
		if (!player.IsValid())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Map map(engine.Renderer(), player.Size());
			map.mapData =
			{
				1,1,1,1,1,1,1,1,1,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,0,0,0,0,0,0,0,0,1,
				1,1,1,1,1,1,1,1,1,1
			};
			//Target target{ 7,6,0xD9, 0xD6, 0x02 };
			PG2Texture oreTexture(engine.Renderer());
			if (!oreTexture.LoadFromFile("diamonds.png"))
			{
				Console::WriteLine("\n\nFAILED to load diamonds.png", ConsoleColor::Red);
			}
			oreTexture.BlendMode(SDL_BLENDMODE_NONE);

			player.SetMap(map.mapData, 10, 10);

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
				}

				engine.ClearScreen(0, 0, 0, 0xFF); 

				map.DrawMap2D();

				for (auto& target : targets)
				{
					map.DrawCell(target.col, target.row, &oreTexture);
				}

				//Update screen
				engine.Present();
			}
		}
	}
	engine.Close();
}