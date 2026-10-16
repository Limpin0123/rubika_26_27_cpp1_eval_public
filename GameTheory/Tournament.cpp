#include "Tournament.h"

#include <algorithm>

#include "AlwaysCooperate.h"
#include "AlwaysBetray.h"
#include "TitforTat.h"
#include "Resentful.h"
#include "Random.h"
#include "Pavlov.h"
#include "Prober.h"

Tournament::~Tournament()
{
	for (IStrategy* strategy : strategies)
	{
		delete strategy;
	}
}

void Tournament::PopulateStrategy()
{
	strategies.push_back(new AlwaysCooperate("Cooperate"));
	strategies.push_back(new AlwaysBetray("Betray"));
	strategies.push_back(new TitforTat("TitforTat"));
	strategies.push_back(new Resentful("Resentful"));
	strategies.push_back(new Random("Random"));
	strategies.push_back(new Pavlov("Pavlov"));
	strategies.push_back(new Pavlov("Prober"));

	for (IStrategy* strategy : strategies)
	{
		Ranking r = Ranking();
		r.StrategyName = strategy->Name;
		r.TotalPoint = 0;
		r.Win = 0;
		r.Draw = 0;
		r.Lose = 0;

		gameResults.emplace(strategy, r);
	}
}

void Tournament::Simulate()
{
	std::vector<Choice> previousDecisions;
	std::vector<Choice> opponentPreviousDecisions;
	int points = 0;
	int opponentpoints = 0;
	for (int index = 0; index < strategies.size(); index++)
	{
		for (int index2 = index; index2 < strategies.size(); index2++)
		{
			IStrategy*& str1 = strategies.at(index);
			IStrategy*& str2 = strategies.at(index2);

			for (int matchIndex = 0; matchIndex < 50; matchIndex++)
			{
				Choice choice = str1->Decide(previousDecisions, opponentPreviousDecisions);
				Choice opponentChoice = str2->Decide(previousDecisions, opponentPreviousDecisions);

				UpdatePoints(str1 == str2, points, opponentpoints, choice, opponentChoice);

				previousDecisions.push_back(choice);
				opponentPreviousDecisions.push_back(opponentChoice);
			}
			UpdateGameResult(str1 == str2, str1, str2, points, opponentpoints);
			points = 0;
			opponentpoints = 0;
			previousDecisions.clear();
			opponentPreviousDecisions.clear();
		}
	}
}

std::vector<Ranking> Tournament::GenerateFinalRankingByPoint() const
{
	std::vector<Ranking> rankings;
	for (auto strategyPair : gameResults)
	{
		rankings.emplace_back(strategyPair.second);
	}

	std::sort(rankings.begin(), rankings.end(), [](Ranking& r1, Ranking& r2)
		{
			if (r1.TotalPoint == r2.TotalPoint)
			{
				if (r1.Win == r2.Win)
				{
					if (r1.Draw == r2.Draw)
					{
						return r1.Lose < r2.Lose;
					}
					else
					{
						return r1.Draw > r2.Draw;
					}
				}
				else
				{
					return r1.Win > r2.Win;
				}
			}
			else
			{
				return r1.TotalPoint > r2.TotalPoint;
			}
		});

	return rankings;
}

std::vector<Ranking> Tournament::GenerateFinalRankingByWinDrawLoss() const
{
	std::vector<Ranking> rankings;
	for (auto strategyPair : gameResults)
	{
		rankings.emplace_back(strategyPair.second);
	}

	std::sort(rankings.begin(), rankings.end(), [](Ranking& r1, Ranking& r2)
		{
			if (r1.Win == r2.Win)
			{
				if (r1.Draw == r2.Draw)
				{
					return r1.Lose < r2.Lose;
				}
				else
				{
					return r1.Draw > r2.Draw;
				}
			}
			else
			{
				return r1.Win > r2.Win;
			}
		});

	return rankings;
}

void Tournament::UpdatePoints(bool isSelfFighting, int& point1, int& point2, const Choice& choice1, const Choice& choice2)
{
	switch (choice1)
	{
	case Choice::Cooperate:
		if (choice2 == Choice::Cooperate)
		{
			point1 += 3;
			point2 += 3;
		}
		else
		{
			point1 += 0;
			if (!isSelfFighting) point2 += 5;
		}
		break;

	case Choice::Betray:
		if (choice2 == Choice::Cooperate)
		{
			point1 += 5;
			if (!isSelfFighting) point2 += 0;
		}
		else
		{
			point1 += 1;
			if (!isSelfFighting) point2 += 1;
		}
		break;
	}
}

void Tournament::UpdateGameResult(bool isSelfFighting, IStrategy*& str1, IStrategy*& str2, const int& point1, const int& point2)
{
	if (point1 == point2)
	{
		gameResults.at(str1).Draw++;
		if (!isSelfFighting) gameResults.at(str2).Draw++;
	}
	else if(point1 > point2)
	{
		gameResults.at(str1).Win++;
		if (!isSelfFighting) gameResults.at(str2).Lose++;
	}
	else
	{
		gameResults.at(str1).Lose++;
		if (!isSelfFighting) gameResults.at(str2).Win++;
	}

	gameResults.at(str1).TotalPoint += point1;
	if (!isSelfFighting) gameResults.at(str2).TotalPoint += point2;
}
