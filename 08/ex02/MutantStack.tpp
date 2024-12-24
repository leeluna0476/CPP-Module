template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other) : _storage(other._storage)
{
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &other)
{
    this->_storage = other._storage;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, typename Container>
bool    MutantStack<T, Container>::empty() const
{
    return _storage.empty();
}

template <typename T, typename Container>
size_t    MutantStack<T, Container>::size() const
{
    return _storage.size();
}

template <typename T, typename Container>
T    &MutantStack<T, Container>::top()
{
    return _storage.back();
}

template <typename T, typename Container>
const T    &MutantStack<T, Container>::top() const
{
    return _storage.back();
}

template <typename T, typename Container>
void    MutantStack<T, Container>::push(const T &value)
{
    _storage.push_back(value);
}

template <typename T, typename Container>
void    MutantStack<T, Container>::pop()
{
    _storage.pop_back();
}

template <typename T, typename Container>
MutantStack<T, Container>::Iterator::Iterator() : _it(NULL)
{
}

template <typename T, typename Container>
MutantStack<T, Container>::Iterator::Iterator(const Iterator &other) : _it(other._it)
{
}

template <typename T, typename Container>
typename MutantStack<T, Container>::Iterator   &MutantStack<T, Container>::Iterator::operator=(const Iterator &other)
{
    if (this != &other)
    {
        _it = other._it;
    }

    return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::Iterator::Iterator(typename Container::iterator it) : _it(it)
{
}

template <typename T, typename Container>
MutantStack<T, Container>::Iterator::~Iterator()
{
}

template <typename T, typename Container>
T   &MutantStack<T, Container>::Iterator::operator*()
{
    return *_it;
}

template <typename T, typename Container>
const T &MutantStack<T, Container>::Iterator::operator*() const
{
    return *_it;
}

template <typename T, typename Container>
void    MutantStack<T, Container>::Iterator::operator++()
{
    ++_it;
}

template <typename T, typename Container>
void    MutantStack<T, Container>::Iterator::operator--()
{
    --_it;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::Iterator MutantStack<T, Container>::Iterator::operator+(int n)
{
    return Iterator(_it + n);
}

template <typename T, typename Container>
bool    MutantStack<T, Container>::Iterator::operator==(const typename MutantStack<T, Container>::Iterator &other) const
{
    return _it == other._it;
}

template <typename T, typename Container>
bool    MutantStack<T, Container>::Iterator::operator!=(const typename MutantStack<T, Container>::Iterator &other) const
{
    return !(*this == other);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::Iterator   MutantStack<T, Container>::begin()
{
    return Iterator(_storage.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::Iterator   MutantStack<T, Container>::end()
{
    return Iterator(_storage.end());
}

template <typename T, typename Container>
bool    operator==(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return x._storage == y._storage;
}

template <typename T, typename Container>
bool    operator<(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return x._storage < y._storage;
}

template <typename T, typename Container>
bool    operator!=(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return !(x == y);
}

template <typename T, typename Container>
bool    operator>(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return y < x;
}

template <typename T, typename Container>
bool    operator>=(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return !(x < y);
}

template <typename T, typename Container>
bool    operator<=(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return !(y < x);
}
