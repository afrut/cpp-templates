#include <iostream>
#include <string>
#include <algorithm>
#include "Tank.h"
using namespace std;

// ----------------------------------------------------------------------
// Class Tank
// ----------------------------------------------------------------------
Tank::Tank() :
     m_tempMin(45)
    ,m_tempMax(60)
    ,m_level(min_level)
    ,m_temp(min_temp)
{
    m_state = (State*)new Tank::Empty(*this);
    m_state->enter();
    this->fill(50, 25);
}

Tank::~Tank() {delete m_state;}

// delegate the fill operation to whatever state is active at the time
void Tank::fill(int amt, int temp)
{
    int overflow = amt;
    while(overflow > 0) overflow = m_state->fill(overflow, temp);
}

// delegate the string representation to whatever state is active at the time
string Tank::toString() {return m_state->toString();}

void Tank::updateState()
{
    // the order in which the conditionals are checked here imply
    // a priority order between the states
    if(m_level <= min_level)
    {
        m_state->exit();
        delete m_state;
        m_state = (State*)new Empty(*this);
        m_state->enter();
    }
    else if(m_temp < m_tempMin)
    {
        m_state->exit();
        delete m_state;
        m_state = (State*) new Cold(*this);
        m_state->enter();
    }
    else if(m_temp > m_tempMax)
    {
        m_state->exit();
        delete m_state;
        m_state = (State*) new Hot(*this);
        m_state->enter();
    }
    else
    {
        m_state->exit();
        delete m_state;
        m_state = (State*) new Normal(*this);
        m_state->enter();
    }
}

// ----------------------------------------------------------------------
// Class Tank::Empty
// ----------------------------------------------------------------------
int Tank::Empty::fill(int amt, int temp)
{
    m_context.m_level++;
    amt--;
    m_context.m_temp = temp;
    m_context.updateState();    // as soon as m_level > 0, tank state should change
    return amt;
}

void Tank::Empty::enter()
{
    cout << "Tank is " << this->toString() << "\n";
}

void Tank::Empty::exit()
{}

// ----------------------------------------------------------------------
// Class Tank::Cold
// ----------------------------------------------------------------------
int Tank::Cold::fill(int amt, int temp)
{
    return 0;
}

void Tank::Cold::enter()
{
    cout << "Tank is " << this->toString() << "\n";
}

void Tank::Cold::exit() {}

// ----------------------------------------------------------------------
// Class Tank::Hot
// ----------------------------------------------------------------------
int Tank::Hot::fill(int amt, int temp)
{
    return 0;
}

void Tank::Hot::enter()
{
    cout << "Tank is " << this->toString() << "\n";
}

void Tank::Hot::exit() {}

// ----------------------------------------------------------------------
// Class Tank::Normal
// ----------------------------------------------------------------------
int Tank::Normal::fill(int amt, int temp)
{
    return 0;
}

void Tank::Normal::enter()
{
    cout << "Tank is " << this->toString() << "\n";
}

void Tank::Normal::exit() {}