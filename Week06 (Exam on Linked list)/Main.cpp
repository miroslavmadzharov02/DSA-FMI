template <typename T>
struct Node { T data; Node* next; };

template <typename T>
void fillGaps(Node<T> head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node<T>* current = head;

    while (current->next != nullptr)
    {
        if (current->data / 2 != current->next->data)
            current->next = new Node<T>{ current->data / 2, current->next };

        current = current->next;
    }
}

template <typename T>
void keepProducts(Node<T>* head)
{
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return;

    Node<T>* first = head;
    Node<T>* second = first->next;
    Node<T>* third = second->next;

    while (third->next != nullptr)
    {
        if (third->data % first->data != 0 || third->data % second->data != 0)
        {
            Node<T>* nodeToDelete = second->next;
            second->next = third->next;
            delete nodeToDelete;
        }

        first = first->next;
        second = second->next;
        third = third->next;
    }
}

template <typename T>
void mirror(Node<T>* head)
{
    if (head == nullptr)
        return;

    Node<T>* current = head;
    Node<T>* headSecondList = nullptr;
    Node<T>* lastElem = nullptr;

    while (current != nullptr)
    {
        lastElem = current;

        Node<T>* nodeToPush = new Node<T>{ current->data, headSecondList };

        headSecondList = nodeToPush;
        current = current->next;
    }
    lastElem->next = headSecondList;
}

int main()
{
    

    return 0;
}
