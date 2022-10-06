#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Элемент односвязного списка
struct one_way_linked_elem {
    int value;
    struct one_way_linked_elem *next_elem;
};
// Односвязный список
// В нем храним первую переменную и последнюю
// (Лень делать функцию нахождения последнего элемента)
struct one_way_linked_list {
    char isnt_null;
    struct one_way_linked_elem *last_elem;
    struct one_way_linked_elem *first_elem;
};

// Функция поиска элемента по номеру и первому элементу
// На вход берет односвязный список и нужный элемент (нумерация с 0)
// На выход дает заданный элемент ИЛИ последний элемент, если position>=len(list)
struct one_way_linked_elem element(struct one_way_linked_list list, int position) {
    struct one_way_linked_elem *current_elem;
    current_elem = list.first_elem;
    for (int i = 0; i < position; i++) {
        if (current_elem->next_elem != 0x100000000) {
            current_elem = current_elem->next_elem;

        }
    }
    return *current_elem;
}

//Функция добавления элемента в односвязный список
//Вход: односвязный список + значение новго элемента
struct one_way_linked_list append(struct one_way_linked_list list, int number) {
    struct one_way_linked_elem new_elem; // Создаем новый элемент
    new_elem.value = number; // Присваеваем новому элементу значение
    if (list.isnt_null != '1') {
        list.first_elem = &new_elem;
        printf("%i\n", list.first_elem->value);
        list.isnt_null = '1';

    }
    (*list.last_elem).next_elem = &new_elem; // Указываем предыдущему элементу на новый
    list.last_elem = &new_elem;
    return list;
};

int main() {
    struct one_way_linked_list new_list;
    for (int i = 0; i < 10; i++) {
        new_list = append(new_list, i);

    }
    printf("%i\n", (*new_list.first_elem).value);
    printf("%i\n", 1);
    printf("%i\n", element(new_list, 4).value);
    return 0;
}