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
typename MutantStack<T, Container>::iterator    MutantStack<T, Container>::begin()
{
    return _storage.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator    MutantStack<T, Container>::end()
{
    return _storage.end();
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
