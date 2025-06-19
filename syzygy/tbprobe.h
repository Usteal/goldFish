

#ifndef TBPROBE_H
#define TBPROBE_H

#include <string>
#include <vector>


namespace goldFish {
class Position;
class OptionsMap;

using Depth = int;

namespace Search {
struct RootMove;
using RootMoves = std::vector<RootMove>;
}
}

namespace goldFish::Tablebases {

struct Config {
    int   cardinality = 0;
    bool  rootInTB    = false;
    bool  useRule50   = false;
    Depth probeDepth  = 0;
};

enum WDLScore {
    WDLLoss        = -2,  // Loss
    WDLBlessedLoss = -1,  // Loss, but draw under 50-move rule
    WDLDraw        = 0,   // Draw
    WDLCursedWin   = 1,   // Win, but draw under 50-move rule
    WDLWin         = 2,   // Win
};

// Possible states after a probing operation
enum ProbeState {
    FAIL              = 0,   // Probe failed (missing file table)
    OK                = 1,   // Probe successful
    CHANGE_STM        = -1,  // DTZ should check the other side
    ZEROING_BEST_MOVE = 2    // Best move zeroes DTZ (capture or pawn move)
};

extern int MaxCardinality;


void     init(const std::string& paths);
WDLScore probe_wdl(Position& pos, ProbeState* result);
int      probe_dtz(Position& pos, ProbeState* result);
bool     root_probe(Position& pos, Search::RootMoves& rootMoves, bool rule50, bool rankDTZ);
bool     root_probe_wdl(Position& pos, Search::RootMoves& rootMoves, bool rule50);
Config   rank_root_moves(const OptionsMap&  options,
                         Position&          pos,
                         Search::RootMoves& rootMoves,
                         bool               rankDTZ = false);

}  // namespace goldFish::Tablebases

#endif



