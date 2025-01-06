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

    std::vector<Pair *> main_chain;
    main_chain.push_back(tree->w_prev);
    main_chain.push_back(tree->l_prev);

    insertLosers(main_chain, players.size());
    printVector(main_chain);
}

void    PmergeMe::insertInRange(std::vector<Pair *> &main_chain, std::vector<Pair *>::size_type start, std::vector<Pair *>::size_type end)
{
    std::vector<std::vector<Pair *>::iterator>  update_pos;
    std::vector<Pair *>                         update_val;
    for (std::vector<Pair *>::size_type i = start; i < end; ++i)
    {
        Pair    *loser_to_insert = main_chain[i]->l_prev;
        if (loser_to_insert)
        {
            update_val.push_back(loser_to_insert);
            update_pos.push_back(binarySearch(main_chain, i + 1, loser_to_insert->winner));
            main_chain[i] = main_chain[i]->w_prev;
        }
        else
        {
        }
    }

    for (std::vector<Pair *>::size_type i = 0; i < update_pos.size(); ++i)
    {
        main_chain.insert(update_pos[i], update_val[i]);
    }
}

void    PmergeMe::insertLosers(std::vector<Pair *> &main_chain, std::vector<Pair *>::size_type target_size)
{
//    printVector(main_chain);
    if (main_chain.size() == target_size / 2)
    {
        return;
    }

    Pair    *odd_man = main_chain.front()->odd;

    int k = 0;
    for (std::vector<Pair *>::size_type i = main_chain.size(); i-- > 0; )
    {
        std::vector<Pair *>::size_type  revised_idx = main_chain.size() - i;
        if (revised_idx == (1 << k))
        {
            insertInRange(main_chain, i, k > 0 ? 1 << (k - 1) : i + 1);
            ++k;
            if (k == 1)
            {
                ++k;
            }
        }
    }

    if (odd_man)
    {
        // search and insert
        std::vector<Pair *>::iterator   pos = binarySearch(main_chain, 0, odd_man->winner);
        main_chain.insert(pos, odd_man->w_prev);
    }
    insertInRange(main_chain, 0, 1 << (k - 1));

    insertLosers(main_chain, target_size);
}

std::vector<Pair *>::iterator   PmergeMe::binarySearch(std::vector<Pair *> &main_chain, std::vector<Pair *>::size_type start, int target)
{
    int left = start;
    int right = main_chain.size() - 1;
    int mid = (left + right) / 2;

    while (left <= right)
    {
        if (main_chain[mid]->winner > target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }

        mid = (left + right) / 2;
    }

    if (static_cast<std::vector<Pair *>::size_type>(left) == main_chain.size())
    {
        return main_chain.end();
    }

    return main_chain.begin() + left;
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
