

#ifndef NNUE_MISC_H_INCLUDED
#define NNUE_MISC_H_INCLUDED

#include <cstddef>
#include <string>

#include "../types.h"
#include "nnue_architecture.h"

namespace goldFish {

class Position;

namespace Eval::NNUE {

struct EvalFile {
    // Default net name, will use one of the EvalFileDefaultName* macros defined
    // in evaluate.h
    std::string defaultName;
    // Selected net name, either via uci option or default
    std::string current;
    // Net description extracted from the net file
    std::string netDescription;
};


struct NnueEvalTrace {
    static_assert(LayerStacks == PSQTBuckets);

    Value       psqt[LayerStacks];
    Value       positional[LayerStacks];
    std::size_t correctBucket;
};

struct Networks;
struct AccumulatorCaches;

std::string trace(Position& pos, const Networks& networks, AccumulatorCaches& caches);

}  // namespace goldFish::Eval::NNUE
}  // namespace goldFish

#endif  // #ifndef NNUE_MISC_H_INCLUDED



