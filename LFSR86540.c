#include "LSFR86540.h"
bool LFSR86540(uint8_t *state)
{
    bool result = (*state & 0x01) != 0;
    if ((*state & 0x80) != 0)
        *state = (*state << 1) ^ 0x71;
    else
        *state <<= 1;
    return result;
}