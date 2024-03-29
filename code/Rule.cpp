#include <vector>
#include <string>
#include "Predicate.h"
#include "Rule.h"
#include <sstream>

using namespace std;

string Rule::toString() const
{
    stringstream ss;

    ss << headPredicate.toString() << " :- ";

    for (unsigned int i = 0; i < bodyPredicates.size(); i++)
    {
        ss << bodyPredicates.at(i).toString();

        if (i < bodyPredicates.size() -1 )
        {
            ss << ",";
        }
    }

    ss << ".";

    return ss.str();
}

string Rule::getName() const
{
    return headPredicate.getName();
}

void Rule::addPredicate(Predicate& predicate)
{
    bodyPredicates.push_back(predicate);
}

void Rule::addPredicates(vector<Predicate> predicates)
{
    for (unsigned int i = 0; i < predicates.size(); i++)
    {
        bodyPredicates.push_back(predicates.at(i));
    }
}

vector<Predicate> Rule::getBodyPredicates() const
{
    return bodyPredicates;
}

Predicate Rule::getHeadPredicate() const
{
    return headPredicate;
}