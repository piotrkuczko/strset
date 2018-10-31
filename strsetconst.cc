#include "strset.h"
#include "strsetconst.h"

namespace {

    using idType = unsigned long;

#ifdef NDEBUG
#define debug 0
#else
#define debug 1
#endif

    static bool strset42_declared = false;
    static idType index;

}

namespace jnp1 {

    idType strset42() {

        if (strset42_declared) {
            //if (debug)
                //std::cerr << "the 42 set already exists" << std::endl;
        }
        else {
            if (debug)
                std::cerr << "strsetconst init invoked" << std::endl;
            index = jnp1::strset_new();
            if (!strset42_declared) {
                strset42_declared = true;
                jnp1::strset_insert(index, "42");
            }
            if (debug)
                std::cerr << "strsetconst init finished" << std::endl;

            //jnp1::strset_insert(index, "const^NV+*63s9LtPdLDB->1 F69EF,;|\a##eLK,ZU`M{Te5z;V+SBmB9#ot@$kmeRLl`Doh?PjanU6yRes,V`_g");
        }

        return index;
    }

}