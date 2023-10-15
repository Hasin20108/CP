#include <iostream>
#include <set>
#include <algorithm>

int main() {
    // Declare a multiset of integers
    std::multiset<int> myMultiset = {10, 20, 30, 20, 40, 20, 50};

    // Print the elements before deletion
    std::cout << "Before deletion: ";
    for (const auto& element : myMultiset) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Delete a specific number of occurrences of a specific element (e.g., 20)
    int elementToDelete = 20;
    int occurrencesToDelete = 2;

    // Count the occurrences of the element in the multiset
    int count = std::count(myMultiset.begin(), myMultiset.end(), elementToDelete);

    // Calculate how many occurrences to delete (minimum of occurrencesToDelete and actual count)
    int occurrencesDeleted = 2;

    // Erase the specified number of occurrences
    for (int i = 0; i < occurrencesDeleted; ++i) {
        myMultiset.erase(elementToDelete);
    }

    // Print the elements after deletion
    std::cout << "After deletion: ";
    for (const auto& element : myMultiset) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
