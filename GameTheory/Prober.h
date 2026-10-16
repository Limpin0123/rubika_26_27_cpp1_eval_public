#pragma once
#include "IStrategy.h"
class Prober : public IStrategy
{
public:
	Prober(const std::string& name) : IStrategy(name) {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

