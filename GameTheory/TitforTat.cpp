#include "TitforTat.h"

Choice TitforTat::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (opponentPreviousDecisions.size() == 0)
    {
        return Choice::Cooperate;
    }
    else
    {
        return opponentPreviousDecisions.at(opponentPreviousDecisions.size() - 1);
    }
}
