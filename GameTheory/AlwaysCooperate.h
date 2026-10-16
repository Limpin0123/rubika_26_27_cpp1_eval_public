#pragma once

#include "IStrategy.h"

class AlwaysCooperate : public IStrategy
{
public:
	AlwaysCooperate(const std::string& name) : IStrategy(name) {}
	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override;
};

