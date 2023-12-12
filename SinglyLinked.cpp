#ifndef SINGLY_SinglyList_CPP
#define SINGLY_SinglyList_CPP

#include "SinglyLinked.h"
#include "List.h"

template <class T>
std::ostream &operator<<(std::ostream &os, const SinglyList<T> *sl)
{
    if (sl->head == NULL)
    {
        os << "NULL";
        return os;
    }
    Node<T> *curr = sl->head;
    while (curr != NULL)
    {
        os << curr;
        curr = curr->next;
    }
    return os;
}


template <class T>
SinglyList<T>::SinglyList(){

}

// //main function
// template <class T>
// SinglyList<T>::SinglyList(T* arr, int size) {
//     //null or negative

//     if (arr == NULL ) {
//         return; 
//     }
//     if( size <= 0){
//         return;
//     }

// for(int i =0 ; i < this->size() ; i++){

//     Node<T>* currentNode = new Node<T> (arr[i]);
// //this
//     if(this->head == NULL){
//         this->head = currentNode;


//     }else{

//         Node<T>*  newptr = this->head;
//         while(newptr->next  != NULL){
//             newptr= newptr->next;
//         }
//         newptr->next = currentNode;
//     }
// }
    

// }

template <class T>
SinglyList<T>::SinglyList(T* arr, int size) {
    this->head = NULL;  // Initialize the head pointer to NULL

    if (arr == NULL || size <= 0) {
        return;  // Return immediately if the array is null or size is invalid
    }

    // Iterate through the array and insert elements into the linked list
    for (int i = 0; i < size; i++) {
        Node<T>* newNode = new Node<T>(arr[i]);
        newNode->next = this->head;  // Insert at the beginning of the list
        this->head = newNode;
    }
}

template <class T>
SinglyList<T>::~SinglyList() {

      Node<T>* current = this->head;

    while (current !=NULL) 
    {

        this->head  = this->head->next;
        delete current;
        current =  this->head;
    }
    this->head =NULL;
}


template <class T>
Node<T>* SinglyList<T>::insert(T data, int pos) {
    Node<T>* tempNode = new Node<T>(data);

    if (this->head == NULL || pos <= 0) {
        tempNode->next = this->head;
        this->head = tempNode;
    } else if (pos > this->size()) {
        Node<T>* newptr = this->head;
        while (!(newptr->next == NULL)) {
            newptr = newptr->next;
        }
        newptr->next = tempNode;
    } else {
        Node<T>* temp1ptr = this->head;
        int index = 0;
        while (temp1ptr->next != NULL && index < pos - 1) {
            temp1ptr = temp1ptr->next;
            index++;
        }
        tempNode->next = temp1ptr->next;
        temp1ptr->next = tempNode;
    }
    return tempNode;
}


// template <class T>
// int SinglyList<T>::remove(T data) {
//     if (this->head == NULL) {
//         return -1;  // List is empty, return -1 indicating failure
//     }

//     if (this->head->getData() == data) {
//         Node<T>* Ndeptr = this->head;
//         this->head = this->head->next;
//         delete Ndeptr;
//         return 0;  // Return 0 to indicate successful removal of the head
//     }

//     Node<T>* current = this->head;
//     int index = 0;
//     Node<T>* prev = NULL;

//     // Traverse the list to find the node with the specified data
//     while (current != NULL) {
//         if (current->getData() == data) {
//             if (prev != NULL) {
//                 prev->next = current->next;
//             }
//             delete current;
//             return index;  // Return the index of the removed node
//         }
//         prev = current;
//         current = current->next;
//         index++;
//     }

//     return -1;  // Data not found in the list, return -1 indicating failure
// }
template <class T>
int SinglyList<T>::remove(T data) {
    if (this->head == NULL) {
        return -1;  // List is empty, return -1 indicating failure
    }

    if (this->head->getData() == data) {
        Node<T>* Ndeptr = this->head;
        this->head = this->head->next;
        delete Ndeptr;
        return 0;  // Return 0 to indicate successful removal of the head
    }

    Node<T>* current = this->head;
    int index = 0;
    Node<T>* prev = NULL;

    while (current != NULL) {
        if (current->getData() == data) {
            if (prev != NULL) {
                prev->next = current->next;
            }
            delete current;
            return index;
        }
        prev = current;
        current = current->next;
        index++;
    }

    return -1;  // Data not found in the list, return -1 indicating failure
}


// template <class T>
// int SinglyList<T>::remove(T data) {
//     if (this->head == NULL) {
//         return -1; 
//     }

//     if (this->head->getData() == data) {
//         Node<T>* Ndeptr = this->head;
//         this->head = this->head->next;
//         delete Ndeptr;

//         return 0; 
//     }

//     Node<T>* current = this->head;
//     int index = 0;
//     Node<T>* prev = NULL;

//     // Traverse the list to find the node with the specified data
//     while ((current != NULL) && (current->getData() != data)) {
//         prev = current;
//         current = current->next;
//         ++index;
//     }

//     if (current == NULL) {
//         return -1; // Data not found in the list, return -1 indicating failure
//     } else {
//         return index ; // Return the index from the front
//     }
// }

// template <class T>
// int SinglyList<T>::remove(T data) {
//     if (this->head == NULL) {
//         return -1; 
//     }

    
//     if (this->head->getData() == data  ) {
//         Node<T>* Ndeptr = this->head;
//         this->head = this->head->next;
//         delete Ndeptr;

//         return 0; 
//     }

//     Node<T>* current = this->head;
//     int index = 0;
//     Node<T>* prev = NULL;


//     // Traverse the list to find the node with the specified data
//     while ((current != NULL) && (current->getData() != data)) {
//      prev = current;
//      current = current->next;
//      ++index;
//     }


//     if(!(current)){
//         return -1;
//     }
//     prev->next = current->next;
//     delete current;

//     return index;  // Data not found in the list, return -1 indicating failure
// }


template <class T>
Node<T>* SinglyList<T>::operator[](int index) const {
    if (this->head == NULL) {
        return NULL;
    }

    if (index >= 0) {
        Node<T>* current = this->head;
        int nodeIndex = 0;

        while (current != NULL && nodeIndex < index) {
            current = current->next;
            nodeIndex++;
        }

        if (current == NULL) {
            return NULL; // Index out of bounds
        }

        return current;
    } else {
        // Calculate the index from the rear
        int size = 0;
        Node<T>* current = this->head;

        while (current != NULL) {
            current = current->next;
            size++;
        }

        int rearIndex = size + index;
        if (rearIndex < 0) {
            return NULL; // Index out of bounds
        }

        current = this->head;
        int nodeIndex = 0;

        while (current != NULL && nodeIndex < rearIndex) {
            current = current->next;
            nodeIndex++;
        }

        if (current == NULL) {
            return NULL; // Index out of bounds
        }

        return current;
    }
}


// template <class T>
//  Node<T>* SinglyList<T>::operator()(T* dataPtr) const {
//     // Check if the list is empty or if the dataPtr is NULL
//     if (this->head == NULL || dataPtr == NULL) {
//         return NULL;
//     }

//     Node<T>* current = this->head;

    
//     while (current != NULL) {
       
//         if (*dataPtr == current->getData()) {
//             return current; 
//         }

//         // Move to the next node
//         current = current->next;
//     }

//         return NULL;
// }

template <class T>
Node<T>* SinglyList<T>::operator()(T* dataPtr) const {
    if (this->head == NULL || dataPtr == NULL) {
        return NULL; // Return null if the list is empty or dataPtr is null
    }

    Node<T>* current = this->head;

    while (current != NULL) {
        if (*dataPtr == current->getData()) {
            return current; // Return the node when a match is found
        }

        current = current->next;
    }

    return NULL; // Return null if the data is not in the list
}


// Find the node with the specified data starting from the front
template <class T>
 int SinglyList<T>::getIndexFromFront(T data) const {
     if(this->head == NULL){return -1;}
     int index = 0;

    Node<T>* current = this->head;
   
    while (current != NULL) {

        if (current->getData() == data) {
            return index - (this->size()-1) ;
        }
          index++;
        current = current->next;
      
    }

    return -1;  // Data not found
}

// Find the node with the specified data starting from the rear
// template <class T>
//  int SinglyList<T>::getIndexFromRear(T data) const {
 
//  if(this->head == NULL){return -1;}

//     int index = -1;
//     int size = this->size()  -1;
//        Node<T>* current = this->head;

//     while (current != NULL) {
//         if (current->getData() == data) {

//             index = size;
//             break;
//         }
//           --size;
//         current = current->next;
      
//     }

//     return index;
// }


//template <class T>
// int SinglyList<T>::getIndexFromFront(T data) const {
//     if (this->head == NULL) {
//         return -1; // List is empty, return -1 indicating failure
//     }
    
//     int index = 0;
//     Node<T>* current = this->head;
    
//     while (current != NULL) {
//         if (current->getData() == data) {
//             return index;
//         }
//         index++;
//         current = current->next;
//     }
    
//     return -1;  // Data not found
// }

template <class T>
int SinglyList<T>::getIndexFromRear(T data) const {
    if (this->head == NULL) {
        return -1; // List is empty, return -1 indicating failure
    }

    int frontIndex = getIndexFromFront(data);
    if (frontIndex == -1) {
        return -1;  // Data not found in the list
    }
    
    int rearIndex = (this->size() - 1 )+ frontIndex;
    
    return rearIndex;
}


template <class T>
List<T>* SinglyList<T>::sort(bool order) const {


    T* newArray = new T[this->size()];
    int number = this->size();
    int index = 0;

    Node<T>* newPtr = this->head;
    
    while (newPtr != NULL) {
        newArray[index] = newPtr->getData();
        newPtr = newPtr->next;
        index++;
    }

    for (int i = 0; i < number - 1; i++) {
        for (int k = 0; k < number - i; k++) {
            if (order && newArray[k] > newArray[k + 1] ) {
                T tempVar = newArray[k];
                newArray[k] = newArray[k + 1];
                newArray[k + 1] = tempVar;
            }

              if ((!order && (newArray[k] < newArray[k + 1]))) {
                T tempVar = newArray[k];
                newArray[k] = newArray[k + 1];
                newArray[k + 1] = tempVar;
            }
        }
    }

    SinglyList<T>* sorted = new SinglyList<T>(newArray, number);
    delete[] newArray;

    return sorted;
}

  

// template <class T>
//  Node<T>* SinglyList<T>::findSmallest() const {
//     if (this->head == NULL) {
//         return NULL;  
//     }
//       Node<T>* current = this->head->next;
//     Node<T>* small = this->head;
  

//     while (current != NULL) {
       
//         if (current->getData() < small->getData()) {
//             small = current;
//         }
//         current = current->next;
//     }

//     return small;
// }
// template <class T>
//  Node<T>* SinglyList<T>::findBiggest() const {
//     if (this->head == NULL) {
//         return NULL;
//     }
//    Node<T>* current = this->head->next;
//     Node<T>* big = this->head;
    

//     while (current != NULL) {
        
//         if (current->getData() > big->getData()) {
//             big = current;
//         }
//         current = current->next;
//     }

//     return big;
// }

template <class T>
Node<T>* SinglyList<T>::findSmallest() const {
    if (this->head == NULL) {
        return NULL;
    }
  
    Node<T>* current = this->head->next;
    Node<T>* small = this->head;

    while (current != NULL) {
        if (current->getData() < small->getData()) {
            small = current;
        }
        current = current->next;
    }

    return small;
}

template <class T>
Node<T>* SinglyList<T>::findBiggest() const {
    if (this->head == NULL) {
        return NULL;
    }

    Node<T>* current = this->head->next;
    Node<T>* big = this->head;

    while (current != NULL) {
        if (current->getData() > big->getData()) {
            big = current;
        }
        current = current->next;
    }

    return big;
}


template <class T>
List<T>*SinglyList<T>::clone() const {
    SinglyList<T>* clonedList = new SinglyList<T>();

    if (this->head == NULL) {
        return clonedList;
    }

    Node<T>* current = this->head;

    while (current != NULL) {
        clonedList->insert(current->getData(), clonedList->size());
        current = current->next;
    }

    return clonedList;
}



#endif /*SinglyList_CPP*/
