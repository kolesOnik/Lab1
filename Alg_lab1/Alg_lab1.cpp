#include <iostream>

using namespace std;

struct Page { //струтура данных
    int number;
    Page* next;
};

void menu() { //функция меню
    cout << "Выберите нужное вам действие: " << endl << endl
        << "1. добавление в конец списка" << endl
        << "2. добавление в начало списка" << endl
        << "3. удаление последнего элемента" << endl
        << "4. удаление первого элемента" << endl
        << "5. добавление элемента по индексу" << endl
        << "6. получение элемента по индексу" << endl
        << "7. удаление элемента по индексу" << endl
        << "8. получение размера списка" << endl
        << "9. удаление всех элементов списка" << endl
        << "10. замена элемента по индексу на передаваемый элемент" << endl
        << "11. проверка на пустоту списка" << endl
        << "12. меняет порядок элементов в списке на обратный" << endl
        << "13. вставка другого списка в список, начиная с индекса" << endl
        << "14. вставка другого списка в конец" << endl
        << "15. вставка другого списка в начало" << endl
        << "16. проверка на содержание другого списка в списке" << endl
        << "17. поиск первого вхождения другого списка в список" << endl
        << "18. поиск последнего вхождения другого списка в список" << endl
        << "19. обмен двух элементов списка по индексам" << endl
        << "20. выход" << endl << endl;
}

void print(Page* &head) { //вывод списка
    Page* current = head;

    cout << "Список:" << endl;

    while (current){
        cout << current->number << " ";
        current = current->next;
    }
}

void add_last(Page* &head, Page* &last, int number) { //1.добавление в конец списка
    if (head == NULL) {
        last = new Page;
        last->number = number;
        last->next = NULL;
        head = last; 
    }
    else {
        last->next = new Page;
        last = last->next;
        last->number = number;
        last->next = NULL;
    }
}

void add_first(Page* &head) { //2. добавление в начало списка
    int number;
    cout << endl << "Введите элемент: " << endl;
    cin >> number;
    Page *add = new Page;
    add->number = number;
    add->next = head;
    head = add;
}

void delete_last(Page* &head, Page* &last) { //3. удаление последнего элемента
    if (head != NULL) {
        Page* current = head;
        while (current->next != NULL && current->next != last) {
            current = current->next; // находим предпоследний элемент
        }
        if (last == head) {
            head = head->next; // список пуст
            delete current;
        }
        else {
            delete last;
            last = current; // новый последний элемент
            last->next = NULL;
        }
    }
}

void delete_first(Page* &head) { //4. удаление первого элемента
    if (head != NULL) {
        Page* current = head;
        head = head->next;
        delete current;
    }
}

void add_before(Page* &head, Page* &last) { //5. добавление элемента по индексу
    int index, number;
    cout << endl << "Введите номер элемента, перед которым нужно добавить элемент: ";
    cin >> index;
    if (index == 1) {
        add_first(head);
    }
    else if (index < 0) cout << endl << "Такого элемента нет" << endl;
    else {
        cout << endl << "Введите элемент: " << endl;
        cin >> number;
        Page* current = head;
        int counter = 1;
        while (current != NULL && counter != index - 1) {
            counter++;
            current = current->next;
        }
        Page* add = new Page;
        add->number = number;
        add->next = current->next;
        current->next = add;
    }
}

int find_by_index(Page* &head, int index) { //6. получение элемента по индексу
    int counter = 1;
    Page* current = head;
    if (index > 0) {
        while (current != NULL && counter != index) {
            counter++;
            current = current->next;
        }
        if (current == NULL) {
            cout << endl << "Такого элемента нет" << endl;
            return -1;
        } 
        else {
            cout << endl << "Ваш элемент: " << current->number << endl;
            return current->number;
        }
    }
    else {
        cout << endl << "Такого элемента нет" << endl;
        return -1;
    }
}

void delete_by_index(Page* &head, Page* &last) { //7. удаление элемента по индексу
    int index, counter = 1;
    cout << endl << "Введите номер элемента: ";
    cin >> index;
    Page* current = head;
    if (index > 0) {
        while (current != NULL && counter != index - 1) {
            counter++;
            current = current->next;
        }
        if (current->next == NULL) {
            cout << endl << "Такого элемента нет" << endl;
        }
        else {
            if (current->next == last) {
                last = current;
            }
            Page* tmp = current->next;
            current->next = (current->next)->next;
            delete tmp;
        }
    }
    else {
        cout << endl << "Такого элемента нет" << endl;
    }
}

int length(Page* &head) { //8. получение размера списка
    int length = 0;
    Page* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void clear(Page* &head) { //9. удаление всех элементов списка
    if (head != NULL) {
        Page* current = head;
        Page* tmp;
        while (current != NULL)
        {
            tmp = current;
            current = current->next;
            delete tmp;
        }
        head = NULL;
    }
}

void change_by_index(Page*& head, int index, int number) { //10. замена элемента по индексу на передаваемый элемент
    int counter = 1;
    Page* current = head;
    if (index > 0) {
        while (current != NULL && counter != index) {
            counter++;
            current = current->next;
        }
        if (current == NULL) {
            cout << endl << "Такого элемента нет" << endl;
        }
        else {
            current->number = number;
        }
    }
    else {
        cout << endl << "Такого элемента нет" << endl;
    }
}

bool empty_check(Page* & head) { //11. проверка на пустоту списка
    Page* current = head;
    if (current == NULL) {
        cout << endl << "Список пуст" << endl;
        return true;
    }
    else {
        cout << endl << "В списке есть элементы" << endl;
        return false;
    }
}

void reverse(Page* &head, Page* &last) { //12. меняет порядок элементов в списке на обратный
    int element;
    Page* current = head;
    for (int i = 0; i < length(head); i++) {
        current = head;
        element = current->number;
        for (int j = 0; j < length(head) - i - 1; j++) {
            current->number = current->next->number;
            current = current->next;
        }
        current->number = element;
        if (i == length(head) - 1) {
            last = current;
        }
    }
}

void InsertListByIndex(Page*& head) { //13. вставка другого списка в список, начиная с индекса
    int index, count_numbers;
    int number;
    cout << "Введите количество элементов\n";
    cin >> count_numbers;
    cout << "Введите с какого места вставлять\n";
    cin >> index;
    if (index < 0) cout << endl << "Такого элемента нет" << endl;
    else {
        for (int i = 0; i < count_numbers; i++)
        {
            cout << endl << "Введите элемент: " << endl;
            cin >> number;
            Page* current = head;
            int counter = 1;
            while (current != NULL && counter != index) {
                counter++;
                current = current->next;
            }
            Page* add = new Page;
            add->number = number;
            add->next = current->next;
            current->next = add;
            index++;
        }
    }
}

void InsertListEnd(Page*& head, Page*& last) { //14. вставка другого списка в конец
    int index;
    int number;
    cout << "Введите количество элементов\n";
    cin >> index;
    for (int i = 0; i < index; i++)
    {
        cout << endl << "Введите элемент: " << endl;
        cin >> number;
        add_last(head, last, number);
    }
}

void InsertListBeginnig(Page* &head) { //15. вставка другого списка в начало
    int index;
    int number;
    cout << "Введите количество элементов\n";
    cin >> index;
    add_first(head);
    for (int i = 1; i < index; i++)
    {
        cout << endl << "Введите элемент: " << endl;
        cin >> number;
        Page* current = head;
        int counter = 1;
        while (current != NULL && counter != i) {
            counter++;
            current = current->next;
        }
        Page* add = new Page;
        add->number = number;
        add->next = current->next;
        current->next = add;
    }
}

bool anotherList(Page* &head, Page* &secondhead) { //16. проверка на содержание другого списка в списке
    bool comparison = false;
    bool empty = empty_check(head);
    if (!empty) {
        Page* current = head;
        while (current != NULL && current->next != NULL) {
            comparison = false;
            if (current->number == secondhead->number) {
                comparison = true;
                Page* ListCur = secondhead;
                while (current->next != NULL && ListCur->next != NULL && comparison) {
                    current = current->next;
                    ListCur = ListCur->next;
                    if (ListCur->number != current->number) {
                        comparison = false;
                    }
                }
            }
            current = current->next;
        }
    }
    if (!empty) {
        return comparison;
    }
    else return 0;
}

int first_in_list(Page*& head, Page*& secondhead) { //17. поиск первого вхождения другого списка в список
    bool comparise = false;
    int FirstIndex = 0;
    int CurrIndex = 0;
    bool empty = empty_check(head);
    bool inList = anotherList(head, secondhead);
    if ((!empty) && (inList)) {
        Page* current = head;
        while (current != NULL && current->next != NULL) {
            comparise = false;
            if (current->number == secondhead->number) {
                comparise = true;
                Page* ListCurrent = secondhead;
                while (current->next != nullptr && ListCurrent->next != nullptr && comparise)
                {
                    current = current->next;
                    ListCurrent = ListCurrent->next;
                    if (ListCurrent->number != current->number)
                    {
                        comparise = false;
                    }
                }
            }
            if (comparise)
            {
                FirstIndex = CurrIndex;
            }
            CurrIndex++;
            current = current->next;
        }
    }
    if (!empty) {
        return FirstIndex + 1;
    }
    else return -1;
}

int last_in_list(Page*& head, Page*& secondhead) { //18. поиск последнего вхождения другого списка в список
    bool comparise = false;
    int LastIndex = 0;
    int CurrIndex = 0;
    bool empty = empty_check(head);
    bool inList = anotherList(head, secondhead);
    if ((!empty) && (inList)) {
        Page* current = head;
        while (current != NULL && current->next != NULL) {
            comparise = false;
            if (current->number == secondhead->number) {
                comparise = true;
                Page* ListCurrent = secondhead;
                while (current->next != nullptr && ListCurrent->next != nullptr && comparise)
                {
                    current = current->next;
                    CurrIndex++;
                    ListCurrent = ListCurrent->next;
                    if (ListCurrent->number != current->number)
                    {
                        comparise = false;
                    }
                }
            }
            if (comparise)
            {
                LastIndex = CurrIndex;
            }
            CurrIndex++;
            current = current->next;
        }
    }
    if (!empty) {
        return LastIndex + 1;
    }
    else return -1;
}

void Swap(Page* &head) { //19. обмен двух элементов списка по индексам
    if (empty_check(head)) return;
    int first, first_num;
    int second, second_num;
    int temp_num;
    cout << "Введите индекс первого элемента \n";
    cin >> first;
    cout << "Введите индекс второго элемента \n";
    cin >> second;
    first_num = find_by_index(head, first);
    temp_num = first_num;
    second_num = find_by_index(head, second);
    change_by_index(head, first, second_num);
    change_by_index(head, second, temp_num);
}

int main()
{
    setlocale(LC_ALL, "ru");

    int user_choice, index, number, last_index, first_index;
    Page *head = NULL;
    Page *last = head;

    Page* secondhead = NULL;
    Page* secondlast = secondhead;

    //заполненим второй список, который будем искать в первом
    add_last(secondhead, secondlast, 5);
    add_last(secondhead, secondlast, 2);
    add_last(secondhead, secondlast, 7);

    while (true) {
        menu();
        print(head);
        cout << endl << endl;
        cin >> user_choice;
        switch (user_choice) {
        case 1:
            cout << endl << "Введите элемент: " << endl;
            cin >> number;
            add_last(head, last, number);
            break;
        case 2:
            add_first(head);
            break;
        case 3:
            delete_last(head, last);
            break;
        case 4:
            delete_first(head);
            break;
        case 5:
            add_before(head, last);
            break;
        case 6:
            cout << endl << "Введите номер искомого элемента: ";
            cin >> index;
            find_by_index(head, index);
            break;
        case 7:
            delete_by_index(head, last);
            break;
        case 8:
            cout << endl << "Длина списка: " << length(head) << endl;
            break;
        case 9:
            clear(head);
            cout << "Список очищен" << endl;
            break;
        case 10:
            cout << endl << "Введите номер искомого элемента: ";
            cin >> index;
            cout << endl << "Введите новое значение:  " << endl;
            cin >> number;
            change_by_index(head, index, number);
            break;
        case 11:
            empty_check(head);
            break;
        case 12:
            reverse(head, last);
            break;
        case 13:
            InsertListByIndex(head);
            break;
        case 14:
            InsertListEnd(head, last);
            break;
        case 15:
            InsertListBeginnig(head);
            break;
        case 16:
            if (anotherList(head, secondhead)) cout << "Вложеный список есть" << endl;
            else cout << "Вложеного списка нет" << endl;
            break;
        case 17:
            first_index = first_in_list(head, secondhead);
            if (first_index > 0) cout << "Первое вхождение на элементе номер " << first_index << endl;
            else cout << "Вхождений нет" << endl;
            break;
        case 18:
            last_index = last_in_list(head, secondhead);
            if (last_index > 0) cout << "Последнее вхождение на элементе номер " << last_index << endl;
            else cout << "Вхождений нет" << endl;
            break;
        case 19:
            Swap(head);
            break;
        case 20:
            exit(false);
            break;
        default:
            cout << "Вы ввели несуществующий пункт, попробуйте еще раз." << endl << endl;
            break;
        }
    }
}
