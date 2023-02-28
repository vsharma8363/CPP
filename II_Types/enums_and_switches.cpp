#include <iostream>

enum class Neighborhood {
    kBernalHeights = 0,
    kNoeValley,
    kDogpatch,
};

void GetNeighborhoodPopulation(Neighborhood neighborhood) {
    switch (neighborhood) {
        case Neighborhood::kBernalHeights: {
            printf("There are 29,502 people who live here!\n");
            break;
        }
        case Neighborhood::kNoeValley: {
            printf("There are 30,502 people who live here!\n");
            break;
        }
        case Neighborhood::kDogpatch: {
            printf("There are 21,502 people who live here!\n");
            break;
        }
        default: {
            // This ensures that if someone adds a neighborhood, you can easily tell from
            // the message, another form of programming "safely"
            printf("I don't know the population of this neighborhood\n\n");
            break;
        }
    }
}

int main() {
    Neighborhood neighborhoods[] = {
        Neighborhood::kBernalHeights, Neighborhood::kDogpatch
    };
    
    for (Neighborhood area: neighborhoods) {
        GetNeighborhoodPopulation(area);
    }
    return 0;
}