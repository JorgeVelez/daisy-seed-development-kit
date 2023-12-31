#pragma once
#ifndef STEP_SEQUENCER_H
#define STEP_SEQUENCER_H
#define STEP_SEQUENCER_PROCESS_INTERVAL_US 500

#define STEP_SEQUENCER_MODE_STOP 0
#define STEP_SEQUENCER_MODE_PLAY 1
#define STEP_SEQUENCER_MODE_STEP_REC 2

#include "daisysp.h"
#include "daisy_seed.h"
#include "IKeys.h"
#include "ILeds.h"
#include "Step.h"

namespace developmentKit::stepSequencer
{
    using namespace daisysp;
    using namespace daisy;

    class StepSequencer
    {
    public:
        //StepSequencer();
        void Init();
        void SetKeys(uint8_t keys);
        void Process(uint32_t currentProcessTimeUs);
        bool leds[32];

    private:
        uint8_t stepCount;
        uint8_t currentStep;
        Step steps[16];
        uint8_t lastKeyPress;
        uint16_t tick;
        uint16_t stepInterval;
        void UpdateLedsForCurrentStep();
        void StartStepRecording();
        uint8_t mode;
        const uint8_t noteToLedLookup[13] = {9, 0, 10, 1, 11, 12, 2, 13, 3, 14, 4, 15, 16};
    };
}

#endif