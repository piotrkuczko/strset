#include "strset.h"
#include "strsetconst.h"
#include <iostream>

#ifdef NDEBUG
#define debug 0
#else
#define debug 1
#endif

namespace jnp1 {

    static bool strset42_declared = false;
    static idType index;

    idType strset42() {
        if (debug)
            std::cerr << "strsetconst init invoked" << std::endl;
        if (strset42_declared) {
            if (debug)
                std::cerr << "the 42 set exist yet" << std::endl;
        }
        else {
            index = jnp1::strset_new();
            if (!strset42_declared) {
                strset42_declared = true;
                jnp1::strset_insert(index, "42");
            }

            jnp1::strset_insert(index, "const^NV+*63s9LtPdLDB->1 F69EF,;|\a##eLK,ZU`M{Te5z;V+SBmB9#ot@$kmeRLl`Doh?PjanU6yRes,V`_g");
        }
        if (debug)
            std::cerr << "strsetconst init finished" << std::endl;
        return index;
    }
}
