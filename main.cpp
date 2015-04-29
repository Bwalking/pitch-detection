#include <iostream>
#include "lib/sinewave/sinegenerator.h"
#include "lib/mpm/mpm.h"
#include "lib/goertzel/goertzel.h"
#include "lib/dft/dft.h"

#define MPM_FFT_NSDF

using namespace std;

int main() {
    sinegenerator sinegenerator1 = sinegenerator(48000, 5337);

    mpm mpm1 = mpm(48000, sinegenerator1.size_single_channel);
    goertzel goertzel1 = goertzel(48000, sinegenerator1.size_single_channel);
    dft dft1 = dft(48000, sinegenerator1.size_single_channel);

    sinegenerator1.generate_tone();

    //MPM result
    double pitch = mpm1.get_pitch(sinegenerator1.tone_single_channel);
    printf("MPM pitch: %f\n", pitch);

    //Goertzel result
    pitch = goertzel1.get_pitch(sinegenerator1.tone_single_channel);
    printf("Goertzel pitch: %f\n", pitch);

    //DFT result
    pitch = dft1.get_pitch(sinegenerator1.tone_single_channel);
    printf("DFT pitch: %f\n", pitch);

    sinegenerator1.cleanup();
    mpm1.cleanup();

    exit(0);
}