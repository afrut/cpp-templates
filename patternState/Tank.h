// This program demonstrates the use of the state pattern.
// Identify the different states of an object.
// Identify the operations of an object that will be different in different states.
// - These are the operations that the object has to delegate to state classes.
// Identify the state transitions that need to be captured.
// If needed, implement an enter and exit method for each state to ensure that certain data is set when a state starts or finishes.

#include <string>
#ifndef _TANK_H
#define _TANK_H

// class to represent a tank whose state is to be tracked
class Tank
{
    public:
        class State;        // base state class; abstract and to be inherited from
        class Empty;        // represents the state when Tank is Empty
        class Cold;         // represents the state when Tank is Cold
        class Hot;          // represents the state when Tank is Hot
        class Normal;       // represents the state when Tank is Normal

    public:
        Tank();
        ~Tank();
        int temp() const {return m_temp;}
        int level() const {return m_level;}
        void fill(int amt, int temp);       // operation that will be different at different states
        std::string toString();

    public:
        static const int min_temp = 15;
        static const int max_temp = 150;
        static const int min_level = 0;
        static const int max_level = 100;

    private:
        State* m_state;     // state of the tank
        int m_temp;         // 15 - 150 [Celsius]
        int m_level;        // 0 - 100 [%]
        int m_tempMin;      // minimum temperature to maintain
        int m_tempMax;      // maximum temperature to avoid
        void updateState(); // check for state changes
};

// abstract base class for a tank's state
class Tank::State
{
    public:
        State(Tank& tank) : m_context(tank) {};         // store backreference to original object
        ~State() {};
        virtual int fill(int amt, int temp) = 0;        // pure virtual function; must be overridden in every concrete state
        virtual void enter() = 0;                       // to ensure that certain data is set when entering or leaving a state
        virtual void exit() = 0;
        virtual std::string toString() = 0;

    protected:
        Tank& m_context;    // backreference to the context tank; protected to allow access by children
};

// empty state of a tank
class Tank::Empty : State
{
    public:
        Empty(Tank& tank):State(tank) {};               // call base constructor to store backreference
        std::string toString() { return std::string("Empty"); }
        int fill(int amt, int temp) override;
        void enter() override;
        void exit() override;
};

class Tank::Cold : State
{
    public:
        Cold(Tank& tank):State(tank) {};
        std::string toString() { return std::string("Cold"); }
        int fill(int amt, int temp) override;
        void enter() override;
        void exit() override;
};

class Tank::Hot : State
{
    public:
        Hot(Tank& tank):State(tank) {};
        std::string toString() { return std::string("Hot"); }
        int fill(int amt, int temp) override;
        void enter() override;
        void exit() override;
};

class Tank::Normal : State
{
    public:
        Normal(Tank& tank):State(tank) {};
        std::string toString() { return std::string("Normal"); }
        int fill(int amt, int temp) override;
        void enter() override;
        void exit() override;
};

#endif