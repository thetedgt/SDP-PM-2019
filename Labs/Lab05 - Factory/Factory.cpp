#include "Factory.h"

void Factory::copy(const char *name, Worker *workers, size_t size, size_t capacity) {
    this->name = nullptr;
    if(name != nullptr) {
       this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    this->workers = nullptr;
    this->capacity = capacity;
    this->size = size;
    this->workers = new Worker[capacity];
    for (int i = 0; i < size; i++) {
        this->workers[i] = workers[i];
    }
}

void Factory::del() {
    delete this->name;
    delete[] this->workers;
}

Factory::Factory(const char *name) {
    this->copy(name, nullptr, 0, 8);
}

Factory::Factory(const Factory &factory) {
    this->copy(factory.name, factory.workers, factory.size, factory.capacity);
}

Factory::~Factory() {
    this->del();
}

Factory& Factory::operator=(const Factory &factory) {
    if(this != &factory) {
        this->del();
        this->copy(factory.name, factory.workers, factory.size, factory.capacity);
    }
    return *this;
}

void Factory::print() const {
    cout << "Factory name: " << this->name << ", Number of workers: " << this->size << endl;
    for (int i = 0; i < size; i++) {
        this->workers[i].print();
    }
}

void Factory::addWorker(const Worker &newWorker) {
    if (this->size >= this->capacity) {
        this->resize();
    }
    this->workers[this->size] = newWorker;
    this->size++;
}

void Factory::resize() {
    Worker *temp = this->workers;
    this->capacity *= 2;
    this->workers = new Worker[this->capacity];
    for (int i = 0; i < this->size; i++) {
        workers[i] = temp[i];
    }
    delete[] temp;
}

void Factory::removeByName(char const* name) {
    int index = 0;
    while (index < size && strcmp(workers[index].getName(), name) != 0) {
        index++;
    }
    if(index != size) {
        this->workers[index] = this->workers[this->size - 1];
        this->size--;
        this->downCapacity();
    }
}

void Factory::downCapacity() {
    if(4*this->size <= this->capacity) {
        Worker *temp = this->workers;
        this->capacity /= 2;
        this->workers = new Worker[this->capacity];
        for (int i = 0; i < this->size; i++) {
            workers[i] = temp[i];
        }
        delete[] temp;
    }
}

void Factory::sort() {
    Worker **temp = new Worker*[this->size];
    for(int i = 0; i<this->size; i++) {
        temp[i] = &(this->workers[i]);
    }

    for(int i = 0; i < size - 1; i++) {
        int index = i;
        for(int j = i + 1; j < size; j++) {
            if (temp[index]->getSalary() < temp[j]->getSalary()) {
                index = j;
            }
        }
        Worker *tempPtr = temp[index];
        temp[index] = temp[i];
        temp[i] = tempPtr;
    }

    cout << "Factory name: " << this->name << ", Number of workers: " << this->size << endl;
    for (int i = 0; i < size; i++) {
        temp[i]->print();
    }
    delete[] temp;
}