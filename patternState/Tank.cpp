#include <iostream>
#include <string>
#include <algorithm>
#include "Tank.h"
using namespace std;

// ----------------------------------------------------------------------
// Class Tank
// ----------------------------------------------------------------------
Tank::Tank() :
     m_temperature(20)
    ,m_mix(50)
    ,m_level(50)
{
    m_state = (State*)new Tank::Idle(*this);
}

Tank::Tank(int temperature, int mix, int level)
{
    m_temperature = min(max(temperature, 15), 150);
    m_mix = min(max(mix, 0), 100);
    m_level = min(max(level, 0), 100);
    m_state = (State*)new Tank::Idle(*this);
}

Tank::~Tank() {delete m_state;}

void Tank::fill(int amt) {m_state->fill(amt);}
string Tank::toString() {return m_state->toString();}

// ----------------------------------------------------------------------
// Class Tank::State common methods
// ----------------------------------------------------------------------
int Tank::State::fill(int amt)
{
    int overflow = amt;
    m_context.fill(1);    
    return overflow * -1;
}

int Tank::State::drain(int amt) {return 0;}
void Tank::State::stir(int sec) {}
void Tank::State::heat(int sec) {}

// ----------------------------------------------------------------------
// Class Tank::State::Idle
// ----------------------------------------------------------------------
int Tank::Idle::fill(int amt)
{
    cout << "Idle fill";
    return 0;
}