#include <map>
#include <set>
#include <sstream>
#include <cassert>
#include "strset.h"
#include "strsetconst.h"

namespace {

#ifdef NDEBUG
#define debug 0
#else
#define debug 1
#endif

    using LL = long long int;
    using idType = unsigned long;

    std::set <idType> & free_ids() {
        static std::set <idType> free_ids;
        return free_ids;
    }
    idType first_not_generated = 0LL;
    std::map<idType, std::pair<bool, std::set<std::string> > > & str() {
        static std::map<idType, std::pair<bool, std::set<std::string> > > str;
        return str;
    }

    inline std::string itoa(idType a) {
        std::stringstream s;
        s << a;
        return s.str();
    }

    std::string name(std::map<idType, std::pair<bool, std::set<std::string> > >::iterator it) {
        if (it->second.first)
            return "the 42 Set";
        return "set " + itoa(it->first);
    }

    std::string name(idType id) {
        std::map<idType, std::pair<bool, std::set<std::string> > >::iterator it = str().find(id);
        if (it == str().end())
            return "set " + itoa(id);
        return name(it);
    }

    inline void init_cerr_short(std::string a, std::string b) {
        if (debug)
            std::cerr << a << "(" << b << ")" << std::endl;
    }

    inline void init_cerr(std::string a, std::string b) {
        if (debug)
            std::cerr << a << "(" << b << ")" << std::endl << a << ": ";
    }

    bool start_function_with_const_char(std::string name, idType id, const char* value) {
        if (value == NULL) {
            init_cerr(name, itoa(id) + ", NULL");

            if (debug)
                std::cerr << "invalid value (NULL)" << std::endl;
            //assert (value != NULL);
            return true;
        }
        return false;

    }

    int strset_compare(idType id1, idType id2) {
        std::map<idType, std::pair<bool, std::set<std::string> > >::iterator it1, it2;
        it1 = str().find(id1);
        it2 = str().find(id2);
        if (it1 != str().end() && it2 != str().end()) {
            if (it1->second.second < it2->second.second)
                return -1;
            else if (it1->second.second == it2->second.second)
                return 0;
            else return 1;
        }
        else if (it1 == str().end() && it2 == str().end()) {
            if (debug) {
                std::cerr << "strset_comp: set " << id1 << " does not exist" << std::endl;
                std::cerr << "strset_comp: set " << id2 << " does not exist" << std::endl;
            }
            return 0;
        }
        else if (it1 == str().end()) {
            if (debug) {
                std::cerr << "strset_comp: set " << id1 << " does not exist" << std::endl;
            }
            return -1;
        }
        else {
            if (debug) {
                std::cerr << "strset_comp: set " << id2 << " does not exist" << std::endl;
            }
            return 1;
        }
    }

}

namespace jnp1 {

    idType strset_new() {
        init_cerr(__func__, "");
        while (free_ids().empty()) {
            free_ids().insert(first_not_generated++);
        }
        idType index = *free_ids().begin();
        free_ids().erase(free_ids().begin());
        str().insert({index, make_pair(false, std::set<std::string>())});
        if (debug) {
            std::cerr << "set " << index << " created" << std::endl;
        }
        return index;
    }

    void strset_delete(idType id) {
        init_cerr(__func__, itoa(id));
        std::map<idType, std::pair<bool, std::set<std::string> > >::iterator it = str().find(id);
        if (it != str().end()) {
            if (it->second.first) {
                if (debug)
                    std::cerr << "attempt to remove the 42 Set" << std::endl;
            }
            else {
                free_ids().insert(it->first);
                str().erase(it);
                if (debug)
                    std::cerr << "set " << id << " deleted" << std::endl;
            }
        }
        else {
            if (debug)
                std::cerr << "set " << id << " not exist" << std::endl;
        }
    }

    size_t strset_size(idType id) {
        init_cerr(__func__, itoa(id));
        std::map<idType, std::pair<bool, std::set<std::string> > >::iterator it = str().find(id);
        if (it == str().end()) {
            if (debug)
                std::cerr << "set " << id << " does not exist" << std::endl;
            return 0;
        }
        size_t size = it->second.second.size();
        if (debug)
            std::cerr << "set " << id << " contains " << size << " element(s)" << std::endl;
        return size;
    }

    void strset_insert(idType id, const char* value) {
        if (start_function_with_const_char(__func__, id, value)) {
            return;
        }

        std::string s(value);
        init_cerr_short(__func__, itoa(id) + ", \"" + s + "\"");
        idType index = strset42();
        std::map<idType, std::pair<bool, std::set<std::string> > >::iterator it = str().find(id);
        /*if (it != str().end() && it->second.second.size() == 1 && *(it->second.second.begin()) == "42" && value == const_key) {
            it->second.first = true;
            return;
        }*/
        if (debug)
            std::cerr << __func__ << ": ";
        if (it != str().end()) {
            if (id == index) {
                //str().insert({index, make_pair(true, std::set<std::string>())});
                it->second.second.insert("42");
                it->second.first=true;
                if (debug)
                    std::cerr << "set " << id << ", element \"" << s << "\" inserted" << std::endl;
                return;
            }
            if (it->second.first == false) {
                size_t size_before = it->second.second.size();
                it->second.second.insert(s);

                if (size_before == it->second.second.size()) {
                    if (debug)
                        std::cerr << "set " << id << ", element \"" << s << "\" was already present" << std::endl;
                }
                else {
                    if (debug)
                        std::cerr << "set " << id << ", element \"" << s << "\" inserted" << std::endl;
                }
            }
            else {
                if (debug)
                    std::cerr << "attempt to insert into the 42 Set" << std::endl;
            }
        }
        else {
            if (debug)
                std::cerr << "set " << id << " does not exist" << std::endl;
        }
    }

    void strset_remove(idType id, const char* value) {
        if (start_function_with_const_char(__func__, id, value)) {
            return;
        }
        std::string s(value);
        init_cerr(__func__, itoa(id) + ", \"" + s + "\"");
        std::map<idType, std::pair<bool, std::set<std::string> > >::iterator it = str().find(id);
        if (it != str().end()) {
            if (it->second.first == false) {
                size_t size_before = it->second.second.size();
                it->second.second.erase(s);

                if (size_before == it->second.second.size()) {
                    if (debug)
                        std::cerr << "set " << id << " does not contain the element \"" << s << "\"" << std::endl;
                }
                else {
                    if (debug)
                        std::cerr << "set " << id << ", element \"" << s << "\" removed" << std::endl;
                }
            }
            else {
                if (debug)
                    std::cerr << "attempt to remove from the 42 Set" << std::endl;
            }
        }
        else {
            if (debug)
                std::cerr << "set " << id << " does not exist" << std::endl;
        }
    }

    int strset_test(idType id, const char* value) {
        if (start_function_with_const_char(__func__, id, value)) {
            return 0;
        }
        std::string s(value);
        init_cerr(__func__, itoa(id) + ", \"" + s + "\"");
        std::map<idType, std::pair<bool, std::set<std::string> > >::iterator it = str().find(id);
        if (it != str().end()) {
            if (it->second.second.find(s) != it->second.second.end()) { // istnieje
                if (debug)
                    std::cerr << name(it) << " contains the element \"" << s << "\"" << std::endl;
                return 1;
            }
            else {
                if (debug)
                    std::cerr << name(it) << " does not contain the element \"" << s << "\"" << std::endl;
                return 0;
            }
        }
        else {
            if (debug)
                std::cerr << "set " << id << " does not exist" << std::endl;
            return 0;
        }
    }

    void strset_clear(idType id) {
        init_cerr(__func__, itoa(id));
        std::map<idType, std::pair<bool, std::set<std::string> > >::iterator it = str().find(id);
        if (it != str().end()) {
            if (it->second.first) {
                if (debug)
                    std::cerr << "attempt to clear the 42 Set" << std::endl;
            }
            else {
                if (debug)
                    std::cerr << "set " << id << " cleared" << std::endl;
                it->second.second.clear();
            }
        }
        else {
            if (debug)
                std::cerr << "set " << id << " does not exist" << std::endl;
        }
    }

    int strset_comp(idType id1, idType id2) {
        init_cerr_short(__func__, itoa(id1) + ", " + itoa(id2));
        int val = strset_compare(id1, id2);
        if (debug)
            std::cerr << __func__ << ": result of comparing " << name(id1) << " to " << name(id2) << " is " << val << std::endl;
        return val;
    }

}