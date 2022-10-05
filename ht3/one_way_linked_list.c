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
    struct one_way_linked_elem last_elem;
    struct one_way_linked_elem *first_elem;
};

//Функция добавления элемента в односвязный список
//Вход: односвязный список + значение новго элемента
struct one_way_linked_list append(struct one_way_linked_list list, int number) {
    struct one_way_linked_elem new_elem; // Создаем новый элемент
    new_elem.value = number; // Присваеваем новому элементу значение
    if (list.last_elem.next_elem == 0x100000000) {
        list.first_elem = &new_elem;
    }
    list.last_elem.next_elem = &new_elem; // Указываем предыдущему элементу на новый
    list.last_elem = new_elem;
    return list;
};

int main() {
    struct one_way_linked_list new_list;
    for (int i = 0; i < 10; i++) {
        new_list = append(new_list, i);

    }
    printf("%i", new_list.last_elem.value);

    return 0;
}