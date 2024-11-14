DOUBLELINKEDLIST
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node*prev;
    int data;
    struct node*next;
};
struct node *head=NULL,*tail,*newnode,*temp,*current,*back,*ptr;

void create()
{
    int n;
    printf("ENTER NO OF NODES: ");
    scanf("%d",&n);
    printf("ENTER ELEMENTS: ");
    for(int i=0;i<n;i++)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL && tail==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void addfront()
{
    int data;
    printf("ENTER ELEMENT TO BE ADDED IN THE FRONT: ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if (head==NULL)
    {
        head=tail=newnode;
    
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
}

void addrear()
{
    int data;
    printf("ENTER ELEMENT TO BE ADDED AT THE END: ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL && tail==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    
}

void addbetween()
{
    int c;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    int pos;
    printf("ENTER POSITION WHERE ELEMENT IS TO BE ADDED: ");
    scanf("%d",&pos);
    int data;
    printf("ENTER ELEMENT: ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if (pos>c)
    {
        printf("invalid pos\n");
        
    }
    else
    {
        int i=1;
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        if(newnode->next!=NULL){
            newnode->next->prev=newnode;
        }
    }
    
}

void delfront()
{
    temp=head;
    printf("Deleted Element: %d\n",temp -> data);
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void delrear()
{
    temp=head;
    while(temp->next!=NULL)
    {
        back=temp;
        temp=temp->next;
        
    }
    back->next=NULL;
    printf("Deleted Element: %d\n",temp -> data);
    free(temp);
}

void delbetween()
{
    int pos;
    printf("ENTER POSITION: ");
    scanf("%d",&pos);
    int i=1;
    temp=head;
    while(i<pos-1)
    {
       temp=temp->next;
       i++;
    }
    ptr=temp->next;
    temp->next=ptr->next;
    printf("Deleted Element: %d\n",ptr -> data);
    free(ptr);
    
}

void main()
{
    int ch;
    int flag=1;
    printf("1.CREATE N NODES\n2.DISPLAY\n3.INSERTION AT FRONT\n4.INSERTION AT REAR\n5.INSERTION IN BETWEEN\n6.DELETION AT FRONT\n7.DELETION AT REAR\n8.DELETION IN BETWEEN\n9.EXIT\n");
    while(flag==1)
    {
        printf("ENTER CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();break;
            case 2:display();break;
            case 3:addfront();break;
            case 4:addrear();break;
            case 5:addbetween();break;
            case 6:delfront();break;
            case 7:delrear();break;
            case 8:delbetween();break;
            case 9:flag=0;break;
            default:printf("invalid ch");break;  
        }
    }
}
SINGLELINKEDLIST
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*current,*head=NULL,*newnode,*temp,*prev;


void display(){
    if(head==NULL)
        printf("LINKED LIST IS EMPTY");
    else{
        current=head;
        printf("LINKED LIST IS: ");
        while(current!=NULL){
            printf("%d ",current->data);
            current=current->next;
    }
}}
void insert_begin(){
    printf("Enter data:");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
       head=newnode;
       printf("%d was inserted.",newnode->data);
    }
    else{
        newnode->next=head;
        head=newnode;
        printf("%d was inserted.",newnode->data);
    }
}
void insert_end(){
    printf("Enter data:");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
       head=newnode;
       printf("%d was inserted.",newnode->data);
    }
    else{
            temp=head;
            while(temp->next!=NULL)
            temp=temp->next;
            temp->next=newnode;
            printf("%d was inserted.",newnode->data);
    }
}
void insert_pos(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter position:");
    int pos;
    scanf("%d",&pos);
    current=head;
    int i=0;
    while(current!=NULL){
        current=current->next;
        i++;
    }
    if(pos>(i+1)||pos<1){
        printf("Invalid Position!");
    }
    else if(pos==1)
        insert_begin();
    else{
        printf("Enter data:");
        scanf("%d",&newnode->data);
        current=head;
        for(int j=1;j<pos-1;j++)
            current=current->next;
        newnode->next=current->next;
        current->next=newnode;
    }
}
void delete_begin(){
    if(head==NULL)
    printf("Linked list is empty. Nothing to delete");
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        printf("%d was deleted",temp->data);
        free(temp);
    }
    else{
        temp=head;
        head=head->next;
        printf("%d was deleted",temp->data);
        free(temp);
    }
}
void delete_end(){
    if(head==NULL)
    printf("Linked list is empty. Nothing to delete");
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        printf("%d was deleted",temp->data);
        free(temp);
    }
    else{
        current=head;
        while(current->next!=NULL){
            prev=current;
            current=current->next;
        }
        prev->next=NULL;
        printf("%d was deleted",current->data);
        free(current);
    }
}
void delete_pos(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter position:");
    int pos;
    scanf("%d",&pos);
    current=head;
    int i=0;
    while(current!=NULL){
        current=current->next;
        i++;
    }
    if(pos>(i)||pos<1){
        printf("Invalid Position!");
    }
    else if(pos==1)
        delete_begin();
    else{
        current=head;
        for(int j=1;j<pos;j++){
            prev=current;
            current=current->next;
        }
        prev->next=current->next;
        free(current);
    }
}
void main(){
    int choice;
    printf("\n1.Display\n2.InsertBegin\n3.InsertEnd\n4.InsertPos\n5.DeleteBegin\n6.DeleteEnd\n7.DeletePos\n8.Exit");
    while(choice!=8){
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display();
                break;
            case 2:
                insert_begin();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_pos();
                break;
            case 5:
                delete_begin();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_pos();
                break;
            case 8:
                break;
            default:
                printf("INVALID CHOICE.");
        }
    }
}

CIRCULARLINKEDLIST
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node * rmfirst(struct node *head){
    if (head==NULL){
        printf("Undedflow\n");
    }
    else if (head->next==head){
        printf("Popped data is : %d",head->data);
        free(head);
        head=NULL;
    }
    else{
        struct node *temp,*current;
        printf("Popped data is : %d",head->data);
        temp = head;
        current=head;
        do{
            current =  current->next;
        }while (current->next != head);
        current->next=head->next;
        head=temp->next;
        free(temp);
    }
    return head;
}
struct node * addlast(struct node *head){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    printf("Enter data : ");
    int e;
    scanf("%d",&e);
    newnode->data = e;
    newnode->next=head;
    if (head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        struct node *current;
        current = head;
        do{
            current =  current->next;
        }while (current->next != head);
        current->next=newnode;
    }
    return head;
}
struct node * addfirst(struct node *head){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    printf("Enter data : ");
    int e;
    scanf("%d",&e);
    newnode->data = e;
    if (head == NULL){
        head =  newnode;
        newnode->next = head;
    }
    else if(head->next==head) {
        newnode->next=head;
        head->next=newnode;
        head=newnode;
    }
    else{
        newnode->next=head;
        struct node *current;
        current=head;
        do{
            current =  current->next;
        }while (current->next != head);
        current->next=newnode;
        head=newnode;
    }
    return head;
}
struct node * rmlast(struct node *head){
    if (head==NULL){
        printf("Underflow\n");
    }
    else if (head->next == head){
        printf("Popped data is : %d",head->data);
        free(head);
        head=NULL;
    }
    else{
        struct node *current;
        current=head;
        while(current->next->next!=head){
            current=current->next;
        }
        struct node *temp;
        temp=current->next;
        printf("Popped element is : %d",temp->data);
        free(temp);
        current->next=head;
    }
    return head;
}
bool search(struct node *head,int data){
    if (head==NULL){
        return false;
    }
    else{
        struct node *current;
        current=head;
        do{
            if (head->data = data){
                return true;
            }
            current=current->next; 
        }while(current!=head);
        return false;
    }
}
bool addmid(struct node *head,int a , int b){
    if(head==NULL){
        return false;
    }
    struct node *newnode;
    newnode= malloc(sizeof(struct node));
    struct node *current;
    current=head;
    do{
       if (current->data ==a && current->next->data==b){
           printf("Enter data : ");
           int e;
           scanf("%d",&e);
           newnode->data=e;
           newnode->next=head->next;
           current->next=newnode;
           return true;
       }
       current=current->next;
    }while(current!=head);
    return false;
     }
void display(struct node *head){
    struct node *current;
    current=head;
    if (head==NULL){
        printf("Underflow\n");
    }
    else{
        do{
            printf("%d\n",head->data);
            head=head->next;
        }while(current!=head);
    }
}
int main(){
    int ch,y,x;
    struct node *head;
    head=NULL;
    while (true){
        printf("1. Display\n");
        printf("2. ADD FIRST\n");
        printf("3. REMOVE FIRST\n");
        printf("4. ADD LAST\n");
        printf("5. REMOVE LAST\n");
        printf("6. SEARCH\n");
        printf("7. ADD MID\n");
        printf("8. Exit\n\n");
        printf("Enter choice :");
        scanf("%d",&ch);
        switch (ch){
            case 1 :display(head);break;
            case 2 :head= addfirst(head);break;
            case 3 :head=rmfirst(head);break;
            case 4 :head=addlast(head);break;
            case 5 :head=rmlast(head);break;
            case 6 :
                printf("Enter search key : ");
                scanf("%d",&x);
                if (search(head,x)){
                    printf("Element found\n");
                }
                else{
                    printf("Element not found\n");
                }
                break;
            case 7 :
                printf("Enter the elements : ");
                scanf("%d %d",&x,&y);
                if(!addmid(head,x,y)){
                    printf("Not Possible\n");
                }
                break;
            case 8 :return 0;break;
            default:printf("Invalid Choice\n");
       }
       printf("\n");
   }
}


POLYADD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node                                                             //Node with fields coefficent, degree and next pointer
{
    int coefficent;
    int degree;
    struct node *next;
};

struct node* poly1 = NULL;
struct node* poly2 = NULL;
struct node* poly3 = NULL;

struct node* read_Poly(struct node *poly, int coeff, int deg)           //Function that creates a new node
{
    struct node *temp = poly;
    struct node* newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->coefficent = coeff;
    newnode->degree = deg;
    if (poly == NULL)
    {
        poly  = newnode; 
    }
    else
    {
        while (temp->next!= NULL)
        {
           temp = temp->next;
        }
        temp->next = newnode;
    }
    return poly;
}
void display(struct node *poly)                                                 //Displaying polynomial function by passing head pointer
{
    while(poly->next!= NULL)
    {
        printf("%dx^%d+ ",poly->coefficent, poly->degree);
        poly = poly->next;
    }
    printf("%dx^%d ",poly->coefficent, poly->degree);
}

void addPoly()
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    struct node *temp1 = poly1;
    struct node *temp2 = poly2;
    struct node *temp3 = poly3;

    while (temp1!= NULL && temp2 != NULL)                                                           //Adding Common terms of both the polynomials
    {
        if (temp1->degree == temp2->degree)
        {
            poly3 = read_Poly(poly3, (temp1->coefficent+temp2->coefficent), temp1->degree);
            temp1 = temp1->next;
            temp2 = temp2->next;
            
        }
        else if (temp1->degree > temp2->degree)
        {
            poly3 = read_Poly(poly3, temp1->coefficent, temp1->degree);
            temp1 = temp1->next;
        }
        else
        {
            poly3 = read_Poly(poly3, temp2->coefficent, temp2->degree);
            temp2 = temp2->next;
        }
    }
    while (temp1!=NULL)                                                                         //Adding remaining terms of poly1 into the resultant polynomial
    {
        poly3 = read_Poly(poly3, temp1->coefficent, temp1->degree);
        temp1 = temp1->next;
    }
    while (temp2!=NULL)                                                                         //Adding remaining terms of poly2 into the resultant polynomial
    {
        poly3 = read_Poly(poly3, temp2->coefficent, temp2->degree);
        temp2 = temp2->next;
    }
    display(poly3);
    
}



void main()
{
    int choice, coeff, deg;
    while(1)
    {
        printf("\nSelect an option:\n");
        printf("1. Enter term for polynomial 1\n");
        printf("2. Enter term for polynomial 2\n");
        printf("3. Perform Addition\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter coefficient and degree for the term: ");
                scanf("%d%d", &coeff, &deg);
                poly1 = read_Poly(poly1, coeff, deg);
                break;
            case 2:
                printf("Enter coefficient and degree for the term: ");
                scanf("%d%d", &coeff, &deg);
                poly2 = read_Poly(poly2, coeff, deg);
                break;
            case 5:
                exit(0);
                break;
            case 3:
                addPoly();
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}

TREE
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node *root=NULL,*temp=NULL;

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

void inorder(struct Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct Node* root)
{
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

void deleteNode(struct Node** root, int key) {
    if (*root == NULL) return;
    if (key < (*root)->key)
        deleteNode(&((*root)->left), key);
    else if (key > (*root)->key)
        deleteNode(&((*root)->right), key);
    else {
        if ((*root)->left == NULL) {
            struct Node *temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL) {
            struct Node *temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else {
            int minKey = minimum((*root)->right);
            (*root)->key = minKey;
            deleteNode(&((*root)->right), minKey);
        }
    }
}

struct Node* insert(struct Node* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

int minimum(struct Node* root){
    if(root==NULL)
        return 0;
    else{
        while(root->left!=NULL){
            root=root->left;
        }
        return root->key;
    }
}

int maximum(struct Node* root){
    if(root==NULL)
        return 0;
    else{
        while(root->right!=NULL){
            root=root->right;
        }
        return root->key;
    }
}

int main()
{
    int ch,key;
    while(1){
        printf("\n1.Insert\n2.Search\n3.Minimum\n4.Maximum\n5.Inorder\n6.Preorder\n7.Postorder\n8.Delete\n9.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the key:");
                scanf("%d",&key);
                root=insert(root,key);
                break;
            case 2:
                printf("Enter the key:");
                scanf("%d",&key);
                temp=search(root,key);
                if(temp==NULL)
                    printf("Key not found\n");
                else
                    printf("Key found\n");
                break;
            case 3:
                printf("Minimum key is %d\n",minimum(root));
                break;
            case 4:
                printf("Maximum key is %d\n",maximum(root));
                break;
            case 5:
                inorder(root);
                break;
            case 6:
                preorder(root);
                break;
            case 7:
                postorder(root);
                break;
            case 8:
                printf("Enter the key to delete:");
                scanf("%d", &key);
                deleteNode(&root, key);
                break;
            case 9:
                exit(0);
        }
    }
    return 0;
}

GRAPH
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
    int data;
    struct node *next;
};
int top=-1,f=0,r=-1;
struct node * addLast(struct node *head,int data){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head==NULL){
        head=newnode;
    }
    else{
        struct node *current;
        current = head;
        while (current->next != NULL){
            current =  current->next;
        }
        current->next=newnode;
    }
    return head;
}
bool isEmptyS(){
    return (top==-1);
}
bool isEmptyQ(){
    return (f>r);
}
void  push(int n, int S[n],int data){
    S[++top]=data;
}
int  pop(int n,int S[n]){
    top=top-1;
    return S[top+1];
}
int  deQueue(int  n,int Q[n]){
    f=f+1;
    return Q[f-1];
}
void enQueue(int n,int Q[n],int data){
    Q[++r]=data;
}
void main(){
    int n,data,m;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    struct node *aList[n];
    printf("Enter vertices :\n");
    for (int i = 0; i < n ; i++){
        aList[i]=NULL;
        scanf("%d",&data);
        aList[i]=addLast(aList[i],data);
    }
    for (int i=0;i<n;i++){
        printf("Enter no neighbours of vertex %d\n",aList[i]->data);
        scanf("%d",&m);
        printf("Enter neighbours : \n");
        for (int j=0;j<m;j++){
            scanf("%d",&data);
            aList[i]=addLast(aList[i],data);
        }
    }
    printf("Adjescentsy List :\n");
    for (int i = 0;i<n;i++){
        struct node *current;
        current=aList[i];
        while(current->next!=NULL){
            printf("%d-->",current->data);
            current=current->next;
        }
        printf("%d\n",current->data);
    }
    int Stack[n],visit[n],Queue[n];
    push(n,Stack,aList[0]->data);
    int index = -1;
    while(!isEmptyS()){
        struct node *current;
        int high = pop(n,Stack);
        visit[++index]=high;
        for (int i=0;i<n;i++){
            if (aList[i]->data==high){
                current = aList[i]->next;
            }
        }
        while(current!=NULL){
            int f=0;
            for (int i=0;i<=index;i++){
                if(visit[i]==current->data){
                    f=1;
                }
            }
            for(int i=0;i<=top;i++){
                if(Stack[i]==current->data){
                    f=1;
                }
            }
            if (f!=1){
                push(n,Stack,current->data);
            }
            current=current->next;
        }
    }

    printf("Depth First Search : \n");
    for (int i = 0;i<=index;i++){
        printf("%d ",visit[i]);
    }
    printf("\n");
    index=-1;
    visit[++index] = aList[0]->data;
    enQueue(n,Queue,aList[0]->data);
    while(!isEmptyQ()){
        struct node *current;
        int low = deQueue(n,Queue);
        for (int i = 0;i<n;i++){
            if (aList[i]->data==low){
                current = aList[i];
            }
        }
        while(current->next!=NULL){
            current=current->next;
            int f=0;
            for (int i = 0 ; i<=index;i++){
                if(visit[i]==current->data){
                    f=1;
                }
            }
            if (f!=1){
                visit[++index]=current->data;
                enQueue(n,Queue,current->data);
            }
        }
    }
    printf("Breadth First Search : \n");
    for(int i =0;i<=index;i++){
        printf("%d ",visit[i]);
    }
    printf("\n");
}

HASHING
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Node
{
    int data;
    struct Node *next;
};
struct HashTable
{
    struct Node *chain[SIZE];
};
void init(struct HashTable *ht)
{
    for (int i = 0; i < SIZE; i++)
    {
        ht->chain[i] = NULL;
    }
}
void insert(struct HashTable *ht, int value)
{
    int key = value % SIZE;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (ht->chain[key] == NULL)
    {
        ht->chain[key] = newNode;
    }
    else
    {
        struct Node *temp = ht->chain[key];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Entered value %d added to hash table\n", value);
}
void printHashTable(struct HashTable *ht)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("chain[%d]-->", i);
        struct Node *temp = ht->chain[i];
        while (temp != NULL)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void main()
{
    struct HashTable ht;
    init(&ht);
    int num, val;
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insert(&ht, val);
    }
    printf("\n\nThe hash table is:\n\n");
    printHashTable(&ht);
}

HEAPSORT

#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void maxheapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        maxheapify(a, n, largest);
    }
}
void heapsort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxheapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        maxheapify(a, i, 0);
    }
}
int main()
{
    int n, a[20], i;
    printf("Enter size of array : ");
    scanf("%d", &n);
    printf("Enter array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    heapsort(a, n);
    printf("Sorted array is\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

POLY MULTIPLICATION
#include <stdio.h>
#include <stdlib.h>
int degree = 0;
struct node
{
    int coeff;
    int pow;
    struct node *next;
} *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
struct node *createPoly(struct node *head)
{
    int n, i, m = 0;
    struct node *ptr, *temp = head;
    printf("ENTER NUMBER OF TERMS IN POLYNOMIAL : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        ptr = malloc(sizeof(struct node));
        printf("ENTER COEFFICIENT AND POWER : ");
        scanf("%d %d", &ptr->coeff, &ptr->pow);
        if (i == 0)
        {
            head = ptr;
            ptr->next = NULL;
            temp = ptr;
        }
        else
        {
            temp->next = ptr;
            ptr->next = NULL;
            temp = ptr;
        }
        if (ptr->pow > m)
        {
            m = ptr->pow;
        }
    }
    degree += m;
    return head;
}
void createPolyFromHash(int hash[], int m)
{
    struct node *ptr, *temp = poly3;
    for (int i = 0; i < m + 1; i++)
    {
        if (hash[i] != 0)
        {
            ptr = malloc(sizeof(struct node));
            ptr->coeff = hash[i];
            ptr->pow = i;
            ptr->next = NULL;
            if (temp == NULL)
            {
                poly3 = ptr;
                temp = ptr;
            }
            else
            {
                temp->next = ptr;
                temp = ptr;
            }
        }
    }
}

void displayPoly(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            printf("%dx^%d", ptr->coeff, ptr->pow);
            break;
        }
        printf("%dx^%d + ", ptr->coeff, ptr->pow);
        ptr = ptr->next;
    }
    printf("\n");
}
void multiplyPoly(struct node *head1, struct node *head2, int m)
{
    struct node *ptr1, *ptr2;
    int hash[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        hash[i] = 0;
    }
    for (ptr1 = head1; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (ptr2 = head2; ptr2 != NULL; ptr2 = ptr2->next)
        {
            int c = ptr1->coeff * ptr2->coeff;
            int p = ptr1->pow + ptr2->pow;
            hash[p] += c;
        }
    }
    createPolyFromHash(hash, m);
}
int main()
{
    poly1 = createPoly(poly1);
    poly2 = createPoly(poly2);
    printf("POLYNOMIAL 1 : ");
    displayPoly(poly1);
    printf("POLYNOMIAL 2 : ");
    displayPoly(poly2);
    multiplyPoly(poly1, poly2, degree);
    printf("MULTIPLIED POLYNOMIAL : ");
    displayPoly(poly3);
}

TREE USING ARRAY
#include <stdio.h>
int complete_node = 15;
char tree[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '\0', '\0',
               'J', '\0', 'K', 'L'};
int get_right_child(int index)
{
    if (tree[index] != '\0' && ((2 * index) + 2) <= complete_node)
        return (2 * index) + 2;
    return -1;
}
int get_left_child(int index)
{
    if (tree[index] != '\0' && (2 * index + 1) <= complete_node)
        return 2 * index + 1;
    return -1;
}
void preorder(int index)
{
    if (index >= 0 && tree[index] != '\0')
    {
        printf(" %c ", tree[index]);
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}
void postorder(int index)
{
    if (index >= 0 && tree[index] != '\0')
    {
        postorder(get_left_child(index));
        postorder(get_right_child(index));
        printf(" %c ", tree[index]);
    }
}
void inorder(int index)
{
    if (index >= 0 && tree[index] != '\0')
    {
        inorder(get_left_child(index));
        printf(" %c ", tree[index]);
        inorder(get_right_child(index));
    }
}
int main()
{
    printf("Preorder:\n");
    preorder(0);
    printf("\nPostorder:\n");
    postorder(0);
    printf("\nInorder:\n");
    inorder(0);
    printf("\n");
    return 0;
}

CIRCULAR QUEUE
#include <stdio.h>
int items[100];
int size;
int front = -1;
int rear = -1;
int size;
int isFull()
{
    return (front == rear + 1) || (front == 0 && rear == size - 1);
}
int isEmpty()
{
    return (front == -1);
}
void enQueue(int element)
{
    if (isFull())
    {
        printf("QUEUE IS FULL \n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        items[rear] = element;
    }
}
int deQueue()
{
    int element;
    if (isEmpty())
    {
        printf("QUEUE IS EMPTY\n");
        return (-1);
    }
    else
    {
        element = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return (element);
    }
}
void display()
{
    int i;
    if (isEmpty())
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        for (i = front; i != rear; i = (i + 1) % size)
        {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
    }
}
void menu()
{
    printf("CHOICES...\n");
    printf("1. INSERT \n");
    printf("2. DELETE \n");
    printf("3. DISPLAY \n");
    printf("4. EXIT \n");
}
int main()
{
    int choice, element;
    printf("enter size\n");
    scanf("%d", &size);
    menu();
    do
    {
       
        printf("ENTER YOUR CHOICE :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER ELEMENT TO BE INSERTED : ");
            scanf("%d", &element);
            enQueue(element);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("EXITING\n");
            break;
        default:
            printf("INVALID CHOICE\n");
        }
        printf("\n");
    } while (choice != 4);
    return 0;
}

DOUBLENDEDQUEUE
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 5
int Q[SIZE];
int F = -1;
int R = -1;
void addRear();
void addFront();
void rmRear();
void rmFront();
void display();
void size();
bool isEmpty()
{
    return F == -1;
}
bool isFull()
{
    return (R + 1) % SIZE == F;
}
void main()
{
    int option;
    printf("\n\nQueue operations\n");
    printf("1.Display\n");
    printf("2.Add to rear\n");
    printf("3.Add to front\n");
    printf("4.Remove from rear\n");
    printf("5.Remove from front\n");
    printf("6.Size\n");
    printf("7.Exit\n");
    while (true)
    {
        printf("Select an option : ");
        scanf("%d", &option);
        printf("\n");
        switch (option)
        {
        case 1:
            display();
            break;
        case 2:
            addRear();
            break;
        case 3:
            addFront();
            break;
        case 4:
            rmRear();
            break;
        case 5:
            rmFront();
            break;
        case 6:
            size();
            break;
        case 7:
            exit(0);
            break;
        default:printf("Invalid option entered\n");
        }
    }
}
void addRear()
{
    if (isFull())
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (isEmpty())
        {
            F = 0;
            R = 0;
        }
        else
        {
            R = (R + 1) % SIZE;
        }
        printf("Enter element : ");
        scanf("%d", &Q[R]);
    }
}
void addFront()
{
    if (isFull())
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (isEmpty())
        {
            F = 0;
            R = 0;
        }
        else if (F == 0)
        {
            F = SIZE - 1;
        }
        else
        {
            F--;
        }
        printf("Enter element : ");
        scanf("%d", &Q[F]);
    }
}
void rmRear()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Removing %d\n", Q[R]);
        if (F == R)
        {
            F = -1;
            R = -1;
        }
        else if (R == 0)
        {
            R = SIZE - 1;
        }
        else
        {
            R--;
        }
    }
}
void rmFront()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Removing %d\n", Q[F]);
        if (F == R)
        {
            F = -1;
            R = -1;
        }
        else
        {
            F = (F + 1) % SIZE;
        }
    }
}
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty ! \n");
        return;
    }
    printf("Queue : ");
    int i = F;
    while (i != R)
    {
        printf("%d\t", Q[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", Q[R]);
}
void size()
{
    int size_v;
    if (isEmpty())
        size_v = 0;
    else if (isFull())
        size_v = SIZE;
    else if (F > R)
        size_v = SIZE - (F - R) + 1;
    else
        size_v = F - R + 1;
    printf("Size is %d\n", size_v);
}

INFIXTOPOSTFIX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}
int Precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '^')
        return 3;
    return 0;
}
void infixToPostfix(char infix[], char postfix[])
{
    char stack[100];
    int top = -1;
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else if (isOperator(infix[i]))
        {
            while (top != -1 && Precedence(stack[top]) >= Precedence(infix[i]))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        else
        {
            postfix[j++] = infix[i];
        }
    }
    while (top != -1)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[100];
    printf("ENTER THE INFIX EXPRESSION: ");
    char postfix[100];
    fgets(infix, 100, stdin);
    infixToPostfix(infix, postfix);
    printf("THE POSTFIX EXPRESSION IS : %s\n", postfix);
    return 0;
}

POSTFIX EVALUATION
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    return stack[top--];
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}
int Precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
        else if(ch == '^')
        return 3;
    return 0;
}
int operation(int a, int b, char ch)
{
    if (ch == '+')
        return a + b;
    else if (ch == '-')
        return a - b;
    else if (ch == '*')
        return a * b;
    else if (ch == '/')
        return a / b;
        else if (ch == '^')
        return a ^ b;
}
int postfixEval(char postfix[])
{
    int res = 0;
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (!isOperator(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            int a = pop();
            int b = pop();
            res = operation(b, a, postfix[i]);
            push(res);
        }
    }
    return res;
}

int main()
{
    char postfix[100];
    printf("ENTER THE EXPRESSION: ");
    scanf("%s", postfix);
    int res = postfixEval(postfix);
    printf("THE RESULT IS : %d\n", res);
    return 0;
}
PRIORITYQUEUE

#include <stdio.h>
#include <stdbool.h>
int Msize = 30, f = -1, r = -1;
int A[30];
bool isEmpty()
{
    return (f == -1 || f > r);
}
bool isFull()
{
    return (r == Msize - 1);
}
void deQueue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Dequeued element is %d", A[f++]);
    }
}
void enQueue()
{
    int key;
    if (isEmpty())
    {
        printf("Enter element : ");
        f++;
        r++;
        scanf("%d", &A[r]);
    }
    else if (isFull())
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter elements : ");
        scanf("%d", &A[++r]);
        key = A[r];
        int j = r - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}
void size()
{
    if (isEmpty())
    {
        printf("Queue Underflow");
    }
    else
    {
        printf("Size is %d\n", r - f + 1);
    }
}
void display()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("The queue is :\n");
        for (int i = f; i <= r; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch, c = 0;
    printf("ASCENDING ORDER PRIORITY QUEUE\n");
    printf("1. Display\n");
    printf("2. Enqueue\n");
    printf("3. Dequeue\n");
    printf("4. Size\n");
    printf("5. Exit\n\n");
    while (true)
    {
        printf("Enter choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            enQueue();
            break;
        case 3:
            deQueue();
            break;
        case 4:
            size();
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Invalid Choice\n");
        }
        printf("\n");
    }
}

SPARSE ADD
#include <stdio.h>

int main()
{
    int rows1, cols1;

    // User input for the dimensions of the first matrix
    printf("Enter the number of rows for first matrix: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for first matrix: ");
    scanf("%d", &cols1);

    int matrix1[rows1][cols1];

    // User input for the elements of the first matrix
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Array to store triplet representation of the first sparse matrix
    int triplet1[rows1 * cols1][3];
    int k1 = 1; // Index for triplet array for the first matrix

    // Generate triplet representation for the first matrix
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            if (matrix1[i][j] != 0)
            {                                    // Only consider non-zero values
                triplet1[k1][0] = i;             // Row index
                triplet1[k1][1] = j;             // Column index
                triplet1[k1][2] = matrix1[i][j]; // Non-zero value
                k1++;
            }
        }
    }
    // Store dimensions and number of non-zero elements in the triplet
    triplet1[0][0] = rows1;
    triplet1[0][1] = cols1;
    triplet1[0][2] = k1 - 1;

    // Input for the second matrix dimensions
    int rows2, cols2;
    printf("Enter the number of rows for second matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for second matrix: ");
    scanf("%d", &cols2);

    // Check if both matrices have the same dimensions
    if (rows1 != rows2 || cols1 != cols2)
    {
        printf("Matrices must have the same dimensions for addition.\n");
        return 1;
    }

    int matrix2[rows2][cols2];

    // User input for the elements of the second matrix
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Array to store triplet representation of the second sparse matrix
    int triplet2[rows2 * cols2][3];
    int k2 = 1; // Index for triplet array for the second matrix

    // Generate triplet representation for the second matrix
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            if (matrix2[i][j] != 0)
            {                                    // Only consider non-zero values
                triplet2[k2][0] = i;             // Row index
                triplet2[k2][1] = j;             // Column index
                triplet2[k2][2] = matrix2[i][j]; // Non-zero value
                k2++;
            }
        }
    }
    // Store dimensions and number of non-zero elements in the triplet
    triplet2[0][0] = rows2;
    triplet2[0][1] = cols2;
    triplet2[0][2] = k2 - 1;

    // Print triplet representation of the first sparse matrix
    printf("Triplet representation of the 1st sparse matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k1; i++)
    {
        printf("%d\t%d\t%d\n", triplet1[i][0], triplet1[i][1], triplet1[i][2]);
    }

    // Print triplet representation of the second sparse matrix
    printf("Triplet representation of the 2nd sparse matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k2; i++)
    {
        printf("%d\t%d\t%d\n", triplet2[i][0], triplet2[i][1], triplet2[i][2]);
    }

    // Sparse matrix addition
    int triplet3[rows1 * cols1][3];
    int k3 = 1; // Index for the result triplet array
    int i = 1, j = 1;

    // Initialize the result triplet with the dimensions
    triplet3[0][0] = rows1;
    triplet3[0][1] = cols1;

    // Perform addition of the two sparse matrices
    while (i < k1 && j < k2)
    {
        if (triplet1[i][0] == triplet2[j][0] && triplet1[i][1] == triplet2[j][1])
        {
            // Same position in both matrices
            triplet3[k3][0] = triplet1[i][0];
            triplet3[k3][1] = triplet1[i][1];
            triplet3[k3][2] = triplet1[i][2] + triplet2[j][2];
            i++;
            j++;
            k3++;
        }
        else if (triplet1[i][0] < triplet2[j][0] ||(triplet1[i][0] == triplet2[j][0] && triplet1[i][1] < triplet2[j][1]))
        {
            // Only in the first matrix
            triplet3[k3][0] = triplet1[i][0];
            triplet3[k3][1] = triplet1[i][1];
            triplet3[k3][2] = triplet1[i][2];
            i++;
            k3++;
        }
        else
        {
            // Only in the second matrix
            triplet3[k3][0] = triplet2[j][0];
            triplet3[k3][1] = triplet2[j][1];
            triplet3[k3][2] = triplet2[j][2];
            j++;
            k3++;
        }
    }

    // Add remaining elements from triplet1
    while (i < k1)
    {
        triplet3[k3][0] = triplet1[i][0];
        triplet3[k3][1] = triplet1[i][1];
        triplet3[k3][2] = triplet1[i][2];
        i++;
        k3++;
    }

    // Add remaining elements from triplet2
    while (j < k2)
    {
        triplet3[k3][0] = triplet2[j][0];
        triplet3[k3][1] = triplet2[j][1];
        triplet3[k3][2] = triplet2[j][2];
        j++;
        k3++;
    }

    // Update the number of non-zero elements in the result triplet
    triplet3[0][2] = k3 - 1;

    // Print the triplet representation of the resulting sparse matrix
    printf("Triplet representation of the resulting sparse matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k3; i++)
    {
        printf("%d\t%d\t%d\n", triplet3[i][0], triplet3[i][1], triplet3[i][2]);
    }

    return 0;
}









