#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Object {
    int id;
    bool marked;
    Object* next;

    Object(int id) : id(id), marked(false), next(nullptr) {}
};

class BakerGC {
    vector<Object*> from_space;
    vector<Object*> to_space;
    unordered_map<int, Object*> forwarding_address;

public:
    Object* allocate(int id) {
        Object* obj = new Object(id);
        from_space.push_back(obj);
        return obj;
    }

    Object* copy(Object* obj) {
        if (forwarding_address.find(obj->id) != forwarding_address.end()) {
            return forwarding_address[obj->id];
        }
        Object* new_obj = new Object(obj->id);
        to_space.push_back(new_obj);
        forwarding_address[obj->id] = new_obj;
        return new_obj;
    }

    void mark_and_copy(vector<Object*>& roots) {
        for (Object*& root : roots) {
            if (root != nullptr) {
                root = copy(root);
            }
        }
        for (Object* obj : to_space) {
            if (obj->next) {
                obj->next = copy(obj->next);
            }
        }
    }

    void flip() {
        for (Object* obj : from_space) {
            delete obj;
        }
        from_space.clear();
        from_space.swap(to_space);
        to_space.clear();
        forwarding_address.clear();
    }

    void collect(vector<Object*>& roots) {
        mark_and_copy(roots);
        flip();
    }

    void display() {
        cout << "Live objects: ";
        for (Object* obj : from_space) {
            cout << obj->id << " ";
        }
        cout << endl;
    }
};

int main() {
    BakerGC gc;
    Object* obj1 = gc.allocate(1);
    Object* obj2 = gc.allocate(2);
    Object* obj3 = gc.allocate(3);
    obj1->next = obj2;
    obj2->next = obj3;

    vector<Object*> roots = {obj1};
    gc.collect(roots);
    gc.display();

    return 0;
}
