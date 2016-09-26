#include "consensus_event.hpp"

#include "../model/transactions/abstract_transaction.hpp"

namespace consensus_event {

    void ConsensusEvent::addSignature(std::string const signature) {
        txSignatures.push_back(signature);
    }

    std::string ConsensusEvent::getHash() const{
        return tx->getHash();
    }
}  // namespace consensus_event
