#include "List.h"
#include "Node.h"
#include "SinglyLinked.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
 // Test the constructor with an array
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = 5;
    SinglyList<int> list(arr, arrSize);
cout<<"front :  "<<list.getIndexFromFront(1)<<endl;
cout<<"Rear : "<<list.getIndexFromRear(1)<<endl;
  
    // Test other functions
    std::cout << "Size of the list: " << list.size() << std::endl;
    
    // Test insertion
    //list.insert(6, 2);
  
    // Test removal
    int removedIndex = list.remove(1);
    if (removedIndex != -1) {
        std::cout << "Removed element at index " << removedIndex << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    // Find the smallest and biggest elements
    Node<int>* smallest = list.findSmallest();
    Node<int>* biggest = list.findBiggest();
    if (smallest != NULL) {
        std::cout << "Smallest element: " << smallest->getData() << std::endl;
    }
    if (biggest != NULL) {
        std::cout << "Biggest element: " << biggest->getData() << std::endl;
    }

    // Find an element by value
    int searchValue = 3;
    Node<int>* searchResult = list(&searchValue);
    if (searchResult != NULL) {
        std::cout << "Found element with value " << searchValue << " at index " << list.getIndexFromFront(searchValue) << std::endl;
    } else {
        std::cout << "Element with value " << searchValue << " not found" << std::endl;
    }

    // Test sorting
    List<int>* sortedListAsc = list.sort(true);
    List<int>* sortedListDesc = list.sort(false);




    // Clean up memory
    delete sortedListAsc;
    delete sortedListDesc;



SinglyList<int> myList1;
// Testing insert
    myList1.insert(10, 0);
    myList1.insert(20, 1);
    myList1.insert(30, 2);
    

    // Testing remove
    myList1.remove(20);
    

    // Testing indexing
    Node<int>* node = myList1[1];
    if (node != NULL) {
        std::cout << "Node at index 1: " << node->getData() << std::endl;
    } else {
        std::cout << "Node at index 1 not found." << std::endl;
    }

    // Testing find from front
    int indexFromFront = myList1.getIndexFromFront(30);
    if (indexFromFront != -1) {
        std::cout << "Index of 30 from the front: " << indexFromFront << std::endl;
    } else {
        std::cout << "30 not found in the list." << std::endl;
    }

    // Testing find from rear
    int indexFromRear = myList1.getIndexFromRear(30);
    if (indexFromRear != -1) {
        std::cout << "Index of 30 from the rear: " << indexFromRear << std::endl;
    } else {
        std::cout << "30 not found in the list." << std::endl;
    }

    // Testing sorting in ascending order
    List<int>* sortedListAscending = myList1.sort(true);
    delete sortedListAscending;

    // Testing sorting in descending order
    List<int>* sortedListDescending = myList1.sort(false);
    delete sortedListDescending;


       // Testing with double data type
    SinglyList<double> doubleList;
    doubleList.insert(3.14, 0);
    doubleList.insert(2.71, 1);

    Node<double>* doubleNode = doubleList[0];
    if (doubleNode != NULL) {
        std::cout << "Double Node at index 0: " << doubleNode->getData() << std::endl;
    } else {
        std::cout << "Double Node at index 0 not found." << std::endl;
    }

    double doubleIndexFromFront = doubleList.getIndexFromFront(3.14);
    if (doubleIndexFromFront != -1) {
        std::cout << "Index of 3.14 from the front (Double List): " << doubleIndexFromFront << std::endl;
    } else {
        std::cout << "3.14 not found in the double list." << std::endl;
    }

    // Testing with string data type
    SinglyList<std::string> stringList;
    stringList.insert("Hello", 0);
    stringList.insert("World", 1);

    Node<std::string>* stringNode = stringList[1];
    if (stringNode != NULL) {
        std::cout << "String Node at index 1: " << stringNode->getData() << std::endl;
    } else {
        std::cout << "String Node at index 1 not found." << std::endl;
    }

    int stringIndexFromFront = stringList.getIndexFromFront("World");
    if (stringIndexFromFront != -1) {
        std::cout << "Index of 'World' from the front (String List): " << stringIndexFromFront << std::endl;
    } else {
        std::cout << "'World' not found in the string list." << std::endl;
    }
return 0;
}