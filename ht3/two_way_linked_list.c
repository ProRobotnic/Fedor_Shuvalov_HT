#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Элемент односвязного списка
struct two_ways_linked_elem {
    int value;
    struct two_ways_linked_elem *next_elem;
    struct two_ways_linked_elem *previous_elem;
};
// Односвязный список
// В нем храним первую переменную и последнюю
// (Лень делать функцию нахождения последнего элемента)
struct two_ways_linked_list {
    char isnt_null;
    struct two_ways_linked_elem *last_elem;
    struct two_ways_linked_elem *first_elem;
};



//Функция добавления элемента в односвязный список
//Вход: односвязный список + значение новго элемента


struct two_ways_linked_list append(struct two_ways_linked_list list, int number) {
    struct two_ways_linked_elem *new_elem = (struct two_way_linked_elem *) malloc(
            sizeof(struct two_ways_linked_elem)); // Создаем новый элемент
    new_elem->value = number; // Присваеваем новому элементу значение
    if (list.isnt_null != 1) {
        list.first_elem = new_elem;
        list.isnt_null = 1;
        list.last_elem = new_elem;
    } else {
        list.last_elem->next_elem = new_elem; // Указываем предыдущему элементу на новый
        new_elem->previous_elem = list.last_elem;
        list.last_elem = new_elem;

    }
    return list;
};

int main() {
    struct two_ways_linked_list new_list;
    new_list.isnt_null = 0;
    for (int i = 0; i < 10; i++) {
        new_list = append(new_list, i);

    }
    printf("%i", new_list.last_elem->value);

    return 0;
}