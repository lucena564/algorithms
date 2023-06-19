#include <iostream>
#include <map>
#include <string>

class No {
public:
    int valor;
    No* proximo;

    No(int valor) {
        this->valor = valor;
        this->proximo = NULL;
    }
};

class Pilha {
public:
    No* head;

    Pilha() {
        head = NULL;
    }

    void push(int valor) {
        No* novo = new No(valor);

        if (head == NULL) {
            head = novo;
        } else if (novo->valor == head->valor) {
            int valor_removido = head->valor;
            head = head->proximo;
            delete novo;
        } else {
            novo->proximo = head;
            head = novo;
        }
    }

    int pop() {
        if (head == NULL) {
            return -1;
        } else {
            int valor_removido = head->valor;
            head = head->proximo;
            return valor_removido;
        }
    }

    void show() {
        No* temp = head;
        while (temp != NULL) {
            std::cout << temp->valor << std::endl;
            temp = temp->proximo;
        }
    }

    std::string output_exs() {
        No* temp = head;
        if (head == NULL) {
            return "0 -1";
        }

        int qtd = 0;
        while (temp != NULL) {
            qtd += 1;
            temp = temp->proximo;
        }

        return std::to_string(qtd) + " " + std::to_string(head->valor);
    }
};

int main() {
    std::map<std::string, Pilha*> jogos;
    int num_de_casos;
    // std::cout << "Número de casos (INT): ";
    std::cin >> num_de_casos;

    for (int caso = 0; caso < num_de_casos; caso++) {
        jogos["Jogo " + std::to_string(caso)] = new Pilha();
        // std::cout << "Inserir valores para Jogo " << caso << " (digite END para parar): " << std::endl;
        while (true) {
            std::string item;
            std::cin >> item;

            if (item == "END") {
                break;
            } else if (item == "" || item == " ") {
                continue;
            } else {
                jogos["Jogo " + std::to_string(caso)]->push(std::stoi(item));
            }
        }
    }

    for (int i = 0; i < num_de_casos; i++) {
        std::cout << "caso " << i << ": " << jogos["Jogo " + std::to_string(i)]->output_exs() << std::endl;
    }

    return 0;
}
