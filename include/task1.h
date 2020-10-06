<<<<<<< HEAD
#ifndef TASK1_H
#define TASK1_H

using namespace std;

const size_t LARGE_SIZE = 120000;
=======
#ifndef TEST1_H
#define TEST1_H

using namespace std;

const size_t LARGE_SIZE = 100000;
>>>>>>> 5fcd52a07bd3bea81b86bc1346ed1ca523d10692

struct rnd {
	int operator()() {
		return rand() % LARGE_SIZE;
	}
};

int comp(const void* a, const void* b);

#endif
