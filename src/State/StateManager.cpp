#include "State/StateManager.hpp"

void StateManager::push(State* state) {
  this->m_states.push_back(state);
}

void StateManager::pop() {
  if (this->m_states.size() > 0)
    this->m_states.pop_back();
}

State* StateManager::getLast() {
  if (this->m_states.size() == 0) return nullptr;
    return this->m_states.back();
}

void StateManager::pushLooped(State* state) {
  this->m_statesAdd.push_back(state);
}

void StateManager::popLooped() {
  if (this->m_states.size() > 0)
    this->m_pops++;
}

void StateManager::update() {
  while (this->m_pops > 0 && this->m_states.size() > 0) {
    this->m_states.pop_back();
    this->m_pops--;
  }
  this->m_pops = 0;

  while (this->m_statesAdd.size() > 0) {
    this->m_states.push_back(this->m_statesAdd.front());
    this->m_statesAdd.erase(this->m_statesAdd.begin());
  }
  this->m_statesAdd.clear();
}
