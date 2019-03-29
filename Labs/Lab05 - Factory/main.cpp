#include "Factory.h"

void testFactory() {
    Worker a("Ivan", "programmer", 100);
    Worker b("Mitko", "programmer", 80);
    Worker c("Kiro", "programmer", 70);
    Worker d("Evstati", "programmer", 150);
    b.setName("Go6o");
    b.setSalary(120);
    //a.print();
    //b.print();
    cout << endl;
    Factory factory("FMI");
    factory.print();
    factory.addWorker(a);
    factory.addWorker(b);
    factory.addWorker(c);
    factory.addWorker(d);
    factory.addWorker(b);
    factory.print();
    cout << endl;

    factory.sort();
    factory.print();
}

int main() {
    testFactory();

    return 0;
}
