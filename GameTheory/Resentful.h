#pragma once

#include "IStrategy.h"
class Resentful : public IStrategy
{
public:
	Resentful(const std::string& name) : IStrategy(name) {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

