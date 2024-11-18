#include <stdio.h>
#include <string.h>

struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    int mileage;
};

void addCar(struct Car cars[], int i) {
    printf("\nEnter Car Make: ");
    scanf(" %[^\n]s", cars[i].make);
    printf("Enter Car Model: ");
    scanf(" %[^\n]s", cars[i].model);
    printf("Enter Year: ");
    scanf("%d", &cars[i].year);
    printf("Enter Price: ");
    scanf("%f", &cars[i].price);
    printf("Enter Mileage: ");
    scanf("%d", &cars[i].mileage);
    printf("Car added successfully!\n");
}

void displayCars(struct Car cars[], int count) {
    if (count == 0) {
        printf("\nNo cars available!\n");
    } else {
        for (unsigned int i = 0; i < count; i++) {
            printf("\nCar %d:", i + 1);
            printf("\nMake: %s", cars[i].make);
            printf("\nModel: %s", cars[i].model);
            printf("\nYear: %d", cars[i].year);
            printf("\nPrice: %.2f", cars[i].price);
            printf("\nMileage: %d\n", cars[i].mileage);
        }
    }
}

void searchByMakeOrModel(struct Car cars[], int count) {
    char query[50];
    int found = 0;

    printf("\nEnter Car Make or Model to Search: ");
    scanf(" %[^\n]s", query);

    for (unsigned int i = 0; i < count; i++) {
        if (strcmp(cars[i].make, query) == 0 || strcmp(cars[i].model, query) == 0) {
            printf("\nCar Found:");
            printf("\nMake: %s", cars[i].make);
            printf("\nModel: %s", cars[i].model);
            printf("\nYear: %d", cars[i].year);
            printf("\nPrice: %.2f", cars[i].price);
            printf("\nMileage: %d\n", cars[i].mileage);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo cars found for the given make or model: %s\n", query);
    }
}

int main() {
    struct Car cars[100];
    int carCount = 0;
    int choice;

    do {
        puts("1. Add Car");
        puts("2. Display All Cars");
        puts("3. Search by Make or Model");
        puts("4. Exit");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (carCount < 100) {
                addCar(cars, carCount);
                carCount++;
            } else {
                printf("Car database is full!\n");
            }
        } else if (choice == 2) {
            displayCars(cars, carCount);
        } else if (choice == 3) {
            searchByMakeOrModel(cars, carCount);
        }
    } while (choice != 4);

    return 0;
}
