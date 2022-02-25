#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void printfunc(Item a)
{
    printf("%d->", *(int *)a);
}

int compfunc(Item a, Item b)
{
    return *(int *)a == *(int *)b ? 1 : 0;
}

int compgreaterfunc(Item a, Item b)
{
    return *(int *)a > *(int *)b ? 1 : 0;
}

void freefunc(Item a)
{
    return;
}

int main(int argc, char *argv[])
{
    List *mylist = Init_List();
    printf("List initialized\n");
    printf("List %s empty\n", Is_Empty_List(mylist) ? "is" : "is not");
    int a = 69, b = 420, c = 360, d = 1337, e = 777, f = 10;
    printf("Add element %i at beginning\n", a);
    mylist = Add_Beginning_List(mylist, (Item)(&a));
    Print_List(mylist, printfunc);
    printf("Add element %i at end\n", b);
    mylist = Add_End_List(mylist, (Item)(&b));
    Print_List(mylist, printfunc);
    printf("Add element %i at index 1\n", e);
    mylist = Add_At_Index_List(mylist, (Item)(&e), 1);
    Print_List(mylist, printfunc);
    printf("Add element %i at beginning\n", f);
    mylist = Add_Beginning_List(mylist, (Item)(&f));
    Print_List(mylist, printfunc);
    printf("Add element %i at end\n", c);
    mylist = Add_End_List(mylist, (Item)(&c));
    Print_List(mylist, printfunc);
    printf("Add element %i at index 3\n", d);
    mylist = Add_At_Index_List(mylist, (Item)(&d), 3);
    Print_List(mylist, printfunc);
    printf("Sorted list:\n");
    mylist = Sort_List(mylist, compgreaterfunc);
    Print_List(mylist, printfunc);
    printf("Delete element at index 4\n");
    mylist = Delete_At_Index_Lista(mylist, 4);
    Print_List(mylist, printfunc);
    printf("Delete element at beginning\n");
    mylist = Delete_Beginning_List(mylist);
    Print_List(mylist, printfunc);
    printf("Delete element at end\n");
    mylist = Delete_End_List(mylist);
    Print_List(mylist, printfunc);
    printf("Get element at beginning: %i\n", *(int *)Get_Beginning_List(mylist));
    printf("Get element at end: %i\n", *(int *)Get_End_List(mylist));
    printf("Get element at index 1: %i\n", *(int *)Get_At_Index_List(mylist, 1));
    Print_List(mylist, printfunc);
    printf("Length of list is: %i\n", Get_Length_List(mylist));
    printf("List %s empty\n", Is_Empty_List(mylist) ? "is" : "is not");

    Free_List(mylist, freefunc);
    return 0;
}