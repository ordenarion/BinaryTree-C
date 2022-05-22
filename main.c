#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MIN(X, Y) (((X) <= (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) >= (Y)) ? (X) : (Y))
typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}node;
node* head = NULL;

typedef struct asciinode
{
    struct asciinode * left, * right;

    //length of the edge from this node to its children
    int edge_length;

    int height;

    int lablen;

    //-1=I am left, 0=I am root, 1=right
    int parent_dir;

    //max supported unit32 in dec, 10 digits max
    char label[11];
}asciinode;

int INFINITY = 100000000;
int MAX_HEIGHT = 100000;

int rprofile[10000000];
int lprofile[10000000];
int gap = 1;

void add();
void show();
int delete();
void post(node *root);
void in(node *root);
void pre(node *root);
void clear();
void PrintTree(node *root);

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
        printf("6. Draw\n");
        printf("7. Clear tree\n");
        printf("8. Exit\n");
        printf("--------------------------------------------------------------\n");
        printf("Enter the number of the command:");




        while (fgets(enter,100,stdin)==NULL && enter[0] != '\n');
        printf("--------------------------------------------------------------\n");
        if (strcmp(enter, "8\n") == 0) {
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
        } else if (strcmp(enter, "7\n") == 0) {
            clear();
            continue;
        } else if (strcmp(enter, "3\n") == 0) {
            pre(head);
            continue;
        } else if (strcmp(enter, "4\n") == 0) {
            in(head);
            continue;
        }else if (strcmp(enter, "5\n") == 0) {
            PrintTree(head);
            continue;
        }else if (strcmp(enter, "6\n") == 0) {
                PrintTree(head);
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

//void print_level(asciinode *node, int x, int level)
//{
//    int i, isleft,print_next = 0;
//    if (node == NULL) return;
//    isleft = (node->parent_dir == -1);
//    if (level == 0)
//    {
//        for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++)
//        {
//            printf(" ");
//        }
//        print_next += i;
//        printf("%s", node->label);
//        print_next += node->lablen;
//    }
//    else if (node->edge_length >= level)
//    {
//        if (node->left != NULL)
//        {
//            for (i=0; i<(x-print_next-(level)); i++)
//            {
//                printf(" ");
//            }
//            print_next += i;
//            printf("/");
//            print_next++;
//        }
//        if (node->right != NULL)
//        {
//            for (i=0; i<(x-print_next+(level)); i++)
//            {
//                printf(" ");
//            }
//            print_next += i;
//            printf("\\");
//            print_next++;
//        }
//    }
//    else
//    {
//        print_level(node->left,
//                    x-node->edge_length-1,
//                    level-node->edge_length-1);
//        print_level(node->right,
//                    x+node->edge_length+1,
//                    level-node->edge_length-1);
//    }
//}
//
//
////This function fills in the edge_length and
////height fields of the specified tree
//
//
//asciinode * build_ascii_tree_recursive(node * t)
//{
//    asciinode * node;
//
//    if (t == NULL) return NULL;
//
//    node = malloc(sizeof(asciinode));
//    node->left = build_ascii_tree_recursive(t->left);
//    node->right = build_ascii_tree_recursive(t->right);
//
//    if (node->left != NULL)
//    {
//        node->left->parent_dir = -1;
//    }
//
//    if (node->right != NULL)
//    {
//        node->right->parent_dir = 1;
//    }
//
//    sprintf(node->label, "%d", t->value);
//    node->lablen = strlen(node->label);
//
//    return node;
//}
//
//
////Copy the tree into the ascii node structre
//asciinode * build_ascii_tree(node * t)
//{
//    asciinode *node;
//    if (t == NULL) return NULL;
//    node = build_ascii_tree_recursive(t);
//    node->parent_dir = 0;
//    return node;
//}
//
////Free all the nodes of the given tree
//void free_ascii_tree(asciinode *node)
//{
//    if (node == NULL) return;
//    free_ascii_tree(node->left);
//    free_ascii_tree(node->right);
//    free(node);
//}
//
////The following function fills in the lprofile array for the given tree.
////It assumes that the center of the label of the root of this tree
////is located at a position (x,y).  It assumes that the edge_length
////fields have been computed for this tree.
//void compute_lprofile(asciinode *node, int x, int y)
//{
//    int i, isleft;
//    if (node == NULL) return;
//    isleft = (node->parent_dir == -1);
//    lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
//    if (node->left != NULL)
//    {
//        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
//        {
//            lprofile[y+i] = MIN(lprofile[y+i], x-i);
//        }
//    }
//    compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
//    compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
//}
//
//void compute_rprofile(asciinode *node, int x, int y)
//{
//    int i, notleft;
//    if (node == NULL) return;
//    notleft = (node->parent_dir != -1);
//    rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
//    if (node->right != NULL)
//    {
//        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
//        {
//            rprofile[y+i] = MAX(rprofile[y+i], x+i);
//        }
//    }
//    compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
//    compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
//}
//
//
//
//void compute_edge_lengths(asciinode *node)
//{
//    int h, hmin, i, delta;
//    if (node == NULL) return;
//    compute_edge_lengths(node->left);
//    compute_edge_lengths(node->right);
//
//    /* first fill in the edge_length of node */
//    if (node->right == NULL && node->left == NULL)
//    {
//        node->edge_length = 0;
//    }
//    else
//    {
//        if (node->left != NULL)
//        {
//            for (i=0; i<node->left->height && i < MAX_HEIGHT; i++)
//            {
//                rprofile[i] = -INFINITY;
//            }
//            compute_rprofile(node->left, 0, 0);
//            hmin = node->left->height;
//        }
//        else
//        {
//            hmin = 0;
//        }
//        if (node->right != NULL)
//        {
//            for (i=0; i<node->right->height && i < MAX_HEIGHT; i++)
//            {
//                lprofile[i] = INFINITY;
//            }
//            compute_lprofile(node->right, 0, 0);
//            hmin = MIN(node->right->height, hmin);
//        }
//        else
//        {
//            hmin = 0;
//        }
//        delta = 4;
//        for (i=0; i<hmin; i++)
//        {
//            delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
//        }
//
//        //If the node has two children of height 1, then we allow the
//        //two leaves to be within 1, instead of 2
//        if (((node->left != NULL && node->left->height == 1) ||
//             (node->right != NULL && node->right->height == 1))&&delta>4)
//        {
//            delta--;
//        }
//
//        node->edge_length = ((delta+1)/2) - 1;
//    }
//
//    //now fill in the height of node
//    h = 1;
//    if (node->left != NULL)
//    {
//        h = MAX(node->left->height + node->edge_length + 1, h);
//    }
//    if (node->right != NULL)
//    {
//        h = MAX(node->right->height + node->edge_length + 1, h);
//    }
//    node->height = h;
//}

void RecursivePrint(node* cur, int depth)
{
    //Don't print a null tree
    if(cur== 0)
    {
        return;
    }

    //Print data value of current node
    int i =0;
    for( i = 0; i <= depth; i++)
    {
        if(depth - i > 1)
        {
            printf("  ");
        }
        else if (depth - i == 1)
        {
            printf("|-");
        }
        else if (depth - i == 0)
        {
            printf("%d", cur->value);
        }
    }
    printf("\n");

    //Print left
    RecursivePrint(cur->left, depth + 1);
    //Print right
    RecursivePrint(cur->right, depth + 1);
}

// Method to call
void PrintTree( node* root)
{
    RecursivePrint(root, 0);
}