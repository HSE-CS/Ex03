
const size_t LARGE_SIZE = 100000;
const size_t STEP = 5000;

struct rnd {
    int operator()() {
        return rand() % LARGE_SIZE;
    }
};

int comp(const void* a, const void* b);