#include "Pavlov.h"

Choice Pavlov::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    if (opponentPreviousDecisions.size() == 0)
    {
        return Choice::Cooperate;
    }
    const Choice& lastChoice = previousDecisions.at(previousDecisions.size() - 1);
    const Choice& lastOpponentChoice = opponentPreviousDecisions.at(opponentPreviousDecisions.size() - 1);

    if (lastChoice == Choice::Betray && lastOpponentChoice == Choice::Betray ||
        lastChoice == Choice::Cooperate && lastOpponentChoice == Choice::Betray)
    {
        return (Choice)(((int)lastChoice + 1) % 2);
    }
    else return lastChoice;
}
