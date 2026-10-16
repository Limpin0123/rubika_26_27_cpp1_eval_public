#pragma once

#include "Ranking.h"
#include "Choice.h"

#include <vector>
#include <unordered_map>

class IStrategy;

class Tournament
{
public:
	~Tournament();

	void PopulateStrategy();

	void Simulate();

	std::vector<Ranking> GenerateFinalRankingByPoint() const;
	std::vector<Ranking> GenerateFinalRankingByWinDrawLoss() const;

private:
	void UpdatePoints(bool isSelfFighting, int& point1, int& point2, const Choice& choice1, const Choice& choice2);
	void UpdateGameResult(bool isSelfFighting, IStrategy*& str1, IStrategy*& str2, const int& point1, const int& point2);

	std::vector<IStrategy*> strategies;
	std::unordered_map<IStrategy*, Ranking> gameResults;
};