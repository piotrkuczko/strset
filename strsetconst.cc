//
// Created by Piotrek on 21.10.2018.
//

#include "strset.h"
#include "strsetconst.h"
#include <windows.h>
#include <intrin.h>

#pragma intrinsic(_ReturnAddress)
using namespace std;

unsigned long strset42() {
    //printf("Return address from %s: %p\n", __FUNCTION__, _ReturnAddress());
    return strset_new();
}