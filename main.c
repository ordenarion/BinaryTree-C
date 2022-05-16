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
int delete();
void post(node *root);
void in(node *root);
void pre(node *root);


int main() {
    node* tmp1;
    tmp1 = (node*)malloc(sizeof (node*));
    printf("Hello, World!\n");
    tmp1 = head;
    add();
    add();
    add();

    delete();
    printf("\n");
    post(head);
    printf("\n");
    in(head);
    printf("\n");
    pre(head);

    tmp1 = head;
    return 0;
}

void add(){
    int entry,flag;
    scanf("%d",&entry);
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

int delete() {
    int entry, flag;
    scanf("%d", &entry);
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