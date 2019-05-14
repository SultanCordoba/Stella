//============================================================================
//
//   SSSS    tt          lll  lll
//  SS  SS   tt           ll   ll
//  SS     tttttt  eeee   ll   ll   aaaa
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2019 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#ifndef STAGGERED_LOGGER
#define STAGGERED_LOGGER

#include <functional>
#include <chrono>
#include <thread>
#include <mutex>

#include "bspf.hxx"
#include "TimerManager.hxx"
/**
 * This class buffers log events and logs them after a certain time window has expired.
 * The timout increases after every log line by a factor of two until a maximum is reached.
 * If no events are reported, the window size decreases again.
 */

class StaggeredLogger {
  public:

    StaggeredLogger(const string& message, uInt8 level);

    ~StaggeredLogger();

    void log();

  private:

    void _log();

    void onTimerExpired(uInt32 timerId);

    void startInterval();

    void increaseInterval();

    void decreaseInterval();

    void logLine();

    string myMessage;
    uInt8 myLevel;

    uInt32 myCurrentEventCount;
    bool myIsCurrentlyCollecting;

    std::chrono::high_resolution_clock::time_point myLastIntervalStartTimestamp;
    std::chrono::high_resolution_clock::time_point myLastIntervalEndTimestamp;

    uInt32 myCurrentIntervalSize;
    uInt32 myMaxIntervalFactor;
    uInt32 myCurrentIntervalFactor;
    uInt32 myCooldownTime;

    std::mutex myMutex;

    // We need control over the destruction porcess and over the exact point where
    // the worker thread joins -> allocate on the heap end delete explicitly in
    // our destructor.
    TimerManager *myTimer;
    TimerManager::TimerId myTimerId;

    // It is possible that the timer callback is running even after TimerManager::clear
    // returns. This id is unique per timer and is used to return from the callback
    // early in case the time is stale.
    uInt32 myTimerCallbackId;
};

#endif // STAGGERED_LOGGER
