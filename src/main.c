#include <stdio.h>

#include "List.h"

int main ()
{
    List_t *list = List();
    printf("%ld\n", list->GetSize(list));
    list->Destroy(list);

    return 0;
}
