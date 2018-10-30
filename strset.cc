//
// Created by Piotrek on 17.10.2018.
//

#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cassert>
#include "strset.h"
#include "strsetconst.h"

#ifdef NDEBUG
#define debug 0
#else
#define debug 1
#endif


namespace jnp1 {

    using std::map;
    using std::set;
    using std::string;
    using std::pair;
    using std::cerr;
    using std::endl;
    using std::stringstream;
    using LL = long long int;
    using idType = unsigned long;


    set <idType> free_ids;
    idType first_not_generated = 0LL;
    map<idType, pair<bool, set<string> > > str;
    const string const_key = "const^NV+*63s9LtPdLDB->1 F69EF,;|\a##eLK,ZU`M{Te5z;V+SBmB9#ot@$kmeRLl`Doh?PjanU6yRes,V`_g";

    inline string itoa(idType a) {
        stringstream s;
        s << a;
        return s.str();
    }

    string name(map<idType, pair<bool, set<string> > >::iterator it) {
        if (it->second.first)
            return "the 42 Set";
        return "set " + itoa(it->first);
    }

    string name(idType id) {
        map<idType, pair<bool, set<string> > >::iterator it = str.find(id);
        if (it == str.end())
            return "set " + itoa(id);
        return name(it);
    }

    inline void init_cerr_short(string a, string b) {
        if (debug)
            cerr << a << "(" << b << ")" << endl;
    }

    inline void init_cerr(string a, string b) {
        if (debug)
            cerr << a << "(" << b << ")" << endl << a << ": ";
    }



    bool start_function_with_const_char(string name, idType id, const char* value) {
        if (value == NULL) {
            init_cerr(name, itoa(id) + ", NULL");

            if (debug)
                cerr << "invalid value (NULL)" << endl;
            assert (value != NULL);
            return true;
        }
        return false;

    }

    idType strset_new() {
        init_cerr(__func__, "");
        while (free_ids.empty()) {
            free_ids.insert(first_not_generated++);
        }
        idType index = *free_ids.begin();
        free_ids.erase(free_ids.begin());
        str.insert({index, make_pair(false, set<string>())});
        if (debug) {
            cerr << "set " << index << " created" << endl;
        }
        return index;
    }


    void strset_delete(idType id) {
        init_cerr(__func__, itoa(id));
        map<idType, pair<bool, set<string> > >::iterator it = str.find(id);
        if (it != str.end()) {
            if (it->second.first) {
                if (debug)
                    cerr << "attempt to remove the 42 Set" << endl;
            }
            else {
                free_ids.insert(it->first);
                str.erase(it);
                if (debug)
                    cerr << "set " << id << " deleted" << endl;
            }
        }
        else {
            if (debug)
                cerr << "set " << id << " not exist" << endl;
        }
    }

    size_t strset_size(idType id) {
        init_cerr(__func__, itoa(id));
        map<idType, pair<bool, set<string> > >::iterator it = str.find(id);
        if (it == str.end()) {
            if (debug)
                cerr << "set " << id << " does not exist" << endl;
            return 0;
        }
        size_t size = it->second.second.size();
        if (debug)
            cerr << "set " << id << " contains " << size << " element(s)" << endl;
        return size;
    }

    void strset_insert(idType id, const char* value) {
        if (start_function_with_const_char(__func__, id, value)) {
            return;
        }

        string s(value);

        map<idType, pair<bool, set<string> > >::iterator it = str.find(id);
        if (it != str.end() && it->second.second.size() == 1 && *(it->second.second.begin()) == "42" && value == const_key) {
            //printf ("zachodzi\n");
            it->second.first = true;
            return;
        }
        init_cerr(__func__, itoa(id) + ", \"" + s + "\"");
        if (it != str.end()) {
            if (it->second.first == false) {
                size_t size_before = it->second.second.size();
                it->second.second.insert(s);

                if (size_before == it->second.second.size()) {
                    if (debug)
                        cerr << "set " << id << ", element \"" << s << "\" was already present" << endl;
                }
                else {
                    if (debug)
                        cerr << "set " << id << ", element \"" << s << "\" inserted" << endl;
                }
            }
            else {
                if (debug)
                    cerr << "attempt to insert into the 42 Set" << endl;
            }
        }
        else {
            if (debug)
                cerr << "set " << id << " does not exist" << endl;
        }
    }

    void strset_remove(idType id, const char* value) {
        if (start_function_with_const_char(__func__, id, value)) {
            return;
        }
        string s(value);
        init_cerr(__func__, itoa(id) + ", \"" + s + "\"");
        map<idType, pair<bool, set<string> > >::iterator it = str.find(id);
        if (it != str.end()) {
            if (it->second.first == false) {
                size_t size_before = it->second.second.size();
                it->second.second.erase(s);

                if (size_before == it->second.second.size()) {
                    if (debug)
                        cerr << "set " << id << " does not contain the element \"" << s << "\"" << endl;
                }
                else {
                    if (debug)
                        cerr << "set " << id << ", element \"" << s << "\" removed" << endl;
                }
            }
            else {
                if (debug)
                    cerr << "attempt to remove from the 42 Set" << endl;
            }
        }
        else {
            if (debug)
                cerr << "set " << id << " does not exist" << endl;
        }
    }

    int strset_test(idType id, const char* value) {
        if (start_function_with_const_char(__func__, id, value)) {
            return 0;
        }
        string s(value);
        init_cerr(__func__, itoa(id) + ", \"" + s + "\"");
        map<idType, pair<bool, set<string> > >::iterator it = str.find(id);
        if (it != str.end()) {
            if (it->second.second.find(s) != it->second.second.end()) { // istnieje
                if (debug)
                    cerr << name(it) << " contains the element \"" << s << "\"" << endl;
                return 1;
            }
            else {
                if (debug)
                    cerr << name(it) << " does not contain the element \"" << s << "\"" << endl;
                return 0;
            }
        }
        else {
            if (debug)
                cerr << "set " << id << " does not exist" << endl;
            return 0;
        }
    }

    void strset_clear(idType id) {
        init_cerr(__func__, itoa(id));
        map<idType, pair<bool, set<string> > >::iterator it = str.find(id);
        if (it != str.end()) {
            if (it->second.first) {
                if (debug)
                    cerr << "attempt to clear the 42 Set" << endl;
            }
            else {
                if (debug)
                    cerr << "set " << id << " cleared" << endl;
                it->second.second.clear();
            }
        }
        else {
            if (debug)
                cerr << "set " << id << " does not exist" << endl;
        }
    }

    int strset_compare(idType id1, idType id2) {
        map<idType, pair<bool, set<string> > >::iterator it1, it2;
        it1 = str.find(id1);
        it2 = str.find(id2);
        if (it1 != str.end() && it2 != str.end()) {
            if (it1->second.second < it2->second.second)
                return -1;
            else if (it1->second.second == it2->second.second)
                return 0;
            else return 1;
        }
        else if (it1 == str.end() && it2 == str.end()) {
            if (debug) {
                cerr << "strset_comp: set " << id1 << " does not exist" << endl;
                cerr << "strset_comp: set " << id2 << " does not exist" << endl;
            }
            return 0;
        }
        else if (it1 == str.end()) {
            if (debug) {
                cerr << "strset_comp: set " << id1 << " does not exist" << endl;
            }
            return -1;
        }
        else {
            if (debug) {
                cerr << "strset_comp: set " << id2 << " does not exist" << endl;
            }
            return 1;
        }
    }


    int strset_comp(idType id1, idType id2) {
        init_cerr_short(__func__, itoa(id1) + ", " + itoa(id2));
        int val = strset_compare(id1, id2);
        if (debug)
            cerr << __func__ << ": result of comparing " << name(id1) << " to " << name(id2) << " is " << val << endl;
        return val;
    }
}