#include <stdio.h>
#include <stdint.h>

namespace { 

enum class Operation {
    kAddition = 0,
    kSubtration,
    kMultiplication,
    kDivision,
};

class Calculator {
    public:
        Calculator() {
            printf("We created a calculator!\n");
        }
        
        Calculator(int number) {
            printf("We created a calculator with id %d\n", number);
        }

        ~Calculator() {
            printf("We destroyed a calculator!\n");
        }

        int64_t PerformOperation(Operation op, int64_t a, int64_t b) {
            int64_t output = 0;
            switch (op) {
                case Operation::kAddition:
                    output = a + b;
                    break;
                case Operation::kSubtration:
                    output = a - b;
                    break;
                case Operation::kMultiplication:
                    output = a * b;
                    break;
                case Operation::kDivision:
                    output = a / b;
                    break;
                default:
                    break;
            }
            last_output_ = output;
            return output;
        }
    
    private:
        int64_t last_output_ = 0;

};

}  // namespace

int main() {
    Calculator calc(1);
    printf("99 + 42 = %ld\n", calc.PerformOperation(/*op=*/Operation::kAddition, /*a=*/99, /*b=*/42));
    printf("99 - 42 = %ld\n", calc.PerformOperation(/*op=*/Operation::kSubtration, /*a=*/99, /*b=*/42));
    printf("99 * 42 = %ld\n", calc.PerformOperation(/*op=*/Operation::kMultiplication, /*a=*/99, /*b=*/42));
    printf("99 / 42 = %ld\n", calc.PerformOperation(/*op=*/Operation::kDivision, /*a=*/99, /*b=*/42));
    return 0;
}
