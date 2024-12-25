template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T, std::deque<T> >(other)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    if (this != &other)
    {
        std::stack<T, std::deque<T> >::operator=(other);
    }

    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator    MutantStack<T>::begin()
{
    return std::stack<T, std::deque<T> >::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator    MutantStack<T>::end()
{
    return std::stack<T, std::deque<T> >::c.end();
}
