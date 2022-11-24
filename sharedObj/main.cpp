#include "polygon.hpp"
#include <iostream>
#include <dlfcn.h>

// Website for dynamic Libs in CPP
//https://tldp.org/HOWTO/C++-dlopen/index.html

int main() {
    using std::cout;
    using std::cerr;

    // load the triangle library
    void* triangle = dlopen("./libtriangle.so", RTLD_LAZY);
    if (!triangle) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }
    // reset errors
    dlerror();
    // load the symbols
    create_t* create_triangle = (create_t*) dlsym(triangle, "create");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        return 1;
    }
    destroy_t* destroy_triangle = (destroy_t*) dlsym(triangle, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        return 1;
    }
    // create an instance of the class
    polygon* poly = create_triangle();

    // use the class
    poly->set_side_length(7);
    cout << "The area is: " << poly->area() << '\n';

    // Wait for user input
    cout<<"Press any key to continue\n";
    std::cin.get();
   
    // load the triangle library
    void* triangle2 = dlopen("./libtriangle.so", RTLD_LAZY);
    if (!triangle2) {
        cerr << "Cannot load library: " << dlerror() << '\n';
        return 1;
    }
    // reset errors
    dlerror();
    // load the symbols
    create_t* create_triangle2 = (create_t*) dlsym(triangle2, "create");
    dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        return 1;
    }
    destroy_t* destroy_triangle2 = (destroy_t*) dlsym(triangle2, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        return 1;
    }
    // create an instance of the class
    polygon* poly2 = create_triangle2();

    // use the class
    poly2->set_side_length(8);
    cout << "The area is: " << poly2->area() << '\n';

    // destroy the class
    destroy_triangle(poly);
    destroy_triangle2(poly2);

    // unload the triangle library
    dlclose(triangle2);
}
