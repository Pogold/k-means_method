
template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_back();//удаление последнего  элемента  вектора
    void push_back(T data); //добавление элемента в конец вектора
    int GetSize() { return Size; }; //нахождение кол-ва элементов  в векторе
    T& operator[] (const int index );//поиск элемента
    bool operator == (List<T> a);//сравнение векторов
    bool operator != (List<T> a);

private:

    template<typename T> //создание шаблоного класса

    class Node // класс узла
    {
    public:
        Node *pNext;//указатель на следующий узел
        T data; //значение узла

        Node(T data = T(), Node* pNext = nullptr) // конструктор ноды присваение значения и адреса
        {
            this->data = data;
            this->pNext = pNext;
        };

    };

    int Size;
    Node<T> *head; //голова списка первый элемент
};

template<typename T>
List<T>::List() //конструктор списка
{
    Size = 0;
    head = nullptr;
}

template<typename T>//деструктор списка
List<T>::~List()
{
}

template<typename T>
void List<T>::pop_back() //удаление последнего элемента
{
    Node<T>* previous = this->head; //временный указатель

    for (int i = 0; i < (Size-1) - 1; i++)// находим адрес предыдущего элемента от которого хотим заменить
    {
        previous = previous->pNext;
    }
    Node<T>* toDelete = previous->pNext;
    previous->pNext = toDelete->pNext;
    delete toDelete;
    Size--;
}

template<typename T>
void List<T>::push_back(T data) //добавление элемента в конец списка
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;
        while(current->pNext!=nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
 T&  List<T>::operator[](const int index ) //поиск элемента
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
bool List<T>::operator==(List<T> a)
 {
    if (this->GetSize() != a.GetSize())
        return false;

    Node<T>* cur1 = this->head;
    Node<T>* cur2 = a.head;
    while (cur1 != nullptr)
    {
        if (cur1 != cur2)
        {
            return false;
        }
        cur1 = cur1->pNext;
        cur2 = cur2->pNext;
    }
     return true;
 }

template<typename T>
bool List<T>::operator!=(List<T> a)
{  if (this->GetSize() != a.GetSize())
        return true;

Node<T>* cur1 = this->head;
Node<T>* cur2 = a.head;
while (cur1 != nullptr)
{
    if (cur1 != cur2)
    {
        return true;
    }
    cur1 = cur1->pNext;
    cur2 = cur2->pNext;
}
return false;
}

