#include <string>
#ifndef _TANK_H
#define _TANK_H

// class to represent a tank whose state is to be tracked
class Tank
{
    public:
        class State;
        class Idle;

    public:
        Tank();
        ~Tank();
        Tank(int temperature, int mix, int level);
        int temperature() const {return m_temperature;}
        int mix() const {return m_mix;}
        int level() const {return m_level;}
        void fill(int amt);
        std::string toString();

    private:
        State* m_state;     // state of the tank
        int m_temperature;  // 15 - 150 [Celsius]
        int m_mix;          // 0 - 100 [%]
        int m_level;        // 0 - 100 [%]
};

// abstract base class for a tank's state
class Tank::State
{
    public:
        State(Tank& tank) : m_context(tank) {};
        ~State() {};
        virtual int fill(int amt);
        virtual int drain(int amt);
        virtual void stir(int sec);
        virtual void heat(int sec);
        virtual std::string toString() = 0;

    protected:
        Tank& m_context;    // backreference to the context tank
};

// idle state of a tank
class Tank::Idle:State
{
    public:
        Idle(Tank& tank):State(tank) {};
        std::string toString() {return std::string("Idle");}
        int fill(int amt);
};

#endif