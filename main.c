#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}node;
node* head = NULL;

void add();
void show();
int delete();
void post(node *root);
void in(node *root);
void pre(node *root);
void clear();


int main() {
    char enter[100];
    while (1) {
        printf("\n");
        printf("----------------There are some Binary Tree commands----------------\n");
        printf("1. Add new root\n");
        printf("2. Delete root\n");
        printf("3. Pre\n");
        printf("4. In\n");
        printf("5. Post\n");
        printf("6. Clear tree\n");
        printf("7. Exit\n");
        printf("--------------------------------------------------------------\n");
        printf("Enter the number of the command:");




        while (fgets(enter,100,stdin)==NULL && enter[0] != '\n');
        printf("--------------------------------------------------------------\n");
        if (strcmp(enter, "7\n") == 0) {
            printf("Goodbye\n");
            printf("--------------------------------------------------------------\n");
            exit(0);

        }
        else if (strcmp(enter, "1\n") == 0) {
            add();
            continue;
        } else if (strcmp(enter, "2\n") == 0) {
            int entry,f = 0;
            char term;
            if (scanf("%d%c", &entry, &term) != 2 || term != '\n') continue;
            delete(entry);
            continue;
        } else if (strcmp(enter, "6\n") == 0) {
            clear();
            continue;
        } else if (strcmp(enter, "3\n") == 0) {
            pre(head);
            continue;
        } else if (strcmp(enter, "4\n") == 0) {
            in(head);
            continue;
        }else if (strcmp(enter, "5\n") == 0) {
            post(head);
            continue;
        } else if (strcmp(enter, "\n") == 0) {continue;}
        else {
            printf("Incorrect input. Try again");
            continue;
        }


        printf("Hello, World!\n");
        exit(0);
    }
    return 0;
}

void add(){
    int entry,flag,f = 0;
    char term;
    if (scanf("%d%c", &entry, &term) != 2 || term != '\n') return;

    node* tmp, *prev, *newNode;
    prev  = (node*)malloc(sizeof (node*));
    tmp = (node*)malloc(sizeof (node*));
    newNode = (node*)malloc(sizeof (node*));

    newNode -> left  = NULL;
    newNode -> right = NULL;
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
            }else if (tmp -> value >= entry){
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

int delete(int entry) {
    int flag;
    node *curr = head, *prev = NULL, *toRemove, *replacement;
//    curr = (node *) malloc(sizeof(node *));
//    prev = (node *) malloc(sizeof(node *));
    toRemove = (node *) malloc(sizeof(node *));
    replacement= (node *) malloc(sizeof(node *));
    flag = 0;
    while (curr != NULL && entry != curr->value){
        prev = curr;
        if (entry < curr->value){
            flag = 1; curr = curr->left;
        } else {
            flag = 0; curr = curr->right;
        }
    }
    if (curr==NULL) return 1;
    if (curr->left != NULL && curr->right != NULL){
        toRemove = curr;
        prev = curr; flag = 0; curr = curr->right;
        while (curr->left != NULL){
            flag = 1; prev = curr; curr = curr->left;
        }
        toRemove->value = curr->value;
    }
    if (curr->right == NULL){
        replacement = curr->left;
    } else replacement = curr->right;
    if (prev == NULL){
        head = replacement;
    } else if (flag == 1){
        prev->left = replacement;
    } else {
        prev->right = replacement;
    }
    return 0;

}


void post(node *root) {
    if (root != NULL) {
        post(root->left);
        post(root->right);
        printf("%d ", root->value);
    }
}
void in(node* root){
    if (root != NULL) {
        in(root->left);
        printf("%d ", root->value);
        in(root->right);
    }
}
void pre(node* root){
    if (root != NULL){
        printf("%d ", root->value);
        pre(root->left);
        pre(root->right);
    }
}

void clear(){
    while (head != NULL){
        delete(head -> value);
    }
    head = NULL;
}