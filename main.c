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
void post(node *root);
void in(node *root);
void pre(node *root);


int main() {
    node* tmp1;
    tmp1 = (node*)malloc(sizeof (node*));
    printf("Hello, World!\n");
    add();
    tmp1 = head;
//    show();
//    delete();
//    pre(head);
//    post(head);
//    in(head);

    add();
   add();
   add();
//    tmp = head;
//    delete();
//    tmp = head;
//    show();
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
    free(tmp);
    free(prev);

}

void delete() {
    int entry, flag;
    scanf("%d", &entry);
    node *tmp, *prev, *newNode, *a, *b;
    tmp = a = b = prev = newNode = (node *) malloc(sizeof(node *));
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
               break;
            }

        }

        if (tmp->left == NULL && tmp->right == NULL) {
            if (flag == 1) { prev->left = NULL; }
            else {
                prev->right = NULL;
            }
            return;
        }else if (tmp -> left == NULL){
            if (flag == 1){
                prev -> left = tmp -> right;
                tmp-> right = NULL;
                free(tmp);
            }else{
                prev -> right = tmp -> right;
                tmp-> right = NULL;
                free(tmp);
            }
            return;
        }else if (tmp -> right == NULL){
            if (flag == 1){
                prev -> left = tmp -> left;
                tmp -> left = NULL;
                free(tmp);
            }else{
                prev -> right = tmp -> left;
                tmp -> right = NULL;
                free(tmp);
            }
            return;

        }else{
            a = tmp->right;
            while (a->left != NULL) {
                b = a;
                a = a->left;
            }
            if (a->right != NULL) {
                b -> left = a -> right;
            }else{
                b -> left = NULL;
            }
            a -> left = tmp -> left;
            a -> right = tmp -> right;
            if (flag == 1) {
                prev->left = a;
            }else{
                prev -> right = a;
            }
            free(tmp);
            return;

        }

    }
}

void show(){
   int id = 1;
}

void post(node *root) // displaying the nodes!
{
    if (root != NULL) {
        post(root->left);
        post(root->right);
        printf("%d \n", root->value);
    }
}

void in(node *root) // displaying the nodes!
{
    if (root != NULL) {
        in(root->left);
        printf("%d \n", root->value);
        in(root->right);
    }
}

void pre(node *root) // displaying the nodes!
{
    printf("%d \n", root->value);
    if (root != NULL) {
        pre(root->left);
        pre(root->right);
    }
}