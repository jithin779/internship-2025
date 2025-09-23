#include<stdio.h>
#include<stdlib.h>

// Structure to represent a term in a polynomial
typedef struct Node{
    int coeff;
    int pow;
    struct Node*next;
}Node;

//Function to create new node
Node*createNode(int coeff,int pow){
    Node*newNode=(Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->coeff=coeff;
    newNode->pow=pow;
    newNode->next=NULL;
    return newNode;
}

// Inserts a new term into a polynomial linked list in descending order of power
void insertNode(Node**poly,int coeff,int pow){
    Node* newNode = createNode(coeff, pow);
    // If the list is empty or the new node's power is greater than the head's power
    if (*poly == NULL || (*poly)->pow < pow) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    Node* temp = *poly;
    Node* prev = NULL;
    // Traverse the list to find the correct position
    while (temp != NULL && temp->pow > pow) {
        prev = temp;
        temp = temp->next;
    }
    
    // If a term with the same power already exists, add the coefficients
    if (temp != NULL && temp->pow == pow) {
        temp->coeff += coeff;
        free(newNode); // Free the newly created node
    } else {
        // Insert the new node
        newNode->next = temp;
        prev->next = newNode;
    }
}

// Display polynomial
void displayPoly(Node* poly){
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while(poly!=NULL){
        printf("%dx^%d",poly->coeff,poly->pow);
        poly=poly->next;
        if(poly!=NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

// Add two polynomials
Node*addPoly(Node*poly1,Node*poly2){
    Node*result=NULL;
    while(poly1!=NULL && poly2!=NULL){
        if(poly1->pow > poly2->pow){
            insertNode(&result,poly1->coeff,poly1->pow);
            poly1=poly1->next;
        }
        else if(poly1->pow < poly2->pow){
            insertNode(&result,poly2->coeff,poly2->pow);
            poly2=poly2->next;
        }
        else{
            int sumCoeff = poly1->coeff + poly2->coeff;
            if(sumCoeff != 0) { // Only insert if the coefficient is not zero
                insertNode(&result, sumCoeff, poly1->pow);
            }
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }
    // Append remaining terms from poly1
    while(poly1!=NULL){
        insertNode(&result,poly1->coeff,poly1->pow);
        poly1=poly1->next;
    }
    // Append remaining terms from poly2
    while(poly2!=NULL){
        insertNode(&result,poly2->coeff,poly2->pow);
        poly2=poly2->next;
    }
    return result; // Correctly return the head of the result list
}

// Multiply two polynomials
Node*multiplyPoly(Node*poly1,Node*poly2){
    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }

    Node*result=NULL;
    for(Node*ptr1=poly1;ptr1!=NULL;ptr1=ptr1->next){
        for(Node*ptr2=poly2;ptr2!=NULL;ptr2=ptr2->next){
            int coeff = ptr1->coeff * ptr2->coeff;
            int pow = ptr1->pow + ptr2->pow;
            insertNode(&result, coeff, pow); // Use the corrected insertNode to handle sorting and addition
        }
    }
    return result; // Correctly return the head of the result list
}

// Main function
int main()
{
    Node*poly1=NULL;
    Node*poly2=NULL;
    Node*sum=NULL;
    Node*product=NULL;
    
    // poly 1: 3x^3 + 2x^2 + 1x^0
    insertNode(&poly1,3,3);
    insertNode(&poly1,2,2);
    insertNode(&poly1,1,0);
    
    // poly 2: 4x^2 + 2x^1 + 5x^0
    insertNode(&poly2,4,2);
    insertNode(&poly2,2,1);
    insertNode(&poly2,5,0);
    
    printf("Polynomial 1 : ");
    displayPoly(poly1);
    printf("Polynomial 2 : ");
    displayPoly(poly2);
    
    sum=addPoly(poly1,poly2);
    printf("Sum : ");
    displayPoly(sum);
    
    product=multiplyPoly(poly1,poly2);
    printf("Product : ");
    displayPoly(product);
    
    // Free allocated memory
    // (This part is missing from the original code but is good practice)
    
    return 0;
}
