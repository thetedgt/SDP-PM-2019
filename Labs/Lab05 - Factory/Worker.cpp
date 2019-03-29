#include "Worker.h"

void Worker::copy(const char *name, const char *position, double salary) {
    this->name = nullptr;
    if(name != nullptr) {
       this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    this->position = nullptr;
    if(position != nullptr) {
       this->position = new char[strlen(position) + 1];
        strcpy(this->position, position);
    }

    this->salary = salary;
}

void Worker::del() {
    delete this->name;
    delete this->position;
}

Worker::Worker(const char *name, const char *position , double salary) {
    this->copy(name, position, salary);
}

Worker::Worker(const Worker &worker) {
    this->copy(worker.name, worker.position, worker.salary);
}

Worker& Worker::operator=(const Worker &worker) {
    if (this != &worker) {
        this->del();
        this->copy(worker.name, worker.position, worker.salary);
    }

    return *this;
}

Worker::~Worker() {
    this->del();
}

const char * Worker::getName() const {
    return this->name;
}

const char * Worker::getPosition() const {
    return this->position;
}

double Worker::getSalary() const {
    return this->salary;
}

void Worker::setName(const char *name) {
    delete this->name;
    this->name = nullptr;
    if(name) {
       this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

void Worker::setPosition(const char *position) {
    delete this->position;
    this->position = nullptr;
    if(position) {
       this->position = new char[strlen(position) + 1];
        strcpy(this->position, position);
    }
}

void Worker::setSalary(double salary) {
    if (salary >= 0) {
        this->salary = salary;
    }
}

void Worker::print() const {
    cout << "Name: " << name << ", Position: " << position << ", Salary: " << salary << endl;
}
