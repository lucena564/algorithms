#include <iostream>
#include <map>
#include <string>

using namespace std;

class Node {
public:
    Node* prev;
    int label;
    Node* next;
    bool body_removed;

    Node(int label) {
        this->prev = nullptr;
        this->label = label;
        this->next = nullptr;
        this->body_removed = false;
    }

    Node* getPrev() {
        return this->prev;
    }

    void setPrev(Node* prev) {
        this->prev = prev;
    }

    int getLabel() {
        return this->label;
    }

    void setLabel(int label) {
        this->label = label;
    }

    Node* getNext() {
        return this->next;
    }

    void setNext(Node* next) {
        this->next = next;
    }
};


class DoubleLinkedList {
public:
    Node* first;
    int len_list;
    int size;

    DoubleLinkedList(int size) {
        this->first = nullptr;
        this->len_list = 0;
        this->size = size;
    }

    bool empty() {
        return this->len_list == 0;
    }

    int length() {
        return this->len_list;
    }

    void clear() {
        this->first = nullptr;
        this->len_list = 0;
    }

    void push(int label) {
        Node* node = new Node(label);

        if (this->empty()) {
            this->first = node;
        }
        else {
            if (label < this->first->getLabel()) {
                node->setNext(this->first);
                this->first->setPrev(node);
                this->first = node;
            }
            else {
                Node* aux1 = this->first;
                Node* aux2 = this->first->getNext();
                bool flag_insert = false;
                while (aux2 != nullptr) {
                    if (label < aux2->getLabel()) {
                        node->setPrev(aux1);
                        node->setNext(aux1->getNext());
                        aux1->setNext(node);
                        aux2->setPrev(node);
                        flag_insert = true;
                        break;
                    }
                    aux1 = aux1->getNext();
                    aux2 = aux2->getNext();
                }
                if (!flag_insert) {
                    aux1->setNext(node);
                    node->setPrev(aux1);
                }
            }
        }
        this->len_list += 1;
    }

    void pop(int label) {
        if (!this->empty()) {
            bool flag_remove = false;

            // Remove from a list with only 1 element
            if (this->first->getNext() == nullptr && this->first->getLabel() == label) {
                delete this->first;
                this->first = nullptr;
                flag_remove = true;
            }

            // Remove the first node from the list
            else if (this->first->getLabel() == label) {
                Node* auxNode = this->first;
                this->first = this->first->getNext();
                if (this->first) {
                    this->first->setPrev(nullptr);
                }
                delete auxNode;
                flag_remove = true;
            }

            // Remove from the middle or end of the list
            else {
                Node* aux1 = this->first;
                Node* aux2 = this->first->getNext();
                while (aux2 != nullptr) {
                    if (aux2->getLabel() == label) {
                        aux1->setNext(aux2->getNext());
                        if (aux2->getNext() != nullptr) {
                            aux2->getNext()->setPrev(aux1);
                        }
                        delete aux2;
                        flag_remove = true;
                        break;
                    }
                    aux1 = aux1->getNext();
                    aux2 = aux2->getNext();
                }
            }

            if (flag_remove == true) {
                this->len_list--;
            }
            else {
                std::cout << "Label not found\n";
            }
        }
        else {
            std::cout << "Can't pop from an empty list\n";
        }
    }

    std::pair<bool, std::string> remove_body(int label) {
        bool flag = false;
        std::string str_cont;

        if (!this->empty()) {
            if (this->first->getNext() == nullptr || this->first->getLabel() == label) {
                this->first->body_removed = true;
                return std::make_pair(true, "0");
            }
            else {
                Node* aux1 = this->first;
                int cont = 0;
                while (aux1 != nullptr) {
                    if (aux1->getLabel() == label) {
                        aux1->body_removed = true;
                        flag = true;
                        str_cont = std::to_string(cont);
                        return std::make_pair(flag, str_cont);
                    }
                    aux1 = aux1->getNext();
                    cont++;
                }

                if (!flag) {
                    str_cont = std::to_string(cont);
                    return std::make_pair(flag, str_cont);
                }
            }
        }
        else {
            std::cout << "Lista vazia - Função remove_body\n";
            return std::make_pair(false, "");
        }
}

    std::pair<bool, std::string> locate_num(int label) {

        bool flag = false;

        if (!this->empty()) {
            // If the list has only 1 element or the first node's label matches
            if (this->first->getNext() == nullptr || this->first->getLabel() == label) {
                flag = true;
                return std::make_pair(flag, "0");
            }

            // If the node to locate is in the middle or end of the list
            else {
                Node* aux1 = this->first;
                int cont = 0;
                while (aux1 != nullptr) {
                    if (aux1->getLabel() == label) {
                        flag = true;
                        return std::make_pair(flag, std::to_string(cont));
                    }
                    aux1 = aux1->getNext();
                    cont++;
                }

                // If we haven't found the node
                if (flag == false) {
                    return std::make_pair(flag, std::to_string(cont));
                }
            }
        }
        else {
            std::cout << "Empty list in function 'locate_num'\n";
            return std::make_pair(flag, "");
        }
}

};


int main() {
    int M, L;
    std::cin >> M >> L;

    std::map<std::string, DoubleLinkedList*> predio;

    for (int i = 0; i < M; i++) {
        predio["Andar " + std::to_string(i)] = new DoubleLinkedList(L);
    }

    std::string command;
    while (true) {
		bool flag = false;
        std::cin >> command;

        if (command == "END") {
            break;

        } if (flag == false) {
            int value;
            std::cin >> value;

            if (command == "ADD") {
                int andar = value % M;
                predio["Andar " + std::to_string(andar)]->push(value);
                // Colocar o método locate que vai retornar apenas a cova.
                std::pair<bool, std::string> result = predio["Andar " + std::to_string(andar)]->locate_num(value);

                if (result.first == true) {
                    std::cout << andar << '.' << result.second << std::endl;
                }
                else {
                    std::cout << "?.?" << std::endl;
                }
            } else if (command == "REM") {
                int andar = value % M;
                predio["Andar " + std::to_string(andar)]->remove_body(value);
            } else if (command == "QRY") {
                int andar = value % M;
                std::pair<bool, std::string> foundNode = predio["Andar " + std::to_string(andar)]->locate_num(value);
                if (foundNode.first != false) {
                    std::cout << andar << '.' << foundNode.second << std::endl;
                } else {
                    std::cout << "?.?" << std::endl;
                }
            }
        } else {
    map<string, DoubleLinkedList*> aux_predio = predio;
    predio.clear();

    for (int i = 0; i < (2 * aux_predio.size()) + 1; ++i) {
        predio["Andar " + to_string(i)] = new DoubleLinkedList(L);
    }

    for (auto& p : aux_predio) {
        Node* next_node = p.second->first;
        while (next_node != nullptr) {
            if (!next_node->body_removed) {
                int aux_ = next_node->getLabel() % predio.size();
                predio["Andar " + to_string(aux_)]->push(next_node->getLabel());
            }
            next_node = next_node->getNext();
        }
        // Clearing the old list
        p.second->clear();
        delete p.second;
    }

    M = predio.size();
	}

} // while(true)

    // clean up
    for(auto it = predio.begin(); it != predio.end(); it++) {
        delete it->second;
    }

    return 0;
}
