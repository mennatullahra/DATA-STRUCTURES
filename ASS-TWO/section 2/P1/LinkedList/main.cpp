#include <iostream>

using namespace std;

template<class type>
class myList {
    int count = 0;

    class node;

public:

    class iterator {
        // your code for the iterator class here
    private:
        node *current_node;
    public:
        iterator() { current_node = root; }

        iterator(node *pointer_node) { current_node = pointer_node; }

        void operator++() {
            if (current_node)
                current_node = current_node->next;
        }

        iterator operator++(int) {
            iterator iterator = *this;
            ++*this;
            return iterator;
        }

        void operator--() {
            iterator iterator = *this;
            --*this;
        }

        type &operator*() {
            return current_node->data;
        }

        iterator &operator=(node *pointer_node) {
            this->current_node = pointer_node;
            return *this;
        }

        bool operator==(const iterator &iterator) {
            return current_node == iterator.current_node;
        }

        bool operator!=(const iterator &iterator) {
            return current_node != iterator.current_node;
        }

        bool operator<=(const iterator &iterator) {
            return current_node <= iterator.current_node;
        }

        bool operator>(const iterator &iterator) {
            return current_node > iterator.current_node;
        }
    };

private:
    //node class//
    class node {
        type data;
        node *next;

        friend class myList;
    };

    node *create_node(type data) {
        node *new_node = new node;
        new_node->data = data;
        new_node->next = nullptr;
        return new_node;
    }

    node *&getRoot() {
        return root;
    }

    static node *root;
    // your code for the list class here
public:
    myList() {
        root = nullptr;
        count = 0;
    }

    myList(type value, int initial_size) {
        root = nullptr;
        for (int i = 0; i < initial_size; ++i) {
            affix(value);
        }
    }

    ~myList() {
        if (!(root == nullptr)) {
            for (myList<type>::iterator i = begin(); i != end(); i++) {
                *i = NULL;
            }
        }
    }

    int size() {
        return count;
    }

    void insert(type value, iterator position) {
        node *temp, *s, *ptr;
        temp = create_node(value);
        s = root;
        while (s != NULL) {
            s = s->next;
            count++;
        }
        if (position == begin()++) {
            if (root == NULL) {
                root = temp;
                root->next = NULL;
            } else {
                ptr = root;
                root = temp;
                root->next = ptr;
            }
        } else if (position != begin() && position != end()) {
            s = root;
            for (myList<type>::iterator i = begin()++; i != position; i++) {
                ptr = s;
                s = s->next;
            }
            ptr->next = temp;
            temp->next = s;
        }
    }

    iterator erase(iterator position) {
        node *tmp, *q;
        if (position == begin()) {
            tmp = root;
            root = root->next;
            cout << "Element Deleted" << endl;
            free(tmp);
            return position;
        }
        q = root;
        while (position != end()) {
            /*Element deleted in between*/
            if (q->next->data == *position) {
                tmp = q->next;
                q->next = tmp->next;
                cout << "Element Deleted" << endl;
                free(tmp);
                return position;
            }
            q = q->next;
        }
        /*last element deleted*/
        if (position == end()) {
            tmp = q->next;
            free(tmp);
            q->next = NULL;
            cout << "Element Deleted" << endl;
            return position;
        }
        cout << "Element " << *position << " not found" << endl;
    }

    myList<type> &operator=(myList<type> another_list) {
        if (another_list.root == NULL) {
            root = NULL;
        } else {
            root = create_node(another_list.root->data);
            node *current = root;
            node *objHead = another_list.root;
            node *currentObj = objHead;
            while (currentObj->next != NULL) {
                current->next = create_node(currentObj->next->data);
                currentObj = currentObj->next;
                current = current->next;
            }
        }
    }

    iterator begin() {
        return iterator(root);
    }

    iterator end() {
        return iterator(nullptr);
    }

    void affix(type data) {
        node *temp = create_node(data);
        if (!getRoot()) {
            getRoot() = temp;
        } else {
            node *start = getRoot();
            while (start->next) {
                start = start->next;
            }

            start->next = temp;
        }
        count++;
    }

    void unfurl() {
        for (myList<type>::iterator i = begin(); i != end(); i++) {
            cout << *i << " ";
        }

    }

    void merge(myList<int> l1, myList<int> l2) {
        myList<int>::iterator dup = l1.begin();
        while (dup != l1.end()) {
            myList<int>::iterator dup2 = dup;
            dup2++;
            while (dup2 != l1.end()) {
                if (*dup == *dup2) {
                    l1.erase(dup2);
                }
                dup2++;
            }
            dup++;
        }
        bool fine = true, check = false;
        myList<int>::iterator jat = l2.begin();
        while (jat != l2.end()) {
            myList<int>::iterator mnt = NULL;
            myList<int>::iterator pot = l1.begin();
            while (pot != l1.end()) {
                if (*pot == *dup) {
                    fine = false;
                    break;
                } else if (*pot > *dup && !check) {
                    mnt = pot;
                    check = true;
                }
                pot++;
            }
            if (fine) {
                if (mnt == NULL) {
                    mnt = l1.end();
                }
                l1.insert(*jat, mnt);
            }
            jat++;
        }
    }

};

template<typename type>
typename myList<type>::node *myList<type>::root = nullptr;

int main() {
    myList<int> LIST;
    LIST.affix(1);
    LIST.affix(2);
    LIST.affix(3);
    LIST.affix(4);
    myList<int>::iterator i=LIST.begin();
    i++;
    LIST.erase(i);
    myList<int> list = LIST;
    list.affix(7);
    list.affix(8);
    LIST.unfurl();
    list.merge(LIST, list);

    return 0;
}
