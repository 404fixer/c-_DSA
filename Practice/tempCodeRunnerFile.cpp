#include <ctype.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int precedence(char);
void init(node **);
int empty(node *);
int pop(node **);
void push(node **, int);
int top(node *);  // value of the top element
void infix_to_prefix(char infix[], char prefix[]);
void infix_to_postfix(char infix[], char postfix[]);
void eval_postfix(char postfix[]);
int evaluate(char x, int op1, int op2);

int main() {
    char infix[30], postfix[30], prefix[30];
    // clrscr();
    // printf("\nEnter an infix expression : ");
    gets(infix);
    infix_to_postfix(infix, postfix);
    infix_to_prefix(infix, prefix);
    printf("\nPostfix : %s\nprefix: %s  ", postfix, prefix);
    printf("\nPostfix evaluation : ");
    eval_postfix(postfix);
    return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    node *head;
    char x;
    int i, j;  // i-index for infix[],j-index for postfix
    char token;
    init(&head);
    j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];
        if (isalnum(token))
            postfix[j++] = token;
        else if (token == '(')
            push(&head, '(');
        else if (token == ')')
            while ((x = pop(&head)) != '(') postfix[j++] = x;
        else {
            while (precedence(token) <= precedence(top(head)) && !empty(head)) {
                x = pop(&head);
                postfix[j++] = x;
            }
            push(&head, token);
        }
    }
    while (!empty(head)) {
        x = pop(&head);
        postfix[j++] = x;
    }
    postfix[j] = '\0';
}
void eval_postfix(char postfix[]) {
    node *head;
    char x;
    int op1, op2, val, i;
    init(&head);
    for (i = 0; postfix[i] != '\0'; i++) {
        x = postfix[i];
        if (isalpha(x)) {
            printf("\nEnter the value of %c : ", x);
            scanf("%d", &val);
            push(&head, val);
        } else {  // pop two operands and evaluate
            op2 = pop(&head);
            op1 = pop(&head);
            val = evaluate(x, op1, op2);
            push(&head, val);
        }
    }
    val = pop(&head);
    printf("\nvalue of expression = %d", val);
}

int evaluate(char x, int op1, int op2) {
    if (x == '+') return (op1 + op2);
    if (x == '-') return (op1 - op2);
    if (x == '*') return (op1 * op2);
    if (x == '/') return (op1 / op2);
    if (x == '%') return (op1 % op2);
}

int precedence(char x) {
    if (x == '(') return (0);
    if (x == '+' || x == '-') return (1);
    if (x == '*' || x == '/' || x == '%') return (2);
    return (3);
}

void init(node **head) { *head = NULL; }

int empty(node *head) {
    if (head == NULL) return (1);
    return (0);
}

void push(node **head, int x) {
    node *p;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = *head;
    *head = p;
}

int pop(node **head) {
    int x;
    node *p;
    p = *head;
    *head = p->next;
    x = p->data;
    free(p);
    return (x);
}

int top(node *head) { return (head->data); }

/*

OUTPUT:

Enter an infix expression : a+b*c

Postfix : abc*+
prefix: +a*bc
Postfix evaluation :
Enter the value of a : 2

Enter the value of b : 3

Enter the value of c : 4

value of expression = 14

*/