#include <iostream>
#include "dad/value.h"
#include "dad.h"

using namespace std;

struct Foo {
    ~Foo() {
        cout << "Foo" << endl;
    }
};

struct Bar {
    Bar(Foo &&foo) {}

    ~Bar() {
        cout << "Bar" << endl;
    }
};

template<typename T>
bool is_rvalue_reference_value(T &&t) {
    return is_lvalue_reference<T>::value;
}

int main() {
    dad::Forward<float> a(1.3f);

    float f = a + a;

    Foo foo;
    cout << is_rvalue_reference_value(foo) << endl;
    cout << is_rvalue_reference_value(Foo()) << endl;


    const Bar &bar = Bar(Foo());

    auto b1 = bar;

    move(b1);

    cout << (&bar == &b1) << endl;
    cout << "main" << endl;
}