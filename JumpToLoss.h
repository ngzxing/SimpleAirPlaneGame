#ifndef JUMPTOLOSS_H
#define JUMPTOLOSS_H

#include "Game.h"
#include "GameFunctor.h"

class JumpToLoss : public GameFunctor<Game>{

public:
    void operator() ();

};


#endif // JUMPTOLOSS_H
