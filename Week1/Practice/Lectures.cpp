#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

int main(int argc, char* args[])
{
	Day2 day2;

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Calling static methods",
		"2. Part A-2: Calling non-static methods",
		"3. Part A-3: Return Values and Passing arguments",
		"4. Part A-4: Creating methods\n",
		"5. Part B-1: Pass by reference",
		"6. Part B-2: Const",
		"7. Part B-3: Erasing in a loop\n",
		"8. Part C-1: Default Parameters",
		"9. Part C-2: Copying Vectors\n",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//
			Console::Write("Batman is > Superman?");
			Console::WriteLine(" YES!", ConsoleColor::Blue, ConsoleColor::White);
			break;
		}
		case 2:
		{
			//
			// part A-2: Calling non-static methods
			//
			Day1::PartA_2();
			break;
		}
		case 3:
		{
			//
			// part A-3: Getting return values and passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code here to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			// 
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			int age = 0;
			age = Input::GetInteger("What is your age?", 0, 120);
			//std::cout << "Your age is " << age << ". Figures.\n";
			Console::WriteLine("Your age is " + std::to_string(age));
			break;
		}
		case 4:
		{
			//
			// part A-4: Creating methods
			//
			Day1::PartA_4();
			break;
		}
		case 5:
		{
			//
			// part B-1: Pass by reference
			//
			break;
		}
		case 6:
		{
			//
			// part B-2: const
			//
			break;
		}
		case 7:
		{
			//
			// part B-3: Erasing in a loop
			//
			break;
		}
		case 8:
		{
			//
			// part C-1: Default Parameters
			//
			break;
		}
		case 9:
		{
			//
			// part C-2: Copying Vectors
			//
			break;
		}
		case 10:
		{
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}

