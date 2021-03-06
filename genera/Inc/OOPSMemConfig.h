/*
  ==============================================================================

    OPPSMemConfig.h
    Created: 23 Jan 2017 10:34:10pm
    Author:  Michael R Mulshine

  ==============================================================================
*/

#ifndef OPPSMEMCONFIG_H_INCLUDED
#define OPPSMEMCONFIG_H_INCLUDED

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                                       *
 * If your application requires use of many instances of one component or is facing memory limitations,  *
 * use this set of defines to increase or limit the number of instances of each component. The library   *
 * will pre-allocate only the number of instances defined here.                                          *
 *                                                                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define SHAPER1_TABLE_SIZE 65536
extern const float shaper1[SHAPER1_TABLE_SIZE];

// Arbitrary number of instances.
#define NI 1
//#define     N_MYOBJECT            0   // Zero instances is fine.
#define     N_808SNARE          NI
#define     N_808HIHAT          NI
#define     N_808COWBELL        NI
#define     N_COMPRESSOR        NI
#define     N_PRCREV            NI
#define     N_NREV              NI
#define     N_PLUCK             NI
#define     N_STIFKARP          NI
#define     N_NEURON            NI
#define     N_PHASOR            NI
#define     N_CYCLE             NI
#define     N_SAWTOOTH          5
#define     N_TRIANGLE          NI + 5 * N_808SNARE
#define     N_SQUARE            NI + 6 * N_808HIHAT + 2 * N_808COWBELL
#define     N_NOISE             NI + (1 * N_STIFKARP) + (1 * N_PLUCK) + 4// StifKarp and Pluck each contain 1 Noise component.
#define     N_ONEPOLE           NI + (1 * N_PLUCK)
#define     N_TWOPOLE           NI
#define     N_ONEZERO           NI + (1 * N_STIFKARP) + (1 * N_PLUCK) + (1 * N_NEURON)
#define     N_TWOZERO           NI
#define     N_POLEZERO          NI + (1 * N_NEURON)
#define     N_BIQUAD            NI + (4 * N_STIFKARP)
#define     N_SVF               NI
#define     N_SVFE              NI 
#define     N_HIGHPASS          NI 
#define     N_DELAY             NI + (14 * N_NREV) + (3 * N_PRCREV) + 5
#define     N_DELAYL            NI + (1 * N_STIFKARP) + (1 * N_PLUCK) 
#define     N_DELAYA            NI + (1 * N_PRCREV) + (1 * N_STIFKARP) 
#define     N_ENVELOPE          NI
#define     N_ENVELOPEFOLLOW    NI + 4
#define     N_ADSR              NI
#define     N_RAMP              NI + N_NEURON + 10

#define     DELAY_LENGTH        2048    // The maximum delay length of all Delay/DelayL/DelayA components.
                                        // Feel free to change to suit memory constraints or desired delay max length / functionality.

#define     INC_MISC_WT         0     // Set this to 1 if you are interested in the mtof1, adc1, tanh1, and shaper1 wavetables
                                        // and have spare memory.

// Preprocessor defines to determine whether to include component files in build.
#define INC_UTILITIES       (N_ENVELOPE || N_ENVELOPEFOLLOW || N_RAMP || N_ADSR || N_COMPRESSOR)
#define INC_DELAY           (N_DELAY || N_DELAYL || N_DELAYA)
#define INC_FILTER          (N_ONEPOLE || N_TWOPOLE || N_ONEZERO || N_TWOZERO || N_POLEZERO || N_BIQUAD || N_SVF || N_SVFE || N_HIGHPASS)
#define INC_REVERB          (N_NREV || N_PRCREV)
#define INC_INSTRUMENT      (N_STIFKARP || N_PLUCK || N_808HIHAT || N_808COWBELL || N_808SNARE)
#define INC_OSCILLATOR      (N_PHASOR || N_SAWTOOTH || N_CYCLE || N_TRIANGLE || N_SQUARE || N_NOISE)

#endif  // OPPSMEMCONFIG_H_INCLUDED
