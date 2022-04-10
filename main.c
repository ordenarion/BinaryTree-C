#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}node;
node* head = NULL;
void add();
void show();
void delete();

int main() {
    node* tmp;
    tmp = (node*)malloc(sizeof (node*));
    printf("Hello, World!\n");
    add();
    add();
    add();
    add();
    add();
    add();
    tmp = head;
    delete();
    tmp = head;
//    printf("\n");
//    printf("%d",head->value);
//    printf("\n");
//    printf("%d",head->left->value);
//    printf("\n");
//    printf("%d",head->right->value);
//    printf("\n");
//    printf("%d",head->right->value);
    return 0;
}

void add(){
    int entry,flag;
    scanf("%d",&entry);
    node* tmp, *prev, *newNode;
    tmp = prev = newNode = (node*)malloc(sizeof (node*));
    newNode -> left = newNode -> right = NULL;
    if (head == NULL){
        newNode -> value = entry;
        head = newNode;
    }else{
        tmp = head;
        while (tmp != NULL){
            if (tmp -> value < entry){
                prev = tmp;
                tmp = tmp -> right;
                flag = 0;
            }else if (tmp -> value > entry){
                prev = tmp;
                tmp = tmp -> left;
                flag = 1;
            }
        }
        newNode -> value = entry;
        if (flag == 1){
            prev -> left = newNode;
        }else{
            prev -> right = newNode;
        }


    }
}

void delete() {
    int entry, flag;
    scanf("%d", &entry);
    node *tmp, *prev, *newNode, *tmp1;
    tmp = tmp1 = prev = newNode = (node *) malloc(sizeof(node *));
    newNode->left = newNode->right = NULL;
    if (head == NULL) {
        return;
    } else {
        tmp = head;
        while (tmp->value != entry && tmp != NULL) {
            if (tmp->value < entry) {
                prev = tmp;
                tmp = tmp->right;
                flag = 0;
            } else if (tmp->value > entry) {
                prev = tmp;
                tmp = tmp->left;
                flag = 1;
            } else if (tmp->value == entry) {
                if (tmp->left == NULL && tmp->right == NULL) {
                    if (flag == 1) { prev->left = NULL; }
                    else {
                        prev->right = NULL;
                        return;
                    }
                    tmp = prev;
                    tmp1 = prev;
                    while (prev->left != NULL) {
                        tmp = prev;
                        prev = prev->left;
                    }
                    tmp1->value = tmp->value;
                    tmp->left = tmp->left->left;
                    tmp->right = tmp -> right -> right;
                }

            }


        }

    }
}

void show(){
    int id = 1;

}