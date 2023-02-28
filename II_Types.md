# I. Types

## The {intX}_t postfix
- This ensures that platform-independent, the size of the integer will be 8/16/32/64 bits

## Signed-Ness
### Signed Integer (+/-/0)
- int8_t, int_16_t ... int64_t
### Unsigned Integer (Non-Negative)
- uint8_t, uint_16_t ... uint64_t

## Integer Literals
- Literal means **hardcoded** value
- Literal prefixes for integer types:
    - Binary: `0b`
    - Octal: `0`
    - Decimal: `DEFAULT - None required`
    - Hexadecimal: `0x`

**The list above illusrates why NOT to use leading zeroes for integers like Zip Codes**

```
// Quotes can be included in literals for readability.
uint64_t bank_balance = 1'000'000;
```

## Floating Point Types

- **Float** - Single Precision
- **Double** - Double Precision
- **Long Double** - Extended Precision

```
float single_prec = 1.1f;
double double_prec = 2.4;
long double extended_prec = 5.5l;

// Using scientific notation
double planks_const = 6.6207004e-34;
```

## std::byte Type (std --> `"stood"`)

- Allows you to work with raw memory directly

## size_t Type (always unsigned)

- Guaranteed to have the **largest possible** object in the system
- Return type for **sizeof(...)**

## Arrays
- Sequences of **identically typed** data
```
int my_arr[100];

int my_second_arr[] = {1, 2, 3}; // Length inferred at compile time
```

## For-Loops (with arrays)
- It is preferable to use **size_t** in array indexing to ensure size will not cause overflow

```
for(;;) {
    // infinite
}

for(size_t i = 0; i < 10; i++) {
    // 10 iterations
}

int arr[] = {1,2,3};
for(int i: arr) {
    // 1,2,3 in arr
}
```

## Array Lengths
- BIG DEAL: **sizeof(...)** calculations happen at **compile-time**
- THERE IS NO RUNTIME COST TO **sizeof(arr)/sizeof(arr_data_type)**

## C-Style Strings
- **null-terminated**/**c-style** strings have a *zero-byte* appended to the end of a string
```
char phrase[] = "Life is like a box of chocolates!";
```

# User-Defined Types

## Enumerations (How we categorize things safely)
- **Used to model *categorical* concepts**
- Safer to use, let you use categories instead of *integers*, which could mean **anything**
```
enum class Neighborhood {
    kDogpatch = 0, // ALWAYS DEFINE THE 0 FOR THE FIRST ONE
    kBernalHeights,
    kSoMa,
    kNoeValley,
    kMissionDolores,
};

// How to reference enums...
Neighborhood place_of_work = Neighborhood::kSoMa;
```

- [Google Cpp Style](https://google.github.io/styleguide/cppguide.html#Enumerator_Names) guide insists use of constants-style naming (kBernalHeights)

### Style-Addendum (Scoped/Unscoped)

#### Scoped-Enums (Prefer use of these - SAFER)
##### Enums that use `enum class`, which therefore require referencing using `::`. Here is an example:

```
enum class StreetName {
    kStockton = 0,
    kMarket,
    kCortland,
};

StreetName home_street = StreetName::kCortland;
```

#### Unscoped Enums
##### Existed in C, used to maintain backwards compatability

```
enum BusinessName {
    kProgressiveGroundsCoffee = 0,
    kJustForYouCafe,
    kPiccino,
};

BusinessName my_favorite_place = kJustForYouCafe;
```

### Switch Statements

- Transfers control based on conditions (consider it an expansion of if-statement logic)
- Confusingly, you need to **break** from the statement once you have reached the case you require

```
switch(variable) {
    case condition_1: {
        // Will reach here if variable == condition_1
        break;
    }
    case condition_2: {
        // Will reach here if variable == condition_2
        break;
    }
    default: { // Executed if no other condition is met
        // No break required here
    }
}
```

## Plain-Old-Data Classes (POD) / Structs

- **Classes** --> User-defined types that contain data and functions
    - Core benefit of C++ over C

- **POD Classes**: Simple data containers, begins with the keyword `struct`

```
struct Neighborhood {
    char name[256];
    int year_founded;
    int population;
    int num_businesses;
}
```

- Variables defined inside these POD Classes can be accessed via the `dot operator (.)`

```
Neighborhood my_neighborhood;
my_neighborhood.name = "Bernal Heights";
my_neighorborhood.population = 20'000;
printf("The %s neighborhood has a population of %d people!", my_neighborhood.name, my_neighorborhood.population);
```

## Unions

- Method of accessing a single block of memory in different ways through different variables

- Example: Let's say we have a struct that represents a type of food, and we want a way to access the information of the macronutrient data through an array of floats and to also be able to set them explicitly

```
union Food {
    struct {
        float grams_carbs;
        float grams_fats;
        float grams_protein;
    };
    float macros[3];
}

Food f;

f.grams_carbs = 42;
f.grams_fats = 55;
f.grams_protein = 99;

// The following statements will be true:
bool x = f.grams_carbs == f.macros[0];
bool y = f.grams_fats == f.macros[1];
bool z = f.grams_protein == f.macros[2];

// The values are the same because they both actually point to the exact same block of memory. In other words:
//      the macros[3] array of floats would point to the memory addresses 0 to 12 in our computers memory (4 bytes per float)
//      while similarly, the grams_carbs would point to 0 to 4, grams_fats would point to 4 to 8, and so on (it's all sequential)
```





- **Classes**: Pair data and functionality
- **Unions**: All members share same location (*multiple ways to access the same data*)

---
</br></br>

# The Things I Know
## I. Fundamental Types (Primitive/Built-In)

### Integer Types
- Store **whole numbers** --> Not fractions:
    - short int
    - int
    - long int
    - long long int