#include <iostream>

#include "Product.h"
#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList* list = new DoublyLinkedList();
    
    Product product1("Notebook", "Dell", 1500.0);
    Product product2("Teclado", "Logitech", 500.0);
    Product product3("Celular", "Apple", 4000.0);

    list->insert(product1);
    list->insert(product2);
    list->insert(product3);

    list->showList();

    const Product* product = list->search(2); 
    if(product) {
        std::cout << "Produto Encontrado!" << std::endl;
        std::cout << "===============" << std::endl;
        product->print();
    } else {
        std::cout << "Produto Não Encontrado!" << std::endl;
        std::cout << "===============" << std::endl;
    }

    bool ret = list->remove(3);
    std::cout << (ret ? "Removido" : "Erro") << std::endl;
    std::cout << "===============" << std::endl;
    list->showList();

    ret = list->update(2, 800.0);
    std::cout << (ret ? "Atualizado" : "Erro") << std::endl;
    std::cout << "===============" << std::endl;
    list->showList();

    delete list;

    return 0;
}