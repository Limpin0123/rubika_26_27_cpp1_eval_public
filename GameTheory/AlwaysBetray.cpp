#include "AlwaysBetray.h"

Choice AlwaysBetray::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    return Choice::Betray;
}
