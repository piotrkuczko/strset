//
// Created by Piotrek on 21.10.2018.
//

#ifndef STRSET_STRSETCONST_H
#define STRSET_STRSETCONST_H

#include "strset.h"
#include <windows.h>
#include <intrin.h>

#pragma intrinsic(_ReturnAddress)

unsigned long strset42();

/*Zwraca identyfikator zbioru, którego nie można modyfikować i który zawiera
        jeden element: napis "42". Zbiór jest tworzony przy pierwszym wywołaniu tej
        funkcji i wtedy zostaje ustalony jego numer.
        */


#endif //STRSET_STRSETCONST_H
