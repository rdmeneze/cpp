#pragma once

#include <cstddef>

namespace simple_linked_list {
class List {
   public:
    List() = default;
    ~List();

    // Moving and copying is not needed to solve the exercise.
    // If you want to change these, make sure to correctly
    // free / move / copy the allocated resources.
    List(const List&) = delete;
    List& operator=(const List&) = delete;
    List(List&&) = delete;
    List& operator=(List&&) = delete;

    size_t size() const;
    void push(const int entry);
    int pop();
    void reverse();

   private:
    struct Element {
        Element(int data) : data{data} {};
        int data{};
        Element* next{nullptr};
    };

    Element* head{nullptr};
    size_t current_size{0};

    void inner_push( Element** list, const int entry );
};

}  // namespace simple_linked_list

