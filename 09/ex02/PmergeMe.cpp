#include "PmergeMe.hpp"
#include <iostream>
#include <set>

void  printVector(const std::vector<Pair *> &v)
{
    std::vector<Pair *>::const_iterator it = v.begin();
    std::vector<Pair *>::const_iterator ite = v.end();

    while (it != ite)
    {
//          std::cout << (*it)->winner << " ";
        std::cout << "winner: " << (*it)->winner << " loser: " << (*it)->loser << std::endl;
        ++it;
    }
    std::cout << std::endl;
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

void    PmergeMe::rank(std::vector<int> &players)
{
    std::vector<Pair *>   initial_pairs;
    std::vector<int>::size_type players_size = players.size();

    if (players_size > 1)
    {
        Pair    *odd_man = NULL;
        if (players_size % 2)
        {
            odd_man = generateASingle(players.back());
        }

        for (std::vector<int>::size_type i = 0; i < players_size - 1; i += 2)
        {
            Pair    *new_pair = generateRankedPair(players[i], players[i + 1]);
            new_pair->odd = odd_man;
            initial_pairs.push_back(new_pair);
        }

        Pair    *tree = haveTournament(initial_pairs);
        std::vector<Pair *> main_chain;
        if (tree->w_prev)
        {
            main_chain.push_back(tree->w_prev);
            main_chain.push_back(tree->l_prev);
        }
        else
        {
            main_chain.push_back(generateASingle(tree->winner));
            main_chain.push_back(generateASingle(tree->loser));
        }

        if (tree->odd)
        {
            insertOdd(main_chain, tree->odd);
        }

        insertLosers(main_chain, players_size);

        std::vector<Pair *>::size_type  j = 0;
        for (std::vector<Pair *>::size_type i = players_size; i-- > 0; )
        {
            players[j] = main_chain[i]->winner;
            ++j;
        }
    }
}

std::vector<Pair *>::iterator   PmergeMe::insertOdd(std::vector<Pair *> &main_chain, Pair *odd_man)
{
    std::vector<Pair *>::iterator   pos = binarySearch(main_chain, 0, odd_man->winner);
    Pair    *odd_to_insert = odd_man->w_prev ? odd_man->w_prev : odd_man;
    main_chain.insert(pos, odd_to_insert);
    return pos;
}

void    PmergeMe::insertInRange(std::vector<Pair *> &main_chain, std::vector<Pair *>::size_type start, std::vector<Pair *>::size_type count, Pair *odd_man = NULL)
{
//    printVector(main_chain);
    std::vector<Pair *>::size_type  range = start + count;

    std::set<Pair *>    inserted;
    Pair    *loser_to_insert = NULL;
    for (std::vector<Pair *>::size_type i = start; i < range; ++i)
    {
        // 바로 다음 칸에 들어간 경우가 아니라 그냥 range 안에 있기만 해도 안됨.
        // 하아아 이런 짜치는 방법 밖에는 없다는 말인가
        if (inserted.find(main_chain[i]) != inserted.end() || odd_man == main_chain[i])
        {
            inserted.erase(main_chain[i]);
            continue;
        }

        loser_to_insert = main_chain[i]->l_prev;
        std::vector<Pair *>::iterator   pos;
        if (loser_to_insert)
        {
            pos = binarySearch(main_chain, i + 1, loser_to_insert->winner);
            main_chain[i] = main_chain[i]->w_prev;
        }
        else
        {
            loser_to_insert = generateASingle(main_chain[i]->loser);
            pos = binarySearch(main_chain, i + 1, loser_to_insert->winner);
        }

        unsigned long   inserted_pos_idx = pos - main_chain.begin();

        main_chain.insert(pos, loser_to_insert);
        inserted.insert(loser_to_insert);

        if (pos != main_chain.end() && inserted_pos_idx < range)
        {
            ++range;
        }
    }
}

void    PmergeMe::insertLosers(std::vector<Pair *> &main_chain, std::vector<Pair *>::size_type target_size)
{
    if (main_chain.size() >= target_size)
    {
        return;
    }

    Pair    *odd_man = main_chain[0]->odd;

    int k = 0;
    std::vector<Pair *>::size_type  before = main_chain.size();
    std::vector<Pair *>::size_type  count = 0;
    for (std::vector<Pair *>::size_type i = main_chain.size(); i-- > 0; )
    {
        std::vector<Pair *>::size_type  revised_idx = main_chain.size() - i;
        if (revised_idx == (1 << k))
        {
            count = before - i;
            insertInRange(main_chain, i, count);
            before = i;
            ++k;
            if (k == 1)
            {
                ++k;
            }
        }
    }

    if (odd_man)
    {
        std::vector<Pair *>::iterator   begin = main_chain.begin();
        std::vector<Pair *>::iterator   pos = insertOdd(main_chain, odd_man);
        if (pos != main_chain.end() && static_cast<unsigned long>(pos - begin) < before)
        {
            ++before;
        }
        odd_man = *pos;
    }
    count = before;
    insertInRange(main_chain, 0, count, odd_man);

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
    Pair    *new_pair = new Pair();

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
