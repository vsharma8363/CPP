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

TODO(viksharma): C-Style Strings Here

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