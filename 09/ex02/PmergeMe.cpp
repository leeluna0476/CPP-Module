#include "PmergeMe.hpp"
#include <iostream>

void  printVector(const std::vector<Pair *> &v)
{
    std::vector<Pair *>::const_iterator it = v.begin();
    std::vector<Pair *>::const_iterator ite = v.end();

    while (it != ite)
    {
        std::cout << "winner: " << (*it)->winner << " loser: " << (*it)->loser << std::endl;
        ++it;
    }
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &)
{
}

PmergeMe    &PmergeMe::operator=(const PmergeMe &)
{
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void    PmergeMe::rank(const std::vector<int> &players)
{
    std::vector<int>::const_iterator  it = players.begin();
    std::vector<int>::const_iterator  ite = players.end();

    std::vector<Pair *>   initial_pairs;
    while (it != ite)
    {
        initial_pairs.push_back(generateRankedPair(*it, *(it + 1)));
        it += 2;
    }

    Pair    *tree = haveTournament(initial_pairs);
    printPairTree(tree);
}

Pair    *PmergeMe::generateRankedPair(Pair *p1, Pair *p2)
{
    Pair    *new_pair = new Pair;

    if (p1->winner > p2->winner)
    {
        new_pair->winner = p1->winner;
        new_pair->w_prev = p1;
        new_pair->loser = p2->winner;
        new_pair->l_prev = p2;
    }
    else
    {
        new_pair->winner = p2->winner;
        new_pair->w_prev = p2;
        new_pair->loser = p1->winner;
        new_pair->l_prev = p1;
    }

    return new_pair;
}

Pair    *PmergeMe::generateRankedPair(int p1, int p2)
{
    Pair    *new_pair = new Pair();

    if (p1 > p2)
    {
        new_pair->winner = p1;
        new_pair->loser = p2;
    }
    else
    {
        new_pair->winner = p2;
        new_pair->loser = p1;
    }

    return new_pair;
}

Pair    *PmergeMe::generateASingle(int p1)
{
    Pair    *new_single = new Pair();

    new_single->winner = p1;

    return new_single;
}

Pair    *PmergeMe::haveTournament(std::vector<Pair *> &players_in_pair)
{
    if (players_in_pair.size() == 1)
    {
        return players_in_pair.front();
    }

    std::vector<Pair *> next_pairs;
    std::vector<Pair *>::size_type  count = players_in_pair.size() / 2 * 2;

    Pair    *oddMan = NULL;
    if (players_in_pair.size() != count)
    {
        oddMan = new Pair();
        oddMan->winner = players_in_pair.back()->winner;
        oddMan->w_prev = players_in_pair.back();
    }

    for (std::vector<Pair *>::size_type i = 0; i < count; i += 2)
    {
        next_pairs.push_back(generateRankedPair(players_in_pair[i], players_in_pair[i + 1]));
        next_pairs.back()->odd = oddMan;
    }

    return haveTournament(next_pairs);
}

void    PmergeMe::printPairTree(Pair *head)
{
    if (head == NULL)
    {
        return;
    }

    std::cout << "{\n";
    std::cout << "\twinner: " << head->winner << std::endl;
    std::cout << "\tloser: " << head->loser << std::endl;
    if (head->odd)
    {
        std::cout << "\todd: " << head->odd->winner << std::endl;
        std::cout << "}" << std::endl;
        printPairTree(head->odd->w_prev);
    }
    else
    {
        std::cout << "}" << std::endl;
    }

    printPairTree(head->w_prev);
    printPairTree(head->l_prev);
}
