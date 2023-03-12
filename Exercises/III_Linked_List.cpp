#include <stdio.h>
#include <stdint.h>
#include <string>

namespace {

class Element {
    public:
        explicit Element(int id) {
            name_ = id;
        }

        ~Element() = default;

        bool SetPrev(Element* e) {
            prev_ = e;
            return static_cast<bool>(prev_);
        }

        bool SetNext(Element* e) {
            next_ = e;
            return static_cast<bool>(next_);
        }

        Element* GetPrev() {
            return prev_;
        }

        Element* GetNext() {
            return  next_;
        }

        int GetID() {
            return name_;
        }

    private:
        Element* prev_ = nullptr;
        Element* next_ = nullptr;
        int name_;

};

}  // namespace

int main() {
    Element One{1};
    Element Two{2};
    Element Three{3};
    Element Four{4};
    Element Five{5};
    Element Six{6};

    // Create linked list
    One.SetPrev(nullptr);
    One.SetNext(&Two);
    Two.SetPrev(&One);
    Two.SetNext(&Three);
    Three.SetPrev(&Two);
    Three.SetNext(&Four);
    Four.SetPrev(&Three);
    Four.SetNext(&Five);
    Five.SetPrev(&Four);
    Five.SetNext(&Six);
    Six.SetPrev(&Five);
    Six.SetNext(nullptr);
    
    printf("Next Demo: START --> ");
    Element* next = &One;
    while (next != nullptr) {
        printf("%d --> ", next->GetID());
        next = next->GetNext();
    }
    printf("END\n");
    
    printf("Prev Demo: END <-- ");
    Element* prev = &Six;
    while (prev != nullptr) {
        printf("%d <-- ", prev->GetID());
        prev = prev->GetPrev();
    }
    printf("Start");

    return 0;
}