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
    ,m_amt(0)
    ,m_level(min_level)
    ,m_temp(min_temp)
{
    m_state = (State*)new Tank::Empty(*this);
    m_state->enter();
    this->fill(50, 25);
}

Tank::~Tank() {delete m_state;}

// delegate the fill operation to whatever state is active at the time
int Tank::fill(int amt, int temp)
{
    m_amt = amt;
    while(m_amt > 0)
    {
        State* newState = m_state->fill(temp);
        if(newState) this->changeState(newState);
        cout << "  Tank temp = " << this->temp() << "\n";
        if(m_state->toString() == std::string("Full"))
            break;
    }
    amt = m_amt;
    m_amt = 0;
    return amt;
}

// delegate the string representation to whatever state is active at the time
string Tank::toString() {return m_state->toString();}

void Tank::changeState(State* newState)
{
    m_state->exit();
    delete m_state;
    m_state = newState;
    newState->enter();
}

// ----------------------------------------------------------------------
// Class Tank::Empty
// ----------------------------------------------------------------------
Tank::State* Tank::Empty::fill(int temp)
{
    m_context.m_level++;
    m_context.m_amt--;
    m_context.m_temp = temp;
    return this->transition();
}

Tank::State* Tank::Empty::transition()
{
    // Empty can only transition to Hot, Cold or Normal
    if(m_context.m_level > 0)
    {
        if(m_context.m_temp < m_context.m_tempMin)
            return (State*)new Tank::Cold(m_context);
        else if(m_context.m_temp > m_context.m_tempMax)
            return (State*)new Tank::Hot(m_context);
        else
            return (State*)new Tank::Normal(m_context);
    }
    return NULL;
}

void Tank::Empty::enter()
{
    cout << "Tank is " << this->toString() << "\n";
    // whenever tank is empty, automatically open the hatch
    m_context.m_hatchOpen = true;
}

void Tank::Empty::exit()
{
    // whenever tank has contents, automatically close hatch
    m_context.m_hatchOpen = false;
}

// ----------------------------------------------------------------------
// Class Tank::Full
// ----------------------------------------------------------------------
Tank::State* Tank::Full::fill(int temp) {return this->transition();}
Tank::State* Tank::Full::transition()
{
    // Full can only transition to Normal
    if(m_context.m_level < max_level)
        return (State*)new Tank::Normal(m_context);
    return NULL;
}

void Tank::Full::enter() {cout << "Tank is " << this->toString() << "\n";}
void Tank::Full::exit() {}

// ----------------------------------------------------------------------
// Class Tank::Cold
// ----------------------------------------------------------------------
Tank::State* Tank::Cold::fill(int temp)
{
    m_context.m_temp = (m_context.m_temp * m_context.m_level) + temp + 1;   // heating should be on
    m_context.m_level++;
    m_context.m_temp /= m_context.m_level;
    m_context.m_amt--;
    if(m_context.m_amt == 0 || m_context.m_level == max_level)
        // done filling or tank is full, heat until within limits
        this->fix();
    return this->transition();
}

Tank::State* Tank::Cold::transition()
{
    // Cold can only transition to Normal
    if(m_context.m_temp > m_context.m_tempMin)
        return (State*)new Tank::Normal(m_context);
    return NULL;
}

void Tank::Cold::fix()
{
    m_context.m_temp = (m_context.m_tempMin + m_context.m_tempMax) / 2;
    this->transition();
}

void Tank::Cold::enter()
{
    cout << "Tank is " << this->toString() << "\n";
    m_context.m_heatOn = true;
}

void Tank::Cold::exit()
{
    m_context.m_heatOn = false;
}

// ----------------------------------------------------------------------
// Class Tank::Hot
// ----------------------------------------------------------------------
Tank::State* Tank::Hot::fill(int temp)
{
    m_context.m_temp = (m_context.m_level * m_context.m_temp) + temp - 1;
    m_context.m_level++;
    m_context.m_temp /= m_context.m_level;
    m_context.m_amt--;
    return this->transition();
}

Tank::State* Tank::Hot::transition()
{
    if(m_context.m_temp < m_context.m_tempMax)
        return (State*)new Tank::Normal(m_context);
    return NULL;
}

void Tank::Hot::fix()
{
    m_context.m_temp = (m_context.m_tempMin + m_context.m_tempMax)/2;
}

void Tank::Hot::enter()
{
    cout << "Tank is " << this->toString() << "\n";
    m_context.m_coolOn = true;
}

void Tank::Hot::exit()
{
    m_context.m_coolOn = false;
}

// ----------------------------------------------------------------------
// Class Tank::Normal
// ----------------------------------------------------------------------
Tank::State* Tank::Normal::fill(int temp)
{
    m_context.m_temp = (m_context.m_temp * m_context.m_level) + temp;
    m_context.m_level++;
    m_context.m_temp /= m_context.m_level;
    m_context.m_amt--;
    return this->transition();
}

Tank::State* Tank::Normal::transition()
{
    if(m_context.m_level == m_context.max_level)
        return (State*)new Tank::Full(m_context);
    else if(m_context.m_level == m_context.min_level)
        return (State*)new Tank::Empty(m_context);
    else if(m_context.m_temp < m_context.m_tempMin)
        return (State*)new Tank::Cold(m_context);
    else if(m_context.m_temp > m_context.m_tempMax)
        return (State*)new Tank::Hot(m_context);
    return NULL;
}

void Tank::Normal::enter()
{
    cout << "Tank is " << this->toString() << "\n";
}
void Tank::Normal::exit() {}
