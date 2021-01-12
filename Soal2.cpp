#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
  int angka;
  Node *next;
} * head, *tail;

struct Node1
{
  int angka;
  Node1 *next;
} * head1, *tail1;

struct Node2
{
  int angka;
  Node2 *next;
} * head2, *tail2;

Node *createNode(int angka)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->angka = angka;
  newNode->next = NULL;
  return newNode;
}

Node1 *createNode1(int angka)
{
  Node1 *newNode1 = (Node1 *)malloc(sizeof(Node1));
  newNode1->angka = angka;
  newNode1->next = NULL;
  return newNode1;
}

Node2 *createNode2(int angka)
{
  Node2 *newNode2 = (Node2 *)malloc(sizeof(Node2));
  newNode2->angka = angka;
  newNode2->next = NULL;
  return newNode2;
}

void pushTail(int angka)
{
  Node *temp = createNode(angka);
  if (!head)
  {
    head = tail = temp;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

void pushTail1(int angka)
{
  Node1 *temp = createNode1(angka);
  if (!head1)
  {
    head1 = tail1 = temp;
  }
  else
  {
    tail1->next = temp;
    tail1 = temp;
  }
}

void pushTail2(int angka)
{
  Node2 *temp = createNode2(angka);
  if (!head2)
  {
    head2 = tail2 = temp;
  }
  else
  {
    tail2->next = temp;
    tail2 = temp;
  }
}

void printList()
{
  Node *curr = head;

  while (curr)
  {
    printf("%d ", curr->angka);
    curr = curr->next;
  }
  printf("\n");
}

void printList1()
{
  Node1 *curr = head1;

  while (curr)
  {
    printf("%d ", curr->angka);
    curr = curr->next;
  }
  printf("\n");
}

void printList2()
{
  Node2 *curr = head2;

  while (curr)
  {
    printf("%d ", curr->angka);
    curr = curr->next;
  }
  printf("\n");
}

void findMaxMin()
{
  Node2 *curr = head2;
  Node2 *max = curr;
  Node2 *min = curr;
  while (curr)
  {
    if (curr->angka <= min->angka)
    {
      min = curr;
    }
    if (curr->angka >= max->angka)
    {
      max = curr;
    }
    curr = curr->next;
  }
  printf("%d\n", max->angka - min->angka);
}

int main()
{
  pushTail(3);
  pushTail(5);
  pushTail(7);
  printList();
  pushTail1(4);
  pushTail1(6);
  pushTail1(8);
  printList1();

  Node *curr = head;
  Node1 *curr1 = head1;
  while (curr && curr1)
  {
    if (curr->angka <= curr1->angka)
    {
      pushTail2(curr->angka);
      curr = curr->next;
    }
    else
    {
      pushTail2(curr1->angka);
      curr1 = curr1->next;
    }
  }

  while (curr)
  {
    pushTail2(curr->angka);
    curr = curr->next;
  }
  while (curr1)
  {
    pushTail2(curr1->angka);
    curr1 = curr1->next;
  }

  printList2();

  printf("The Difference between Max and Min value is ");

  findMaxMin();
  return 0;
}