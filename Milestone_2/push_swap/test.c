#include "includes/push_swap.h"

// Вспомогательная функция: создание элемента стека
t_stack *stack_new(int value)
{
    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = value;
    node->index = -1;
    node->next = NULL;
    return node;
}

// Вспомогательная функция: добавление в начало стека
void stack_add_front(t_stack **stack, t_stack *new)
{
    if (!new)
        return;
    new->next = *stack;
    *stack = new;
}

// Вывод стека
void print_stack(t_stack *stack, char name)
{
    printf("Stack %c: ", name);
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

// Освобождение стека
void stack_clear(t_stack **stack)
{
    t_stack *tmp;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

int main()
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    // Инициализация стека A: 3 -> 1 -> 2
    stack_add_front(&stack_a, stack_new(2));
    stack_add_front(&stack_a, stack_new(1));
    stack_add_front(&stack_a, stack_new(3));
    stack_add_front(&stack_a, stack_new(8));

    // Инициализация стека B: 5 -> 4
    stack_add_front(&stack_b, stack_new(4));
    stack_add_front(&stack_b, stack_new(5));
    stack_add_front(&stack_b, stack_new(7));
    stack_add_front(&stack_b, stack_new(6));


//------------------------------------- SA  SB -------------------------------------//
    printf("Before operations:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    // Тест sa
    sa(&stack_a);
    printf("\nAfter sa:\n");
    print_stack(stack_a, 'A');

    // Тест sb
    sb(&stack_b);
    printf("\nAfter sb:\n");
    print_stack(stack_b, 'B');

   

//------------------------------------- PA  PB -------------------------------------//

    printf("\nBefore operations:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    // Тест pa
    pa(&stack_a, &stack_b);
    printf("\nAfter pa:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    // Тест pb
    pb(&stack_a, &stack_b);
    printf("\nAfter pb:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

//------------------------------------- RA  RB RR -------------------------------------//

    printf("\nBefore operations:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    // Тест ra
    ra(&stack_a);
    printf("\nAfter ra:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    // Тест rb
    rb(&stack_b);
    printf("\nAfter rb:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    // Тест rr
    rr(&stack_a, &stack_b);
    printf("\nAfter rr:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    //------------------------------------- RRA  RRB RRR -------------------------------------//

    printf("\nBefore operations:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    // Тест rra
    rra(&stack_a);
    printf("\nAfter rra:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    // Тест rrb
    rrb(&stack_b);
    printf("\nAfter rrb:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    // Тест rrr
    rrr(&stack_a, &stack_b);
    printf("\nAfter rrr:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

//------------------------------------- SS -------------------------------------//
    
    // Сброс стеков
    stack_clear(&stack_a);
    stack_clear(&stack_b);


    // Новые данные для теста ss
    stack_add_front(&stack_a, stack_new(20));
    stack_add_front(&stack_a, stack_new(10));
    stack_add_front(&stack_b, stack_new(40));
    stack_add_front(&stack_b, stack_new(30));

    printf("\nBefore ss:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');

    ss(&stack_a, &stack_b);

    printf("\nAfter ss:\n");
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');


//------------------------------------- CLEAR -------------------------------------//

    // Очистка памяти
    stack_clear(&stack_a);
    stack_clear(&stack_b);

    return 0;
}

