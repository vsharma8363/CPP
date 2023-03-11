#include <stdio.h>
#include <stdint.h>

/*********** I. Numbers **************/

// intX_t --> X is the width of the integer (how much it can store)
//  Example: int8_t means [-2^8, 2^8] range
// --> the '_t' is just a 'standards' thing, it's meaningless for our purposes.

// Unsigned integers (>= 0)
uint8_t some_value = 100;
// Signed integers (Pos/Neg/0)
int8_t some_other_value = -100;

// Integer literals (i.e. hardcoded values)
int binary_number = 0b11; // Prefix: 0b
int octal_number = 020; // Prefix: 0
int decimal_number = 42; // Prefix: None
int hexadecimal_number = 0x05; // Prefix: 0x

// You can use scientific notation
double planks_const = 6.6207004e-34;

/*********** II. Precision **************/

// Decimal number
float precise_decimal = 1.1f; // always add 'f' to the end
double more_precise_decimal = 2.4; // No post-fix
long double most_precise_decimal = 5.5l; // Add the 'l'

/*********** III. Arrays **************/

void SquareAnArray() {
    // Define array length
    size_t num_elements = 100;

    // Declare array of integer values
    int output[num_elements];

    // For each element in the array, set the
    // value to the index^2.
    printf("I. SquareAnArray(): [");
    // Always use size_t for loops and sizes, it is safe becuase it is
    // set to the maximum size of the system (e.g. on a 32-bit system, it
    // will eval to int32_t).
    for (size_t i = 0; i < num_elements; ++i) {
        output[i] = i * i;
        printf("%d", output[i]);
        if (i >= num_elements - 1) { // The last element was added
            break; // Exit loop
        }
        printf(", ");
    }
    printf("]\n");
}

/*********** IV. For-Loops **************/

void RunSomeLoops() {
    size_t number_of_iterations = 0;

    // Infinite loop
    for(;;) {
        number_of_iterations++; // Increment by 1.

        // Without this, the loop will continue forever.
        if (number_of_iterations >= 100) {
            break;
        }
    }
    printf("RunSomeLoops(): Inf-Loop: %zu | ", number_of_iterations);

    // General loop
    // ALWAYS: Use '++i' not 'i++'
    number_of_iterations = 0;
    for (size_t i = 0; i < 100; ++i) {
        number_of_iterations++;
    }
    printf("Normal-Loop: %zu | ", number_of_iterations);

    // Iterate through some array
    int output_value = 0;
    int arr[] = {1, 2, 3};
    for (int value : arr) {
        // This is basically: output_value = output_value + value.
        output_value += value;
    }
    printf(" Array-Loop: %d\n", output_value);
}

/*********** V. Enums **************/

// Scoped: Uses `class`, means you have to reference it
// like this: Neighborhood::kDogpatch;
enum class Neighborhood {
    kDogpatch = 0, // ALWAYS DEFINE THE 0 FOR THE FIRST ONE
    kBernalHeights,
    kSoMa,
    kNoeValley,
    kMissionDolores,
};

/*********** VI. Initializations **************/

// These are all the same
int e = 42;
int f{42};
int g = {42};
int h(42);

/*********** VII. Most Vexing Parse **************/

/*
    Taxonomist t8(); <-- Where taxonomist is a class
    // This is the problem, because the compiler is looking
    // for a function t8() that returns a Taxonomist object.
*/

/*********** VIII. Narrowing Conversions **************/

int number(2.0f/1.1f); // This will result in 2.0/1.1 = 1.818..
// Because the number is being initialized with (), you will get
// number = 1;

// ALWAYS USE BRACED/UNIFORM INIT

/*********** IX. Destructors **************/

// AKA: Cleanup function

// ALMOST NEVER CALLED EXPLICITLY --> Called by compiler

struct Earth {
    ~Earth() { // Destructor `~`
        printf("No longer required for humanity.");
    }
};


int main() {
    SquareAnArray();
    RunSomeLoops();
    return 0;
}

