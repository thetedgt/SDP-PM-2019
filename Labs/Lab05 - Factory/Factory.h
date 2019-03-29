#ifndef FACTORY_H
#define FACTORY_H

#include "Worker.h"

class Factory {
private:
    char *name;
    Worker *workers;
    size_t size;
    size_t capacity;

public:
    Factory(const char *name = nullptr);
    Factory(const Factory &factory);
    ~Factory();
    Factory& operator=(const Factory &factory);
    void print() const;
    void addWorker(Worker const& newWorker);
    void removeByName(char const* name);
    void sort();

private:
    void copy(const char *name, Worker *workers, size_t size, size_t capacity);
    void del();
    void resize();
    void downCapacity();
};

#endif