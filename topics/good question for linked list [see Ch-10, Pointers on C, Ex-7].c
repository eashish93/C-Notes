// Assume that the node array begins at location 200 and that integers and pointers are four bytes on the machine

#include <stdio.h>

struct NODE {
	int a;
	struct NODE *b;
	struct NODE *c;
};

struct NODE nodes[5] = {
	{5, 	nodes+ 3, 		NULL},
	{15, 	nodes+ 4, 		nodes + 3},
	{22, 	NULL, 			nodes + 4},
	{12, 	nodes+ 3, 		nodes},
	{18, 	nodes+ 3, 		nodes + 1}

};

struct NODE *np = nodes + 2;
struct NODE **np = &nodes[1].b;

