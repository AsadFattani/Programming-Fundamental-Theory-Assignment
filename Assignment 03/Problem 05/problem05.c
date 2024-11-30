// Pets in Heart

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

void addSupplies(char **speciesSupplies, int *suppliesCount,int speciesIndex, int numSupplies){
    speciesSupplies[speciesIndex] = (char *)calloc(numSupplies, MAX_NAME_LENGTH * sizeof(char));
    suppliesCount[speciesIndex] = numSupplies;
    for (int i = 0; i < numSupplies; i++){
        printf("Enter supply %d for species %d: ", i + 1, speciesIndex + 1);
        scanf("%s", speciesSupplies[speciesIndex] + i * MAX_NAME_LENGTH);
    }
}

void updateSupply(char **speciesSupplies, int *suppliesCount,int speciesIndex, int numSupplies, const char *newSupplyName){
    if (speciesIndex < *suppliesCount && numSupplies < suppliesCount[speciesIndex]){
        strncpy(speciesSupplies[speciesIndex] + numSupplies * MAX_NAME_LENGTH, newSupplyName, MAX_NAME_LENGTH);
    } else {
        printf("Invalid species or supply index.\n");    
    }
}

void removeSpecies(char **speciesSupplies, int *suppliesCount, int *speciesCount, int speciesIndex){
    if (speciesIndex < *speciesCount){
        free(speciesSupplies[speciesIndex]);
        for (int i = speciesIndex; i < *speciesCount - 1; i++){
            speciesSupplies[i] = speciesSupplies[i + 1];
            suppliesCount[i] = suppliesCount[i + 1];
        }
        (*speciesCount)--;
        speciesSupplies = (char **)realloc(speciesSupplies, (*speciesCount) * sizeof(char *));
        suppliesCount = (int *)realloc(suppliesCount, (*speciesCount) * sizeof(int));
        if (speciesSupplies == NULL || suppliesCount == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    } else {
        printf("Invalid species index.\n");
    }
}

void displayInventory(char **speciesSupplies, int *suppliesCount, int speciesCount){
    for (int i = 0; i < speciesCount; i++){
        printf("Species %d supplies:\n", i + 1);
        for (int j = 0; j < suppliesCount[i]; j++){
            printf("  %s\n", speciesSupplies[i] + j * MAX_NAME_LENGTH);
        }
    }
}

int main(){
    int numSpecies;

    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    char **speciesSupplies = (char ** )malloc(numSpecies * sizeof(char*));
    int *suppliesCount = (int *)malloc(numSpecies * sizeof(int));

    for (int i = 0; i < numSpecies; i++){
        int numSupplies;
        printf("Enter the number of supplies for species %d: ", i + 1);
        scanf("%d", &numSupplies);
        addSupplies(speciesSupplies, suppliesCount, i, numSupplies);
    }

    displayInventory(speciesSupplies, suppliesCount, numSpecies);

    // Example of updating a supply
    updateSupply(speciesSupplies, suppliesCount, 0, 0, "NewSupplyName");
    displayInventory(speciesSupplies, suppliesCount, numSpecies);

    // Example of removing a species
    removeSpecies(speciesSupplies, suppliesCount, &numSpecies, 0);
    displayInventory(speciesSupplies, suppliesCount, numSpecies);

    // Free allocated memory
    for (int i = 0; i < numSpecies; i++) {
        free(speciesSupplies[i]);
    }

    free(speciesSupplies);
    free(suppliesCount);

    return 0;
}

