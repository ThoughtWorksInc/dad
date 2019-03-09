#ifndef DAD_DAD_H
#define DAD_DAD_H
//
//template<typename Data0, typename Delta0>
//struct Tape {
//    typedef Delta0 Delta;
//    typedef Data0 Data;
//    Data data;
//    Delta delta;
//
//    Tape(Data data, Delta delta) : data(data), delta(delta) {}
//};


namespace dad {

    template<typename Node>
    struct Tape;

    template<typename Data, typename Delta>
    struct Expression {
        Data data;
        Delta delta;

        Expression(Data data, Delta delta) : data(data), delta() {}
    };

    template<typename Value>
    Value &&forward_pass(Value &&value) {
        return value;
    }

    template<typename Data, typename Delta>
    Data forward_pass(Expression<Data, Delta> node) {

    }

    namespace ast {
        template<typename Data, typename Delta, typename Operand0, typename Operand1>
        struct Plus : Expression<Data, Delta> {
            Tape<Operand0> tape0;
            Tape<Operand1> tape1;

            Plus(Operand0 &&operand0, Operand1 &&operand1) :
                    Expression<Data, Delta>(forward_pass(operand0) + forward_pass(operand1)),
                    tape0(operand0),
                    tape1(operand1) {
            }

            ~Plus() {
                if (this->delta != Delta()) {
                    tape0.backward_pass(this->delta);
                    tape1.backward_pass(this->delta);
                }
            };
        }
    }


#endif //DAD_DAD_H
