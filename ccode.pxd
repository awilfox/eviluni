from libc.stdint cimport int32_t
from libcpp cimport bool

cdef extern from "ccode.h":
    bool spoof_init()
    int32_t spoof_is_evil(const char *to_check)

