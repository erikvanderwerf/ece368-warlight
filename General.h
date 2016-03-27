#ifndef GENERAL_H
#define GENERAL_H

#include <vector>

#include "Bot.h"
#include "region.h"
#include "SuperRegion.h"

#include "Attack.h"
#include "Defense.h"

class Map;

class General {
    
    public:
        
        General();
        
        virtual ~General();

        /** \brief Calculates the suggested attacks for this turn.
         *
         *
         */
        std::vector<Move> getAttack();
        
        /** \brief Returns the calculated deployment for this turn.
         *
         */  
        std::vector<Move> getDeployment();
        
        /** calculateStrategy
         *  
         *  This function prioritizes different troop placements and
         *  prioritizes different attacks and moves taking into account the
         *  results from getAttack and getDefense.
         */
        void calculateTurn(float time);

    private:
        
        //std::vector<SUGGESTED_MOVE> m_suggestedAttacks;
        
        //suggested moves with to and from as the same region
        //std::vector<SUGGESTED_MOVE> m_suggestedDefenses;
        
        //suggested moves with from region as null
        //std::vector<SUGGESTED_MOVE> m_suggestedReinforcements;
        
        //std::vector<SUGGESTED_MOVE> m_plannedMoves;

        //Map gameMap;
        
};

#endif // GENERAL_H
