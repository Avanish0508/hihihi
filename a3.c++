#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int row, col, value;
    struct Node *next;
};
struct Node *createNode(int row, int col, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void displaySparseMatrix(struct Node *head)
{
    if (head == NULL)
    {
        printf("The sparse matrix is empty.\n");
        return;
    }
    printf("Row\tColumn\tValue\n");
    printf("-----------------\n");
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d\t%d\t%d\n", current->row, current->col, current->value);
        current = current->next;
    }
}
int main()
{
    int m, n;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);
    struct Node *head = NULL;
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int element;
            scanf("%d", &element);
            if (element != 0)
            {
                if (head == NULL)
                {
                    head = createNode(i, j, element);
                }
                else
                {
                    struct Node *newNode = createNode(i, j, element);
                    newNode->next = head;
                    head = newNode;
                }
            }
        }
    }
    printf("Linked List Representation of Sparse Matrix:\n");
    displaySparseMatrix(head);
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}