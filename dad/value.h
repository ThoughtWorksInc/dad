
#ifndef DAD_FLOAT_H
#define DAD_FLOAT_H

#include "dad.h"

namespace dad {
    namespace detail {

        // FIXME: ValueBackward和ValueForward会复制值，不适合多维数组。
        template<typename T>
        struct ValueBackward {
            typedef T Node;
            typedef Node Delta;

            ValueBackward(Node ignore) {}

            void operator()(Delta ignored) {
            }
        };

        template<typename T>
        struct ValueForward {
            typedef T Node;
            typedef Node Data;
            Data data;

            ValueForward(Node data) : data(data) {}

            operator Data() {
                return data;
            }

        };

    }
    template<>
    struct Tape<double> : detail::ValueBackward<double> {
        Tape(Node data) : ValueBackward(data) {}
    };

    template<>
    struct Tape<float> : detail::ValueBackward<float> {
        Tape(Node data) : ValueBackward(data) {}
    };


    template<>
    struct Forward<double> : detail::ValueForward<double> {
        Forward(Node data) : ValueForward(data) {}
    };

    template<>
    struct Forward<float> : detail::ValueForward<float> {
        Forward(float data) : ValueForward(data) {}
    };
}
#endif //DAD_FLOAT_H
