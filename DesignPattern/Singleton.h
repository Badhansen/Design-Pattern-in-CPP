#pragma once
#include <iostream>
#include <mutex>

class Singleton
{
    /**
     * The Singleton's constructor/destructor should always be private to
     * prevent direct construction/destruction calls with the `new`/`delete`
     * operator.
     */
private:
    static Singleton* pinstance_;
    static std::mutex mutex_;
protected:
    Singleton(const std::string value) : value_(value) {}
    ~Singleton() {}
    std::string value_;
public:
    /**
     * Singletons should not be cloneable.
     */
    Singleton(Singleton& other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Singleton&) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static Singleton* GetInstance(const std::string& value);
    void SomeBusinessLogic()
    {
        // do someting
    }
    std::string GetValue() const
    {
        return value_;
    }
};



