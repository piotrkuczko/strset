#include "strset.h"
#include "strsetconst.h"
#include <iostream>

#ifdef DEBUG
#define debug 1
#else
#define debug 0
#endif

namespace jnp1 {

	using idType = unsigned long;
	
	unsigned long strset42() {
		if (debug)
			std::cerr << "strsetconst init invoked" << std::endl;
		idType index = jnp1::strset_new();
		jnp1::strset_insert(index, "42");
		jnp1::strset_insert(index, "const^NV+*63s9LtPdLDB->1 F69EF,;|\a##eLK,ZU`M{Te5z;V+SBmB9#ot@$kmeRLl`Doh?PjanU6yRes,V`_g");
		if (debug)
			std::cerr << "strsetconst init finished" << std::endl;
		return index;
	}
}

