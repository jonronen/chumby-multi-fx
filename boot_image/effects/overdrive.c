#include "effects/overdrive.h"
#include "engine/parameters.h"
#include "math.h"


overdrive_t::overdrive_t()
    : effect_base_t()
{
    unsigned short levels[NUM_CHANNELS];
    int i;
    for (i=0; i<NUM_CHANNELS; i++) {
        levels[i] = OVERDRIVE_NORMAL_LEVEL;
    }
    set_levels(levels);
}


unsigned short overdrive_t::translate_level(unsigned short level)
{
    return level < 257 ? 0x40 : 0x41 + (level-257)/20;
}


int overdrive_t::process_sample(int sample, unsigned char channel)
{
    return limit_value_of_sample(
        sample * (int)m_levels[channel] / OVERDRIVE_MAX_LEVEL
    );
}
