# CPP-Module 04

- virtual
- 순수가상함수
  - 순수가상함수/가상함수 차이?
    - 순수가상함수는 *재정의를 반드시 재정의를 해야  하는 함수*, 가상함수는 *재정의를 할 것으로 기대하는 함수*이다.
- 추상 클래스의 조건
  - 순수가상함수를 한개 이상 포함하고 있는 클래스를 추상 클래스라고 한다.
- 인터페이스의 조건
  - 추상 클래스와 인터페이스 차이
    - 인터페이스는 구현이 없다.
    - 인터페이스는 *pure virtual* 클래스이다.
    - 인터페이스를 상속받는 파생 클래스는 인터페이스에서 선언된 모든 메소드를 구현해야 한다.
    - 예를 들면 *인터페이스 : 파생 클래스 = 헤더파일 : 구현파일* 정도의 관계로 생각할 수 있다.

## Subtype

[Subtyping](https://en.wikipedia.org/wiki/Subtyping)

A subtype is a datatype related to another datatype(the supertype) by some notion of substitutability.

The program elements written to operate on elements of the supertype, can also operate on elements of the subtype.

If *S* is a subtype of *T*, the subtyping relation means that any term of type *S* can safely be used in any context where a term of type *T* is expected.

In a number of object-oriented languages, subtyping is called **interface inheritance**, with inheritance reffered as implementation inheritance.
