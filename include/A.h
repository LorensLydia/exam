#ifndef A_H
#define A_H

class A {
public:
    static A* getInstance();
    virtual ~A();

private:
    A();
    static A* instance;
};

#endif // A_H
