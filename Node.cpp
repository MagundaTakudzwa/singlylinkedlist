#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"
template <typename T>
Node<T>::Node(T data) : data(data), next(NULL) {

}

template <typename T>
 T Node<T>::getData() const {
    return data;
}

template <typename T>
bool Node<T>::operator==(T other) const {
    return data == other.data;
}


#endif /*NODE_CPP*/