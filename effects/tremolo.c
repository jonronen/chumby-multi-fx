#include "effects/tremolo.h"
#include "engine/parameters.h"
#include "math.h"


tremolo_t::tremolo_t()
    : effect_base_t()
{
    int i;
    for (i=0; i<NUM_CHANNELS; i++) {
        m_phase[i] = 0;
    }
    set_level(TREMOLO_MAX_LEVEL);
}


int tremolo_t::process_sample(int sample, unsigned char channel)
{
    return sample * get_channel_level(channel) / TREMOLO_MAX_LEVEL;
}
