#include "Random.h"

Choice Random::Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions)
{
    return (Choice)(std::rand()%2);
}
