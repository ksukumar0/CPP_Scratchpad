#!/usr/bin/python3
import os
from ctypes import *
class SMB_REQUEST(Structure):
    _fields_ = [
            ("Address", c_double)
            ]

if __name__ == "__main__":
    input("Press Enter to continue...")
    #cdll.LoadLibrary("libstdc++.so");
    dll = cdll.LoadLibrary(os.path.join(os.getcwd(), "libtriangle.so"))
    t = dll.create()
    set_side = dll.setSide
    set_side.argtypes = [POINTER(SMB_REQUEST), c_double]

    dll.printRandom()
    del dll
    #set_side(byref(t),5.6)
