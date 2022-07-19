#ifndef ATG_ENGINE_SIM_ENGINE_CONTEXT_H
#define ATG_ENGINE_SIM_ENGINE_CONTEXT_H

#include "engine_sim.h"

#include <map>

namespace es_script {

    class CylinderHeadNode;
    class CylinderBankNode;
    class CrankshaftNode;
    class FunctionNode;
    class ExhaustNode;
    class IntakeNode;
    class RodJournalNode;

    class EngineContext {
    public:
        EngineContext();
        ~EngineContext();

        void addHead(CylinderHeadNode *node, CylinderHead *head);
        CylinderHead *getHead(CylinderHeadNode *head);

        void addBank(CylinderBankNode *node, CylinderBank *bank);
        CylinderBank *getBank(CylinderBankNode *bank) const;

        void addRodJournal(RodJournalNode *node, int index);
        int getRodJournalIndex(RodJournalNode *node) const;

        void addIntake(IntakeNode *node, Intake *intake);
        Intake *getIntake(IntakeNode *intake) const;

        void addExhaust(ExhaustNode *node, ExhaustSystem *exhaust);
        ExhaustSystem *getExhaust(ExhaustNode *exhaust) const;

        void addFunction(FunctionNode *node, Function *function);
        Function *getFunction(FunctionNode *exhaust) const;

        void addCrankshaft(CrankshaftNode *node, Crankshaft *crankshaft);
        Crankshaft *getCrankshaft(CrankshaftNode *node) const;

    protected:
        std::map<CylinderHeadNode *, CylinderHead *> m_heads;
        std::map<CylinderBankNode *, CylinderBank *> m_banks;
        std::map<ExhaustNode *, ExhaustSystem *> m_exhaustSystems;
        std::map<IntakeNode *, Intake *> m_intakes;
        std::map<FunctionNode *, Function *> m_functions;
        std::map<RodJournalNode *, int> m_rodJournals;
        std::map<CrankshaftNode *, Crankshaft *> m_crankshafts;
    };

} /* namespace es_script */

#endif /* ATG_ENGINE_SIM_ENGINE_CONTEXT_H */
