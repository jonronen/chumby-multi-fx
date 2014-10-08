PLATFORM ?= chumby


# Generic code
UTILS_OBJS = str math
ENGINE_OBJS = fx_main parameters metronome param_transitions
EFFECTS_OBJS = effect_base low_pass resonance passthru
EFFECTS_OBJS += delay overdrive tremolo high_pass
EFFECTS_OBJS += band_pass distortion
GENERIC_OBJS = $(addsuffix .$(PLATFORM).o, \
                $(addprefix utils/, $(UTILS_OBJS)) \
                $(addprefix engine/, $(ENGINE_OBJS)) \
                $(addprefix effects/, $(EFFECTS_OBJS)) \
               )

BAREMETAL_OBJS = $(addsuffix .$(PLATFORM).o, \
                  $(addprefix utils/, new heap) \
                 )

include $(PLATFORM).mk

