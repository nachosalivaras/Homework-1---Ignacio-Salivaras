#include <iostream>
#include <fstream>
#include <string>
#include <memory>
using namespace std;

//COMENTARIO GENERAL PROCESO E IMPLEMENTACION:

/*
Para implementar mis funciones sobre una lista simplemente enlazada, primero hice un `struct` de nodo 
y un `struct` de lista que simulaba una clase. Sin embargo, luego leí el correo que aclaraba que esa 
no era la idea de la consigna. 

Entonces, lo que hice fue modificar mis funciones para que reciban la dirección de memoria del `head`, 
y a partir de ahí las fui recorriendo y modificando el `head` para poder realizar las inserciones 
y eliminaciones. Contemplé todos los casos para evitar errores y los probé con distintos tests.
*/


struct Node{
    int data;
    shared_ptr<Node> next;
    
    Node(int value) : data(value), next(nullptr) {}
};


shared_ptr<Node> CreateNode(int value){
    return make_shared<Node>(value);
}



void push_front(shared_ptr<Node>& head, int value) {
    shared_ptr<Node> newNode = CreateNode(value);
    newNode->next = head;
    head = newNode;
}


void push_back(shared_ptr<Node>& head, int value){
    shared_ptr<Node> newNode = CreateNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    shared_ptr<Node> curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    }

void insert(shared_ptr<Node>& head, int value, int posicionainsertar){
    if (!head) {
        push_front(head, value);
        return;
    }
    
    if (posicionainsertar <= 0) {
        push_front(head, value);
        return;
    }
    shared_ptr<Node> newNode = CreateNode(value);
    shared_ptr<Node> curr = head;
    for (int i = 0; curr->next && i < posicionainsertar - 1; i++) {
        curr = curr->next;
    }
    if (!curr->next) {
        push_back(head, value);
        return;    
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

void erase(shared_ptr<Node>& head, int posicionaEliminar){
    if (posicionaEliminar < 0){
        cout<<"Borrado fuera de indice"<<endl;
        return;
    }
    if (!head) return;
    if (!head->next) {  
        head = nullptr; 
        return;
    }
    if (posicionaEliminar == 0) {
        head = head->next;
        return;
    }
    shared_ptr<Node>prev = nullptr;
    shared_ptr<Node>curr = head;
    int contador_size = 0;
    while(curr->next){
        if (contador_size == posicionaEliminar){
            break;
        }
        prev = curr; 
        curr = curr->next;
        contador_size++;
    }
    if (curr->next == nullptr ) {
            prev->next = nullptr;
    } else {
        prev->next = curr->next;
    }
    }
void print_list(shared_ptr<Node> head) {
    if (!head) {
        cout << "Lista vacía" << endl;
        return;
    }
    shared_ptr<Node> current = head;
    while (current) {
        cout << current->data;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
    }
    


int main(){
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> nodo1 = CreateNode(10);
    shared_ptr<Node> nodo2 = CreateNode(20);
    shared_ptr<Node> nodo3 = CreateNode(30);
    push_front(head,5);
    push_back(head,3);
    push_front(head,1);
    insert(head,2,1);
    erase(head,10);
    erase(head,10);
    erase(head,-1);
    print_list(head);

}