#include <iostream>
#include <type_traits>
#include <set>
#include <vector>

namespace asdf {
    class A {
    public:
        int x;

        A(int x) : x(x) {}
    };

    class B : public A {
    public:
        int y;

        B(int x, int y) : A(x), y(y) {}

        explicit B(const A &a) : A(a.x), y(0) {}
    };

    template<int n>
    struct V {
        void print() {
            std::cout << n << std::endl;
        }
    };

    template<int m, int n>
    V<m + n> multiply(V<m>, V<n>) {
        return V<m + n>{};
    }

    template<class T, int n>
    struct C {
    };
}

namespace testingasdf {
    class A {
    };

    class B: A {
    };

    template<typename T, std::enable_if_t<std::is_base_of_v<A, T>, std::nullptr_t> = nullptr>
    class C {};

    template<typename T, std::enable_if_t<std::is_base_of_v<A, T>, std::nullptr_t> = nullptr>
    class D: public C<T> {
    };
}

namespace testing {
    struct V {
        int v;
        V(int v): v(v) {}
    };

    template<class T>
    struct C {
        virtual void print() = 0;
    };
}


int main() {
    using namespace testing;
    V a = {1}, b = {2}, c = {5}, d = {6};
    std::vector<V*> list = {&a, &b, &c, &d};
    std::cout << c.v << std::endl;
    list.at(2)->v = 7;
    std::cout << c.v << std::endl;


    std::function<bool(int, int)> comp = [](int x, int y) {
        return abs(x) < abs(y);
    };
    std::cout << typeid(comp).name() << std::endl;
    std::multiset<int, decltype(comp)> ms({1, 2, 3, 4, 5, 6, 7, -8, -1, -2, -3, 9, -7}, comp);
    for (int n : ms) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    // int arr[] = {1, 2, 3, 4, 5};
    /**A a = {1};
    A *apt = &a;
    B b = {13, 7};
    B b2 = B(a);
    std::cout << "type: " << typeid(std::enable_if_t<true, int>).name() << std::endl;
    std::cout << "type: " << typeid(std::enable_if_t<false, int>).name() << std::endl;
    std::cout << "value: " << *((int *) apt) << std::endl;
    std::cout << "size: " << sizeof(*apt) << std::endl;
    std::cout << apt->x << std::endl;
    *((B *) apt) = b;
    std::cout << "cast: " << static_cast<B *>(apt)->y << std::endl;
    std::cout << "value: " << *((int *) apt) << std::endl;
    std::cout << "size: " << sizeof(*((B *) apt)) << std::endl;
    std::cout << apt->x << std::endl;
    std::cout << "cast: " << static_cast<B>(a).y << std::endl;*/

    /**int mat[3][4] = {
            {1, 2, 3},
            {3, 4, 5, 6},
            {0}
    };
    V<3> v1;
    V<4> v2;
    v1.print();
    v2.print();
    multiply(v1, v2).print();
    const int *p = arr;
    p = arr + 1;
    typedef int K[50];
    K k = {1, 2, 3};
    (*k)++;
    const int *pt = arr;
    pt = arr + 20;*/
    // std::cout << ((B*) apt)->x << std::endl;
    return 0;
}
