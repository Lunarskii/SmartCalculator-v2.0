#include "model.h"

Model::Stack::Stack() : peak(nullptr) {}

Model::Stack::~Stack() {
    while (peak != nullptr) pop();
}

void Model::Stack::push(const_reference data, type_t type, int priority) {
    if (peak == nullptr) {
        peak = new Node(data, priority, type, nullptr);
    } else {
        Node* newNode = new Node(data, priority, type, peak);
        peak = newNode;
    }
}

void Model::Stack::pop() {
    if (peak != nullptr) {
        Node* temp = peak;
        peak = peak->prev;
        delete temp;
    }
}

typename Model::Stack::value_type Model::Stack::top() const {
    if (peak != nullptr) {
        return peak->data;
    } else {
        return value_type{};
    }
}

typename Model::Stack::size_type Model::Stack::size() const {
    size_type size = 0;

    if (peak != nullptr) {
        Node* temp = peak;

        for (; temp != nullptr; ++size) {
            temp = temp->prev;
        }
    }

    return size;
}

int Model::Stack::getPriority() const {
    return peak->priority;
}

typename Model::Stack::value_type Model::Stack::getData() const {
    return peak->data;
}

type_t Model::Stack::getType() const {
    return peak->type;
}

typename Model::Stack::Node* Model::Stack::getNode() const {
    return peak;
}

void Model::Stack::moveElement(Stack& other) {
    push(other.getData(), other.getType(), other.getPriority());
    other.pop();
}

void Model::Stack::spliceOperators(Stack& other) {
    while (isOperator(other.getType())) {
        moveElement(other);
    }
}

void Model::Stack::spliceNumbers(Stack& other) {
    while (other.getType() == NUMBER) {
        moveElement(other);
    }
}
