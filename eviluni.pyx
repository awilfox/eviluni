cimport ccode

cdef class UnicodeEvilnessTester:
    def __cinit__(self):
        ccode.spoof_init()

    def test(self, unicode uni):
        utf8 = uni.encode('utf-8')
        return ccode.spoof_is_evil(utf8)
