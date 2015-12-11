#ifndef __STATE_MANAGER_HPP__
#define __STATE_MANAGER_HPP__

#include <vector>
#include <cstdint>

class State;

class StateManager {
  public:
    std::vector <State*> m_states;
    std::vector <State*> m_statesAdd;
    uint16_t m_pops = 0;

    void push (State* state);
    void pop ();
    State* getLast();

    void pushLooped (State* state);
    void popLooped ();
    void update();
};

#endif // __STATE_MANAGER_HPP__
