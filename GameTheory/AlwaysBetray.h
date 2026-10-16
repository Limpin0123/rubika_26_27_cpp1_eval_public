#pragma once

#include "IStrategy.h"
class AlwaysBetray : public IStrategy
{
public:
	AlwaysBetray(const std::string& name) : IStrategy(name) {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

