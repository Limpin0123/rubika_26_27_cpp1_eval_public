#include "AlwaysCooperate.h"

Choice AlwaysCooperate::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
	return Choice::Cooperate;
}
