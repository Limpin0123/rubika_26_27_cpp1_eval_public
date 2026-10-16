#include "Prober.h"

Choice Prober::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (opponentPreviousDecisions.size() == 0)
    {
        return Choice::Betray;
    }
    else if(opponentPreviousDecisions.size() <= 3)
    {
        //Cooperative for 2 rounds
        return Choice::Cooperate;
    }
    else
    {
        bool didBetray = opponentPreviousDecisions.at(0) == Choice::Betray ||
                        opponentPreviousDecisions.at(1) == Choice::Betray ||
                        opponentPreviousDecisions.at(2) == Choice::Betray;
        if (didBetray)
        {
            //TitForTat
            return opponentPreviousDecisions.at(opponentPreviousDecisions.size() - 1);
        }
        else
        {
            //always betray
            return Choice::Betray;
        }
    }
}
