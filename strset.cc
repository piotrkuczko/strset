//
// Created by Piotrek on 17.10.2018.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "strset.h"
#include <windows.h>
#include <intrin.h>
#include <cstdio>
using namespace std;
#pragma intrinsic(_ReturnAddress)





using namespace std;
using LL = long long int;
using idType = unsigned long;
static set <size_t> free_ids;
static size_t first_not_generated = 1;
static map<idType , pair<bool, set<string> > > str;


idType strset_new() {
    while (free_ids.empty()) {
        free_ids.insert(first_not_generated++);
    }
    idType index = *free_ids.begin();
    free_ids.erase(free_ids.begin());

    cout <<  __FUNCTION__ << endl;
    return 1;
}


void strset_delete(unsigned long id) {
    if (str.)

}
size_t strset_size(unsigned long id) {
    return 1;
}

void strset_insert(unsigned long id, const char* value) {

}

void strset_remove(unsigned long id, const char* value){
    return;

}

int strset_test(unsigned long id, const char* value) {
    return 1;
}

void strset_clear(unsigned long id) {
    return;
}


int strset_comp(unsigned long id1, unsigned long id2) {
    return 1;
}

