/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_l_a_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:14:35 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/22 23:31:36 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"


static struct { char strVal[21]; int intVal; } tuple[10];
static int tupleCount = 0;

void listTuples(void)
{
    printf("==========\nTuple count is %d\n", tupleCount);
    for (int i = 0; i < tupleCount; ++i)
        printf("   [%s] -> %d\n", tuple[i].strVal, tuple[i].intVal);
    puts("==========");
}

void addTuple(char *str, int val)
{
    printf("Adding '%s', mapped to %d\n", str, val);
    strcpy(tuple[tupleCount].strVal, str);
    tuple[tupleCount++].intVal = val;
}

void deleteTuple(char *str)
{
    int index = 0;
    while (index < tupleCount) {
        if (strcmp(str, tuple[index].strVal) == 0) break;
        ++index;
    }
    if (index == tupleCount) return;

    printf("Deleting '%s', mapped to %d\n", str, tuple[index].intVal);
    if (index != tupleCount - 1) {
        strcpy(tuple[index].strVal, tuple[tupleCount - 1].strVal);
        tuple[index].intVal = tuple[tupleCount - 1].intVal;
    }
    --tupleCount;
}

int main(void) {
    listTuples();

    addTuple("gato", 53);
    addTuple("pavao", 73);
    addTuple("camelo", 30);
    addTuple("cavalo", 42);
    listTuples();

    deleteTuple("cavalo");
    listTuples();

    return 0;
}