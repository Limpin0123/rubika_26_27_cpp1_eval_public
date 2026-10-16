#pragma once

#include "IStrategy.h"
class Random : public IStrategy
{
public:
	Random(const std::string& name) : IStrategy(name) {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

