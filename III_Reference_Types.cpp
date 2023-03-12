#include <stdio.h>
#include <string>
#include <vector>

namespace {

/******* I. Pointers ********/

// Reference Types: Store memory address of objects

// How to use basic reference types
void BasicPointersInfo() {
    // Address-of operator --> & (get address of memory)
    int some_value = 42; // The actual value
    int* ptr_to_some_value = &some_value; // The address in memory
    printf("some_value = %d | &some_value = %p\n", some_value, ptr_to_some_value);

    // Dereference Operator --> * (get memory at address)
    printf("Changing ptr value through dereferencing...\n");
    *ptr_to_some_value = 55;
    printf("some_value = %d | &some_value = %p\n", some_value, ptr_to_some_value);
}

/******* II. -> Operator ********/

struct Home {
    char address[256];
};

void AccessElements() {
    // Use the -> operator to access elements of the array
    // -> is equivalent to dereferencing and using (.)
    Home home{"901 Tennessee St"};
    Home* home_ptr = &home;
    printf("My address is %s\n", home_ptr->address);
    printf("... which is the same as %s\n", (*home_ptr).address);
}

/******* III. Handling Array Decay ********/

void HandleArrayDecay() {
    int house_numbers[]{901, 1001, 1101};

    // All length information has been lost.
    int* house_numbers_ptr = house_numbers; // Points to 901.

    // You can handle decay by passing in **data** and **data_length**.
    size_t data_length = 3;
    for (size_t i = 0; i < data_length; ++i) {
        printf("house_numbers[%zu] = %d\n", i, house_numbers_ptr[i]);
    }

    // Pointer arithmetic --> +/- on pointers --> It is just
    // another way to access array elements.
    int* third_element = house_numbers_ptr + 2;
    printf("%d == %d", *third_element, house_numbers_ptr[2]);
}

// Undefined behavior --> Cpp specification can't tell what will happen

/******* IV. void* or std::byte ********/

// void* ptr --> If you don't care about type
// - CANNOT BE DEREFERENCED
//
// std::byte ptr --> If you want to interact with raw data

/******* V. nullptr/booleans ********/

void EvaluateNullptr() {
    int some_value = 42;
    // Pointer to nullptr evaluates to false, else true.
    void* some_data = &some_value;
    printf("%s == true\n", (static_cast<bool>(some_data) ? "true" : "false"));
    some_data = nullptr;
    printf("%s == false\n", (static_cast<bool>(some_data) ? "true" : "false"));
}

/******* VI. References (&) ********/
// Safer versions of pointers:
// - Cannot be reassigned (reseated)
// - Cannot be assigned to null

// TLDR: Under-the-hood it's a pointer, but to you, it's an object.
// Also, don't assign to nullptr.

void TestReference() {
    int x = 1;
    // y is a reference to x.
    int& y = x;

    // A reference, but can be used as an object.
    y += 2;
    printf("3 == %d\n", y);
}

/******* VII. Const (READONLY) Methods ********/
// --> Only usable for member functions <--
// Marking a method const --> "I promise not to modify data inside"

class Me {
    public:
        explicit Me() : my_age_(22) {
            // The my_age_(22) above is basically like this:
            // --> my_age_ = 22;
        }

        ~Me() {}

        // READONLY member function
        int GetMyAge() const {
            return my_age_;
        }

    private:
        int my_age_;
};

void TestMe() {
    Me me{};
    printf("I am %d years old\n", me.GetMyAge());
}

/******* VIII. Auto Keyword ********/

int GetNextInt() { return 22; }

std::string GetProtobuffer() {return "";}

// RULE: If the type is obvious from the line, use auto, else, DONT!
void DemoAuto() {

    // OK: It literally says the type on the RHS.
    auto coin_denominations = std::vector<int>();

    // MAYBE: The function return is obvious, but could be (un)signed.
    auto some_value = GetNextInt();

    // BAD: Unclear what the type is supposed to be.
    auto another_value = 23.0; // float or double?

    // BAD: Total unclear what this is.
    auto some_protobuffer = GetProtobuffer();

    // Avoid compiler complaints about unused variables
    (void)coin_denominations;
    (void)some_value;
    (void)another_value;
    (void)some_protobuffer;
}

}  // namespace

int main() {
    printf("\n\nDemo of basic (de)referencing\n");
    BasicPointersInfo();
    printf("\n\nDemo of -> operator\n");
    AccessElements();
    printf("\n\nDemo of array decay\n");
    HandleArrayDecay();
    printf("\n\nDemo of nullptr/bool\n");
    EvaluateNullptr();
    printf("\n\nDemo of reference\n");
    TestReference();
    printf("\n\nDemo of const methods\n");
    TestMe();
    printf("\n\nDemo of auto keyword\n");
    DemoAuto();
}