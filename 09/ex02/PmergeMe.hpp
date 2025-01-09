#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

typedef struct _pair
{
    int             winner;
    int             loser;
    struct _pair    *w_prev;
    struct _pair    *l_prev;
    struct _pair    *odd;
} Pair;

class   PmergeMe
{
    private:
        Pair    *generateRankedPair(Pair *p1, Pair *p2);
        Pair    *generateRankedPair(int p1, int p2);
        Pair    *generateASingle(int p1);

        std::vector<Pair *>::iterator   binarySearch(std::vector<Pair *> &main_chain, std::vector<Pair *>::size_type start, int target);
        std::deque<Pair *>::iterator   binarySearch(std::deque<Pair *> &main_chain, std::deque<Pair *>::size_type start, int target);
        std::vector<Pair *>::size_type   insertOdd(std::vector<Pair *> &main_chain, Pair *odd_man);
        std::deque<Pair *>::size_type   insertOdd(std::deque<Pair *> &main_chain, Pair *odd_man);
        void    insertInRange(std::vector<Pair *> &main_chain, std::vector<Pair *>::size_type start, std::vector<Pair *>::size_type count, Pair *odd_man);
        void    insertInRange(std::deque<Pair *> &main_chain, std::deque<Pair *>::size_type start, std::deque<Pair *>::size_type count, Pair *odd_man);

        void    insertLosers(std::vector<Pair *> &main_chain, std::vector<Pair *>::size_type target_size);
        void    insertLosers(std::deque<Pair *> &main_chain, std::deque<Pair *>::size_type target_size);
        Pair    *haveTournament(std::vector<Pair *> &players);
        Pair    *haveTournament(std::deque<Pair *> &players);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &);
        PmergeMe    &operator=(const PmergeMe &);
        ~PmergeMe();

        void    rank(std::vector<int> &players);
        void    rank(std::deque<int> &players);
};

#endif
