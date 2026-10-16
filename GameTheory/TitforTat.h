#pragma once

#include "IStrategy.h"
class TitforTat : public IStrategy
{
public:
	TitforTat(const std::string& name) : IStrategy(name) {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

