#pragma once
#include <vector>
#include "Target.h"
class Day1
{
public:
	static void PartA_2();
	static void PartA_4();

	//
	// Part A-4.1: create the DECLARATION for CreateTargets
	//
	static std::vector<Target> CreateTargets(int mapSize);
};

