#include "Resentful.h"

Choice Resentful::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    for (Choice choice : opponentPreviousDecisions)
    {
        if (choice == Choice::Betray)
        {
            return Choice::Betray;
        }
    }
    return Choice::Cooperate;
}
