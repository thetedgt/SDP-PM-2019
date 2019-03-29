#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <cstring>

using namespace std;

class Worker {
private:
    char *name;
    char *position;
    double salary;

public:
    Worker(const char *name = nullptr, const char *position = nullptr, double salary = 0.0);
    Worker(const Worker &worker);
    Worker& operator=(const Worker &worker);
    ~Worker();

    const char *getName() const;
    const char *getPosition() const;
    double getSalary() const;

    void setName(const char *name);
    void setPosition(const char *position);
    void setSalary(double salary);

    void print() const;

private:
    void copy(const char *name, const char *position, double salary);
    void del();

};

#endif