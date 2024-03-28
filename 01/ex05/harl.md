# Harl 2.0

```cpp
void	debug(void);
void	info(void);
void	warning(void);
void	error(void);
```

1. Dictionary처럼 사용할 `std::string` 배열 선언. `key:value = index::name`
2. 위와 상응하는 멤버함수포인터 배열 선언. `index::name = index::function`
3. for문에서 std::string 배열에서 해당하는 이름을 찾은 뒤, 그 인덱스로 멤버함수포인터 배열에서 함수를 찾아 호출한다.
